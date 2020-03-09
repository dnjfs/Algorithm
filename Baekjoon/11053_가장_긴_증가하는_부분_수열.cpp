//백준 11053

#include "iostream"

using namespace std;

int A[1000], cnt[1000]; //수열, i번째 수열까지 가장 긴 증가하는 부분 수열의 길이
int main()
{
	int N, length = 0; //수열 A의 크기, 수열 A의 가장 긴 증가하는 부분 수열의 길이
	cin >>N;
	for (int i = 0; i < N; i++)
	{
		cin >>A[i];

		int max = 0;
		for (int j = 0; j < i; j++) //입력받은 수열까지 탐색하며
			if (A[j]<A[i] && cnt[j]>max) //A[i]보다 작으면서 가장 큰 길이를 찾음
				max = cnt[j];

		cnt[i] = max + 1; //수열의 길이에 A[i] 포함
		if (cnt[i] > length) //최대값 갱신
			length = cnt[i];
	}

	cout <<length;
}
