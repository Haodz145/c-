#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string manv;
    string hoten;
    int sogiolamviec;
    Node *next;
};
Node *first;

Node *TaoNode(string a, string b, int x){
	Node *p = new Node;
	p->manv = a;
	p->hoten = b;
	p->sogiolamviec = x;
	return p;
}

void insertFirst(Node *&first, string a, string b, int x){
	Node *p = TaoNode(a, b, x);
	p->next = first;
	first = p;
};

void insertLast(Node *&first, string a, string b, int x){
	Node *p = TaoNode(a, b, x);
	p->next = NULL;
	if(first == NULL){
		first = p;
	}
	else
	{
		Node *k = first;
		while(k->next != NULL)
			k = k->next;
		k->next = p;
	}
}

bool ktra (Node *first, string a){
	while(first != NULL){
		if(first->manv == a) return 1;
		first = first->next;
	}
	return 0;
}

int count(Node *first){
	int cnt = 0;
	while(first != NULL){
		cnt++;
		first = first->next;
	}
	return cnt;
}
long long luong(Node *first, string a){
	long long sum = 0;
	while(first != NULL){
		if(first->manv == a){
			if (first->sogiolamviec < 0) return -1;
			else if(first->sogiolamviec >= 0 && first->sogiolamviec < 20) {
				sum += first->sogiolamviec * 15000;
			}
			else if(first->sogiolamviec >= 20) sum += 19 * 15000 + (first->sogiolamviec - 19) * 20000;
			return sum;
		}
		first = first->next;
	}
	
}
void in(Node *first){
	while(first != NULL){
		cout << first->manv << " " << first->sogiolamviec<< " " << first->hoten << endl;
		first = first->next;
	}
}


int main(){
	Node *head = NULL;
	string s;
	while(cin >> s){
		if(s == "insert"){
			string a, b; 
			int x;
			cin >> a >> x ;
			cin.ignore();
			getline(cin, b);
			if(ktra(head, a) == 0)
				insertLast(head, a, b, x);
		}
		else if(s ==  "count") cout << count(head) << endl;
		else if(s == "summoney"){
			string str; cin >> str;
			cout << luong(head, str) << endl;
		}
		else if(s == "display") {
			in(head);
		}
		else if(s == "finish") break;
	}
	return 0;
}
