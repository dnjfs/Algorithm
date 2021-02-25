//���� 13549 ���ٲ��� 3
//solved.ac CLASS 4

#include "iostream"
#include "queue"

using namespace std;

int v[100001]; //v[i]: �� N���� i���� ���� ������ ���µ� �ɸ��� �ð�
int main()
{
	int N, K;
	cin >>N >>K;

	priority_queue<pair<int, int>> pq; //�켱���� ť <�ð�, ��ġ>
	pq.push({0, N}); //�� N���� ����
	while(true) //BFS, �������� �������� �����ϹǷ� ���� ����
	{
		int l = -pq.top().first, w = pq.top().second; //�켱���� ť�� ���� ���� �ð��� top�� ��ġ
		pq.pop();
		v[w] = l; //l�� �� �� w�� ����
		if(w == K) //������ ã��
			break;

		if(w && w*2 <= 1e5 && !v[w*2]) //�����̵�
			pq.push({-l, w*2});
		if(w > 0 && !v[w-1]) //w-1�� �ȱ�
			pq.push({-(l+1), w-1});
		if(w < 1e5 && !v[w+1]) //w+1�� �ȱ�
			pq.push({-(l+1), w+1});
	}

	cout <<v[K];
}




/*
�� N���� �� K�� ���� ������ ���� �ð��� ���ϴ� �����Դϴ�.
���� ��ġ�� X�� ��, �ɾ 1�� �� (X-1)/(X+1)�� �̵��ϰų�, �����̵� �Ͽ� 0�� �� (X*2)�� �̵��� �� �ֽ��ϴ�.
�켱���� ť�� �̿��Ͽ� ���� ���� �ð����� BFS�� Ž���Ͽ� ���������� �̵��մϴ�.
*/