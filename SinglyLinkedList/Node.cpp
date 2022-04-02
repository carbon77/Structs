#include "Node.h"

// Сравнивает два числа по старшей цифре.
// 1 - > 
// 0 - ==
// -1 - <
int compareByLeftNumber(int num1, int num2)
{
	int olderNum1 = num1 < 10 ? num1 : num1 / 10;
	int olderNum2 = num2 < 10 ? num2 : num2 / 10;

	if (olderNum1 == olderNum2)
	{
		return 0;
	}

	return olderNum1 > olderNum2 ? 1 : -1;
}

int compareByRightNumber(int num1, int num2)
{
	int olderNum1 = num1 < 10 ? num1 : num1 % 10;
	int olderNum2 = num2 < 10 ? num2 : num2 % 10;

	if (olderNum1 == olderNum2)
	{
		return 0;
	}

	return olderNum1 > olderNum2 ? 1 : -1;
}

void printList(Node* list)
{
	while (list != nullptr)
	{
		std::cout << list->data << " ";
		list = list->next;
	}
}

void addNode(Node*& list, int data, int (*compareFunc)(int, int))
{
	Node* newNode = new Node();
	newNode->data = data;

	if (list == nullptr)
	{
		list = newNode;
		return;
	}

	// Проверка если вставить надо в начало списка
	if (compareFunc(list->data, data) > 0)
	{
		newNode->next = list;
		list = newNode;
		return;
	}

	Node* currentNode = list;
	while (currentNode->next != nullptr &&
		compareFunc(currentNode->next->data, newNode->data) < 0)
	{
		currentNode = currentNode->next;
	}

	// Проверка если вставить надо в конец списка
	if (currentNode->next == nullptr)
	{
		currentNode->next = newNode;
		newNode->next = nullptr;
		return;
	}

	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

void removeNode(Node*& list, int index)
{
	if (index == 0)
	{
		Node* old = list;
		list = list->next;
		delete old;
		return;
	}

	Node* currentList = list;
	for (int i = 0; i < index - 1; i++)
	{
		if (currentList->next == nullptr)
		{
			return;
		}

		currentList = currentList->next;
	}

	Node* forRemove = currentList->next;
	currentList->next = forRemove->next;
	delete forRemove;
}

void createNewList(Node*& oldList, Node*& newList)
{
	while (oldList != nullptr)
	{
		addNode(newList, oldList->data, compareByRightNumber);
		removeNode(oldList, 0);
	}
}

bool isSorted(Node* list, int(*compareFunc)(int, int))
{
	while (list->next != nullptr)
	{
		if (compareFunc(list->data, list->next->data) > 0)
		{
			return false;
		}

		list = list->next;
	}

	return true;
}

void testLinkedList()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	Node* list = nullptr;
	std::cout << "Enter n numbers less than 100: ";

	int num;
	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		addNode(list, num, compareByLeftNumber);
	}

	std::cout << "\nList sorted by left number: ";
	printList(list);
	std::cout << '\n';
	std::cout << "Is this list sorted by right number: ";
	std::cout << (isSorted(list, compareByRightNumber) ? "yes" : "no") << '\n';

	Node* newList = nullptr;
	createNewList(list, newList);
	std::cout << "\nNew list sorted by right number: ";
	printList(newList);
	std::cout << '\n';

	std::cout << "Is new list sorted by right number: ";
	std::cout << (isSorted(newList, compareByRightNumber) ? "yes" : "no") << '\n';
}