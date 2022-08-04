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
const int MAX = 200001;

int adj[500][500];
int n;
vector<string> ans;

void dfs(int here) {

    for (int i=0; i<=n; ++i) {
        if (adj[here][i]) {
            adj[here][i] = adj[i][here] = 0;
            dfs(i);
        }
    }
    ans.push_back(string("a") + to_string(here));
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) adj[i][j] = 1;
        }
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    for (auto& s : ans) cout << s << " ";
    cout << el;
}