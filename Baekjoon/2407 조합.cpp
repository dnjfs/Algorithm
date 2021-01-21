//백준 2407 조합
//solved.ac CLASS 4

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

string StrSum(string s1, string s2) //문자열 합
{
	string sum; //두 문자열을 합한 결과
	int n = 0; //자릿수끼리 합한 결과
	while(s1.size() || s2.size() || n) //합할 수 있는 경우 반복
	{
		if(s1.size()) //!s1.empty()
		{
			n += s1.back() - '0'; //문자열의 가장 뒤의 수
			s1.pop_back(); //더했으므로 제거
		}
		if(s2.size())
		{
			n += s2.back() - '0';
			s2.pop_back();
		}

		sum.push_back(n%10 + '0'); //같은 자릿수를 합한 결과를 저장하며 자릿수 증가
		n /= 10; //캐리 발생도 고려
	}
	reverse(sum.begin(), sum.end()); //문자열을 거꾸로 하여 일의 자릿수를 맨 뒤로 보냄

	return sum;
}

string c[101][101];
int main()
{
	int n, m;
	cin >>n >>m;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= min(i, m); j++) //nCm을 구하는 것이므로 iCj에서 j가 m을 넘어갈 필요가 없음 (파스칼의 삼각형)
			if(j == 0 || i == j)
				c[i][j] = "1";
			else
				c[i][j] = StrSum(c[i-1][j-1], c[i-1][j]); //iCj = (i-1)C(j-1) + (i-1)Cj

	cout <<c[n][m]; //nCm 출력
}




/*
nCm을 출력하는 문제입니다.
n의 범위가 작다면 int로, 살짝 커도 long long 자료형으로 출력할 수 있겠지만,
무려 100까지라 일반적인 자료형으로는 20자리가 넘는 큰 수를 한 번에 담아낼 수 없습니다.
큰 수를 여러 부분으로 나누어 담는 방법도 사용할 수 있지만, 문자열로 구현해보았습니다.
*/