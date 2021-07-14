//백준 1012 유기농 배추
//solved.ac CLASS 3

#include "iostream"

using namespace std;

int g[50][50], M, N, K; //배추밭, 가로길이, 세로길이, 배추 개수
void DFS(int x, int y) //깊이 우선 탐색
{
	g[x][y] = 0; //배추흰지렁이에게서 보호 받음

	if(x > 0 && g[x-1][y]) //배추밭의 범위를 벗어나지 않으면서 인접한 배추가 있다면
		DFS(x-1, y); //보호
	if(x < M-1 && g[x+1][y])
		DFS(x+1, y);
	if(y > 0 && g[x][y-1])
		DFS(x, y-1);
	if(y < N-1 && g[x][y+1])
		DFS(x, y+1);
}

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while(T--)
	{
		//DFS로 방문하면 원소의 값이 0이 되므로 배열을 초기화 할 필요가 없음
		cin >>M >>N >>K;
		for(int i = 0; i < K; i++)
		{
			int X, Y; //배추가 심어져 있는 위치
			cin >>X >>Y;
			g[X][Y] = 1;
		}

		int cnt = 0; //필요한 최소의 배추흰지렁이 마리 수
		for(int y = 0; y < N; y++)
			for(int x = 0; x < M; x++)
				if(g[x][y]) //아직 보호받지 못한 배추
				{
					DFS(x, y);
					cnt++;
				}

		cout <<cnt <<endl;
	}
}




/*
배추밭을 해충으로부터 보호하기 위해 인접한 배추를 보호하는 배추흰지렁이를 최소로 놓았을 때 마리 수를 구하는 문제입니다.
DFS를 이용하여 상하좌우 네 방향으로 배추를 방문하여 인접한 배추를 모두 보호하는 방법으로 해결하였습니다.
*/