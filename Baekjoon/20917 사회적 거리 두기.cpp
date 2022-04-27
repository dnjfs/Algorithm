//백준 20917 사회적 거리 두기

#include "iostream"
#include "algorithm"

using namespace std;

int p[200000]; //콘센트 위치
int main()
{
	int T;
	cin >>T;
	while(T--)
	{
		int n, s, ans; //콘센트 수, 팀 수, 가장 가까운 두 자리의 최대 거리
		cin >>n >>s;

		for(int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		sort(p, p+n);

		int l = 1, r = p[n-1]/(s-1);
		//l을 1로 한 이유는 콘센트 위치는 중복되지 않기 때문
		//p[n-1]/(s-1)의 의미는 p[0]는 아무리 작아도 1이며,
		//실제 콘센트 위치를 신경쓰지 않고 모든 팀이 가장 멀리 앉았을 경우 팀 사이의 거리
		while(l <= r)
		{
			int prev = -1E9, cnt = 0, dist = (l+r)/2;

			for(int i = 0; i < n; i++)
				if(prev+dist <= p[i]) //직전에 위치한 팀보다 dist 이상 거리를 둔 상태
				{
					cnt++;
					prev = p[i]; //prev 위치에 팀이 자리함
				}

			if(cnt >= s)
			{
				ans = dist;
				l = dist+1;
			}
			else
				r = dist-1;
		}

		cout <<ans <<endl;
	}
}

/*
n개의 콘센트를 s개의 팀이 자리할 때 가장 가까운 두 자리의 거리가 최대가 되도록 사용할 때의 거리를 구하는 문제입니다.
이진탐색을 이용하여 dist 값을 조절하며 모든 팀이 dist 이상 거리를 둘 수 있는지 확인하는 방법으로 해결하였습니다.

입력의 개수가 최대 20만개라 빠른 입력을 사용했어야 했는데 C++의 표준입력 함수인 cin을 그대로 사용하여 시간초과가 발생하였습니다.
배열의 크기가 고정된 상태에서 범위 기반 for문을 사용하여 틀렸는데 오랜만에 알고리즘을 풀어 감이 떨어졌는지 실수가 잦아 아쉬웠습니다.
*/