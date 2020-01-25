//ACM-ICPC 2015 본선 I번 주식
//백준 11501

#include "iostream"

using namespace std;

int day[1000000];
int main()
{
	int T;

	cin >>T;
	while (T--)
	{
		int N, value = 0; //N: 날의 수, value: 최대 값
		long long int profit = 0; //최대 이익

		cin >>N;
		for (int i = 0; i < N; i++)
			cin >>day[i];

		for (int i = N-1; i >= 0; i--) //배열을 거꾸로 탐색하며
			if (day[i] > value) //현재 최대 값보다 더 큰 게 있으면
				value = day[i]; //업데이트
			else //최대 값보다 작거나 같으면
				profit += value - day[i]; //오늘 사서 최대 값일 때 팜

		cout <<profit <<endl;
	}
}
