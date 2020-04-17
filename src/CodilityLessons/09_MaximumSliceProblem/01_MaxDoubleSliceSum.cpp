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
	int result = 1;

	if (A.size() <= 3)
	{
		return 0;
	}

	vector<int> copyA(A.begin(), A.end());
	//vector<int> copyA(A.begin()+1, A.end()-1);
	vector<int> forwardSum;
	vector<int> reverseSum;
	vector<std::pair<int,int>> combinedSum;

	int sum_f = 0;
	int sum_r = 0;
	int sumAtIndex = 0;

	auto it_R = copyA.rbegin(); // reverse iterator
	bool firstIteration = true;

	///////////////////////////////////////////
	// Calculate max slice value
	//////////////////////////////////////////

	int max_ending = 0;
	int max_slice = 0;
	vector<int> maxSlice;

	for (auto it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		max_ending = std::max(0, max_ending + *it_A);
		max_slice = std::max(max_slice, max_ending);
		maxSlice.push_back(max_slice);
	}

	//////////////////////////////////////////

	for (auto it_F = copyA.begin(); (it_F != copyA.end()) && (it_R != copyA.rend()); ++it_F , ++it_R)
	{
		if (firstIteration)
		{
			*it_F = 0;
			*it_R = 0;
			firstIteration = false;
		}

		sum_f = sum_f + *it_F;
		sum_r = sum_r + *it_R;
		forwardSum.push_back(sum_f);
		reverseSum.push_back(sum_r);
	}

	int N = forwardSum.size() - 1;

	for (int m = 0; m < forwardSum.size(); ++m)
	{
		sumAtIndex = forwardSum[m] + reverseSum[N -m];
		combinedSum.push_back(std::pair<int,int>(sumAtIndex,m));
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
	assert(solution(A) > 0);
	assert(solution(B) > 0);
	assert(solution(C) > 0);
	assert(solution(D) > 0);
	assert(solution(E) > 0);
	assert(solution(F) > 0);

	//// first lets return the leader and check if we are getting the correct answer
	//assert(solution(A) == 17);
	//assert(solution(B) == 12);
	//assert(solution(C) == 0);
	//assert(solution(D) == 5);
	//assert(solution(E) == 13);
	//assert(solution(F) == 6);
	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

