//ACM-ICPC 2015 예선 H번 회문인 수
//백준 11068

#include "iostream"

using namespace std;

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while(T--)
	{
		int num, arr[20]; //입력 받은 수 저장용, 진수 배열
		bool find = false;
		cin >>num;

		for(int i = 2; i <= 64; i++) //2~64진수 검사
		{
			int n = num, left = 0, right = -1; //입력 받은 수, i진수로 만들어진 배열을 왼쪽/오른쪽부터 탐색할 인덱스
			while(n)
			{
				arr[++right] = n % i; //i진수로 한 자리씩 배열에 넣음
				n /= i;
			}
			for( ; left < right; left++, right--)
				if(arr[left] != arr[right]) //회문인 수가 아님
					break;

			if(left >= right) //left가 right보다 큰 경우 i진수로 만들어진 자릿수를 모두 검사한 경우임
			{
				find = true;
				break;
			}
		}

		if(find)
			cout <<1 <<endl;
		else
			cout <<0 <<endl;
	}
}
