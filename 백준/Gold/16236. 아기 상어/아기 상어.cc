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
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;




int dr[] = { -1, 0, 0, 1 };
int dc[] = {  0,-1, 1, 0 };

int N;
int grid[20][20];
int dist[20][20];

inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int main()
{
    cin >> N;
    pii cur;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 9) {
                cur = make_pair(i, j);
                grid[i][j] = 0;
            }
                
        }
    }

    queue<pii> q;
    int ans = 0;
    int level = 2;
    int eat = 0;
    while (true) 
    {
        if (eat == level) {
            eat = 0;
            level++;
        }
        
        // reset
        queue<pii>().swap(q);
        memset(dist, -1, sizeof(dist));


        //bfs
        dist[cur.first][cur.second] = 0;
        q.push(cur);

        int least_dist = INF;
        vector<pii> locs;
        while (!q.empty())
        {
            int r, c;
            tie(r, c) = q.front(); q.pop();

            if (least_dist != INF && least_dist < dist[r][c]) break;

            //success to eat
            if (grid[r][c] > 0 && grid[r][c] < level) 
            {
                least_dist = min(least_dist, dist[r][c]);
                locs.emplace_back(r, c);
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (!valid(nr, nc) || grid[nr][nc] > level || dist[nr][nc] != -1 )
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr, nc);
            }

        } // bfs while

        if (locs.size() == 0 )
            break;
        else {
            ++eat;
            // cur find by sorting
            sort(locs.begin(), locs.end());
            cur = locs.front();

            // after each
            grid[cur.first][cur.second] = 0;
            ans += dist[cur.first][cur.second];
        }
    }

    cout << ans << endl;
}
