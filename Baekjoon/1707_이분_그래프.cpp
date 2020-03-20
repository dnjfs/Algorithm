//1707 이분 그래프

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int bin[20001]; //정점에 번호를 부여하여 그래프 분할
void bfs(vector<vector<int>> v, int s, bool *ans) //너비우선탐색
{
	queue<int> q;
	q.push(s);
	bin[s] = 1; //1번부터 부여

	while (!q.empty())
	{
		int w = q.front();
		q.pop();
		for (int i = 0; i < v[w].size(); i++)
		{
			int temp = v[w][i];
			if (bin[w] == bin[temp]) //현재 정점과 인접한 정점이 같은 번호인 경우
			{
				*ans = false; //이분 그래프가 아님
				return;
			}
			if (bin[temp] == 0) //아직 방문하지 않은 정점인 경우
			{
				q.push(temp);
				if (bin[w] == 1) //현재 정점이 1번이면
					bin[temp] = 2; //2번으로 부여
				else if (bin[w] == 2) //현재 정점이 2번이면
					bin[temp] = 1; //1번으로 부여
			}
		}
	}
}

int main()
{
	int K; //테스트 케이스 개수
	cin >>K;
	while (K--)
	{
		int V, E; //정점의 수, 간선의 수
		bool ans = true; //이분 그래프 여부
		cin >>V >>E;

		vector<vector<int>> v(V+1); //그래프
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >>a >>b;
			v[a].push_back(b); //무방향 그래프
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) //테스트 케이스가 여러개라 전역변수 초기화
			bin[i] = 0;

		for (int i = 1; i <= V; i++)
			if (!bin[i] && ans) //이분 그래프가 아닌 경우 계속 탐색하면 시간 초과
				bfs(v, i, &ans); //방문하지 않은 정점부터 너비우선탐색

		if (ans)
			cout <<"YES" <<endl;
		else
			cout <<"NO" <<endl;
	}
}
