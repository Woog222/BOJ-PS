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
const double PI = acos(-1.0);



ll sqrdist(ll dx, ll dy) {
    return dx * dx + dy * dy;
}

int main() {
    int t;  cin >> t;
    while (t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll d = sqrdist(x1 - x2, y1 - y2);
        ll rsum = (r1 + r2) * (r1 + r2);
        ll rm = (r1 - r2) * (r1 - r2);

        if (rsum < d) cout << 0 << el;
        else if (rsum == d) cout << 1 << el;
        else if (rm < d && d < rsum) cout << 2 << el;
        else if (rm == d) {
            if (rm == 0) cout << -1 << el;
            else cout << 1 << el;
        }
        else cout << 0 << el;
    }

}