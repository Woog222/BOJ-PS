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
const ll INF = numeric_limits<ll>::min();
const int MAX = 1000;

int N;
int adj[MAX][MAX], start[MAX];

void dfs(int here) {
    
    for (int there = start[here]; there < N; ++there) {
        start[here] = there;
        if (adj[here][there]) {
            adj[here][there] = 0;
            dfs(there);
        }
    }

    cout << here + 1 << " ";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N;
    memset(adj, -1, sizeof(adj));
    cout << N * N + 1 << el;
    dfs(0);
}
