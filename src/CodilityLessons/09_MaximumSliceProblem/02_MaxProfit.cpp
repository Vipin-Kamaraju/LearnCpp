/*

An array A consisting of N integers is given. It contains daily prices of a stock share for a period of N consecutive days. If a single share was bought on day P and sold on day Q, where 0 = P = Q < N, then the profit of such transaction is equal to A[Q] - A[P], provided that A[Q] = A[P]. Otherwise, the transaction brings loss of A[P] - A[Q].

For example, consider the following array A consisting of six elements such that:
A[0] = 23171
A[1] = 21011
A[2] = 21123
A[3] = 21366
A[4] = 21013
A[5] = 21367

If a share was bought on day 0 and sold on day 2, a loss of 2048 would occur because A[2] - A[0] = 21123 - 23171 = -2048. If a share was bought on day 4 and sold on day 5, a profit of 354 would occur because A[5] - A[4] = 21367 - 21013 = 354. Maximum possible profit was 356. It would occur if a share was bought on day 1 and sold on day 5.

Write a function,

int solution(vector<int> &A);

that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, returns the maximum possible profit from one transaction during this period. The function should return 0 if it was impossible to gain any profit.

For example, given array A consisting of six elements such that:
A[0] = 23171
A[1] = 21011
A[2] = 21123
A[3] = 21366
A[4] = 21013
A[5] = 21367

the function should return 356, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..400,000];
each element of array A is an integer within the range [0..200,000].

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

	if (A.size() == 0 || A.size() == 1)
	{
		return 0;
	}

	int minBuyingPrice = std::numeric_limits<int>::max();
	int maxSellingPrice = 0;
	int maxProfit = 0;
	int profit = 0;
	vector<int> profits;

	for (auto it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		if (*it_A < minBuyingPrice)
		{
			minBuyingPrice = *it_A;
			maxSellingPrice = *it_A;
		}

		if (*it_A > maxSellingPrice)
		{
			maxSellingPrice = *it_A;
		}
		profit = maxSellingPrice - minBuyingPrice;
		maxProfit = std::max(profit, maxProfit);
	}

	return maxProfit;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 23171, 21011, 21123, 21366, 21013, 21367 };
	/*vector<int> B = { 5,-7,3,5,-2,4,-1 };
	vector<int> C = { 3,-3,-4,-5,-6,-3,-5,-3 };
	vector<int> D = { 3,-3,-4,-5,-6,-3,-5,5,-3 };
	vector<int> E = { 20,-1,3,-40,5,4,-40,4,-40,5,3,-2,3 };
	vector<int> F = { 3,-3,3,-3,3,-3,3,-3,3 };
*/
	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 356);
	/*assert(solution(B) == 12);
	assert(solution(C) == 0);
	assert(solution(D) == 5);
	assert(solution(E) == 13);
	assert(solution(F) == 6);
	*/
	cout << "All tests passed" << endl;
	system("PAUSE");
}

