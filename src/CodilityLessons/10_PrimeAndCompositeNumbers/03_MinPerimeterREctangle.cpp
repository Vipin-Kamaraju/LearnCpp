/*

An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are:

(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.

Write a function:

int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int solution(int N)
{
	/*
	** Logic : find the number of divisors and send them as pairs to a vector
	*/
	int maxInteger = sqrt(N);
	vector<std::pair<int, int>> divisorsPair;
	vector<int> vecPerimeter;
	int divisor = 0;
	int perimeter = 0;

	for (int m = 1; m <= maxInteger; ++m)
	{
		if (N%m == 0)
		{
			divisor = N / m;
			divisorsPair.push_back(std::pair<int, int>(m, divisor));
			perimeter = 2 * (m + divisor);
			vecPerimeter.push_back(perimeter);
		}
	}

	sort(vecPerimeter.begin(), vecPerimeter.end());
	int minPerimeter = vecPerimeter.front();

	return minPerimeter;
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	int A = 30;

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 22);

	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

