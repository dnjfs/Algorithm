//ACM-ICPC 2018 예선 F번 Parcel
//백준 16287

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

struct num //
{
	int n1; //숫자1
	int n2; //숫자2
	int sum; //숫자1과 2의 합
};

bool operator<(num s1, num s2) //구조체 배열의 정렬을 위한 연산자 오버로딩
{
	return s1.sum < s2.sum;
}

int main()
{
	int w, n, input[5001];
	/*
	w: 물품의 무게 합
	n: 물품의 개수
	input[]: 물픔의 무게 배열
	*/
	vector<num> v; //물품을 두 개씩 저장할 배열

	cin >>w >>n;
	for (int i = 0; i < n; i++)
	{
		cin >>input[i];

		num temp;
		temp.n1 = input[i];
		for (int j = 0; j < i; j++) //물품의 모든 조합을 v 배열에 저장
		{
			temp.n2 = input[j];
			temp.sum = temp.n1 + temp.n2;
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end()); //오름차순 정렬

	int left = 0, right = v.size()-1;
	while (left < right)
	{
		int sum = v[left].sum + v[right].sum;
		if (sum == w) //물품의 무게 합이 w일 경우
		{
			if (v[left].n1 != v[right].n1 && v[left].n1 != v[right].n2
				&& v[left].n2 != v[right].n1 && v[left].n2 != v[right].n2) //네 물품이 모두 다름
			{
				cout <<"YES" <<endl;
				return 0;
			}
			else //같은 게 있는 경우
				left++;
		}
		else if (sum < w) //무게가 모자랄 경우
			left++; //왼쪽을 늘려 무게를 늘림
		else //(sum > w) 무게가 초과할 경우
			right--; //오른쪽을 줄여 무게를 줄임
	}

	cout <<"NO" <<endl;
}
