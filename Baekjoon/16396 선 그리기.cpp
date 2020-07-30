//백준 16396 선 그리기

#include "iostream"

using namespace std;

int main()
{
	int N, ans = 0; //선의 개수, 투사된 선의 총 길이 합
	bool proj[10000] = { false }; //proj[i]: i번째 칸에 선이 투사되어 있는지 나타냄
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int l, r; //선의 시작 좌표, 끝 좌표
		cin >> l >> r;

		for (int j = l; j < r; j++) //l번째 칸부터 r-1번째 칸까지 선을 투사
			proj[j] = true;
	}

	for (int i = 1; i < 10000; i++)
		if (proj[i]) //i번째 칸에 선이 투사되어 있으면 투사된 선의 총 길이 합을 증가
			ans++;

	cout << ans;
}



/*
한 직선에 평행한 선분 N개를 그려 직선 좌표에 투사했을 때 투사된 선의 총 길이의 합을 구하는 문제입니다.
좌표의 점과 점 사이를 한 칸으로 생각한 배열을 만들어 투사하는 방법으로 간단하게 해결하였습니다.
*/