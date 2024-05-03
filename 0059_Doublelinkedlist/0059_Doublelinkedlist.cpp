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

		while 
	}

}