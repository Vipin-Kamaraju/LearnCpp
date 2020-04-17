/*

A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 = P = Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

For example, given array A such that:
A[0] = 3  A[1] = 2  A[2] = -6
A[3] = 4  A[4] = 0

the function should return 5 because:

(3, 4) is a slice of A that has sum 4,
(2, 2) is a slice of A that has sum -6,
(0, 1) is a slice of A that has sum 5,
no other slice of A has sum greater than (0, 1).

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [-1,000,000..1,000,000];
the result will be an integer within the range [-2,147,483,648..2,147,483,647].

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
	int minInt = std::numeric_limits<int>::min();
	int max_ending = 0;
	int max_slice = 0;
	bool positiveElem = false;

	for (int m = 0; m < A.size(); ++m)
	{
		if (A[m] >= 0)
		{
			positiveElem = true;
		}
	}

	if (positiveElem)
	{
		for (auto it_A = A.begin(); it_A != A.end(); ++it_A)
		{
			max_ending = std::max(0, (max_ending + *it_A));
			max_slice = std::max(max_slice, max_ending);
		}
	}
	else
	{
		sort(A.begin(), A.end());
		return A.back();
	}



	return max_slice;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 3,2,-6,4,0 };
	/*vector<int> B = { 5,-7,3,5,-2,4,-1 };
	vector<int> C = { 3,-3,-4,-5,-6,-3,-5,-3 };
	vector<int> D = { 3,-3,-4,-5,-6,-3,-5,5,-3 };
	vector<int> E = { 20,-1,3,-40,5,4,-40,4,-40,5,3,-2,3 };
	vector<int> F = { 3,-3,3,-3,3,-3,3,-3,3 };
*/
	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 5);
	/*assert(solution(B) == 12);
	assert(solution(C) == 0);
	assert(solution(D) == 5);
	assert(solution(E) == 13);
	assert(solution(F) == 6);
	*/
	cout << "All tests passed" << endl;
	system("PAUSE");
}

