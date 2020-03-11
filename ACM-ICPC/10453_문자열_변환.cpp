//ACM-ICPC 2014 본선 H번 문자열 변환
//백준 10453

#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while(T--)
	{
		int ans = 0; //문자열을 변환하는데 필요한 연산의 수
		string A, B; //문자열A, 문자열B
		vector<int> v1, v2; //문자열A와 문자열B에서 a의 위치를 저장할 배열
		cin >>A >>B;

		for(int i = 0; i < A.size(); i++) //각 문자열의 a의 위치를 순서대로 배열에 저장
		{
			if(A[i] == 'a')
				v1.push_back(i);
			if(B[i] == 'a')
				v2.push_back(i);
		}
		for(int i = 0; i < v1.size(); i++)
			ans += abs(v1[i]-v2[i]); //순서대로 저장된 a의 위치 차이를 계산
		
		cout <<ans <<endl;
	}
}
