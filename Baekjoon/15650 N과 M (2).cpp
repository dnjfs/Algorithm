//���� 15650 N�� M (2)

#include "iostream"
#include "algorithm"

using namespace std;

int num[8], sel[8]; //1���� ������������ ��� �迭, ������ �����ϴ� �迭
int main()
{
	int N, M; //num[] �迭�� �� �ִ�, �� ���� ������ ������ ũ��
	cin >>N >>M;
	for(int i = 0; i < N; i++) //1~N���� �迭�� ����
		num[i] = i+1;

	for(int i = 0; i < M; i++) //�� ���� M�� ����, ���� ����� ���� ������
		sel[i] = 1;

	do
	{
		for(int i = 0; i < N; i++)
			if(sel[i])
				cout <<num[i] <<" ";
		cout <<endl;
	}while(next_permutation(sel, sel+N, [](int a, int b){ //���� ǥ�������� ������ ��������
		return a > b;
	}));
}




/*
1~N�� ����� �ڿ��� �迭���� M���� �� ������ ����ϴ� �����Դϴ�.
STL�� next_permutation() �Լ��� �̿��Ͽ� �����ϰ� �����Ͽ����ϴ�.
next_permutation() �Լ��� �� ��° ���ڿ� �������� �Լ� �����͸� �־����� ������ sel[] �迭�� ���� ����� ��ȯ���� �ʽ��ϴ�.
���� ǥ���� ��� greater<>()��� �Լ� ��ü�� �־��൵ �˴ϴ�.
*/