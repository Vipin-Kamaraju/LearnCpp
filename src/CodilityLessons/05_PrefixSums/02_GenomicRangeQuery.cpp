
/*


A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. 
Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. 
You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. 
There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. 
The K-th query (0 = K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
P[0] = 2    Q[0] = 4
P[1] = 5    Q[1] = 5
P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, 
returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
P[0] = 2    Q[0] = 4
P[1] = 5    Q[1] = 5
P[2] = 0    Q[2] = 6

the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N - 1];
P[K] = Q[K], where 0 = K < M;
string S consists only of upper-case English letters A, C, G, T.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	vector<int> result;

	// Change in idea: Iterate through S and save 4vectors information of A,C,G & T
	// Since the problem cannot be solved in time complexity we need to increase the space complexity
	// Space complexity increased since 4 new vectors are now added

	vector<int> A;
	vector<int> C;
	vector<int> G;
	vector<int> T;

	int ALastSeenAt = -1;
	int CLastSeenAt = -1;
	int GLastSeenAt = -1;
	int TLastSeenAt = -1;
	
	for (size_t i = 0; i != S.size(); ++i)
	{
		switch (S.at(i))
		{
		case 'A':
			ALastSeenAt = i;
			break;
		case 'C':
			CLastSeenAt = i;
			break;
		case 'G':
			GLastSeenAt = i;
				break;
		case 'T':
			TLastSeenAt = i;
			break;
		}
		A.push_back(ALastSeenAt);
		C.push_back(CLastSeenAt);
		G.push_back(GLastSeenAt);
		T.push_back(TLastSeenAt);

	}

	for (int m = 0; m < P.size();++m)
	{
		int P_val = P.at(m);
		int Q_val = Q.at(m);

		if (A.at(Q_val) >= P_val)
		{
			result.push_back(1);
		}
		else if (C.at(Q_val) >= P_val)
		{
			result.push_back(2);
		}
		else if (G.at(Q_val) >= P_val)
		{
			result.push_back(3);
		}
		else if (T.at(Q_val) >= P_val)
		{
			result.push_back(4);
		}
			
	}

	return result;
}


void main()
{
	string S = "CAGCCTA";
	vector<string> DNA = { "A", "C", "G","T" };
	vector<int> P = { 2,5,0,2 };
	vector<int> Q = { 4,5,6,4 };
	vector<int> result;

	result = solution(S, P, Q);
	
	system("PAUSE");
}

