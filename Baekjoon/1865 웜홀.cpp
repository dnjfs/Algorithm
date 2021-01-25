//백준 1865 웜홀
//solved.ac CLASS 4

#include "iostream"
#include "vector"

using namespace std;

#define INF 1e8
bool BellmanFord(vector<vector<pair<int, int>>> g, vector<int> &d, int S, int N) //벨만-포드
{
	d[S] = 0; //시작 지점
	for(int r = 0; r < N; r++) //N-1번 반복하며 최단거리 계산, N번째 반복에서 음수 사이클 확인
		for(int i = 1; i < N+1; i++) //정점의 수만큼 반복
			for(auto t: g[i]) //i번 정점과 인접한 정점들의 경로 계산
			{
				int u = t.first, w = t.second; //다음 정점, 간선의 가중치
				if(d[i] != INF && d[u] > d[i] + w) //현재 정점이 방문된 상태며 인접한 정점을 방문하는데 시간이 더 줄어드는 경우
				{
					d[u] = d[i] + w; //경로의 길이 갱신
					if(r == N-1) //N번째 반복에서도 경로가 갱신되면
						return true; //음수 사이클의 존재 확인
				}
			}

	return false; //음수 사이클이 없음
}

int main()
{
	int TC; //테스트 케이스 개수
	cin >>TC;
	while(TC--)
	{
		int N, M, W; //	지점의 수, 도로의 개수, 웜홀의 개수
		cin >>N >>M >>W;

		vector<vector<pair<int, int>>> g(N+1); //그래프
		vector<int> d(N+1, INF); //경로의 길이, 무한으로 초기화
		int S, E, T;
		for(int i = 0; i < M; i++) //도로
		{
			cin >>S >>E >>T;
			g[S].push_back(make_pair(E, T));
			g[E].push_back(make_pair(S, T));
		}
		for(int i = 0; i < W; i++) //웜홀
		{
			cin >>S >>E >>T;
			g[S].push_back(make_pair(E, -T)); //시간이 뒤로 감
		}

		bool cycle = false; //음수 사이클 존재 여부
		for(int i = 1; i <= N; i++) //그래프의 연결 성분이 여러 개일 수 있음
			if(d[i] == INF) //아직 방문하지 않은 상태
			{
				if(cycle = BellmanFord(g, d, i, N)) //음수 사이클을 찾으면
					break; //반복문 종료
			}

		if(cycle)
			cout <<"YES";
		else
			cout <<"NO";
		cout <<endl;
	}
}




/*
N개의 지점이 있고 M개의 도로(무방향)와 시간이 뒤로 가는 W개의 웜홀(방향)이 주어졌을 때,
어느 한 지점에서 출발하여 다시 출발점에 돌아왔을 때 시간이 되돌아가 있을 수 있는지를 검사하는 문제입니다.
이를 간단하게 말하면 그래프에서 음수 사이클이 있는지 검사하는 것과 같습니다.
벨만-포드 알고리즘을 이용하여 음수 사이클 존재 여부를 찾아냈습니다.
13번째 줄에서 N번 반복하는 이유는 정점의 개수가 N일 때 (N-1)번의 반복으로 이미 시작점으로부터 모든 정점의 최단 경로는 모두 찾은 상태입니다.
만약 음수 사이클이 존재한다면 음수 사이클을 이루고 있는 정점들은 음의 무한으로 값이 갱신될 테니 N번째 반복에서도 경로의 길이가 갱신될 것입니다.
또한 간선의 개수가 많고 가중치의 범위도 크다면 이를 고려하여 충분히 큰 값을 담을 수 있는 자료형을 사용해야 합니다.
참고: http://algo-revolution.blogspot.com/2016/05/bellman-ford-algorithm.html
*/