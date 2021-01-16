//백준 1629 곱셈
//solved.ac CLASS 4

#include "iostream"

using namespace std;

long long multi(int A, int B, int C) //long long 자료형으로 오버플로우 방지
{
	if(B == 1) //Base Case
		return A % C;

	if(B & 1) //홀수일 때(B%2 == 1)
		return multi(A, B-1, C)*A % C; //A^(B-1)*B % C
	long long t = multi(A, B/2, C); //짝수일 때
	return t*t % C; //(A^(B/2))^2 % C
}

int main()
{
	int A, B, C;
	cin >>A >>B >>C;
	cout <<multi(A, B, C);
}




/*
자연수 A를 B번 곱하여 C로 나눈 나머지를 구하는 문제입니다.
처음엔 오버플로우만 고려하여 변수의 자료형을 long long으로 설정하여
ans = (ans*A)%C를 B번 반복하는 일을 해버려 시간초과가 발생하였습니다.
B 또한 2^31-1값이 들어올 수 있다는 걸 깨달은 후 분할과 정복을 이용하여 해결하였습니다.
*/