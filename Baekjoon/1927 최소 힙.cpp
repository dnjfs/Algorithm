//백준 1927 최소 힙
//solved.ac CLASS 3

#include "iostream"
#include "queue"

using namespace std;

int main()
{
	int N, x; //연산의 개수, 입력받을 정수
	cin >>N;

	priority_queue<int> pq; //우선순위 큐 (최대 힙)
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if(x)
			pq.push(-x); //최대 힙이므로 음수로 바꿔 넣어 절대값이 작은 수가 루트로 가게 함
		else
		{
			if(pq.empty()) //배열이 비어 있는 경우
				printf("0\n");
			else
			{
				printf("%d\n", -pq.top()); //배열에서 가장 작은 값 출력 (음수로 바뀐 상태라 다시 양수로 바꿔줌)
				pq.pop();
			}
		}
	}
}




/*
최소 힙을 이용하여 입력받은 자연수를 배열에 넣거나 출력하는 문제입니다.
우선순위 큐를 선언할 때 priority_queue<int, vector<int>, greater<int>>와 같은 형식으로 선언해도 되지만,
다익스트라를 구현할 때처럼 최대 힙에서 원소를 음수로 바꿔 넣어 더 작은 값이 루트로 가게 만들었습니다.

의문인 건 어떤 문제는 100만 번의 입력을 받아도 1초가 되지 않았었는데
입력과 출력이 많아도 20만 번이라 cin과 cout으로도 될 줄 알았지만,
시간 초과가 발생하는 것으로 봐선 입력보단 출력이 더 오래 걸리는 것 같습니다.
*/