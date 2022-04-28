#include "Node.h"

void print(Node* node)
{
	Node* temp = node;
	while (temp != nullptr)
	{
		std::cout << temp->data;
		temp = temp->next;

		if (temp != nullptr)
		{
			std::cout << " -> ";
		}
	}
}

void deleteNode(Node* node)
{
	Node* next = node->next;
	delete node;

	if (next != nullptr)
	{
		deleteNode(next);
	}
}

void push(Node*& node, int newData)
{

	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;

	if (node == nullptr)
	{
		node = newNode;
		return;
	}

	Node* temp = node;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

Node* reverse(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return rest;
}

void testReverseLinkedList()
{
	srand(time(NULL));
	
	int count;
	std::cout << "Enter count: ";
	std::cin >> count;
	Node* head = nullptr;

	std::cout << "Enter numbers: ";
	for (int i = 0; i < count; i++)
	{
		int x;
		std::cin >> x;
		push(head, x);
	}

	std::cout << "\nYour linked list: ";
	print(head);
	Node* reversedHead = reverse(head);
	std::cout << "\nReversed linked list: ";
	print(reversedHead);
	deleteNode(head);
}