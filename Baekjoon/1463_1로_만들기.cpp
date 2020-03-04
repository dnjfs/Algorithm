//백준 1463

#include "iostream"
#include "algorithm"

using namespace std;

int cnt[1000001]; //i에서 1로 만들기 위한 연산 횟수
int main()
{
	int N;
	cin >>N;
	for(int i = 2; i <= N; i++)
	{
		int d1 = 30, d2 = 30, d3 = 30; //1~1000000까지의 수 중 연산의 최대 횟수가 22라서 30으로 함

		if(i%3 == 0) //연산1
			d1 = cnt[i/3]; //3으로 나누어 떨어짐
		if(i%2 == 0) //연산2
			d2 = cnt[i/2]; //2로 나누어 떨어짐
		d3 = cnt[i-1]; //연산3: 1을 뺌

		cnt[i] = min(d1, min(d2, d3)) + 1; //최솟값을 구함
	}
  
	cout <<cnt[N];
}
