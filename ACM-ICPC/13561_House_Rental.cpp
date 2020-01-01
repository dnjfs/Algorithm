//ACM-ICPC 2016 본선 C번 House Rental
//백준 13561

#include "iostream"
#include "algorithm"

using namespace std;

struct Facility //시설물 구조체
{
	int type; //종류
	int location; //위치
};

bool operator<(Facility a, Facility b) //구조체에서 sort() 사용을 위한 연산자 오버로딩
{
	return a.location < b.location;
}

Facility facilities[1000000]; //시설물이 위치 값을 기준으로 정렬되어 있음
int street[1000001]; //street[i]는 종류 i인 시설이 left에서 right까지의 구간에 몇 개가 있는지 나타냄
int main()
{
	int k, n, answer, min = 2000000001, kNum = 0, left = 0, right = 0;
	/*
	k: 시설물의 종류
	n: 시설물의 개수
	answer: 정답
	min: 구간에 모든 종류의 시설물이 있을 경우 구간의 최소 길이
	kNum: 구간에서 서로 다른 종류의 시설물의 개수
	left: 구간의 왼쪽 끝
	right: 구간의 오른쪽 끝
	*/

	cin >>k >>n;
	for (int i = 0; i < n; i++)
	{
		cin >>facilities[i].location;
		cin >>facilities[i].type;
	}
	sort(facilities, facilities + n); //location을 기준으로 오름차순 정렬

	while (right < n) //right를 증가시키며 구간을 만드므로 right는 시설물의 개수인 n보다 커질 수 없음
	{
		if (++street[facilities[right].type] == 1) //구간에서 해당 종류의 시설물이 1개 증가하여 0에서 1이 되면 새로운 종류의 시설물이 구간에 들어온 것이므로
			kNum++; //kNum 증가

		while (kNum == k) //모든 종류의 시설물이 구간 사이에 있는 경우
		{
			int mid = facilities[left].location + facilities[right].location;
			if (mid < 0) //중앙이 홀수인 음의 정수인 경우 가능한 위치가 두 곳인데
				mid -= 1; //더 작은 위치는 절대값이 더 큰 곳임
			mid /= 2; //중앙을 구함
			int distance = facilities[right].location - facilities[left].location; //구간의 길이
			if (distance < min) //구간의 길이가 더 작은 경우 업데이트
			{
				answer = mid;
				min = distance;
			}
			if (!--street[facilities[left].type]) //구간의 가장 왼쪽에 위치한 시설을 제외하여 해당 종류의 시설이 구간에 남아있지 않는 경우
				kNum--; //kNum 감소
			left++; //Window Sliding, 구간의 왼쪽 감소
		}
		right++; //Window Sliding, 구간의 오른쪽 증가
	}

	cout <<answer;
}
