#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(Node** Mohammad, Node** Zachary);
	bool search(int rollno, Node** Mohammad, Node** Zachary);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode(Node** Mohammad, Node** Zachary) {
	Node* newNode = new Node();
	LAST = newNode;
	newNode->next = LAST;
	LAST->next = newNode;
	LAST = NULL;

	while ((*Zachary) != LAST) {
		*Mohammad = *Zachary;
		*Zachary = (*Mohammad)->next;
	}
	Node* temp = new Node();
	temp->next;
	newNode->next = LAST;
	LAST = newNode;
}

bool CircularLinkedList::search(int rollno, Node** Mohammad, Node** Zachary) {
	*Mohammad = LAST->next;
	*Zachary = LAST->next;
	while (*Zachary != LAST) {
		if (rollno == (*Zachary)->rollNumber) {
			return true;
		}
		*Mohammad = *Zachary;
		*Zachary = (*Zachary)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	LAST = NULL;
	return LAST;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* Zachary = LAST->next;
		while (Zachary != LAST) {
			cout << Zachary->rollNumber << " " << Zachary->name << endl;
			Zachary = Zachary->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the record  in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";

			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}