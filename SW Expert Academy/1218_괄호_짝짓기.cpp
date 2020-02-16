//SW Expert Academy D4
//1218 괄호 짝짓기

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test_case, T = 10; //테스트 케이스, 10개의 테스트 케이스
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, cnt = -1; //총 괄호 개수, 배열에 저장한 괄호의 개수
		string s; //입력받을 괄호문자열
		bool ans = true; //정답
		cin >>n >>s;
		char *c = new char[n]; //여는 괄호를 저장할 문자 배열

		for(int i = 0; i < n; i++)
		{
			char t = s[i];
			if(t == '(' || t == '{' || t == '[' || t == '<') //여는 괄호
				c[++cnt] = t; //배열에 저장
			else if(t == ')') //)인 경우
			{
				if(t != c[cnt--]+1) //ASCII 코드로 ')' == '('+1
				{
					ans = false;
					break;
				}
			}
			else if(t != c[cnt--]+2)
			{
				ans = false;
				break;
			}
		}
		if(cnt >= 0) //여는 괄호가 다 닫히지 않은 경우
			ans = false;

		cout <<"#" <<test_case <<" " <<ans <<endl;
	}
}
