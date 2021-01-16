//���� 1629 ����
//solved.ac CLASS 4

#include "iostream"

using namespace std;

long long multi(int A, int B, int C) //long long �ڷ������� �����÷ο� ����
{
	if(B == 1) //Base Case
		return A % C;

	if(B & 1) //Ȧ���� ��(B%2 == 1)
		return multi(A, B-1, C)*A % C; //A^(B-1)*B % C
	long long t = multi(A, B/2, C); //¦���� ��
	return t*t % C; //(A^(B/2))^2 % C
}

int main()
{
	int A, B, C;
	cin >>A >>B >>C;
	cout <<multi(A, B, C);
}




/*
�ڿ��� A�� B�� ���Ͽ� C�� ���� �������� ���ϴ� �����Դϴ�.
ó���� �����÷ο츸 ����Ͽ� ������ �ڷ����� long long���� �����Ͽ�
ans = (ans*A)%C�� B�� �ݺ��ϴ� ���� �ع��� �ð��ʰ��� �߻��Ͽ����ϴ�.
B ���� 2^31-1���� ���� �� �ִٴ� �� ������ �� ���Ұ� ������ �̿��Ͽ� �ذ��Ͽ����ϴ�.
*/