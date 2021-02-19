//백준 2263 트리의 순회
//solved.ac CLASS 4

#include "iostream"

using namespace std;

int in[100000], post[100000], idx[100001]; //in[]: 인오더, post[]: 포스트오더, idx[i]: 정점 i를 인오더로 방문한 순서
void pre(int inL, int inR, int postL, int postR) //프리오더
{
	if(inL > inR || postL > postR) //범위 벗어남
		return;

	int r = post[postR]; //포스트오더에서 가장 나중에 방문하는 정점은 루트
	cout <<r <<" "; //프리오더이므로 루트부터 출력

	pre(inL, idx[r]-1, postL, postL+(idx[r]-inL)-1); //인오더와 포스트오더의 왼쪽 자식의 범위를 인자로 넘겨줌
	pre(idx[r]+1, inR, postL+(idx[r]-inL), postR-1); //오른쪽 자식
}

int main()
{
	int n; //정점의 개수
	cin >>n;

	for(int i = 0; i < n; i++)
		cin >>in[i];
	for(int i = 0; i < n; i++)
		cin >>post[i];
	for(int i = 0; i < n; i++)
		idx[in[i]] = i;

	pre(0, n-1, 0, n-1);
}




/*
이진 트리를 인오더와 포스트오더로 방문한 순서가 주어졌을 때, 프리오더로 방문한 순서를 출력하는 문제입니다.
문제를 해결하기 위해 포스트오더는 루트를 가장 나중에 방문한다는 걸 이용해야 하는 건 알고 있었지만 재귀를 이용하여 표현하기가 매우 어려웠습니다.
재귀로 불러온 트리의 루트가 된 자식 노드가 인오더에서 언제 방문했는지 알기 위하여 idx[] 배열을 새로 만들어 저장하였습니다.

참고: https://suhwanc.tistory.com/26
*/