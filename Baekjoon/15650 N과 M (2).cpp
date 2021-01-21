//백준 15650 N과 M (2)

#include "iostream"
#include "algorithm"

using namespace std;

int num[8], sel[8]; //1부터 오름차순으로 담긴 배열, 수열을 선택하는 배열
int main()
{
	int N, M; //num[] 배열에 들어갈 최댓값, 한 번에 선택할 수열의 크기
	cin >>N >>M;
	for(int i = 0; i < N; i++) //1~N까지 배열에 저장
		num[i] = i+1;

	for(int i = 0; i < M; i++) //한 번에 M개 선택, 수열 출력은 사전 순으로
		sel[i] = 1;

	do
	{
		for(int i = 0; i < N; i++)
			if(sel[i])
				cout <<num[i] <<" ";
		cout <<endl;
	}while(next_permutation(sel, sel+N, [](int a, int b){ //람다 표현식으로 구현한 내림차순
		return a > b;
	}));
}




/*
1~N이 저장된 자연수 배열에서 M개를 고른 수열을 사전 순으로 출력하는 문제입니다.
STL의 next_permutation() 함수를 이용하여 간단하게 구현하였습니다.
next_permutation() 함수의 세 번째 인자에 내림차순 함수 포인터를 넣어주지 않으면 sel[] 배열의 값이 제대로 순환되지 않습니다.
람다 표현식 대신 greater<>()라는 함수 객체를 넣어줘도 됩니다.
*/
