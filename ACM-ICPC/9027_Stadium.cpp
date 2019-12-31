//ACM-ICPC 2010 예선 B번 Stadium
//백준 9027

#include "iostream"

using namespace std;

int village[100000]; //마을의 위치
int fan[100000]; //팬의 수

int main()
{
	int T; //테스트 케이스 수
	cin >>T;

	while(T--)
	{
		int N, sum = 0, fanNum = 0;
		/*
		N: 마을의 수
		sum: 왼쪽부터 i번째 마을까지 팬의 수의 합
		fanNum: 모든 마을의 팬의 수의 합
		*/
		cin >>N;
		for (int i = 0; i < N; i++)
			cin >>village[i];
		for (int i = 0; i < N; i++)
		{
			cin >>fan[i];
			fanNum += fan[i];
		}

		int i = 0;
		while (sum < (fanNum/2+fanNum%2)) //중앙값(median) 찾기
			sum += fan[i++];

		cout <<village[--i] <<endl; //조건을 만족하는 위치에서 i++로 끝을 냈으므로 원래 값으로 --i
	}
}
