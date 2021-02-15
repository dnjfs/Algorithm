#include "iostream"
using namespace std;

int ans[1500050];
int main()
{
	int N, T, P, m = 0;
	cin >>N;

	for(int i = 0; i < N; i++)
	{
		cin >>T >>P;

		m = max(m, ans[i]);
		ans[i+T] = max(ans[i+T], m+P);
	}

	cout <<max(m, ans[N]);
}