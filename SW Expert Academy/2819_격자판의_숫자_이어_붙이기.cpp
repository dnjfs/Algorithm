//SW Expert Academy D4
//2819 격자판의 숫자 이어 붙이기

#include<iostream>

using namespace std;

bool num[10000000]; //인덱스 크기와 같은 이어 붙여 만들어진 숫자가 존재
void search(int a[][4], int x, int y, int n, int cnt) //격자 탐색
{
	n *= 10; //자릿수 증가
	n += a[x][y];
	cnt++;
	if(cnt == 7) //일곱 자리 숫자 완성
	{
		num[n] = true; //일곱 자리 숫자인 n이 만들어짐
		return;
	}

	if(x > 0) //왼쪽
		search(a, x-1, y, n, cnt);
	if(x < 3) //오른쪽
		search(a, x+1, y, n, cnt);
	if(y > 0) //아래
		search(a, x, y-1, n, cnt);
	if(y < 3) //위
		search(a, x, y+1, n, cnt);
}

int main(int argc, char** argv)
{
	int test_case, T;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//memset(num, false, sizeof(num));
		for(int i = 0; i < 10000000; i++) //테스트 케이스가 여러 개이므로 초기화 필요
			num[i] = false;
		int arr[4][4], ans = 0; //4x4 크기의 격자, 서로 다른 일곱 자리 수들의 개수

		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cin >>arr[i][j];

		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				search(arr, i, j, 0, 0); //(0,0)부터 (3,3)까지 전부 탐색

		for(bool t : num)
			if(t)
				ans++;
		cout <<"#" <<test_case <<" " <<ans <<endl;
	}
	return 0;
}
