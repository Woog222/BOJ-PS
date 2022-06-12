#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;

int n, m;
int graph[20][20];
int dp[401][20][20]; // [length][from][to]

void cal(int len, int right_after, int right_before)
{
    for (int start = 0; start < n; ++start) {
        for (int end = 0; end < n; ++end) 
        {
            if (graph[start][right_after] == -1 ||
                graph[right_before][end] == -1)
                continue;
            if (graph[start][right_after] ==
                graph[right_before][end]) {
                dp[len][start][end] = 1;
            }
        }
    }
}

int main()
{   
    memset(graph, -1, sizeof(graph));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to; char val;
        cin >> from >> to >> val;
        val = val - 'a';
        graph[from][to] = (int)val;
        graph[to][from] = (int)val;
    }


    // l : 1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] >= 0)
                dp[1][i][j] = 1;               
        }
    }
    // l : 2
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
        {
            if (dp[1][i][j] == -1) continue;
            for (int next = 0; next < n; ++next) {
                if (graph[j][next] != -1 && (graph[j][next] == graph[i][j]) )
                    dp[2][i][next] = 1;
            }
        }
    }

    for (int L = 3; L <= 400; ++L) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
            {
                if (dp[L - 2][i][j] == 0) continue;
                cal(L, i, j);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= 400; ++i) {
        if (dp[i][0][1] > 0)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}
