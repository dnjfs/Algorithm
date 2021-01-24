//백준 1932 정수 삼각형
//solved.ac CLASS 4

#include "iostream"
#include "algorithm"

using namespace std;

int t[501][501]; //정수 삼각형
int main()
{
	int n, m = 0; //삼각형의 크기, 합이 최대가 되는 경로에 있는 수의 합
	cin >>n;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
		{
			cin >>t[i][j];
			t[i][j] += max(t[i-1][j-1], t[i-1][j]); //대각선 왼쪽, 대각선 오른쪽에서 현재 위치로 가는 경로 중 더 큰 값을 저장
		}

	for(int i = 1; i <= n; i++)
		m = max(m, t[n][i]); //모든 경로를 지난 삼각형 마지막 층에서 최댓값을 찾음
	
	cout <<m;
}




/*
정수 삼각형의 맨 위층에서 대각선 왼쪽, 대각선 오른쪽으로 이동하며 선택한 수의 합이 최대가 되는 경로의 합을 출력하는 문제입니다.
DP를 이용하여 현재 위치에서 대각선 왼쪽과 대각선 오른쪽까지의 경로 중 더 큰 값을 선택하여 해결하였습니다.
*/