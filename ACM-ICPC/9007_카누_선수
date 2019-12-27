//ACM-ICPC 2012 예선 B번 카누 선수
//백준 9007

#include "iostream"
#include "algorithm"

using namespace std;

int arr1[1000000], arr2[1000000]; //arr1은 1팀과 2팀, arr2는 3팀과 4팀의 모든 조합을 넣음
int main()
{
	int T;
	cin >>T;
	for (int t = 0; t < T; t++)
	{
		int c[4][1000], k, n, ans, diff = 40000000;
		/*
		c[i][]: i번째 팀의 몸무게 배열
		k: 보트의 특정 값
		n: 각 반의 학생수
		ans: 답
		diff: 몸무게 차이의 최소값
		*/

		cin >>k >>n;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < n; j++)
				cin >>c[i][j];

		int index = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++, index++)
				arr1[index] = c[0][i] + c[1][j]; //두 팀의 모든 조합을 배열에 따로 저장
		index = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++, index++)
				arr2[index] = c[2][i] + c[3][j];
		sort(arr1, arr1+index); //각 두 팀의 모든 조합이 저장된 배열을 오름차순으로 정렬
		sort(arr2, arr2+index);

		int left = 0, right = index-1;
		while (left < index && right >= 0)
		{
			int sum = arr1[left] + arr2[right]; //arr1은 왼쪽부터, arr2는 오른쪽부터 검사
			if (sum > k) //합이 보트의 특정 값보다 큰 경우
			{
				if (sum-k < diff) //합의 차이가 예전에 구한 것보다 작으면
				{
					diff = sum - k; //업데이트하고
					ans = sum; //답으로 저장
				}
				right--; //합이 줄도록 오른쪽을 내림
			}
			else if (sum < k) //합이 보트의 특정 값보다 작은 경우
			{
				if (k-sum <= diff)
				{
					diff = k - sum;
					ans = sum;
				}
				left++; //합이 커지도록 왼쪽을 올림
			}
			else //sum == k 답을 찾은 경우
			{
				ans = sum;
				break;
			}
		}

		cout <<ans <<endl;
	}
}
