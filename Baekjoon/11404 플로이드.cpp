//백준 11404 플로이드
//solved.ac CLASS 4

#include "iostream"

using namespace std;

int main()
{
	int n, m, v[101][101]; //도시의 개수, 버스의 개수, v[i][j]: 도시 i에서 j로 가는 최소 비용
	cin >>n >>m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			v[i][j] = i == j ? 0 : 1e9; //INF값으로 초기화, 자기 자신으로는 비용이 0

	for(int i = 0; i < m; i++)
	{
		int a, b, w; //출발 도시, 도착 도시, 비용
		cin >>a >>b >>w;
		v[a][b] = min(v[a][b], w); //노선이 하나가 아닐 수 있음
	}

	for(int k = 1; k <= n; k++) //플로이드-와샬 알고리즘
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				v[i][j] = min(v[i][j], v[i][k]+v[k][j]); //도시 k를 거쳐서 가는 것이 더 빠르면 갱신

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout <<(v[i][j] == 1e9 ? 0 : v[i][j]) <<" "; //INF는 0으로 출력
		cout <<endl;
	}
}




/*
n개의 도시가 있고 다른 도시로 이동하는 m개의 버스가 있을 때 모든 도시의 쌍에 대하여 다른 도시로 가는데 필요한 비용의 최솟값을 구하는 문제입니다.
주의해야 할 사항은 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다는 점입니다.
플로이드-와샬 알고리즘을 이용하여 현재 비용보다 다른 도시를 거쳐서 가는 비용이 더 적다면 더 작은 비용으로 갱신해줍니다.

참고: https://blog.naver.com/ndb796/221234427842
*/