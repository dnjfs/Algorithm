//백준 1931 회의실 배정
//solved.ac CLASS 3

#include "iostream"
#include "algorithm"

using namespace std;

struct T //회의 시간
{
	int s, e; //시작, 끝
};

T l[100000]; //회의
int main()
{
	int N, m = 0, ans = 1; //회의의 수, 마지막으로 한 회의의 인덱스, 최대 회의 수
	cin >>N;

	for(int i = 0; i < N; i++)
		cin >>l[i].s >>l[i].e;

	sort(l, l+N, [](T a, T b){ //회의가 끝나는 순으로 정렬, 끝나는 시간이 같다면 시작하는 시간으로 정렬
		return a.e == b.e ? a.s < b.s : a.e < b.e;
		});

	for(int i = 1; i < N; i++)
		if(l[m].e <= l[i].s) //마지막으로 회의가 끝나는 시간과 겹치지 않으면 회의실 사용
			m = i, ans++;

	cout <<ans;
}




/*
회의 N개의 시작시간과 끝나는 시간이 주어질 때, 한 개의 회의실을 사용하는데 겹치지 않도록 최대한 많은 회의를 배정하는 문제입니다.
그리디를 이용하여 끝나는 시간이 가장 빠른 회의부터 배정하기 위해 끝나는 시간을 기준으로 회의를 정렬하였습니다.
*/