//백준 1167 트리의 지름
//solved.ac CLASS 4

#include "iostream"
#include "vector"

using namespace std;

int ans; //트리의 지름
vector<vector<pair<int, int>>> tree(100001); //트리
bool visited[100001]; //정점 방문 여부
int dfs(int v) //현재 정점의 번호를 인자로 받는 깊이 우선 탐색
{
	int max1 = 0, max2 = 0; //현재 정점을 기준으로 가장 멀리 있는 두 경로의 길이를 저장 (max1 >= max2)
	visited[v] = true; //v번 정점 방문

	for(pair<int, int> p : tree[v]) //현재 정점과 연결된 정점들 방문
	{
		int c = p.first; //다음으로 방문할 정점의 번호
		if(!visited[c]) //아직 방문하지 않은 경우
		{
			int t = dfs(c) + p.second; //해당 정점과 연결된 가장 긴 경로의 길이를 반환받아 해당 정점까지의 거리를 더함 (반환값은 34번째 줄 참고)
			if(t > max1) //해당 정점을 방문했을 때의 경로가 현재 노드에 연결된 경로의 길이 중 가장 긴 경우
			{
				max2 = max1;
				max1 = t;
			}
			else if(t > max2) //두 번째로 긴 경우
				max2 = t;
		}
	}
	ans = max(ans, max1+max2); //현재 정점과 연결된 가장 긴 경로 두 개를 트리의 지름으로 정함

	return max1; //가장 긴 경로의 길이 반환 (DFS로 함수 호출이 종료되면 거꾸로 타고 올라가며 길이가 길어지는 방식)
}

int main()
{
	int n; //정점의 개수
	cin >>n;

	for(int i = 0; i < n; i++)
	{
		int n1, n2, w; //정점 번호, 간선으로 연결된 정점 번호, 간선의 길이
		cin >>n1;
		while(true)
		{
			cin >>n2;
			if(n2 == -1) //줄의 마지막
				break;

			cin >>w;
			tree[n1].push_back(make_pair(n2, w)); //n1->n2 연결
		}
	}
	dfs(1); //1번 정점부터 DFS 시작
	cout <<ans;
}




/*
트리의 지름(백준 1967) 문제와 동일한 문제지만 루트 노드가 따로 없다는 점과 입력이 달라져 그래프가 양방향으로 연결됩니다.
이전 문제는 루트 노드가 있어 리프 노드부터 차근차근 올라가며 트리의 지름을 구했지만
이번엔 리프 노드가 없어 1번 정점부터 DFS를 이용하여 트리의 지름을 구하였습니다.
DFS로 그래프를 탐색하며 리프 노드까지 도달한 후 함수를 종료하며
가장 긴 경로의 리프 노드에서 현재 정점까지의 경로의 길이가 증가하며 되돌아갑니다.
그렇게 반환받은 경로의 길이 중 가장 긴 두 경로의 길이를 더하면 트리의 지름이 됩니다.
*/