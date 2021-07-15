//���� 20044 Project Teams
//ACM-ICPC 2020 ���� I��

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int n, w[10000], m = 200000; //�� ��, �ڵ� ����, Sm
	cin >>n;
	for(int i = 0; i < n*2; i++)
		cin >>w[i];
	sort(w, w+n*2);

	int l = -1, r = n*2;
	while(l++ < r--)
		if(w[l]+w[r] < m)
			m = w[l]+w[r]; //�ּҰ� ����

	cout <<m;
}




/*
�л����� �ڵ� ������ �־����� �� �� ������Ʈ ���� © �� ���� �ڵ� ������ �ּҰ��� �ִ밡 �ǵ��� ����� �����Դϴ�.
���ĵ� ������ �迭���� �� ���� �������� ��� ������ �������� �� ���� ���� �ּҰ����� ���Ͽ� �����ϰ� �ذ��Ͽ����ϴ�.
*/