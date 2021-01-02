//1339 단어 수학

#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int weight[26] = {0}; //알파벳 대문자의 가중치 (알파벳의 개수는 26개)
	int N, sum = 0; //단어의 개수, 단어의 최대 합

	cin >>N;
	for(int i = 0; i < N; i++)
	{
		string str;
		cin >>str;

		int pos = 1; //알파벳 대문자의 자릿수
		for(int j = str.size()-1; j >= 0; j--)
		{
			weight[str[j]-'A'] += pos; //자릿수만큼 가중치 증가
			pos *= 10; //자릿수 증가
		}
	}

	sort(weight, weight+26, greater<int>()); //내림차순으로 정렬
	for(int i = 0; i < 10; i++)
		sum += weight[i] * (9-i); //가중치가 가장 높은 알파벳 대문자부터 가장 큰 수 대입

	cout <<sum;
}




/*
알파벳 대문자로 이루어진 N개의 단어가 주어질 때 각 알파벳 대문자에 0~9의 수를 대입하여 합이 최대가 되도록 만드는 문제입니다.
단어에 나온 알파벳 대문자의 자릿수를 배열에 저장하여 내림차순 정렬 후,
가중치가 가장 높은 알파벳 대문자부터 9, 8, 7...을 대입하면 간단하게 해결할 수 있습니다.
알파벳의 개수를 생각을 못해 배열의 크기를 10으로 잡아 런타임 에러가 계속 났는데 앞으로 배열 인덱스 참조에 주의해야겠습니다.
*/