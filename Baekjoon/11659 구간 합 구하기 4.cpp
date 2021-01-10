//백준 11659 구간 합 구하기 4

#include "iostream"

using namespace std;

int n[100001]; //n[i]: 처음부터 i까지 수의 누적합
int main()
{
	/* cin, cout 속도 빠르게하기
	ios_base::sync_with_stdio(0); //(false)
	cin.tie(0); //(NULL)
	cout.tie(0); //(NULL)
	*/
	int N, M; //수의 개수, 합을 구해야 하는 횟수
	cin >>N >>M;

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &n[i]);
		n[i] += n[i-1]; //누적합
	}
	for(int k = 0; k < M; k++)
	{
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", n[j]-n[i-1]); //(1, j)구간의 합에 (1, i-1)구간의 합을 빼면 (i, j)구간의 합을 구할 수 있음
	}
}




/*
수 N개가 주어졌을 때, i부터 j번째 수까지 합을 M번 구하는 문제입니다.
입력된 수를 배열에 차례대로 누적하고, 27번째 줄처럼 미리 구한 누적합 배열을 이용하면 간단하게 해결됩니다.
간단한 문제지만 C++에서는 신경을 써야 할 부분이 있는데 cin과 cout을 사용하면 수십만 번의 입출력 때문에 시간초과가 발생합니다.
더 빠른 scanf()와 printf()를 사용하거나, 11~13번째 줄 주석과 같이 sync_with_stdio() 코드를 추가해주면 해결됩니다.
*/