#include "sort.h"
#include "Node.h"

int main()
{
    int choice;
    std::cout << "Choose task:\n" << "1: Merge sort\n" << "2: Reverse linked list\n: ";
    std::cin >> choice;

    if (choice == 1)
    {
        testMergeSort();
    }
    else if (choice == 2)
    {
        testReverseLinkedList();
    }
}