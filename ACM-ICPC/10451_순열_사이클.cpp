//ACM-ICPC 2014 본선 F번 순열 사이클
//백준 10451

#include "iostream"

using namespace std;

int main()
{
	int T;
	cin >>T;
	while(T--)
	{
		int N, n[1001], now, next, ans = 0;
		/*
		N: 순열의 크기
		n[]: 방향 그래프
		now: 현재 정점
		next: 다음 정점
		ans: 정답
		*/

		cin >>N;
		for(int i = 1; i <= N; i++)
			cin >>n[i];

		for(int i = 1; i <= N; i++)
			if(n[now = i]) //현재 정점을 방문하지 않은 경우
			{
				while(n[now]) //사이클을 돎
				{
					next = n[now]; //다음 정점 저장
					n[now] = 0; //현재 정점 방문
					now = next; //다음 정점으로
				}
				ans++; //순열 사이클 개수 증가
			}
		cout <<ans <<endl;
	}
}
