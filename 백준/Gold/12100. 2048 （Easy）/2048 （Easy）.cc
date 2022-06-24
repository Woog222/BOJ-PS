#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

// 우 하 좌 상
int dr[] = { 0, 1, 0,-1 };
int dc[] = { 1, 0,-1, 0 };


int N;
inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

vector<vi> move(const vector<vi>& grid, int dir);
int fun(const vvi& grid, int nth);
int main()
{
    cin >> N;
    vector<vi>  grid(N, vi(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    
    cout << fun(grid, 0) << endl;

  
    

    
}

int fun(const vvi& grid, int nth) 
{
    if (nth == 5) 
    {
        int ret = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ret = max(ret, grid[i][j]);
            }
        }
        return ret;
    }

    int ret = 0;
    for (int dir = 0; dir < 4; ++dir) {
        ret = max(ret, fun(move(grid, dir), nth + 1));
    }

    return ret;
}

vvi move(const vector<vi>& grid, int dir)
{
    vvi ret = grid;
    vector<vector<bool>> merged(N, vector<bool>(N, false));

    // 우
    if (dir == 0)
    {
        for (int i = 0; i < N; ++i) {
            for (int j = N - 2; j >= 0; --j)
            {
                if (ret[i][j] == 0) continue;


                int nr = i + dr[dir];
                int nc = j + dc[dir];
                while (valid(nr, nc) && ret[nr][nc] == 0) {
                    nr += dr[dir];
                    nc += dc[dir];
                }

                // 끝 도착 + 끝에도 아무도 없음
                // 끝으로 그냥 이동시킴
                if (!valid(nr, nc)) {

                    nr -= dr[dir];
                    nc -= dc[dir];
                    ret[nr][nc] = ret[i][j];
                    ret[i][j] = 0;
                }
                // 이미 합쳐진 곳 or 다름 (not merge)
                else if (merged[nr][nc] || ret[nr][nc] != ret[i][j]) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    if (i != nr || j != nc) { // 이동하긴 함

                        ret[nr][nc] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
                // merge

                else if (ret[nr][nc] == ret[i][j]) {

                    ret[nr][nc] *= 2;
                    ret[i][j] = 0;
                    merged[nr][nc] = true;
                }

            }
        } 
    }

    // down
    else if (dir == 1)
    {
        for (int j = 0; j < N; ++j) {
            for (int i = N-2; i >= 0; --i )
            {
                if (ret[i][j] == 0) continue;


                int nr = i + dr[dir];
                int nc = j + dc[dir];
                while (valid(nr, nc) && ret[nr][nc] == 0) {
                    nr += dr[dir];
                    nc += dc[dir];
                }

                // 끝 도착 + 끝에도 아무도 없음
                // 끝으로 그냥 이동시킴
                if (!valid(nr, nc)) {

                    nr -= dr[dir];
                    nc -= dc[dir];
                    ret[nr][nc] = ret[i][j];
                    ret[i][j] = 0;
                }
                // 이미 합쳐진 곳 or 다름 (not merge)
                else if (merged[nr][nc] || ret[nr][nc] != ret[i][j]) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    if (i != nr || j != nc) { // 이동하긴 함

                        ret[nr][nc] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
                // merge

                else if (ret[nr][nc] == ret[i][j]) {

                    ret[nr][nc] *= 2;
                    ret[i][j] = 0;
                    merged[nr][nc] = true;
                }

            }
        }
    }
    // left
    else if (dir == 2)
    {
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <N; ++j)
            {
                if (ret[i][j] == 0) continue;


                int nr = i + dr[dir];
                int nc = j + dc[dir];
                while (valid(nr, nc) && ret[nr][nc] == 0) {
                    nr += dr[dir];
                    nc += dc[dir];
                }

                // 끝 도착 + 끝에도 아무도 없음
                // 끝으로 그냥 이동시킴
                if (!valid(nr, nc)) {

                    nr -= dr[dir];
                    nc -= dc[dir];
                    ret[nr][nc] = ret[i][j];
                    ret[i][j] = 0;
                }
                // 이미 합쳐진 곳 or 다름 (not merge)
                else if (merged[nr][nc] || ret[nr][nc] != ret[i][j]) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    if (i != nr || j != nc) { // 이동하긴 함

                        ret[nr][nc] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
                // merge

                else if (ret[nr][nc] == ret[i][j]) {

                    ret[nr][nc] *= 2;
                    ret[i][j] = 0;
                    merged[nr][nc] = true;
                }

            }
        }
    }
    //UP
    else if (dir == 3)
    {
        for (int j = 0; j < N; ++j) {
            for (int i = 1; i <N; ++i)
            {
                if (ret[i][j] == 0) continue;


                int nr = i + dr[dir];
                int nc = j + dc[dir];
                while (valid(nr, nc) && ret[nr][nc] == 0) {
                    nr += dr[dir];
                    nc += dc[dir];
                }

                // 끝 도착 + 끝에도 아무도 없음
                // 끝으로 그냥 이동시킴
                if (!valid(nr, nc)) {

                    nr -= dr[dir];
                    nc -= dc[dir];
                    ret[nr][nc] = ret[i][j];
                    ret[i][j] = 0;
                }
                // 이미 합쳐진 곳 or 다름 (not merge)
                else if (merged[nr][nc] || ret[nr][nc] != ret[i][j]) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    if (i != nr || j != nc) { // 이동하긴 함

                        ret[nr][nc] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
                // merge

                else if (ret[nr][nc] == ret[i][j]) {

                    ret[nr][nc] *= 2;
                    ret[i][j] = 0;
                    merged[nr][nc] = true;
                }

            }
        }
    }


    return ret;
}