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

int a[101];
int d[10001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[0] = 0;
    for (int i = 1; i <= m; ++i)
        d[i] = INF;

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (j - a[i] >= 0) {
                d[j] = min(d[j], d[j - a[i]] + 1);
            }
        }

    }

    if (d[m] == INF)
        cout << -1 << endl;
    else
        cout << d[m] << el;
    return 0;
}