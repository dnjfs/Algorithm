//백준 18870 좌표 압축
//solved.ac CLASS 3

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int main()
{
	int N; //좌표의 개수
	cin >>N;

	vector<int> X(N), S; //좌표, 서로 다른 좌표
	for(int i = 0; i < N; i++)
		cin >>X[i];
	S = X; //배열 복사
	sort(S.begin(), S.end()); //오름차순 정렬 후
	S.erase(unique(S.begin(), S.end()), S.end()); //중복된 원소 제거

	for(int i = 0; i < N; i++)
		cout <<lower_bound(S.begin(), S.end(), X[i])-S.begin() <<" "; //X[i]의 압축된 좌표 출력
}




/*
수직선 위의 N개의 좌표를 압축하여 압축을 적용한 좌표를 출력하는 문제입니다.
좌표를 입력받아 새로운 배열에 깊은 복사를 해주어 정렬을 해주고 중복되는 원소를 제거하면,
각 좌표의 압축된 좌표는 해당 배열의 인덱스로 나타낼 수 있습니다.
S[] 배열에서 입력받은 좌표가 저장된 인덱스를 출력해주는데 완전 탐색을 하면 O(N^2)의 시간복잡도로 시간 초과가 발생합니다.
이진 탐색을 이용하면 O(N logN)의 시간복잡도로 빠르게 압축된 좌표를 찾을 수 있습니다.
lower_bound() 함수는 배열에서 이진 탐색으로 찾은 원소의 주소값을 반환하기에 S[] 배열이 시작되는 주소값을 빼주어 인덱스를 계산할 수 있습니다.
*/