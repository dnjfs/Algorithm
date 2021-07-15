//백준 20044 Project Teams
//ACM-ICPC 2020 예선 I번

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int n, w[10000], m = 200000; //팀 수, 코딩 역량, Sm
	cin >>n;
	for(int i = 0; i < n*2; i++)
		cin >>w[i];
	sort(w, w+n*2);

	int l = -1, r = n*2;
	while(l++ < r--)
		if(w[l]+w[r] < m)
			m = w[l]+w[r]; //최소값 갱신

	cout <<m;
}




/*
학생들의 코딩 역량이 주어지고 두 명씩 프로젝트 팀을 짤 때 팀의 코딩 역량의 최소값이 최대가 되도록 만드는 문제입니다.
정렬된 상태의 배열에서 양 끝을 기준으로 잡고 구간을 좁혀가며 두 값의 합이 최소값인지 비교하여 간단하게 해결하였습니다.
*/