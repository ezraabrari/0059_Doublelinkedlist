#include <iostream>
using namespace std;

struct Node {
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

Node* START = NULL;

void addNode() {
	Node* newNode = new Node();
	cout << "\nMasukkan NIM dari mahasiswa :  : ";
	cin >> newNode->noMhs;
	cout << "\nMasukkan nama dari mahasiswa : ";
	cin >> newNode->name;

	if (START == NULL || newNode->noMhs <= START->noMhs) {
		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
		}

		newNode->next = START;
		if (START != NULL) {
			START->prev = newNode;
	}
		newNode->prev = NULL;
		START = newNode;
	}
	else {
		Node* current = START;
		Node* previous = NULL;

		while (current != NULL && current->noMhs < newNode->noMhs) {
			previous = current;
			current = current->next;
		}

		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL) {
			current->prev = newNode;
		}

		if (previous != NULL) {
			previous->next = newNode;
		}
		else {
			START = newNode;
		}
	}

}

bool search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void deleteNode() {
	Node* previous, * current;
	int rollNo;

	cout << "\nEnter the roll number of the student whose record is to be deleted : ";
	cin >> rollNo;

	if (START == NULL) {
		cout << "list is empty" << endl;
		return;
	}

	current = START;
	previous = NULL;

	while (current != NULL && current->noMhs != rollNo) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "\033[31m The record with roll number " << rollNo << "Not Found\033[0" << endl;
		return;
	}

	if (current == START) {
		START = START->next;
		if (START != NULL) {
			START->prev = NULL
		}
	}
	else {
		previous->next = current->next;
		if (current->next != NULL) {
			current->next->prev = previous;
		}
	}

	delete current;
	cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listEmpty