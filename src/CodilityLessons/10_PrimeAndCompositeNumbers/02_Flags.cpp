/*

A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbours. 
More precisely, it is an index P such that 0 < P < N - 1 and A[P - 1] < A[P] > A[P + 1].

For example, the following array A:
A[0] = 1
A[1] = 5
A[2] = 3
A[3] = 4
A[4] = 3
A[5] = 4
A[6] = 1
A[7] = 2
A[8] = 3
A[9] = 4
A[10] = 6
A[11] = 2

has exactly four peaks: elements 1, 3, 5 and 10.

You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. 
You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.

Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. 
The distance between indices P and Q is the absolute value |P - Q|.

For example, given the mountain range represented by array A, above, with N = 12, if you take:

two flags, you can set them on peaks 1 and 5;
three flags, you can set them on peaks 1, 5 and 10;
four flags, you can set only three flags, on peaks 1, 5 and 10.

You can therefore set a maximum of three flags in this case.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

For example, the following array A:
A[0] = 1
A[1] = 5
A[2] = 3
A[3] = 4
A[4] = 3
A[5] = 4
A[6] = 1
A[7] = 2
A[8] = 3
A[9] = 4
A[10] = 6
A[11] = 2

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..400,000];
each element of array A is an integer within the range [0..1,000,000,000].

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

int solution(vector<int> &A)
{
	/*
	** Logic : step1 : find all the peaks that are possible. the first and the last element can be eleminated
	** since they do not have the possibility of a peak
	** step 2: The max Flags that you can set is depending on two factors
	** 1: Number of peaks
	** 2: Size of the array (N flags => size must be min of N*N). Counting also the first element leads to N+1 possible flags in few cases
	**
	** step 3: Find when the setFlags are equal to the maxFlags
	** contradiction is sometimes they cannot be equal and setFlags become greater than maxFlags in this case
	** setFlags can never be greater than the maxFlags
	*/
	int A_size = A.size();
	if (A.size() == 0 || A.size() == 1)
	{
		return 0;
	}
	vector<int> peaks;

	for (unsigned int i = 1; i < A.size() - 1; ++i)
	{
		if ((A[i] > A[i - 1]) && (A[i] > A[i + 1]))
		{
			peaks.push_back(i);
		}
	}

	int numPeaks = peaks.size();
	int possiblePeaks = sqrt((A_size - 2)) + 1;
	unsigned int maxFlags = min(numPeaks, possiblePeaks);

	vector<int> setFlags;

	while (maxFlags != setFlags.size())
	{
		bool firstIteration = true;
		for (unsigned int m = 0; m < peaks.size(); ++m)
		{
			if (firstIteration)
			{
				setFlags.push_back(peaks[m]);
				firstIteration = false;
			}
			else
			{
				if ((peaks[m] - setFlags.back()) >= maxFlags)
				{
					setFlags.push_back(peaks[m]);
				}
			}
		}

		if (maxFlags > setFlags.size())
		{
			cout << "maxFlags after loop : " << maxFlags << endl;
			cout << "setFlags.size() after loop : " << setFlags.size() << endl;
			maxFlags--;
			setFlags.erase(setFlags.begin(), setFlags.end());
		}
		else if (maxFlags < setFlags.size())
		{
			return maxFlags;
		}
	}


	return setFlags.size();
}

void main()
{
	// refer : https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=vs-2015
	printf("%ld\n", __cplusplus); // this is by default C++98 but C++ Language std used is actually C++14
	printf("%ld\n", _MSC_VER);    // MSVC version VC++ 14.0
	printf("%ld\n", _MSVC_LANG);  // shows unidentified due to Intellisense but Macro is defined.

	vector<int> A = { 1,5,3,4,3,4,1,2,3,4,6,2 };

	// first lets return the leader and check if we are getting the correct answer
	assert(solution(A) == 3);

	
	cout << "All tests passed" << endl;
	system("PAUSE");
}

