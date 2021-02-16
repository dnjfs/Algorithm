//백준 9251 LCS
//solved.ac CLASS 4

#include "iostream"

using namespace std;

int l[1001][1001]; //l[i][j]: 문자열 s1의 (i-1)까지의 부분 문자열과 문자열 s2의 (j-1)까지의 부분 문자열의 LCS 길이
int main()
{
	string s1, s2;
	cin >>s1 >>s2;

	for(int i = 1; i <= s1.size(); i++)
		for(int j = 1; j <= s2.size(); j++)
		{
			if(s1[i-1] == s2[j-1]) //s1의 (i-1)번째 문자와 s2의 (j-1)번째 문자가 같은 경우
				l[i][j] = l[i-1][j-1]+1; //각 문자를 뺀 부분 문자열의 LCS의 길이에서 한자리를 늘림
			else //서로 다른 경우
				l[i][j] = max(l[i-1][j], l[i][j-1]); //s1[i-1]을 제외하거나 s2[j-1]을 제외한 부분 문자열의 LCS의 길이 중 더 큰 값을 가져옴
		}

	cout <<l[s1.size()][s2.size()]; //s1과 s2의 LCS의 길이
}




/*
두 문자열의 LCS의 길이를 구하는 문제입니다.
알고리즘 강의시간에 배웠던 문제라 간단하게 DP를 이용하여 구현하였습니다.
s1(i)와 s2(j)가 같다면 s1(0)~s1(i-1)의 부분 문자열과 s2(0)~s2(j-1)의 부분 문자열의 LCS의 길이에 1을 더해주고,
다르다면 각 문자를 제외했을 때 더 큰 LCS의 길이를 가져옵니다.
*/