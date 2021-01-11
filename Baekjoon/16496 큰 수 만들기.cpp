//백준 16496 큰 수 만들기

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	int N; //수의 개수
	vector<string> list; //정수 리스트
	cin >>N;

	for(int i = 0; i < N; i++)
	{
		string str;
		cin >>str;
		list.push_back(str);
	}
	sort(list.begin(), list.end()); //사전순으로 정렬

	for(int h = 0; h < N; h++) //문제에 맞게 한 번 더 정렬
		for(int i = h; i < N-1; i++)
		{
			char l = list[i][0], r = list[i+1][0]; //각 숫자의 첫 번째 자리로 초기화
			for(int j = 1; j < list[i].size() || j < list[i+1].size(); j++) //아직 검사할 수가 남은 경우 반복
			{
				if(l != r) //이전에 비교한 수가 다른 경우
					break;
				if(list[i].size() <= j) //비교할 수의 자릿수를 넘긴 경우
				{
					l = list[i][0]; //첫 번째 자리로 초기화
					r = list[i+1][j];
				}
				else if(list[i+1].size() <= j)
				{
					l = list[i][j];
					r = list[i+1][0];
				}
				else
				{
					l = list[i][j];
					r = list[i+1][j];
				}

				if(l > r) //왼쪽에 있는 수가 더 큰 경우
				{
					string temp = list[i]; //스왑
					list[i] = list[i+1];
					list[i+1] = temp;
					break;
				}
			}
		}

	if(list[N-1] == "0") //모두 0인 경우
		cout <<0;
	else
		for(int i = N-1; i >= 0; i--) //가장 큰 수가 되도록 출력
			cout <<list[i];
}




/*
음이 아닌 정수가 N개 들어있는 리스트가 주어질 때, 리스트에 포함된 수를 나열하여 만들 수 있는 가장 큰 수를 구하는 문제입니다.
0이 정답인 경우 0 하나를 출력해야 합니다.
문자열 배열을 사전 순으로 정렬 후 문제에 맞게 한 번 더 정렬하여 해결하였습니다.

그리디 문제라 단순히 정렬하면 되는 문제인 줄 알았으나 문자열을 사전 순으로 정렬했을 땐 길이가 더 긴 문자가 더 크게 되는 문제가 있었습니다.
"99"와 "991"을 비교하면 "99" < "991"이 되어 99991이 아닌 99199로 출력되어버립니다.

"6"과 "607"을 비교할 때 29번째 줄처럼 직전에 비교한 문자,
즉 list[i][j-1]과 list[i+1][j-1]을 비교하는 식으로 했더니 왼쪽 문자가 공백으로 나와 “607”이 더 큰 것처럼 정렬이 되어버렸습니다.

아래는 제가 검사한 테스트 케이스입니다.
[입력]
25
603 58 55 607 5 60 6 61 0 0 51 510 10 11 1 67 601 99 90 9 911 98 661 660 600000
[출력]
9999891190676661660616076060360160000058555515101111000
*/