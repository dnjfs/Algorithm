//���� 2206 �� �μ��� �̵��ϱ�

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct pos //��ġ ����ü
{
	int R, C;
};

int cnt[1000][1000]; //cnt[r][c]: (1, 1)���� (r, c)������ �ִ� ���
int bfs(vector<string> v, int N, int M)
{
	queue<pos> q, qc; //���� �Ⱥν��� ��/�ν��� �� �̵��� ��ġ
	pos temp {0, 0}; //(1, 1)���� Ž�� ����
	q.push(temp);
	cnt[0][0] = 1; //�����ϴ� ĭ ����

	int rc[] = {-1,0, 1,0, 0,-1, 0,1}; //��,��,��,��
	while (!q.empty())
	{
		int r = q.front().R, c = q.front().C;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			if((i==0 && r==0) || (i==1 && r==N-1) || (i==2 && c==0) || (i==3 && c==M-1)) //�̵� ����
				continue;

			int tr = rc[i*2]+r, tc = rc[i*2+1]+c;
			if(!cnt[tr][tc]) //���� �湮���� ���� ���
			{
				temp.R = tr;
				temp.C = tc;
				cnt[tr][tc] = cnt[r][c]+1; //��� ����
				if (v[tr][tc] == '0')
					q.push(temp);
				else //���� �μ�
					qc.push(temp);
			}
		}
	}

	while (!qc.empty())
	{
		int r = qc.front().R, c = qc.front().C;
		qc.pop();

		for (int i = 0; i < 4; i++)
		{
			if ((i==0 && r==0) || (i==1 && r==N-1) || (i==2 && c==0) || (i==3 && c==M-1))
				continue;

			int tr = rc[i*2]+r, tc = rc[i*2+1]+c;
			if (v[tr][tc] == '0' && (cnt[tr][tc]>cnt[r][c]+1 || !cnt[tr][tc])) //���� �� �� �ν����� �̵��� �� �ִ� ĭ�̸鼭 �� ª�� ��ΰų� ���� �湮���� ���� ĭ�� ���
			{
				temp.R = tr;
				temp.C = tc;
				cnt[tr][tc] = cnt[r][c]+1; //��� ����
				qc.push(temp);
			}
		}
	}

	return cnt[N-1][M-1]; //(N, M)������ �ִ� ��� ��ȯ
}

int main()
{
	int N, M; //�� ũ�� NxM
	cin >>N >>M;

	vector<string> v; //��
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >>s;
		v.push_back(s);
	}

	int ans = bfs(v, N, M);
	if (!ans) //�Ұ���
		ans = -1;
	cout <<ans;
}




/*
NxM�� ��ķ� ǥ���Ǵ� ���� �־����� �� (1, 1)���� (N, M)������ �ִ� �Ÿ��� ���ϴ� �����Դϴ�.
�Ϲ����� �ʺ�켱Ž�� ������ �ٸ� ���� ���� �ϳ� �μ� �� �ִٴ� ���Դϴ�.

��� ���� �ν����� ǥ���ϱ� ���� ť�� ���� �μ� ���θ� �����ϰų�,
�ִ� ��θ� �����ϴ� �迭�� �ϳ� �� ����ų� �ϴ� ��� ����� ���� �ϸ� ������ ���,
ť�� �ϳ� �� ����� BFS�� �� �� �ϴ� ����� ���߽��ϴ�.

���� ���� �μ��� ���� ���¿��� BFS�� �ϸ� �ִ� ��θ� ���ϴµ�
���� ���� ������ �� ���� �ν� �ٸ� ť�� �ش� ��ġ�� �־��ִ� ������ ���� �ν����� ����������ϴ�.
�� �� ���� �μ� ���¸� ���� ť�� �̿��Ͽ� BFS�� �� �� �� �ϸ� �ִ� ��θ� �����ϴ� ������� �ذ��Ͽ����ϴ�.
�̶� ���� �� �μ� �� �����Ƿ� ���� �ƴ� ĭ���θ� �̵��ϸ� ù BFS ������ ��ΰ� �� ª�ų� ���� ���� �������� ���ߴ� ĭ���θ� �̵��մϴ�.
*/