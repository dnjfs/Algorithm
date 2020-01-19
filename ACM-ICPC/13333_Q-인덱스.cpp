//ACM-ICPC 2016 예선 I번 Q-인덱스
//백준 13333

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int n, paper[1001];
	/*
	n: 논문의 수
	paper[]: 인용횟수
	*/

	cin >>n;
	for(int i = 0; i < n; i++)
		cin >>paper[i];
	sort(paper, paper+n); //인용횟수 오름차순으로 정렬

	for(int k = n; k >= 0; k--)
		if (paper[n-k] >= k) //k번 이상 인용된 논문이 k편인 경우
		{
			cout <<k; //Q-인덱스 출력 후
			break; //종료
		}
}
