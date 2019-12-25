//ACM-ICPC 2017 예선 H번 MultiMax
//백준 14753

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int n, card[10000], multi1, multi2;
	/*
	n: 카드 개수
	card[]: 정수 값을 가진 카드
	multi1: 가장 큰 값을 가진 카드 두 장을 선택하여 저장
	multi2: 가장 작은 값을 가진 카드 두 장을 선택하여 저장
	*/

	cin >>n;
	for (int i = 0; i < n; i++)
		cin >>card[i];
	sort(card, card+n); //오름차순 정렬

	multi1 = card[n-1] * card[n-2]; //가장 큰 2장이 양수라고 가정
	if (card[n-3] > 0) //세번째로 큰 수도 양수일 경우 곱하면 값이 더 커짐
		multi1 *= card[n-3];
	multi2 = card[0] * card[1]; //가장 작은 2장이 음수라고 가정
	if (card[n-1] > 0) //가장 큰 수가 양수일 경우 곱하면 값이 더 커짐
		multi2 *= card[n-1];

	if (multi1 > multi2) //둘 중 더 큰 값을 출력
		cout <<multi1;
	else
		cout <<multi2;
}
