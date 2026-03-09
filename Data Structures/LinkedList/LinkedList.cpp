#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Node {
	int val;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
	List() : head(nullptr), tail(nullptr){}
};

void initList(List* list) {
	list->head = nullptr;
	list->tail = nullptr;
}

void insertHead(List* list, int newval) {
	Node* newhead = new Node;
	newhead->val = newval;

	if (list->head == nullptr) {
		list->head = newhead;
		list->tail = list->head;
	}
	else {
		newhead->next = list->head;
		list->head = newhead;
	}
}

void insertTail(List* list, int newval) {
	Node* newtail = new Node;
	newtail->val = newval;
	newtail->next = nullptr;

	if (list->tail == nullptr) {
		list->tail = newtail;
		list->head = list->tail;
	}
	else {
		list->tail->next = newtail;
		list->tail = newtail;
	}
}

void printList(List* list) {
	while (list->head != NULL) {
		cout << list->head->val << " ";
		list->head = list->head->next;
	}
}

void deleteList(List*& list) {
	while (list->head != NULL) {
		Node* temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	list->tail = nullptr;
	delete list;
}

void reverseList(List* list) {

}

int main() {
	List* list = new List;
	initList(list);
	insertHead(list, 2);
	insertHead(list, 1);
	insertTail(list, 3);
	printList(list);
	deleteList(list);
}