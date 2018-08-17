#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first;            // list的第一個node
public:
    LinkedList():first(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};

void LinkedList::PrintList(){
	if(first==0){
		cout<<"the list is empty!"<<endl;;
		return;
	}
	
	ListNode *cur = first;
	while(cur){
		cout<<cur->data<<" ";
		cur = cur->next;
	}
	cout<<endl;
}

void LinkedList::Push_back(int x){
	ListNode *newnode = new ListNode(x);
	if(first==0){
		first = newnode;
		cout<<"it's a new node!"<<endl;
		}
	else{
		ListNode *cur = first;
		while(cur->next!=0){
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void LinkedList::Push_front(int x){
	ListNode *newnode = new ListNode(x);
	if(first==0){
		first = newnode;
		cout<<"it's a new node!"<<endl;
	}
	else{
		newnode->next = first;
		first = newnode;
	}
}

void LinkedList::Delete(int x){
	ListNode *pre = new ListNode(0), *cur = first;
	while(cur != 0 && cur->data != x){
		pre = cur;
		cur = cur->next;
	}
	
	if(cur==0){
		cout << "there is no " << x << " in the list!" << endl;
	}
	else if(cur==first){
		first = cur->next;
		delete cur;
		cur = 0;
	}
	else{
		pre->next = cur->next;
		delete cur;
		cur = 0;
	}
}

void LinkedList::Clear(){
	while(first){
		ListNode *cur = first;
		first = first->next;
		delete cur;
		cur = 0;
	}
}

void LinkedList::Reverse(){
	ListNode *pre = 0, *cur = first, *prec = first->next;
	while(prec){
		cur->next = pre;
		pre = cur;
		cur = prec;
		prec = prec->next;
	}
	cur->next = pre;
	first = cur;
}

int main(){
	LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Push_back(5);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(9);  // list: 9 5 3
    list.PrintList();    // 印出:  9 5 3
    list.Push_back(4);   // list: 9 5 3 4
    list.Delete(9);      // list: 5 3 4
    list.PrintList();    // 印出:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // 印出:  8 5 3 4
    list.Reverse();      // list: 4 3 5 8
    list.PrintList();    // 印出:  4 3 5 8
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.

    return 0;
}
