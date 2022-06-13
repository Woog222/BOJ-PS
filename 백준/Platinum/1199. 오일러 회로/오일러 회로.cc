#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int n;
int graph[1001][1001];
int start[1001];


void dfs(vi& ans, int now)
{
    for (int next = start[now]; next <= n; ++next) 
    {
        start[now] = next;
        while (graph[now][next] > 0) {
            graph[now][next]--;
            graph[next][now]--;
            dfs(ans, next);
        }
    }

    ans.push_back(now);
}


int main()
{
    cout.tie(nullptr);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }
    vi ans;
    for (int i = 1; i <= n; ++i) {
        start[i] = 1;
    }
    dfs(ans, 1);

    if (ans.front() != ans.back()) {
        cout << -1 << endl;
        return 0;
    }

    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}