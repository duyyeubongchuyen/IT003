#include <iostream>

using namespace std;

struct Node {
	int info;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void Init(List& danhsach) {
	danhsach.head = NULL;
	danhsach.tail = NULL;
}

void swapInfo(Node* a,Node* b) {
	int temp = a->info;
	a->info = b->info;
	b->info = temp;
}

int minInfo(List danhsach) {
	int min = danhsach.head->info;
	Node* p = danhsach.head->next;
	while (p!=NULL) {
		if (p->info < min) min = p->info;
		p = p->next;
	}
}

void selectionSort(List& danhsach) {
	Node* p = danhsach.head;
	while (p != NULL) {
		Node* temp = p->next;
		p->next = NULL;
	}
}

Node* createNode(int info) {
	if (info == NULL)
		exit(1);
	Node* p = new Node;
	p->info = info;
	p->next = NULL;
	return p;
}



int main() {

}