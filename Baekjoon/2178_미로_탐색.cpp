//백준 2178

#include "iostream"
#include "queue"
#include "cstring"

using namespace std;

int BFS(string miro[], int n, int m) //너비우선탐색
{
    int r, c, cnt[100][100]; //r은 현재 행, c는 현재 열, cnt[i][j]는 시작점부터 i행j열까지의 길이
    queue<pair<int, int>> q;

    memset(cnt, 0, sizeof(cnt)); //cnt[i][j]가 0일 경우 해당 칸을 방문하지 않은 상태

    q.push(make_pair(0, 0)); //0행0열부터 시작 (1, 1)
    cnt[0][0] = 1; //0행0열 방문

    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        if (r != 0)
            if (miro[r-1][c]=='1' && !cnt[r-1][c]) //up, 이동할 수 있는 칸이면서 방문하지 않은 경우
            {
                q.push(make_pair(r-1, c));
                cnt[r-1][c] = cnt[r][c] + 1;
            }
        if (c != 0)
            if (miro[r][c-1]=='1' && !cnt[r][c-1]) //left
            {
                q.push(make_pair(r, c-1));
                cnt[r][c-1] = cnt[r][c] + 1;
            }
        if (r != n-1)
            if (miro[r+1][c]=='1' && !cnt[r+1][c]) //down
            {
                q.push(make_pair(r+1, c));
                cnt[r+1][c] = cnt[r][c] + 1;
            }
        if (c != m-1)
            if (miro[r][c+1]=='1' && !cnt[r][c+1]) //right
            {
                q.push(make_pair(r, c+1));
                cnt[r][c+1] = cnt[r][c] + 1;
            }
    }
    return cnt[n-1][m-1]; //(N, M) 값을 반환
}

int main()
{
    int N, M; //미로의 크기 N행, M열
    string miro[100]; //배열로 표현된 미로
    cin >>N >>M;
    for (int i = 0; i < N; i++)
        cin >>miro[i];

    cout <<BFS(miro, N, M);
}
