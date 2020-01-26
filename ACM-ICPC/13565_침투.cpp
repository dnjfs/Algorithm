//ACM-ICPC 2016 본선 G번 침투
//백준 13565

#include "iostream"

using namespace std;

void dfs(string str[], int M, int N, int row, int column) //깊이우선탐색
{
	str[row][column] = '2'; //현재 격자 방문

	if (row != 0) //맨 위 행이 아닐 때
		if (str[row-1][column] == '0') //현재에서 위 행을 갈 수 있다면
			dfs(str, M, N, row-1, column); //up
	if (column != 0)
		if (str[row][column-1] == '0')
			dfs(str, M, N, row, column-1); //left
	if (row != M-1)
		if (str[row+1][column] == '0')
			dfs(str, M, N, row+1, column); //down
	if (column != N-1)
		if (str[row][column+1] == '0')
			dfs(str, M, N, row, column+1); //right
}

int main()
{
	int M, N, i;
	string str[1000];
	/*
	M: 격자의 행 크기
	N: 격자의 열 크기
	i: 배열을 탐색하는 인덱스
	str[]: 격자 배열
	*/

	cin >>M >>N;
	for (i = 0; i < M; i++)
		cin >>str[i];

	for (i = 0; i < N; i++)
		if (str[0][i] == '0') //방문 가능
			dfs(str, M, N, 0, i);
	for (i = 0; i < N; i++)
		if (str[M-1][i] == '2') //침투됨
			break;

	if (i < N) //침투된 경우 for문의 i < N 조건에서 멈춤
		cout <<"YES";
	else
		cout <<"NO";
}
