//백준 1753 최단경로
//solved.ac CLASS 4

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

#define INF 1e9 //10^9
vector<pair<int, int>> g[20001]; //vector<vector<pair<int, int>>> g(20001)
vector<int> d(20001, INF); //d[i]: 시작점부터 i번 정점까지의 최단 경로
void Dijkstra(int s) //우선순위 큐로 구현한 다익스트라
{
	priority_queue<pair<int, int>> pq; //우선순위 큐 (최대힙으로 구현)
	pq.push({0, s}); //시작점은 거리가 0
	d[s] = 0;

	while(!pq.empty())
	{
		int v = pq.top().second, w = -pq.top().first; //현재 정점, 시작점부터 현재 정점까지의 거리 (절대값이 가장 작은 것이 루트, 0에 가까울 수록 짧은 경로)
		pq.pop();

		if(d[v] < w) //이미 더 짧은 경로를 발견한 상태
			continue;

		for(auto t: g[v]) //현재 정점과 인접한 정점들을 방문하며 경로의 길이를 비교
		{
			int u = w + t.second; //현재까지 거리에 해당 정점의 가중치를 더해줌
			if(u < d[t.first]) //더 짧은 경로 발견
			{
				d[t.first] = u;
				pq.push({-u, t.first}); //절대값이 작은 것이 루트로 가도록 음수로 저장
			}
		}
	}
}

int main()
{
	int V, E, K; //정점의 개수, 간선의 개수, 시작점
	cin >>V >>E >>K;

	for(int i = 0; i < E; i++)
	{
		int u, v, w; //u에서 v로 가는 가중치 w인 간선
		scanf("%d%d%d", &u, &v, &w); //cin은 시간 초과 발생! (E의 범위 주의)
		g[u].push_back({v, w}); //u->v 연결
	}
	Dijkstra(K); //K번 정점부터 시작

	for(int i = 1; i <= V; i++)
		if(d[i] == INF) //시작점에서 방문할 수 있는 경로가 존재하지 않음
			cout <<"INF" <<endl;
		else
			cout <<d[i] <<endl;
}




/*
최소비용 구하기(백준 1916) 문제와 비슷한 유형의 문제로 다익스트라를 이용하는 문제입니다.
이전의 문제의 정점의 개수와 간선의 개수를 곱해도 1억밖에 되지 않아 0.5초 안에 통과가 되었지만,
이번 문제는 60억이 되어 10초가 주어져도 해결되지 않을 것입니다.
벨만 포드의 알고리즘은 시간 초과가 발생하여 우선순위 큐를 이용한 다익스트라로 해결해야 합니다.

단순히 다익스트라 문제라고 생각하면서 풀었는데 오답을 많이 받으며 깨달음을 많이 얻어간 문제입니다.
1. 우선순위 큐를 이용한 다익스트라 알고리즘의 시간복잡도는 O(V*logE) (벨만 포드는 O(V*E))
2. 우선순위 큐의 정렬은 기본으로 first를 기준으로 정렬
3. pair<int, int>는 {v, w}과 같은 모양으로 묶을 수 있음
4. vector<vector<int>> v(10)은 vector<int> v[10]과 같음 (괄호는 생성자, 대괄호는 배열선언)
5. 입력이 10만 번 이상 들어오면 C++은 scanf() 함수 사용하는 것 잊지 않기
*/