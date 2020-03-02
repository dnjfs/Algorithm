//ACM-ICPC 2015 예선 G번 모노톤길
//백준 11067

#include "iostream"
#include "algorithm"

using namespace std;

struct cafe //카페
{
	int x, y;
};

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while(T--)
	{
		int n, m; //카페의 수, 좌표를 출력할 카페의 수
		cafe c[100001]; //카페의 위치

		cin >>n;
		for(int i = 1; i <= n; i++)
			cin >>c[i].x >>c[i].y;
		c[0].x = -1; c[0].y = 0; //(0,0)에서 내려가는 경우를 위함

		sort(c, c+n+1, [](cafe a, cafe b){ //x를 우선 정렬하고 x가 같은 경우 y로 오름차순 정렬
			if(a.x != b.x)
				return a.x < b.x;
			else
				return a.y < b.y;
		});

		int s = 0; //내림차순 정렬을 시작할 위치
		for(int i = 1; i <= n; i++)
			if(c[i-1].x != c[i].x && c[i-1].y != c[i].y) //오른쪽으로 가는데 내려가야함
				s = i;
			else if(s && c[s-1].y == c[i].y) //내려가다가 오른쪽으로 감(x 좌표가 다른 경우와 같음)
			{
				int l = s, r = i;
				while(l < r) //s~i 범위 거꾸로(y로 내림차순 정렬)
				{
					cafe t = c[l];
					c[l++] = c[r];
					c[r--] = t;
				}
				s = 0;
			}

		int o;
		cin >>m;
		for (int i = 0; i < m; i++)
		{
			cin >>o;
			cout <<c[o].x <<" "<<c[o].y <<endl;
		}
	}
}
