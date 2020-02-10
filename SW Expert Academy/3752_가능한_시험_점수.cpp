//SW Expert Academy D4
//3752 가능한 시험 점수

#include <iostream>

using namespace std;

int main()
{
	int test_case; //테스트 케이스 번호
	int T; //테스트 케이스 개수
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, ans = 0; //문제의 개수, 경우의 수
		bool arr[10001] = {true}; //가능한 시험 점수

		cin >>N;
		for(int i = 0; i < N; i++)
		{
			int s;
			cin >>s;
			for(int j = i*100; j >= 0; j--) //현재까지 최대 i*100으로 만들 수 있음, j를 증가시키면서 탐색하면 점수가 중복돼버림
				if(arr[j]) //현재까지 가능한 시험점수에
					arr[j+s] = true; //입력받은 점수를 각각 더함
		}

		for(int i = 0; i <= 10000; i++)
			if(arr[i]) //가능한 시험 점수의 개수 확인 
				ans++;

		cout <<"#" <<test_case <<" " <<ans <<endl;
	}
}
