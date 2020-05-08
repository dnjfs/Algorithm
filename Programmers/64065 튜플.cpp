//2019 카카오 개발자 겨울 인턴십
//문제2 튜플

#include <string>
#include <vector>
#include "algorithm"

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    bool table[100001] ={ false }; //해당 숫자가 나타났는지 확인
    vector<vector<int>> tuple; //이차원 배열로 집합 구분

    for (int i = 1; i < s.length()-1; i++)
    {
        vector<int> t; //집합
        int n = 0; //집합의 원소
        if (s[i] == '{') //집합 시작
        {
            while (s[++i] != '}') //집합이 끝날 때까지 반복
            {
                if (s[i] == ',') //원소 구분
                {
                    t.push_back(n);
                    n = 0;
                }
                else
                {
                    n *= 10;
                    n += s[i] - '0'; //문자를 숫자로 변환
                }
            }
            t.push_back(n); //맨 마지막 원소는 ','를 만날 수 없으므로 꼭 추가
            tuple.push_back(t); //집합 추가
        }
    }

    sort(tuple.begin(), tuple.end(), [](vector<int> a, vector<int> b) {
        return a.size() < b.size();
    }); //각 집합의 원소의 개수를 기준으로 오름차순 정렬

    for (auto t: tuple) //원소의 개수가 작은 집합부터 탐색
        for (auto n: t)
            if (!table[n]) //아직 나오지 않은 원소면
            {
                answer.push_back(n); //튜플의 원소로 추가
                table[n] = true;
            }

    return answer;
}
