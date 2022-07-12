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
#include <set>
#include <iterator>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int N, M;
int grid[1000][1000];
int group[1000][1000];
int groupNum;
vi groupSize;


inline bool valid(int r, int c);
int bfs(pii st);
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    memset(group, -1, sizeof(group));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) 
        {
            if (grid[i][j] == 1 && group[i][j] == -1) {
                groupSize.push_back(bfs(pii{ i,j }));
                groupNum++;
            }
        }
    }

    int ans = *max_element(groupSize.begin(), groupSize.end());

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) 
        {
            if (grid[i][j] != 0) continue;
            
            vi adjGroup;
            for (int k = 0; k < 4; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (!valid(nr, nc) || group[nr][nc]==-1) continue;
                adjGroup.push_back(group[nr][nc]);
            }

            sort(adjGroup.begin(), adjGroup.end());
            adjGroup.erase(unique(adjGroup.begin(), adjGroup.end()), adjGroup.end());

            int temp = 0;
            for (int g : adjGroup)
                temp += groupSize[g];

            ans = max(ans, temp+1);
        }
    }

    cout << ans << endl;
}


inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int bfs( pii st)
{
    int ret = 0;
    queue<pii> q;
    q.push(st);
    group[st.first][st.second] = groupNum;

    while (!q.empty())
    {
        int r, c; tie(r, c) = q.front(); q.pop();
        ret++;

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (valid(nr, nc) && grid[nr][nc] == 1 && group[nr][nc] == -1)
            {
                group[nr][nc] = groupNum;
                q.emplace(nr, nc);
            }
        }
    }

    return ret;
}