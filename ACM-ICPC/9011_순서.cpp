//ACM-ICPC 2012 예선 F번 순서
//백준 9011

#include "iostream"

using namespace std;

int main()
{
	int T;
	cin >>T;
	while (T--)
	{
		int n, R[100];
		/*
		n: 정수의 개수
		R[]: 새로운 순서를 입력받아 원래 순서(S)로 변경
		*/
		bool arr[100] = {false}, find = true;
		/*
		arr[]: i번째 숫자의 S 찾음
		find: S 찾음
		*/

		cin >>n;
		for (int i = 0; i < n; i++)
			cin >>R[i];

		for (int i = n-1; i >= 0; i--)
		{
			if (i < R[i]) //i보다 작은 수의 개수가 i보다 커질 순 없음
			{
				find = false;
				break;
			}
			int j, cnt = 0;
			for (j = 0; cnt <= R[i]; j++)
				if (!arr[j]) //S로 만들어진 수를 제외하고
					cnt++; //가장 작은 수부터 카운트하여
			R[i] = j; //S가 될 수를 찾음
			arr[--j] = true; //배열의 인덱스는 0부터 시작
		}

		if (find)
			for (int i = 0; i < n; i++) //S 출력
				cout <<R[i] <<" ";
		else
			cout <<"IMPOSSIBLE";
		cout <<endl;
	}
}
