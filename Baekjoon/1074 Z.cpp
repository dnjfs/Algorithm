//백준 1074 Z
//solved.ac CLASS 3

#include "iostream"
#include "cmath" //pow()

using namespace std;

int N, r, c; //배열의 크기(2^Nx2^N), 행, 열
int Find(int y, int x, int p) //재귀 함수
{
	if(p < 1) //p가 0인 경우
		return 0; //base case

	int P = pow(2, --p), quad = 0; //한 블럭의 길이 (현재 pxp 배열이라 한 블럭은 (p-1)x(p-1) 배열), 블럭의 위치를 네 구간으로 나눔
	if(r >= y + P) //현재 블럭을 위아래로 나눴을 때 찾는 칸의 위치가 아래에 있으면
	{
		y += P; //행을 아래 블럭으로 옮김
		quad += 2; //블럭 위치만큼 더해줌
	}
	if(c >= x + P) //현재 블럭을 좌우로 나눴을 때 찾는 칸의 위치가 오른쪽에 있으면
	{
		x += P; //행을 오른쪽 블럭으로 옮김
		quad++; //블럭 위치만큼 더해줌
	}

	return Find(y, x, p) + P*P*quad;
}

int main()
{
	cin >>N >>r >>c;

	cout <<Find(0, 0, N);
}




/*
2^N x 2^N 크기의 배열을 Z모양으로 탐색할 때 r행 c열 칸을 방문하는 순서를 출력하는 문제입니다.
재귀를 이용하여 한 배열을 네 블럭으로 나누어 r행 c열의 위치에 따라 구간을 줄여나가 해결하였습니다.
*/