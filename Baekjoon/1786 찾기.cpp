//백준 1786 찾기
//solved.ac CLASS 4

#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
	string T, P; //텍스트, 패턴
	getline(cin, T);
	getline(cin, P);

	int n = T.size(), m = P.size(); //텍스트의 길이, 패턴의 길이
	vector<int> pi(m, 0), pos; //pi[i]: 패턴의 P[0]~P[i]에서 접두사와 접미사가 같은 가장 긴 길이, pos[i]: 텍스트에서 패턴이 나타난 위치
	for(int i = 1, j = 0; i < m; i++) //전처리 과정에서 pi[] 배열을 구함
	{
		while(j > 0 && P[i] != P[j]) //접두사와 접미사가 다름
			j = pi[j-1]; //접두사와 접미사의 길이를 줄임
		if(P[i] == P[j]) //접두사와 접미사가 같은 경우
			pi[i] = ++j; //접두사와 접미사의 길이 저장
	}

	//KMP 알고리즘
	for(int i = 0, j = 0; i < n; i++) //i: 텍스트를 탐색하는 인덱스, j: 패턴을 탐색하는 인덱스
	{
		while(j > 0 && T[i] != P[j]) //찾기 실패
			j = pi[j-1]; //저장해둔 pi[] 배열을 이용하여 탐색하지 않아도 되는 부분 점프
		if(T[i] == P[j]) //텍스트의 문자와 패턴의 문자가 같은 경우
		{
			if(j == m-1) //패턴을 발견
			{
				pos.push_back(i-m+1); //텍스트에서 패턴이 시작되는 위치 저장
				j = pi[j]; //T[i]와 P[j]가 같으므로 pi[j-1]이 아닌 p[j]를 대입
			}
			else //패턴이 완전히 발견되지 않은 경우
				j++; //i와 j 모두 증가시키며 탐색 진행
		}
	}

	cout <<pos.size() <<endl; //패턴이 발견된 횟수 출력
	for(auto t : pos)
		cout <<t+1 <<" "; //패턴이 발견된 위치 출력
}




/*
텍스트와 패턴을 입력받으면 텍스트에서 패턴이 발견되는 횟수와 위치를 출력하는 문제입니다.
KMP 알고리즘을 공부하기 위해 풀었습니다.
텍스트에서 패턴을 찾다가 실패한 경우, 직전의 문자열은 같다는 정보를 이용하여
O(n*m)의 시간복잡도를 O(n+m)의 시간복잡도로 단축할 수 있습니다.
전처리 과정에서 패턴 내에서 접두사와 접미사가 같은 가장 긴 길이를 미리 구하여
텍스트에서 패턴을 찾기 실패했을 때, 탐색하지 않아도 되는 부분은 건너뛰어 탐색시간을 줄일 수 있습니다.
참고: https://bowbowbow.tistory.com/6
*/