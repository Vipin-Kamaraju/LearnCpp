/*

A non-empty array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 = X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y - 1] + A[Y + 1] + A[Y + 2] + ... + A[Z - 1].

For example, array A such that:
A[0] = 3
A[1] = 2
A[2] = 6
A[3] = -1
A[4] = 4
A[5] = 5
A[6] = -1
A[7] = 2

contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 - 1 = 16,
double slice (3, 4, 5), sum is 0.

The goal is to find the maximal sum of any double slice.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:
A[0] = 3
A[1] = 2
A[2] = 6
A[3] = -1
A[4] = 4
A[5] = 5
A[6] = -1
A[7] = 2

the function should return 17, because no double slice of array A has a sum of greater than 17.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [-10,000..10,000].

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

int solution(vector<int> &A)
{
	/*
	** Logic : treat the array as 2 slices
	** Getting the index of the max double slice is not important so we find the prefix sum of 
	** all the slices from 2 directions. forward and reverse iterator.
	** Ignore the 1st and last element in the calculation since they are not required
	** find the max of 2 slices for every position of Y (Range 1 to N-1)
	*/
	int result = 0;

	if (A.size() <= 3)
	{
		return 0;
	}
	int N = A.size();

	vector<int> maxValuesForward(N,0);
	int maxValue_F = 0;
	
	int count_F = 0;
	int count_R = 0;

	for (int it_F = 1; it_F < N-1; ++it_F)
	{
		maxValue_F = std::max((maxValue_F + A[it_F]), 0);
		maxValuesForward.at(it_F) = maxValue_F;
		count_F++;
	}


	vector<int> maxValuesReverse(N,0);
	int maxValue_R = 0;


	for (int it_R = N -2; it_R > 0; --it_R)
	{
		maxValue_R = std::max((maxValue_R + A[it_R]), 0);
		maxValuesReverse.at(it_R) = maxValue_R;
		count_R++;
	}


	for (int m = 1; (m < A.size() - 1); ++m)
	{
		result = std::max((maxValuesForward[m-1] + maxValuesReverse[m+1]), result);
	}


	return result;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 3,2,6,-1,4,5,-1,2 };
	vector<int> B = { 5,-7,3,5,-2,4,-1 };
	vector<int> C = { 3,-3,-4,-5,-6,-3,-5,-3 };
	vector<int> D = { 3,-3,-4,-5,-6,-3,-5,5,-3 };
	vector<int> E = { 20,-1,3,-40,5,4,-40,4,-40,5,3,-2,3 };
	vector<int> F = { 3,-3,3,-3,3,-3,3,-3,3 };

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 17);
	assert(solution(B) == 12);
	assert(solution(C) == 0);
	assert(solution(D) == 5);
	assert(solution(E) == 13);
	assert(solution(F) == 6);
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

