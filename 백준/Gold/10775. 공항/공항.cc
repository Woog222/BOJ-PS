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
typedef vector <ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;


int G, P;
int p[100001];

int Find(int u) {
    if (u == p[u]) return u;
    else return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    p[Find(u)] = p[Find(v)];
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> G >> P;
    for (int i = 1; i <= G; ++i) p[i] = i;

    vi plane(P); 
    for (int i = 0; i < P; ++i) cin >> plane[i];
    int ans = 0;
    for (int i = 0; i < P; ++i) {
        int g = plane[i];
        g = Find(g);
        if (g == 0) break;
        ans++; 
        Union(g, g - 1);
    }
    cout << ans << el;
}