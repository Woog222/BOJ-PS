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

int v, e;
vi adj[10001];
int order[10001]; // 방문순서 0~
bool is_cut[10001];
int cnt;

// 방문할 간선조차 없으면 자신 리턴 (루트도 자신리턴)
// 방문할 간선 있고 자식이면 거기서 방문한 제일 높은 곳들중에서 높은거 리턴
// 방문할 간선은 있지만 이미 갔던 곳이라도 갱신 (부모는 빼고)

int dfs(int here, bool is_root) // 올라갈 수 있는 가장 높은 곳 리턴 (루트는 그냥 자신 리턴)
{
    order[here] = ++cnt;

    // 루트 자식 판별용
    int child_cnt = 0;
    int ret = order[here];

    for (auto next : adj[here]) 
    {
        if (order[next] == 0) {
            child_cnt++;

            int sub_connected_min = dfs(next, false);
            if (!is_root && sub_connected_min >= order[here])
                is_cut[here] = true;

            ret = min(ret, sub_connected_min);
        }
        // 연결돼있지만 이미 방문한 곳이다.
        else {
            ret = min(ret, order[next]);
        }
    }

    if (is_root) {
        is_cut[here] = (child_cnt >= 2);
    }
    return ret;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> v >> e;
    while (e--) {
        int  from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i <= v; ++i) {
        if (order[i] == 0)
            dfs(i, true);
    }

    vi ans;
    for (int i = 1; i <= v; ++i) {
        if (is_cut[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
