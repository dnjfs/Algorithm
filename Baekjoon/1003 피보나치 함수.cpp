//백준 1003 피보나치 함수

#include "iostream"

using namespace std;

int main()
{
	int T, N, fib[42] = {1, 0, 1};
	/*
	T: 테스트 케이스의 개수
	N: fibonacci() 함수를 호출할 때 보낼 인자
	fib[i]/fib[i+1]: fibonacci(i)를 호출했을 때, 0이 출력되는 횟수/1이 출력되는 횟수
	*/
	cin >>T;
	while(T--)
	{
		cin >>N;
		for(int i = 2; i <= N+1; i++)
			fib[i] = fib[i-1] + fib[i-2];

		cout <<fib[N] <<" " <<fib[N+1] <<endl;
	}
}




/*
fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 문제입니다.
DP를 이용하기 위해 배열에 0이 출력되는 횟수와 1이 출력되는 횟수를 저장하는 방식으로 해결하였습니다.
배열에 0과 1이 출력되는 횟수를 따로 저장했었는데 이 횟수도 피보나치 수열로 증가합니다.
fibonacci(i)에서 0이 출력되는 횟수는 fibonacci(i-1)에서 1이 출력되는 횟수와 같으므로 배열을 하나로 합쳐서 구현하였습니다.
*/