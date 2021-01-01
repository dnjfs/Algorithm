//백준 11047 이동하기

#include "iostream"

using namespace std;

int map[1001][1001]; //미로
int main()
{
	int N, M; //미로의 크기
	cin >>N >>M;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			cin >>map[i][j];

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			int n1 = map[i-1][j], n2 = map[i][j-1], n3 = map[i-1][j-1]; //현재 (r, c)에 있을 때 (r-1, c), (r, c-1), (r-1, c-1)까지 이동했을 때의 최댓값
			int max = n1 > n2 ? n1 : n2;
			max = n3 > max ? n3 : max;
			
			map[i][j] += max; //세 방 중 최댓값을 찾아 현재 방에 더함
		}

	cout <<map[N][M]; //(N, M)의 값 출력
}




/*
NxM 크기의 미로에서 각 방에 사탕이 놓여져 있을 때
(1, 1)에서 (N, M)까지 이동하며 가져올 수 있는 사탕 개수의 최대값을 구하는 문제입니다.
(r, c)에 있으면 (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있으므로,
20번째 줄처럼 (r-1, c), (r, c-1), (r-1, c-1)에서만 (r, c)로 향할 수 있습니다.
DP를 이용하여 세 방에 이동할 때까지 가진 사탕의 개수 중 최댓값에 (r, c)에 있는 사탕의 개수를 더하면 간단하게 해결할 수 있습니다.
*/