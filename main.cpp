#include<iostream>

using namespace std;
class Node {
public:
	int data;
	Node* nextNode;

	Node(int data = 0) {
		this->data = data;
		nextNode = NULL;
	}
};

int getInput() {
	int input = 0;

	cin >> input;
	while (!cin.good()) {
		cout << "Wrong input" << "\n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Try again: ";
		cin >> input;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return input;
}

void printList(Node* head) {
	cout << "List: ";
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->nextNode;
	}
	cout << "\n";
}

void addToFront(Node** head, int newData) {
	Node* newNode = new Node(newData);

	newNode->nextNode = *head;

	*head = newNode;
}

void addToBack(Node** head, int newData) {
	Node* newNode = new Node(newData);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	Node* last = *head;
	while (last->nextNode != NULL) {
		last = last->nextNode;
	}

	last->nextNode = newNode;
}

void addAfter(Node** head, int prev, int newData)	 {
	Node* newNode = new Node(newData);

	Node* find = *head;
	while (find->nextNode != NULL) {
		if (find->data == prev)
			break;
		find = find->nextNode;
	}
	
	if (find->data != prev) {
		cout << "Element not found" << "\n";
		return;
	}

	if (find == NULL) {
		find = newNode;
		return;
	}

	newNode->nextNode = find->nextNode;
	find->nextNode = newNode;
}

void delFirst(Node* &head) {
	if(head != NULL){
		Node* temp = head->nextNode;

		delete head;

		head = temp;
	}
}

void delLast(Node* &head) {
	if (head == NULL)
		return;

	Node* seclast = head;
	while (seclast->nextNode->nextNode != NULL) {
		seclast = seclast->nextNode;
	}

	delete seclast->nextNode;
	seclast->nextNode = NULL;
}

void delAll(Node* &head) {
	if (head == NULL)
		return;

	Node* next = new Node();
	while (head != NULL) {
		next = head->nextNode;
		delete head;
		head = next;
	}
}

int lengthOfList(Node* head) {
	int listLength = 0;
	while (head != NULL) {
		head = head->nextNode;
		listLength++;
	}

	return listLength;
}

enum Options {
	Quit, PrintList, AddToFront, AddToBack, AddAfter, DelFirst, DelLast, DelAll, LengthOfList,
};

bool menu(Node* &head) {
	int num = 0, el = 0, choice = 0;

	cout << "\tMENU" << "\n"
		<< "1: Print list" << "\n"
		<< "2: Add first element" << "\n"
		<< "3: Add last element" << "\n"
		<< "4: Add after element" << "\n"
		<< "5: Delete first element" << "\n"
		<< "6: Delete last element" << "\n"
		<< "7: Delete all elements" << "\n"
		<< "8: Length of list" << "\n"
		<< "0: Quit" << "\n\n";

	cout << "Write your choice: ";
	choice = getInput();

	switch (choice)
	{
	case PrintList:
		printList(head);
		break;

	case AddToFront:
		cout << "What num u wanna add: ";
		num = getInput();
		addToFront(&head, num);
		break;

	case AddToBack:
		cout << "What num u wanna add: ";
		num = getInput();
		addToBack(&head, num);
		break;

	case AddAfter:
		cout << "After what element u wanna add num: ";
		el = getInput();
		cout << "What num u wanna add: ";
		num = getInput();
		addAfter(&head, el, num);
		break;

	case DelFirst:
		delFirst(head);
		break;

	case DelLast:
		delLast(head);
		break;

	case DelAll:
		delAll(head);
		break;

	case LengthOfList:
		cout << "Length of list is " << lengthOfList(head);
		break;

	case Quit:
		cout << "Quiting...";
		return false;
		break;

	default:
		cout << "Wrong option" << "\n";
		break;
	}

	return true;
}

int main() {
	Node* head = NULL;

	int working = menu(head);

	while (working)
		working = menu(head);

	return 0;
}
