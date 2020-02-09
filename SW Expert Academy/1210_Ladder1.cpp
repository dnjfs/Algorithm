//SW Expert Academy D4
//1210 Ladder1

#include <iostream>

using namespace std;

int search(int a[][100], int x, int y, int old_x) //사다리 거꾸로 타기
{
	if(!y) //y가 0일 때
		return x; //시작 위치 반환

	if(x > 0)
		if(a[x-1][y] && (x-1 != old_x)) //왼쪽에 다리가 있고 왔던 곳이 아닌 경우
			return search(a, x-1, y, x);

	if(x < 99) //오른쪽
		if (a[x+1][y] && (x+1 != old_x))
			return search(a, x+1, y, x);

	return search(a, x, y-1, x); //위
}

int main()
{
	int test_case, T = 10; //테스트 케이스 10개
	while(T--)
	{
		int test_case; //테스트 케이스 번호 입력 받음
		cin >>test_case;
		int ladder[100][100], e; //사다리 배열, 도착 위치

		for(int y = 0; y < 100; y++)
			for(int x = 0; x < 100; x++)
				cin >>ladder[x][y];

		for(int x = 0; x < 100; x++)
			if(ladder[x][99] == 2) //도착 위치 찾기
				e = x;

		cout <<"#" <<test_case <<" " <<search(ladder, e, 99, e) <<endl;
	}
}
