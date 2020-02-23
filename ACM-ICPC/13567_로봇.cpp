//ACM-ICPC 2016 본선 I번 로봇
//백준 13567

#include "iostream"

using namespace std;

int main()
{
	int M, n, x = 0, y = 0, d, move = 0;
	/*
	M: 정사각형 한 변의 길이
	n: 로봇이 수행할 명령어 수
	x, y: 로봇의 현재 위치
	d: 명령어 이후 받는 수
	move: 로봇이 향하고 있는 방향
	*/
	string s; //명령어
	cin >>M >>n;

	for (int i = 0; i < n; i++)
	{
		cin >>s >>d;
		if (s == "MOVE")
		{
			if (move == 0) //right
				x += d;
			else if (move == 1) //up
				y += d;
			else if (move == 2) //left
				x -= d;
			else //down
				y -= d;

			if (x < 0 || x > M || y < 0 || y > M) //정사각형 영역을 벗어난 경우
				break;
		}
		else if (s == "TURN")
		{
			if (d) //d == 1
				move--;
			else //d == 0
				move++;

			if (move > 3)
				move = 0;
			else if (move < 0)
				move = 3;
		}
	}

	if (x < 0 || x > M || y < 0 || y > M)
		cout <<-1;
	else
		cout <<x <<" " <<y;
}
