//백준 11725 트리의 부모 찾기
//solved.ac CLASS 4

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

vector<int> T[100001], P(100001); //트리의 연결 상태, P[i]: i번 노드의 부모 번호
bool v[100001]; //방문 상태
int main()
{
	int n; //노드의 개수
	cin >>n;

	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >>a >>b;
		T[a].push_back(b); //누가 부모가 될지 몰라 양방향으로 연결
		T[b].push_back(a);
	}

	queue<int> q;
	q.push(1); //루트는 1번 노드
	while(!q.empty()) //BFS로 트리를 내려가며 부모를 판별
	{
		int w = q.front();
		q.pop();

		for(auto t : T[w])
			if(!v[t])
			{
				v[t] = true;
				q.push(t);
				P[t] = w;
			}
	}

	for(int i = 2; i <= n; i++) //2번 노드부터 부모 노드 번호 출력
		printf("%d\n", P[i]);
}




/*
루트 없는 트리가 주어지고, 트리의 루트를 1이라고 정했을 때 각 노드의 부모를 구하는 문제입니다.
처음엔 예제의 입력처럼 항상 부모 노드가 먼저 나타날 줄 알았지만, 부모 노드가 나중에 나오는 경우도 있다는 걸 알게 되고 그래프로 접근을 하였습니다.
모든 정점이 연결된 후 루트 노드인 1번 노드에서 BFS를 시작하여 현재 정점에서 자식 정점을 방문하면 P[] 배열의 자식 정점의 위치에 부모 노드의 번호를 넣는 방법으로 해결하였습니다.
*/