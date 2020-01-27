//ACM-ICPC 2017 본선 C번 Game Map
//백준 14953

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int dg[100000], maxLength = 1, depth[100000];
/*
dg[]: 정점의 차수
maxLength: 정답
depth[]: 정점까지의 깊이
*/
void bfs(vector<vector<int>> v, int s) //너비우선탐색
{
	for(int i = 0; i < v.size(); i++) //깊이 초기화
		depth[i] = 0;
	queue<int> q;
	q.push(s);
	depth[s] = 1;

	while(!q.empty())
	{
		int w = q.front();
		q.pop();
		for(int i = 0; i < v[w].size(); i++)
		{
			int temp = v[w][i];
			if(dg[w] < dg[temp]) //차수가 더 높은 경우 이동
			{
				q.push(temp);
				depth[temp] = depth[w] + 1;
				if(depth[temp] > maxLength)
					maxLength = depth[temp];
			}
		}
	}
}

int main()
{
	int n, m;
	cin >>n >>m;
	vector<vector<int>> v(n);

	for(int k = 0; k < m; k++)
	{
		int i, j;
		cin >>i >>j;
		v[i].push_back(j);
		v[j].push_back(i);
		dg[i]++;
		dg[j]++;
	}

	for (int i = 0; i < n; i++) //모든 정점에 대하여 bfs를 실행해 가장 긴 경로 찾기
		bfs(v, i);

	cout <<maxLength;
}
