//ACM-ICPC 2018 예선 B번 Farm
//백준 16283

#include "iostream"

using namespace std;

int main()
{
	int a, b, n, w, s;
	/*
		a: 양이 하루에 먹는 사료
		b: 염소가 하루에 먹는 사료
		n: 양과 염소의 수
		w: 하루 동안 소비한 사료의 양
		s: 해가 되는 양의 수
	*/
	bool find = false; //가능한 해가 존재

	cin >>a >>b >>n >>w;

	for(int i = 1; i < n; i++) //양과 염소는 각각 1마리 이상
		if(w == (a*i + b*(n-i))) //w = a*sheep + b*goat 방정식
		{
			if(find) //가능한 해가 존재한 상태에서 또 다른 해가 있는 경우
			{
				cout <<-1 <<endl;
				return 0;
			}
			find = true; s = i; //해 저장
		}

	if(find) //가능한 해가 1개만 있는 경우
		cout <<s <<" " <<n-s <<endl;
	else //가능한 해가 없는 경우
		cout <<-1 <<endl;
}
