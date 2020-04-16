/*

You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N-1] is the height of the wall's right end.

The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:

int solution(vector<int> &H);

that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:
H[0] = 8    H[1] = 8    H[2] = 5
H[3] = 7    H[4] = 9    H[5] = 8
H[6] = 7    H[7] = 4    H[8] = 8

the function should return 7. The figure shows one possible arrangement of seven blocks.
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array H is an integer within the range [1..1,000,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>

typedef long long int l_int;

using namespace std;

int solution(vector<int> &H)
{
	/*
	** Logic : if there are 2 stones with the same height with no smaller stones in between they can be made one stone
	** Use a stack to push unmatched stones with greater height + to pop matched stones and stones with less height
	*/
	if (H.size() == 0)
	{
		return 0;
	}

	stack<int> stoneStack;
	int result = 0;

	for (int m = 0; m < H.size(); ++m)
	{
		if (stoneStack.empty())
		{
			stoneStack.push(H[m]);
		}
		else
		{
			while ((!stoneStack.empty()) && H[m] < stoneStack.top())
			{
				stoneStack.pop();
			}

			if (stoneStack.empty())
			{
				stoneStack.push(H[m]);
			}
			else if (H[m] > stoneStack.top())
			{
				stoneStack.push(H[m]);
			}
			else if (H[m] == stoneStack.top())
			{
				result++;
			}
		}
	}
	return (H.size() - result);
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 8,8,5,7,9,8,7,4,8 };
	vector<int> B = { 8,8,8,8,8,8,8,8,8 };
	vector<int> C = { 8 };
	vector<int> D = {  };
	vector<int> E = { 8,8,5,7,9,8,7,4,8,8 };
	vector<int> F = { 8,8,5,7,9,8,7,7,4,8,8 };
	

	assert(solution(A) == 7);
	assert(solution(B) == 1);
	assert(solution(C) == 1);
	assert(solution(D) == 0);
	assert(solution(E) == 7);
	assert(solution(F) == 7);


	cout << "All tests passed" << endl;
	system("PAUSE");
}

