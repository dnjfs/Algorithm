//ACM-ICPC 2016 예선 A번 이진 트리
//백준 13325

#include "iostream"
#include "algorithm"

using namespace std;

int tree[1<<21]; //트리 배열, 1<<21: 2^21
int main()
{
	int k, n, sum = 0; //트리의 높이, 노드의 개수, 모든 에지들의 가중치들의 총합
	cin >>k;
	n = (1<<k+1) - 1;
	for(int i = 2; i <= n; i++) //루트 노드는 1번
	{
		cin >>tree[i];
		sum += tree[i]; //가중치 합이 중복되지 않게 미리 원래 가중치들을 합함
	}

	for(int i = n/2; i > 0; i--) //높이-1 노드부터 거꾸로 확인
	{
		int left = tree[i*2], right = tree[i*2+1]; //현재 노드의 왼쪽 자식, 오른쪽 자식
		sum += max(left, right) - min(left, right); //두 자식으로 가는 경로의 길이가 같게 함
		tree[i] += max(left, right); //리프 노드에서 현재 노드까지 가는 경로의 가중치
	}

	cout <<sum <<endl;
}
