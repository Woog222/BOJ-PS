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


vi a[5];
vector<pii> b;
int main() {
    int k; cin >> k;

    for (int i = 0; i < 6; ++i) {
        int dir; int len; cin >> dir >> len;
        a[dir].push_back(len);
        b.emplace_back(dir, len);
    }

    int m = (a[1].size() == 1) ? a[1][0] : a[2][0];
    int n = (a[3].size() == 1) ? a[3][0] : a[4][0];

    int x, y;
    for (int i = 0; i < 6; ++i) {
        if (b[(i + 1) % 6].first == b[(i + 5) % 6].first) {
            if (b[i].first == 1 || b[i].first == 2) {
                x = b[i].second;
            }
            else {
                y = b[i].second;
            }
        }
    }
    cout << (n * m - x * y) * k << el;
}
