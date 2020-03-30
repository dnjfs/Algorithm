//백준 1967 트리의 지름

#include "iostream"
#include "vector"

using namespace std;

int main()
{
	int n, ans = 0; //노드의 수, 트리의 지름
	int length[10001] = {0}; //가중치(0으로 초기화)
	cin >>n;
	vector<vector<int>> v(n+1); //그래프

	for(int i = 2; i <= n; i++)
	{
		int n1, n2, w; //부모, 자식, 가중치
		cin >>n1 >>n2 >>w;

		v[n1].push_back(n2); //부모에서 자식으로만 향하는 방향 그래프
		length[n2] = w; //현재는 n1에서 n2까지 경로의 가중치
	}
	
	for(int i = n; i > 0; i--) //모든 노드에서 각각 중심이 되어 지름을 구함
	{
		int max1 = 0, max2 = 0;
		for(auto t : v[i]) //i에서 모든 자식의 가중치 중 최대값 2개를 구함
		{
			int temp = length[t];
			if(temp > max1)
			{
				max2 = max1;
				max1 = temp;
			}
			else if(temp > max2)
				max2 = temp;
		}

		length[i] += max1; //i에서 리프까지 경로의 최대 가중치
		int d = max1 + max2; //i를 중심으로 양쪽으로 당겼을 때, 트리의 지름
		if(d > ans)
			ans = d;
	}

	cout <<ans;
}
