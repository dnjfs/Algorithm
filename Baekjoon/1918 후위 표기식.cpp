//백준 1918 후위 표기식
//solved.ac CLASS 4

#include "iostream"
#include "stack"

using namespace std;

int main()
{
	string str; //중위 표기식
	cin >>str;

	stack<char> st; //연산자를 저장할 스택
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if(c >= 'A' && c <= 'Z') //문자는 그대로 출력
			cout <<c;
		else if(c == '(') //여는 괄호
			st.push(c); //스택에 쌓음
		else if(c == ')') //닫는 괄호
		{
			while(st.top() != '(') //여는 괄호가 나올 때까지 연산자 출력
			{
				cout <<st.top();
				st.pop();
			}
			st.pop(); //여는 괄호는 스택에서 삭제
		}
		else if(c =='*' || c == '/') //연산순위가 높은 곱하기와 나누기
		{
			while(!st.empty() && (st.top() == '*' || st.top() == '/')) //연산순위가 같은 곱하기와 나누기가 나오면 출력
			{
				cout <<st.top();
				st.pop();
			}
			st.push(c); //출력 후 연산자 저장
		}
		else if(c == '+' || c == '-') //연산순위가 낮은 더하기와 빼기
		{
			while(!st.empty() && st.top() != '(') //연산순위가 같거나 높은 연산자(+-*/) 출력
			{
				cout <<st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty()) //중위 표기식을 모두 탐색 후 스택에 남은 연산자들 모두 출력
	{
		cout <<st.top();
		st.pop();
	}
}




/*
중위 표기식을 후위 표기식으로 변환시키는 문제입니다.
후위 표기식을 계산하는 방법은 알고 있었지만,
중위 표기법에서 후위 표기법으로 변환된 예시를 잘 몰라 많이 헤맸습니다.
이번 문제를 통하여 후위 표기법으로 표현하는 방법을 제대로 공부하게 되었습니다.
*/