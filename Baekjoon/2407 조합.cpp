//���� 2407 ����
//solved.ac CLASS 4

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

string StrSum(string s1, string s2) //���ڿ� ��
{
	string sum; //�� ���ڿ��� ���� ���
	int n = 0; //�ڸ������� ���� ���
	while(s1.size() || s2.size() || n) //���� �� �ִ� ��� �ݺ�
	{
		if(s1.size()) //!s1.empty()
		{
			n += s1.back() - '0'; //���ڿ��� ���� ���� ��
			s1.pop_back(); //�������Ƿ� ����
		}
		if(s2.size())
		{
			n += s2.back() - '0';
			s2.pop_back();
		}

		sum.push_back(n%10 + '0'); //���� �ڸ����� ���� ����� �����ϸ� �ڸ��� ����
		n /= 10; //ĳ�� �߻��� ���
	}
	reverse(sum.begin(), sum.end()); //���ڿ��� �Ųٷ� �Ͽ� ���� �ڸ����� �� �ڷ� ����

	return sum;
}

string c[101][101];
int main()
{
	int n, m;
	cin >>n >>m;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= min(i, m); j++) //nCm�� ���ϴ� ���̹Ƿ� iCj���� j�� m�� �Ѿ �ʿ䰡 ���� (�Ľ�Į�� �ﰢ��)
			if(j == 0 || i == j)
				c[i][j] = "1";
			else
				c[i][j] = StrSum(c[i-1][j-1], c[i-1][j]); //iCj = (i-1)C(j-1) + (i-1)Cj

	cout <<c[n][m]; //nCm ���
}




/*
nCm�� ����ϴ� �����Դϴ�.
n�� ������ �۴ٸ� int��, ��¦ Ŀ�� long long �ڷ������� ����� �� �ְ�����,
���� 100������ �Ϲ����� �ڷ������δ� 20�ڸ��� �Ѵ� ū ���� �� ���� ��Ƴ� �� �����ϴ�.
ū ���� ���� �κ����� ������ ��� ����� ����� �� ������, ���ڿ��� �����غ��ҽ��ϴ�.
*/