//ACM-ICPC 2012 예선 A번 다리
//백준 9006

#include "iostream"
#include "algorithm"

using namespace std;

struct House
{
	int y; //집의 위치
	int r; //0: 왼쪽 집, 1: 오른쪽 집
};

bool operator<(House a, House b) //sort를 위한 연산자 오버로딩
{
	return a.y < b.y;
}

House H[2000000]; //집
int main()
{
	int T; //테스트 케이스
	cin >>T;
	while (T--)
	{
		int n, m, i, p = 0, q = 0;
		/*
		n: 왼쪽 강의 집
		m: 오른쪽 강의 집
		i: 배열 탐색을 위한 인덱스
		p: 다리 아래에 있는 왼쪽 집의 수
		q: 다리 아래에 있는 오른쪽 집의 수
		*/

		cin >>n >>m;
		for (i = 0; i < n; i++) //왼쪽 집의 위치 입력
		{
			cin >>H[i].y;
			H[i].r = 0;
		}
		for (; i < n+m; i++) //오른쪽 집의 위치 입력
		{
			cin >>H[i].y;
			H[i].r = 1;
		}
		sort(H, H+n+m); //위치를 기준으로 정렬

		for (i = 0; i < n+m; i++)
		{
			if (!H[i].r)
				p++;
			else
				q++;

			//(n-p)(m-q)는 현재 상태에서 다리를 올릴 경우 줄어드는 거리의 수
			//pq는 늘어나는 거리의 수
			if ((long long)(n-p)*(m-q) <= (long long)p*q)
				break;
		}
		cout <<H[i].y <<".0" <<endl; //다리를 놓는 위치 h 출력, 소수점은 함정
	}
}
