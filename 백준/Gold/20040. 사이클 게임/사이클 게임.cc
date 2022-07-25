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

int p[500000];
int n, m;

int Find(int u);
void Union(int u, int v);
int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) p[i] = i;
    
    bool findAnswer = false;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        if (!findAnswer && Find(a) == Find(b)) {
            cout << i << el; 
            findAnswer = true;
        }
        Union(a, b);
    }
    if (!findAnswer)
        cout << 0 << el;
}

int Find(int u) {
    if (p[u] == u) return u;
    else return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    if (p[u] == p[v]) return;
    int pu = p[u];
    int pv = p[v];
    p[pu] = pv; // u전체를 -> v아래로
    return;
}