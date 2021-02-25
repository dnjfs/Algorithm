//백준 13549 숨바꼭질 3
//solved.ac CLASS 4

#include "iostream"
#include "queue"

using namespace std;

int v[100001]; //v[i]: 점 N에서 i으로 가장 빠르게 가는데 걸리는 시간
int main()
{
	int N, K;
	cin >>N >>K;

	priority_queue<pair<int, int>> pq; //우선순위 큐 <시간, 위치>
	pq.push({0, N}); //점 N에서 시작
	while(true) //BFS, 언젠가는 목적지에 도달하므로 조건 생략
	{
		int l = -pq.top().first, w = pq.top().second; //우선순위 큐라서 가장 빠른 시간이 top에 위치
		pq.pop();
		v[w] = l; //l초 후 점 w에 도착
		if(w == K) //동생을 찾음
			break;

		if(w && w*2 <= 1e5 && !v[w*2]) //순간이동
			pq.push({-l, w*2});
		if(w > 0 && !v[w-1]) //w-1로 걷기
			pq.push({-(l+1), w-1});
		if(w < 1e5 && !v[w+1]) //w+1로 걷기
			pq.push({-(l+1), w+1});
	}

	cout <<v[K];
}




/*
점 N에서 점 K로 가장 빠르게 가는 시간을 구하는 문제입니다.
현재 위치가 X일 때, 걸어서 1초 후 (X-1)/(X+1)로 이동하거나, 순간이동 하여 0초 후 (X*2)로 이동할 수 있습니다.
우선순위 큐를 이용하여 가장 빠른 시간부터 BFS로 탐색하여 목적지까지 이동합니다.
*/