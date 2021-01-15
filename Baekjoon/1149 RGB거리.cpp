//백준 1149 RGB거리

#include "iostream"

using namespace std;

int main()
{
	int N, home[1001][3] = {0}; //집의 수, home[i]: i번 집을 빨강, 초록, 파랑으로 칠했을 때 최소비용
	cin >>N;

	for(int i = 1; i <= N; i++)
	{
		cin >>home[i][0] >>home[i][1] >>home[i][2];

		home[i][0] += min(home[i-1][1], home[i-1][2]); //빨강으로 칠함
		home[i][1] += min(home[i-1][0], home[i-1][2]); //초록으로 칠함
		home[i][2] += min(home[i-1][0], home[i-1][1]); //파랑으로 칠함
	}

	cout <<min(home[N][0], min(home[N][1], home[N][2]));
}




/*
N개의 집에 각각 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때 인접하는 집의 색깔이 서로 다르게 칠하는 비용의 최솟값을 구하는 문제입니다.
예전에 풀었던 백준 9465 스티커 문제와 비슷하게 느껴져 바로 DP로 구현하여 해결하였습니다.
마지막 집까지 칠했을 때 어떤 색으로 칠해야 비용이 최소로 들지 알 수 없으므로 1번 집부터 끝까지 세 가지 색 모두 칠해보며 비용을 비교해가면 됩니다.
i번 집을 빨강으로 칠할 때는 1번부터 (i-1)번까지의 집을 모두 칠한 상태에서 인접한 집은 다른 색으로 칠할 수 있으므로
(i-1)번 집이 초록으로 칠해졌을 때와 (i-1)번 집이 파랑으로 칠해졌을 때의 최소비용 중 더 작은 값을 찾아 비용을 더해줍니다.
모든 집이 칠해졌을 때 N번 집을 어떤 색으로 칠하는 게 가장 비용이 적은지 비교하면 됩니다.
*/