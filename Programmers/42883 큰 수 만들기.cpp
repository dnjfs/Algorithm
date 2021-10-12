//프로그래머스 42883 큰 수 만들기
//코딩테스트 연습 Level 2

#include <string>

using namespace std;

int ans[1000000], idx; //정답에 들어갈 문자를 숫자로 변환한 배열, ans[] 배열의 크기
string solution(string number, int k)
{
	for (char c : number)
	{
		int n = c - '0';
		for (int i = idx - 1; i >= max(idx - k, 0); i--) //j는 스택처럼 ans 배열의 끝부터 시작
			if (ans[i] < n && k) //ans 배열에 n을 삽입하는 게 더 큰 수가 되는 경우 && 아직 수를 제거할 수 있는 경우
			{
				idx--; //배열의 크기를 줄여 값을 덮어 씌울 것임
				k--; //수를 제거
			}
			else
				break;

		ans[idx++] = n; //ans 배열 끝에 n 추가
	}

	string answer;
	for (int i = 0; i < idx - k; i++)
		answer += ans[i] + '0';
	return answer;
}




/*
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하는 문제입니다.
자릿수의 범위는 100만자리 이하라 문자열로 입력이 들어옵니다.

ans[] 배열을 선언하여 스택처럼 사용하여 수를 순서대로 넣고,
어떤 수를 지울 때는 ans[] 배열에 가장 끝에 있는 수를 차례로 지웁니다.
먼저 나오는 수일수록 더욱 큰 숫자로 표현할 수 있기 때문에
수를 제거할 수 있는 경우엔 가능한 빠르게 제거해주는 방식을 이용하였습니다.
*/