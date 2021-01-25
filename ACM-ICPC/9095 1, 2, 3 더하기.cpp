//ACM-ICPC 2001 본선 PC번
//백준 9095 1, 2, 3 더하기
//solved.ac CLASS 3

#include "iostream"

using namespace std;

int main()
{
	int T, n, dp[12] = {1, 1, 2};
	cin >>T;
	while(T--)
	{
		cin >>n;
		for(int i = 3; i <= n; i++)
			dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

		cout <<dp[n] <<endl;
	}
}




/*
정수 n을 입력받아 1, 2, 3의 합으로 나타내는 방법을 구하는 문제입니다.
1, 2, 3 더하기 3(백준 15988)을 이미 푼 상태라 쉽게 풀 수 있었습니다.
조금 다른 점이라면 배열을 초기화할 때 dp[3]에 값을 뺀 건데 3의 합을 구할 때
dp[i-3]이 0+3으로 3 자체를 나타내기에 코드 길이를 조금이나마 더 줄이고자 지웠습니다.
*/