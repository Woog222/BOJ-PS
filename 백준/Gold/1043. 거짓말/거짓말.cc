#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;


vi adj[51];
vi party[50];
int know[51];
int n, m;

int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n >> m;
    queue<int> q;
    memset(know, -1, sizeof(know));

    // knower
    int k; cin >> k;
    while (k--) {
        int num; cin >> num;
        q.push(num);
        know[num] = 1;
    }
    // party members
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        while (k--) {
            int num; cin >> num;
            party[i].push_back(num);
        }

        for (int j = 1; j < (int)party[i].size(); ++j) {
            int a = party[i][j];
            int b = party[i][j - 1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    //bfs
    while (!q.empty())
    {
        int here = q.front(); q.pop();

        for (int next : adj[here]) {
            if (know[next] == -1) {
                know[next] = 1;
                q.push(next);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        bool canLie = true;
        for (int member : party[i]) {
            if (know[member] == 1) {
                canLie = false;
                break;
            }
        }
        if (canLie)
            ans++;
    }
    cout << ans << '\n';
}
