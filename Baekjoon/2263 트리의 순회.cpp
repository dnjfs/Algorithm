//���� 2263 Ʈ���� ��ȸ
//solved.ac CLASS 4

#include "iostream"

using namespace std;

int in[100000], post[100000], idx[100001]; //in[]: �ο���, post[]: ����Ʈ����, idx[i]: ���� i�� �ο����� �湮�� ����
void pre(int inL, int inR, int postL, int postR) //��������
{
	if(inL > inR || postL > postR) //���� ���
		return;

	int r = post[postR]; //����Ʈ�������� ���� ���߿� �湮�ϴ� ������ ��Ʈ
	cout <<r <<" "; //���������̹Ƿ� ��Ʈ���� ���

	pre(inL, idx[r]-1, postL, postL+(idx[r]-inL)-1); //�ο����� ����Ʈ������ ���� �ڽ��� ������ ���ڷ� �Ѱ���
	pre(idx[r]+1, inR, postL+(idx[r]-inL), postR-1); //������ �ڽ�
}

int main()
{
	int n; //������ ����
	cin >>n;

	for(int i = 0; i < n; i++)
		cin >>in[i];
	for(int i = 0; i < n; i++)
		cin >>post[i];
	for(int i = 0; i < n; i++)
		idx[in[i]] = i;

	pre(0, n-1, 0, n-1);
}




/*
���� Ʈ���� �ο����� ����Ʈ������ �湮�� ������ �־����� ��, ���������� �湮�� ������ ����ϴ� �����Դϴ�.
������ �ذ��ϱ� ���� ����Ʈ������ ��Ʈ�� ���� ���߿� �湮�Ѵٴ� �� �̿��ؾ� �ϴ� �� �˰� �־����� ��͸� �̿��Ͽ� ǥ���ϱⰡ �ſ� ��������ϴ�.
��ͷ� �ҷ��� Ʈ���� ��Ʈ�� �� �ڽ� ��尡 �ο������� ���� �湮�ߴ��� �˱� ���Ͽ� idx[] �迭�� ���� ����� �����Ͽ����ϴ�.

����: https://suhwanc.tistory.com/26
*/