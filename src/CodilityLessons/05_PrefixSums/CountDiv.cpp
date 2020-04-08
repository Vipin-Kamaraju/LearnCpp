
/*

Write a function:

int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

{ i : A = i = B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:

A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A = B.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>


int solution(int A, int B, int K)
{
	/*
	/////////////////////// Solution ///////////////////////////
	To summarize : can be cut short into 2 cases
	case Sol_1 : A is not divisible, B is not divisible => Ans : int((B-A)/K)
	case Sol_2 : Others => Ans : int((B-A)/K) + 1
	///////////////////////////////////////////////////////////
	*/

	bool IsADivisibleByK = (A%K);
	bool IsBDivisibleByK = (B%K);


	int result;
	result = ((B - A) / K);

	if ((IsADivisibleByK == true) && (IsBDivisibleByK == true))
	{
	}
	else
	{
		result = result + 1;
	}

	return result;
}


void main()
{
	int A = 11;
	int B = 345;
	int K = 17;

	int result = solution(A, B, K);
	std::cout << "result = " << result << "\n";
	system("PAUSE");
}

