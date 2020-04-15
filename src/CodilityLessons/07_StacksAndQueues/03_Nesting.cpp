/*

A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.

For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <string>
#include <stack>

typedef long long int l_int;

using namespace std;

int solution(string &S)
{
	/* 
	** Can be done same as the previous 2 problems.(Brackets and Fish)
	** Lets write this solution in another way than the Brackets solution
	** 2 cases: open bracket and closed bracket
	** return 0 if closed bracket appears before open bracket
	** return 1
	*/
	if (S.size() == 0)
	{
		return 1;
	}

	// check if the size is odd
	if (S.size() % 2 != 0)
	{
		return 0;
	}

	stack<char> charStack;
	char lastElement = NULL;
	bool firstIteration = true;

	for (auto it_S = S.begin() ;it_S != S.end(); ++it_S)
	{
		if (firstIteration)
		{
			if (*it_S == ')')
			{
				return 0;
			}

			firstIteration = false;
		}

		if (*it_S == '(')
		{
			charStack.push(*it_S);
		}
		else
		{
			if (charStack.empty())
			{
				return 0;
			}
			else
			{
				charStack.pop();
			}
		}
	}

	if (charStack.size() == 0)
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
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.
	
	string A = "(()(())())";
	string B = "())";
	string C = "";
	string D = ")(((())())";
	string E = "())(()";

	assert(solution(A) == 1);
	assert(solution(B) == 0);
	assert(solution(C) == 1);
	assert(solution(D) == 0);
	assert(solution(E) == 0);

	cout << "All tests passed" << endl;
	system("PAUSE");
}

