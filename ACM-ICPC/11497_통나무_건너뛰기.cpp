//ACM-ICPC 2015 본선 E번 통나무 건너뛰기
//백준 11497

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while(T--)
	{
		int N, L[10000], circle[10000], level = 0;
		/*
		N: 통나무의 개수
		L[]: 통나무의 높이
		circle[]: 원형으로 세운 통나무
		level: 난이도
		*/

		cin >>N;
		for(int i = 0; i < N; i++)
			cin >>L[i];
		sort(L, L+N); //오름차순 정렬

		int idx = 0, left = 0, right = N-1; //L[] 탐색 인덱스, circle[]의 왼쪽, 오른쪽 인덱스
		while(left <= right)
		{
			circle[left++] = L[idx++];
			if(idx < N) //N이 홀수면 마지막에 넣으면 안됨
				circle[right--] = L[idx++];
		}

		for(int i = 1; i < N; i++) //level 계산
		{
			int t = abs(circle[i]-circle[i-1]);
			if(level < t)
				level = t;
		}
		cout <<level <<endl;
	}
}
