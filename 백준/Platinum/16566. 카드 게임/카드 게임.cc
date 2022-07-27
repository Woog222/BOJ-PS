#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int N, M, K;
int cards[4000002];
int p[4000002];

int Find(int u) {
    if (u == p[u]) return u;
    else return p[u] = Find(p[u]);
}

// u를 v로
void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    p[u] = v;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 0; i <= N; ++i) p[i] = i;
    for (int i = 0; i < M; ++i) cin >> cards[i];
    sort(cards , cards + M);

    while (K--) {
        int card; cin >> card;

        int lo = 0, hi = M;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (cards[mid] > card)
                hi = mid;
            else
                lo = mid + 1;
        }
        int idx = Find(hi);
        cout << cards[idx] << el;
        Union(idx, idx+1);
    }
}
