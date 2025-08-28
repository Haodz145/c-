#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

Node *TaoNode(int x){
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void duyet(Node *first){
	while(first != NULL){
		cout << first->data << " ";
		first = first->next;
	}
}

int len(Node *first){
    int dem = 0;
    while(first != NULL){
        ++dem;
        first = first->next; // cho head chuyen sang node ke tiep
    }
    return dem;
}

void InsertFirst(Node *&first, int x){
	Node *p = TaoNode(x);
	if(first == NULL){
		first = p;
	}
	else {
		p->next = first;
		first = p;
	}
}

void InsertLast(Node *&first, int x){
	Node *p = TaoNode(x);
	if(first == NULL){
		first = p;
	}
	else {
		Node *q = first;
		while(q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

void InsertMiddle(Node *&first, int x, int k){
	int n = len(first);
	if(k < 1 || k > n + 1){
		cout << "Chen vi tri khong hop le";
		return;
	}
	Node *p = TaoNode(x);
	if(k == 1){
		InsertFirst(first, x); 
		return;
	}
	else {
		Node *q = first;
		for(int i=1;i<k-1;i++){
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
}


void DeleteFirst(Node *&first){
	if(first == NULL) return;
	Node *p = first;
	first = first->next;
	delete p;
}

void DeleteLast(Node *&first){
	if(first == NULL) return;
	if(first->next == NULL) {
		delete first; 
		first = NULL;
	}
	else {
		Node *p = first;
		while(p->next->next != NULL){
			p = p->next;
		}
		Node *q = p->next;
		p->next = NULL;
		delete q;
	}
}

void DeleteMiddle(Node *&first, int k){
	if( k < 1 || k > len(first)) return;
	if(k == 1){
		DeleteFirst(first);
	}
	else {
		Node *p = first;
		for(int i=1; i<k-2;i++){
			p = p->next;
		}
		Node *q = p->next;
		p->next = q->next;
		delete q;
	}
} 


int main(){
	Node *head = NULL;
	for(int i=0;i<=10;i++){
		InsertFirst(head, i);
	}
	InsertMiddle(head, 28, 5);
	InsertMiddle(head, 28, 9);
	DeleteFirst(head);
	DeleteLast(head);
	DeleteMiddle(head, 3);
	duyet(head);
}
