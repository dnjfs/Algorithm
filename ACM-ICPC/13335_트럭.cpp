//ACM-ICPC 2016 예선 L번 트럭
//백준 13335

#include "iostream"
#include "queue"

using namespace std;

int main()
{
	int n, w, L, a[1000], time, sum;
	queue<int> Q;
	/*
	n: 트럭의 수
	w: 다리의 길이
	L: 다리의 최대하중
	a[]: 트럭의 무게
	time: 모든 트럭들이 다리를 건너는 최단시간
	sum: 다리 위에 올라간 트럭의 무게 합

	Q: 다리 위에 올라간 트럭의 각자 무게
	*/

	cin >>n >>w >>L;
	for(int i = 0; i < n; i++)
		cin >>a[i];

	Q.push(a[0]); //첫번째 트럭을 올림
	sum = a[0];
	time = 1;

	for (int i = 1; i < n; i++)
		while(true)
			if(Q.size() >= w) //다리의 길이보다 트럭의 수가 더 많아질 경우
			{
				sum -= Q.front(); //해당 트럭의 무게만큼 감소
				Q.pop();
			}
			else //다리에 트럭을 올릴 공간이 있는 경우
			{
				time++; //(큐에 push하는 경우) 시간이 증가
				if(sum + a[i] > L) //다리의 최대하중보다 트럭의 무게 합이 더 나가게 될 경우
					Q.push(0); //다리에 올라온 트럭을 보내주기 위해 무게가 0인 트럭을 올린다 생각함
				else
				{
					Q.push(a[i]);
					sum += a[i]; //해당 트럭의 무게만큼 증가
					break;
				}
			}

	cout <<time + w <<endl; //가장 마지막으로 올린 트럭을 보내는 시간까지 추가로 걸림
}
