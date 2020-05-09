//백준 1916

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

#define INF 2100000000
int Dijkstra(vector<vector<pair<int, int>>> g, int A, int B) //다익스트라
{
	vector<int> w(1001, INF); //출발점부터 i번째 도시까지 경로의 비용
	vector<bool> d(1001, false); //출발점부터 i번째 도시까지 경로의 최소비용를 찾음
	queue<int> q;
	q.push(A);
	w[A] = 0; //출발 위치는 거리가 0

	while(true)
	{
		int v = q.front();
		q.pop();
		for(auto t: g[v]) //정점 v와 인접한 정점들의 경로 업데이트
		{
			int u = t.first;
			w[u] = min(w[u], w[v] + t.second); //현재 경로의 비용과 v를 거쳐 가는 경로의 비용 중 작은 값을 저장
		}

		int min = INF, index = 0;
		for(int i = 1; i < g.size(); i++) //아직 최소비용을 찾지 못한 경로 중 최소값을 찾음
			if(w[i] < min && !d[i])
			{
				min = w[i];
				index = i;
			}
		if(index == 0) //모든 경로의 최소비용을 찾음
			break;
		d[index] = true;
		q.push(index);
	}

	return w[B]; //A부터 B까지 경로의 최소비용 반환
}

int main()
{
	int N, M; //도시의 개수, 버스의 개수
	cin >>N >>M;

	vector<vector<pair<int, int>>> g(N+1); //정점이 N개인 그래프, 도시의 번호는 1부터 시작
	for(int i = 0; i < M; i++) //버스의 개수만큼 에지 연결
	{
		int u, v, w;
		cin >>u >>v >>w;
		g[u].push_back(make_pair(v, w)); //방향 그래프
	}
	int A, B; //출발점, 도착점
	cin >>A >>B;

	cout <<Dijkstra(g, A, B);
}


/*
출발점에서 도착점까지 버스를 타고 가는 최소비용을 구하는 문제입니다.
가중치가 있는 방향그래프이며 가중치가 있는 그래프에서 최단거리를 구하는 방법은
다익스트라 알고리즘을 사용하면 구할 수 있습니다.
우선순위 힙을 사용하지 않아 시간복잡도는 O(N^2)입니다.
도시의 개수가 작아서 시간초과가 되지 않았지만 정점이 100000이 되면
우선순위 힙을 사용하여 시간복잡도를 O(E + VlogV)만큼 줄여야 합니다.
*/