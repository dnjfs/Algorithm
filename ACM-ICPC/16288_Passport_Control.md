//ACM-ICPC 2018 예선 G번 Passport Control
//백준 16288

#include "iostream"

using namespace std;

int main()
{
	int N, k, p[100];
	/*
	N: 입국 승객의 수
	k: 여권 심사 창구의 수
	p[]: 입국장을 빠져나가는 순서
	*/

	cin >>N >>k;
	for(int i = 0; i < N; i++)
		cin >>p[i];

	for(int i = 0; i < k; i++) //i번째 창구에 들어가는 사람을 0으로 만들어줌
	{
		int pass = 0; //현재 들어간 사람 중 가장 순서가 큰 사람
		for(int j = 0; j < N; j++)
			if(p[j] > pass) //현재 창구에 줄을 설 수 있는 경우
			{
				pass = p[j]; //pass 업데이트 후
				p[j] = 0; //들어갔다는 표시로 0으로 만듦
			}
	}

	for(int i = 0; i < N; i++)
		if(p[i]) //창구에 못들어간 사람이 남은 경우
		{
			cout <<"NO";
			return 0;
		}
	cout <<"YES";
}
