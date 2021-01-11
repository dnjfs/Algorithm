//���� 1991 Ʈ�� ��ȸ

#include "iostream"
#include "vector"

//��ũ�� ���� (�������� ���� \ ��ȣ�� ����)
#define LT(func)\
	if(v[t][0] != '.')\
		func(v, v[t][0]-A); //���� �ڽ� ���� Ž��
#define RT(func)\
	if(v[t][1] != '.')\
		func(v, v[t][1]-A); //������ �ڽ� ���� Ž��
#define PRINT cout <<(char)(A+t); //���

using namespace std;

const int A = 'A'; //'A'�� ������ ����� ����
void preorder_traversal(vector<vector<char>> v, int t) //���� ��ȸ
{
	PRINT	LT(preorder_traversal)	RT(preorder_traversal) //��Ʈ, ����, ������ ������ �湮
}
void inorder_traversal(vector<vector<char>> v, int t) //���� ��ȸ
{
	LT(inorder_traversal)	PRINT	RT(inorder_traversal) //����, ��Ʈ, ������ ������ �湮
}
void postorder_traversal(vector<vector<char>> v, int t) //���� ��ȸ
{
	LT(postorder_traversal)	RT(postorder_traversal)	PRINT //����, ������, ��Ʈ ������ �湮
}

int main()
{
	int N; //����� ����
	vector<vector<char>> tree(26); //���� Ʈ�� (����� ������ �ִ� 26��)
	cin >>N;

	for(int i = 0; i < N; i++)
	{
		char c1, c2, c3; //���, ���� �ڽ�, ������ �ڽ�
		cin >>c1 >>c2 >>c3;
		tree[c1-A].push_back(c2);
		tree[c1-A].push_back(c3);
	}
	preorder_traversal(tree, 0);
	cout <<endl;
	inorder_traversal(tree, 0);
	cout <<endl;
	postorder_traversal(tree, 0);
}




/*
���� Ʈ���� �Է¹޾� ���� ��ȸ, ���� ��ȸ, ���� ��ȸ�� ����� ����ϴ� �����Դϴ�.
�ͼ��� ������ �ڵ带 �� �����ϰ� ����� �;� ��ũ�θ� �̿��غ��ҽ��ϴ�.
�ݺ��� �ڵ尡 ���� �� ��ũ�θ� �̿��ϸ� �ڵ嵵 ���������� �������� ���ƺ��� ���� �̿��� �� �����ϴ�.
*/