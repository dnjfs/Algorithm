//ACM-ICPC 2015 예선 F번 파일 합치기
//백준 11066

#include "iostream"

using namespace std;

int main()
{
	int T; //테스트 케이스
	cin >>T;
	while (T--)
	{
		int K; //소설을 구성하는 장의 수
		long long file[501][501] = {0}, sum[501] = {0}; //file[i][j]: i장부터 j장까지 합치는데 필요한 최소비용, sum[i]: 1~i장의 파일의 크기 합
		cin >>K;
		for (int i = 1; i <= K; i++)
		{
			cin >>sum[i];
			sum[i] += sum[i-1];
		}

		for (int j = 2; j <= K; j++) //합칠 파일의 끝범위 지정
			for (int i = j-1; i > 0; i--) //합칠 파일의 시작범위 지정
			{
				long long min = 9223372036854775807; //long long int의 MAX값
				for (int l = i; l < j; l++) //합칠 두 파일을 l로 구분
				{
					long long temp = file[i][l] + file[l+1][j] + sum[j] - sum[i-1]; //i~l과 (l+1)~j장이 합쳐진 파일을 합칠 때 드는 비용에 i~j장의 파일의 크기를 더함
					if (temp < min)
						min = temp;
				}
				file[i][j] = min; //i~j장을 합치는데 필요한 최소비용을 저장
			}

		cout <<file[1][K] <<endl; //1장부터 K장까지 합치는데 필요한 최소비용
	}
}



/*
소설의 각 장의 파일 크기가 주어질 때, 연속되게 두 파일을 합치며 모든 파일을 하나로 만드는데 필요한 최소비용을 구하는 문제입니다.
이차원 배열을 이용하여 행은 합친 파일의 시작범위, 열은 합친 파일의 끝범위로 배열에 최소비용이 저장됩니다.
DP를 이용하여 합칠 파일의 범위를 2장부터 K장까지 늘려가 모든 파일을 합치는데 필요한 최소비용을 구하였습니다.

file[i][l], file[l+1][j]는 각각 i~l장, (l+1)~j장을 합치는데 필요한 최소비용이 저장되어 있으며,
sum[j] - sum[i-1]을 더해준 이유는 두 파일을 하나의 파일로 합치는데 필요한 비용은 각 파일의 크기를 더한 것과 같기 때문입니다.
i~l장으로 합쳐진 파일 크기는 sum[l]-sum[i-1]이고, (l+1)~j장으로 합쳐진 파일 크기는 sum[j]-sum[l]이라서,
sum[l]-sum[i-1] + sum[j]-sum[l] = sum[j] - sum[i-1]이란 식이 나오게 됩니다.
따라서 i~j장의 파일을 합치는데 드는 비용은 i~l장과 (l+1)~j장을 만드는데 필요한 비용에
i~l장과 (l+1)~j장, 즉 i~j장의 파일의 크기를 더한 것과 같습니다.

for문에서 j는 K만큼, i는 j만큼, l은 i~j만큼 반복하므로 한 테스트 케이스당 시간복잡도는 O(K^3)입니다.
*/