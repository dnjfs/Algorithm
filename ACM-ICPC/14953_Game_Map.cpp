//ACM-ICPC 2017 본선 C번 Game Map
//백준 14953

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int nb[100000], order[100000], dp[100000];
/*
nb[]: 정점(도시)의 차수(이웃수)
opder[]: 정점의 차수가 작은 순으로 정점의 번호가 정렬된 배열
dp[]: 해당 정점까지 정복하는 최대 길이
*/
int main()
{
	int n, m;
	/*
	n: 정점의 수
	m: 간선의 수
	ans: 가장 긴 경로의 길이
	*/
	cin >>n >>m;
	vector<vector<int>> v(n); //그래프

	for(int k = 0; k < m; k++) //그래프 연결
	{
		int i, j;
		cin >>i >>j;
		v[i].push_back(j);
		v[j].push_back(i);
		dg[i]++;
		dg[j]++;
	}

	for(int i = 0; i < n; i++)
	{
		order[i] = i;
		dp[i] = 1;
	}
	sort(order, order+n, [](int a, int b)
	{
		return nb[a] < nb[b];
	}); //nb[]을 기준으로 order[]을 정렬시키도록 람다 함수(Lambda Expression) 정의

	for(int i = 0; i < n; i++)
	{
		int t = order[i];
		for(int p : v[t]) //v[t]의 첫번째 원소부터 마지막 원소까지 탐색하는 범위 기반 for문(range based for loop)
			if(nb[t] < nb[p]) //t보다 p의 이웃이 더 많은 경우
				dp[p] = max(dp[p], dp[t]+1); //t에서 p로 가야하므로 +1
	}

	for(int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout <<ans;
}
