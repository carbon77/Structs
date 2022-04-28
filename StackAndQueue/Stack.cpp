#include "Stack.h"

int top(Stack& stack)
{
	return stack.top->value;
}

void push(Stack& stack, int value)
{
	Node* node = new Node();
	node->next = stack.top;
	node->value = value;

	stack.top = node;
	stack.size++;
}

int pop(Stack& stack)
{
	Node* node = stack.top;

	int value = node->value;

	stack.top = node->next;
	delete node;
	stack.size--;

	return value;
}

std::ostream& operator<<(std::ostream& cout, Stack& stack)
{
	Node* temp = stack.top;

	while (temp != nullptr)
	{
		std::cout << temp->value;
		temp = temp->next;

		if (temp != nullptr)
			std::cout << " ";
	}

	return cout;
}

int calculatePostfix(std::string exp)
{
	Stack stack;

	for (int i = 0; i < exp.size(); i++)
	{
		char ch = exp.at(i);

		if (48 <= ch && ch <= 57)
		{
			int num = ch - '0';
			push(stack, num);
		}
		else
		{
			int b = pop(stack);
			int a = pop(stack);
			int n;

			switch (ch)
			{
				case '+':
					n = a + b;
					break;
				case '-':
					n = a - b;
					break;
				case '*':
					n = a * b;
					break;
				case '/':
					n = a / b;
					break;
			}

			push(stack, n);
		}

		std::cout << i + 1 << ") char = " << ch << ", stack = [" << stack << "]\n";
	}

	return pop(stack);
}

void testTask2()
{
	std::string exp;
	std::cout << "Enter expression in postfix notation: ";
	std::cin >> exp;

	int n = calculatePostfix(exp);
	std::cout << "Result: " << n;
}
