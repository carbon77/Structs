#pragma once

#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void testLinkedList(); // �������� ������� ������������

// ���������� ������ ���� � ������, ���������������
// �� ������������ �� ������� compareFunc
void addNode(Node*& list, int data, int(*compareFunc)(int, int)); 

void printList(Node* list); // ����� ������
void removeNode(Node*& list, int index); // �������� ���� �� �������, ������� �� start

// �������� ������ ������ newList �� ������ ������� oldList, ��������
// �������� ����������� �� ����������� ������� �����
void createNewList(Node*& oldList, Node*& newList); 

bool isSorted(Node* list, int(compareFunc)(int, int)); // ���������, ���������� �� ������ list �� ������������ �� ������� compareFunc
