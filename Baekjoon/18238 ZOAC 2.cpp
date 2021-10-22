//백준 18238 ZOAC 2

#include "iostream"
#include "string"

using namespace std;

int main()
{
	string str;
	cin >>str;

	int pos = 'A', ans = 0; //현재 화살표의 위치, 원판을 돌린 시간
	for(char c: str)
	{
		//원판이 Z-A 사이를 지나지 않는 경우와 지나는 경우를 나눠서 더 적게 돌리는 쪽을 선택함
		//Z-A를 지나는 경우엔 현재 화살표 위치가 출력할 문자보다 더 큰 경우와 작은 경우를 나눔
		ans += min(abs(c-pos), c<pos ? 'Z'-pos + c-'A' + 1 : 'Z'-c + pos-'A' + 1); //시간 소요
		pos = c; //화살표의 위치를 현재 출력한 문자로 옮김
	}

	cout <<ans;
}




/*
입력받은 문자열을 원판을 돌려 순서대로 출력하는데 걸리는 시간을 최소로 만드는 문제입니다.
다음 출력할 문자가 무엇이든 상관없이 현재 출력할 문자를 최대한 빠르게 출력하여 해결할 수 있습니다.
원판을 돌려 문자를 찾으므로 화살표가 Z-A 사이를 지나는지 지나지 않는지 상황을 나누어 해결하였습니다.
*/