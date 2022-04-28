#include "task1.h"

typedef std::map<char, int> MyMap;

std::ostream& operator<<(std::ostream& cout, std::stack<char>& stack)
{
	std::stack<char> copy = stack;

	while (copy.size() > 0) {
		cout << copy.top();
		copy.pop();

		if (copy.size() != 0)
			cout << " ";
	}

	return cout;
}

std::ostream& operator<<(std::ostream& cout, std::stack<std::string>& stack)
{
	std::stack<std::string> copy = stack;

	while (copy.size() > 0) {
		cout << copy.top();
		copy.pop();

		if (copy.size() != 0)
			cout << " ";
	}

	return cout;
}

std::ostream& operator<<(std::ostream& cout, std::stack<int>& stack)
{
	std::stack<int> copy = stack;

	while (copy.size() > 0) {
		cout << copy.top();
		copy.pop();

		if (copy.size() != 0)
			cout << " ";
	}

	return cout;
}

std::string fromInfToPost(std::string& exp)
{
	std::string newExp;
	std::stack<char> stack;
	MyMap pr;

	pr.insert(MyMap::value_type('-', 1));
	pr.insert(MyMap::value_type('+', 1));
	pr.insert(MyMap::value_type('*', 2));
	pr.insert(MyMap::value_type('/', 2));
	pr.insert(MyMap::value_type('^', 3));

	for (int i = 0; i < exp.size(); i++)
	{
		char ch = exp.at(i);

		if (ch == '(')
		{
			stack.push(ch);
		}
		else if (ch == ')')
		{
			while (stack.size() > 0)
			{
				if (stack.top() != '(')
				{
					newExp += stack.top();
					stack.pop();
				}
				else
				{
					stack.pop();
					break;
				}
			}
		}
		else if (97 <= ch && ch <= 122)
		{
			newExp += ch;
		}
		else
		{
			if (stack.size() == 0 || stack.top() == '(' || pr.at(stack.top()) < pr.at(ch))
			{
				stack.push(ch);
			}
			else
			{
				newExp += stack.top();
				stack.pop();
				stack.push(ch);
			}
		}

		std::cout << i + 1 << ") ch = " << ch << ", stack = [" << stack << "], exp = " << newExp << "\n";
	}

	while (stack.size() > 0)
	{
		newExp += stack.top();
		stack.pop();
	}

	return newExp;
}

std::string fromPostToInf(std::string& exp)
{
	std::stack<std::string> stack;

	for (int i = 0; i < exp.size(); i++)
	{
		char ch = exp.at(i);

		if (97 <= ch && ch <= 122)
		{
			std::string s;
			s += ch;
			stack.push(s);
		}
		else
		{
			std::string a = stack.top();
			stack.pop();
			std::string b = stack.top();
			stack.pop();

			std::string s = '(' + b + ch + a + ')';
			stack.push(s);
		}

		std::cout << i + 1 << ") char = " << ch << ", stack = [" << stack << "]\n";
	}

	return stack.top();
}

int calculatePrefix(std::string& exp) 
{
	std::stack<int> stack;

	for (int i = exp.size() - 1; i >= 0; i--)
	{
		char ch = exp.at(i);
		std::string s;
		s += ch;

		if (48 <= ch && ch <= 57)
		{
			stack.push(std::stoi(s));
		}
		else
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
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
				case '^':
					n = pow(a, b);
					break;

			}

			stack.push(n);
		}

		std::cout << exp.size() - i << ") char = " << ch << " stack = [" << stack << "]\n";
	}

	return stack.top();
}

void testTask1()
{
	std::string exp1 = "(a-b*c)*(d-e/f/g)*(k-l*m)";
	std::string exp2 = "ab*cde*+*k^";
	std::string exp3 = "+7//8-42+^215";

	std::cout << "Convert " << exp1 << " from infix to postfix notation:\n";
	std::cout << "Result: " << fromInfToPost(exp1);

	std::cout << "\n\nConvert " << exp2 << " from postfix to infix notation:\n";
	std::string s = fromPostToInf(exp2);
	std::cout << "Result: " << s;

	std::cout << "\n\nConvert " << s << " from infix to postfix notation:\n";
	std::cout << "Result: " << fromInfToPost(s);

	std::cout << "\n\nCalculate: " << exp3 << " from prefix notation:\n";
	std::cout << "Result: " << calculatePrefix(exp3);
}
