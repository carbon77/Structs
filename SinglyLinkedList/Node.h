#pragma once

#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void testLinkedList(); // Основная функция тестирования

// Добавление нового узла в список, отсортированных
// по возврастанию по функции compareFunc
void addNode(Node*& list, int data, int(*compareFunc)(int, int)); 

void printList(Node* list); // Вывод списка
void removeNode(Node*& list, int index); // Удаление узла по индексу, начиная со start

// Создание нового списка newList на основе старого oldList, элементы
// которого упорядочены по возрастанию младшей цифры
void createNewList(Node*& oldList, Node*& newList); 

bool isSorted(Node* list, int(compareFunc)(int, int)); // Проверяет, упорядочен ли список list по возврастанию по функции compareFunc
