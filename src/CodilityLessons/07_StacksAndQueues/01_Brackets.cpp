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
#include <string>


using namespace std;

int solution(string &S)
{

	// S.empty() == true
	if (S.size() == 0)
	{
		return 1;
	}

	// Since S contains no extra elements other than the mentioned elements
	// S.size cannot be odd
	if ((S.size() % 2) != 0)
	{
		return 0;
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

		if ((*it == '}') && (lastElement == '{'))
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
			else
			{
				lastElement = NULL;
			}
		}
		else if ((*it == ']') && (lastElement == '['))
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
			else
			{
				lastElement = NULL;
			}
		}
		else if ((*it == ')') && (lastElement == '('))
		{
			filteredString.pop_back();
			if (filteredString.size() != 0)
			{
				lastElement = *(filteredString.end() - 1);
			}
			else
			{
				lastElement = NULL;
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
	printf("%ld\n", __cplusplus);

	string S1 = "{[()()]}";
	string S2 = "([)()]";
	string S3 = "{[()()]}{[()()]}";
	//string S4 = "{[(U)()]}{[()()]}"; // check no longer valid since S does not contain U
	string S5 = "())(()";
	
	assert(solution(S1) == 1);
	assert(solution(S2) == 0);
	assert(solution(S3) == 1);
	//assert(solution(S4) == 0);
	assert(solution(S5) == 0);
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

