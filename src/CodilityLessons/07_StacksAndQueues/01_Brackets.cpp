/*

A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.

For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>


using namespace std;

int solution(string &S)
{

	// S.empty() == true
	if (S.size() == 0)
	{
		return 1;
	}
	string filteredString; //contains only brackets
	char lastElement = NULL;

	for (auto it = S.begin(); it != S.end(); ++it)
	{
		if (*it == '{')
		{
			filteredString.push_back(*it);
			lastElement = *it;
		}
		else if (*it == '[')
		{
			filteredString.push_back(*it);
			lastElement = *it;
		}
		else if (*it == '(')
		{
			filteredString.push_back(*it);
			lastElement = *it;
		}

		if (*it == '}' && lastElement == '{')
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
		}
		else if (*it == ']' && lastElement == '[')
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
		}
		else if (*it == ')' && lastElement == '(')
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
		}

	}

	if (filteredString.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	string S1 = "{[()()]}";
	string S2 = "([)()]";
	string S3 = "{[()()]}{[()()]}";
	string S4 = "{[()(U)]}{[()()]}";

	assert(solution(S1) == 1);
	assert(solution(S2) == 0);
	assert(solution(S3) == 1);
	assert(solution(S3) == 1);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

