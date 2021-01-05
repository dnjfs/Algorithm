//백준 2206 벽 부수고 이동하기

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct pos //위치 구조체
{
	int R, C;
};

int cnt[1000][1000]; //cnt[r][c]: (1, 1)에서 (r, c)까지의 최단 경로
int bfs(vector<string> v, int N, int M)
{
	queue<pos> q, qc; //벽을 안부쉈을 때/부쉈을 때 이동할 위치
	pos temp {0, 0}; //(1, 1)부터 탐색 시작
	q.push(temp);
	cnt[0][0] = 1; //시작하는 칸 포함

	int rc[] = {-1,0, 1,0, 0,-1, 0,1}; //상,하,좌,우
	while (!q.empty())
	{
		int r = q.front().R, c = q.front().C;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			if((i==0 && r==0) || (i==1 && r==N-1) || (i==2 && c==0) || (i==3 && c==M-1)) //이동 제한
				continue;

			int tr = rc[i*2]+r, tc = rc[i*2+1]+c;
			if(!cnt[tr][tc]) //아직 방문하지 않은 경우
			{
				temp.R = tr;
				temp.C = tc;
				cnt[tr][tc] = cnt[r][c]+1; //경로 저장
				if (v[tr][tc] == '0')
					q.push(temp);
				else //벽을 부숨
					qc.push(temp);
			}
		}
	}

	while (!qc.empty())
	{
		int r = qc.front().R, c = qc.front().C;
		qc.pop();

		for (int i = 0; i < 4; i++)
		{
			if ((i==0 && r==0) || (i==1 && r==N-1) || (i==2 && c==0) || (i==3 && c==M-1))
				continue;

			int tr = rc[i*2]+r, tc = rc[i*2+1]+c;
			if (v[tr][tc] == '0' && (cnt[tr][tc]>cnt[r][c]+1 || !cnt[tr][tc])) //벽을 한 번 부쉈으니 이동할 수 있는 칸이면서 더 짧은 경로거나 아직 방문하지 못한 칸인 경우
			{
				temp.R = tr;
				temp.C = tc;
				cnt[tr][tc] = cnt[r][c]+1; //경로 갱신
				qc.push(temp);
			}
		}
	}

	return cnt[N-1][M-1]; //(N, M)까지의 최단 경로 반환
}

int main()
{
	int N, M; //맵 크기 NxM
	cin >>N >>M;

	vector<string> v; //맵
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >>s;
		v.push_back(s);
	}

	int ans = bfs(v, N, M);
	if (!ans) //불가능
		ans = -1;
	cout <<ans;
}




/*
NxM의 행렬로 표현되는 맵이 주어졌을 때 (1, 1)에서 (N, M)까지의 최단 거리를 구하는 문제입니다.
일반적인 너비우선탐색 문제와 다른 점은 벽을 하나 부술 수 있다는 점입니다.

어떻게 벽을 부쉈는지 표현하기 위해 큐에 벽을 부순 여부를 저장하거나,
최단 경로를 저장하는 배열을 하나 더 만들거나 하는 등등 고민을 많이 하며 실험한 결과,
큐를 하나 더 만들고 BFS를 두 번 하는 방법이 통했습니다.

먼저 벽을 부수지 않은 상태에서 BFS를 하며 최단 경로를 구하는데
만약 벽을 만나면 그 벽을 부숴 다른 큐에 해당 위치를 넣어주는 식으로 벽을 부쉈는지 구분해줬습니다.
그 후 벽을 부순 상태를 가진 큐를 이용하여 BFS를 한 번 더 하며 최단 경로를 갱신하는 방법으로 해결하였습니다.
이땐 벽을 더 부술 순 없으므로 벽이 아닌 칸으로만 이동하며 첫 BFS 때보다 경로가 더 짧거나 벽에 막혀 도달하지 못했던 칸으로만 이동합니다.
*/