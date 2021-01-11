//백준 1991 트리 순회

#include "iostream"
#include "vector"

//매크로 선언 (가독성을 위해 \ 기호로 개행)
#define LT(func)\
	if(v[t][0] != '.')\
		func(v, v[t][0]-A); //왼쪽 자식 노드로 탐색
#define RT(func)\
	if(v[t][1] != '.')\
		func(v, v[t][1]-A); //오른쪽 자식 노드로 탐색
#define PRINT cout <<(char)(A+t); //출력

using namespace std;

const int A = 'A'; //'A'를 정수형 상수로 선언
void preorder_traversal(vector<vector<char>> v, int t) //전위 순회
{
	PRINT	LT(preorder_traversal)	RT(preorder_traversal) //루트, 왼쪽, 오른쪽 순으로 방문
}
void inorder_traversal(vector<vector<char>> v, int t) //중위 순회
{
	LT(inorder_traversal)	PRINT	RT(inorder_traversal) //왼쪽, 루트, 오른쪽 순으로 방문
}
void postorder_traversal(vector<vector<char>> v, int t) //후위 순회
{
	LT(postorder_traversal)	RT(postorder_traversal)	PRINT //왼쪽, 오른쪽, 루트 순으로 방문
}

int main()
{
	int N; //노드의 개수
	vector<vector<char>> tree(26); //이진 트리 (노드의 개수가 최대 26개)
	cin >>N;

	for(int i = 0; i < N; i++)
	{
		char c1, c2, c3; //노드, 왼쪽 자식, 오른쪽 자식
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
이진 트리를 입력받아 전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 문제입니다.
익숙한 문제라 코드를 더 간결하게 만들고 싶어 매크로를 이용해보았습니다.
반복된 코드가 나올 때 매크로를 이용하면 코드도 간결해지고 가독성도 좋아보여 자주 이용할 것 같습니다.
*/