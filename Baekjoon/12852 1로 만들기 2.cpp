//백준 12852 1로 만들기 2
//solved.ac CLASS 5

#include "iostream"

using namespace std;

int cnt[1000001], pre[1000001]; //cnt[i]: i에서 1로 만들기 위한 최소 연산 횟수, pre[i]: i에서 1로 만들기 위해 지나갈 수
int main()
{
	int N;
	cin >>N;
	for (int i = 2; i <= N; i++)
	{
		int d1 = 30, d2 = 30, d3 = 30;
		if (i%3 == 0)
			d1 = cnt[i/3];
		if (i%2 == 0)
			d2 = cnt[i/2];
		d3 = cnt[i-1];

		int m = min(d1, min(d2, d3));
		if(m == d1) //3으로 나누는 연산이 가장 빠름
			pre[i] = i/3;
		else if(m == d2) //2로 나누는 연산이 가장 빠름
			pre[i] = i/2;
		else //1로 빼는 연산이 가장 빠름
			pre[i] = i-1;
		cnt[i] = m+1;
	}

	cout <<cnt[N] <<endl;
	int t = N;
	while(t) //N에서 1로 만들기 위한 경로 출력
	{
		cout <<t <<" ";
		t = pre[t];
	}
}




/*
1로 만들기(백준 1463) 문제에서 연산을 하는 횟수의 최솟값과 N을 1로 만드는 방법에 포함되어 있는 수를 순서대로 출력하는 문제입니다.
각 연산을 했을 때의 최솟값을 찾아 새로운 배열에 경로를 저장하는 방법으로 해결하였습니다.
*/