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
#define el '\n';
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int N;
int ti[1001]; //1~N
vi adj[1001]; // init
int indeg[1001]; // init
int start[1001]; // init

void init();
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
    {
        int k; cin >> N >> k;
        init();
        for (int i = 1; i <= N; ++i) cin >> ti[i];
        while (k--) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            indeg[b]++;
        }
        int goal; cin >> goal;

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int here = q.front(); q.pop();

            for (int next : adj[here]) {
                indeg[next]--;
                start[next] = max(start[next], start[here] + ti[here]);
                if (indeg[next] == 0)
                    q.push(next);
            }
        }

        cout << start[goal] + ti[goal] << el;
    }
}


void init() {
    for (int i = 1; i <= N; ++i)
        vi().swap(adj[i]);
    memset(indeg, 0, sizeof(indeg));
    memset(start, 0, sizeof(start));
}