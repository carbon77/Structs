#include "bm_search.h"

const int TABLE_SIZE = 256;

int bmSearch(std::string& text, std::string& substr)
{
	int badchar[TABLE_SIZE];
	int n = text.size();
	int m = substr.size();

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		badchar[i] = -1;
	}

	for (int i = 0; i < substr.size(); i++)
	{
		badchar[(int)substr[i]] = i;
	}

	int s = 0;

	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && substr[j] == text[s + j])
			j--;

		if (j < 0)
		{
			return s;
		}

		s += std::max(1, j - badchar[text[s + j]]);
	}

	return -1;
}


void testBmSearch()
{
	std::string largeText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam id consectetur elit. Curabitur vitae eleifend ante. Etiam a enim at dui ultrices blandit. Mauris posuere dolor elit, a imperdiet quam mollis non. Ut eget venenatis massa. Mauris a pharetra felis, quis mattis elit. Ut diam felis, venenatis vel ex in, commodo tempor mi. Nulla nec orci in arcu ultrices pulvinar sit amet eget tortor. Vestibulum porta ante quis ullamcorper dictum. Etiam dapibus eleifend commodo. Phasellus posuere lorem at rutrum vulputate.";
	std::string smallText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	std::string pat = "Etiam dapibus";
	
	std::cout << "Test large text:\n" << largeText;
	std::cout << "\n\nPattern: " << pat;
	std::cout << "\nOccurs: " << bmSearch(largeText, pat);

	pat = "this string doesn't exist";
	std::cout << "\n\nPattern: " << pat;
	std::cout << "\nOccurs: " << bmSearch(largeText, pat);

	pat = "sit amet";
	std::cout << "\n======\nTest small text:\n" << smallText;
	std::cout << "\n\nPattern: " << pat;
	std::cout << "\nOccurs: " << bmSearch(smallText, pat);

	pat = "lalala";
	std::cout << "\n\nPattern: " << pat;
	std::cout << "\nOccurs: " << bmSearch(smallText, pat);
}
