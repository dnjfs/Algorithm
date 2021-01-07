//백준 6603 로또

#include "iostream"

using namespace std;

void lotto(int *S, int *print, int k, int d) //로또 번호 출력
{
	if(d == 7) //번호 여섯 개를 모두 선택한 경우
	{
		for(int i = 1; i < 7; i++) //번호 출력
			cout <<S[print[i]] <<" ";
		cout <<endl;

		return;
	}

	while(print[d]-d <= k-6) //d번째 순서에서 출력할 번호의 위치가 유효한 범위를 넘으면 종료
	{
		lotto(S, print, k, d+1); //다음 순서에서 출력할 번호 선택

		print[d]++; //현재 순서에서 출력할 번호의 위치 증가
		for(int i = d; i < 6; i++) //d+1번째부터 6번째까지 인덱스 초기화
			print[i+1] = print[i]+1;
	}
}

int main()
{
	while(true)
	{
		int k, S[13], print[7]; //집합의 크기, 번호 집합, print[i]: 집합 S에서 print[i]번째 번호 선택
		cin >>k;
		if(!k) //k가 0이면 종료
			break;

		for(int i = 1; i <= k; i++)
			cin >>S[i];

		for(int i = 0; i < 7; i++) //인덱스 초기화
			print[i] = i;
		lotto(S, print, k, 1); //첫 번째로 출력할 번호부터 선택하며 재귀함수로 여섯 번째로 출력할 번호까지 선택하면 출력

		cout <<endl;
	}
}




/*
k개의 로또 번호가 오름차순으로 주어졌을 때 그중 6개의 번호를 선택하는 모든 방법을 사전 순으로 출력하는 문제입니다.
재귀함수를 이용하여 d번째 순서에서 선택한 인덱스를 저장할 배열을 하나 만들어 번호 여섯 개를 모두 선택하면 인덱스 배열을 참조하여 집합 S에서 번호를 출력하였습니다.
간단한 문제라 쉽게 구현할 수 있을 줄 알았으나 재귀함수로 구현하는 게 오랜만이라 생각보다 시간이 걸려 아쉬웠습니다.

18번째 줄에 대해 추가로 설명하면 만약 k가 8인데 2번째로 출력할 숫자의 인덱스가 5라면 적어도 156789와 같은 위치의 번호가 선택되므로 유효범위를 지정해주었습니다.
*/