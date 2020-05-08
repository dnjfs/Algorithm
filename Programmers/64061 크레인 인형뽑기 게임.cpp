//2019 카카오 개발자 겨울 인턴십 코딩 테스트
//문제1 크레인 인형뽑기 게임

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0; //정답
    vector<int> arr; //바구니

    for (auto m: moves)
    {
        int doll = 0; //크레인으로 뽑은 인형
        m--; //벡터 인덱스 맞추기(0부터 시작)
        for (int i = 0; i < board.size(); i++)
            if (board[i][m] != 0)
            {
                doll = board[i][m];
                board[i][m] = 0;
                break;
            }

        if (!doll) //인형이 없는 곳
            continue;

        if (arr.empty()) //바구니에 인형 없음
            arr.push_back(doll);
        else if (arr.back() == doll) //같은 인형
        {
            arr.pop_back();
            answer += 2;
        }
        else
            arr.push_back(doll);
    }

    return answer;
}
