#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000007;

int n, w;
vector<pii> crime;
int dp[1001][1001];

int dist(pii a, pii b) {
    int r, c, x, y;
    tie(r, c) = a;
    tie(x, y) = b;

    return ((r > x) ? (r - x) : x - r) + ((c > y) ? c - y : y - c);
}

int fun(int last_a, int last_b) 
{
    int now = max(last_a, last_b) + 1;
    if (now > w)
        return 0;

    int& ret = dp[last_a][last_b];
    if (ret != -1)
        return ret;

    int dist_a = dist( crime[now], (last_a == 0) ? pii{1, 1} : crime[last_a] );
    int dist_b = dist( crime[now], (last_b == 0) ? pii{n, n} : crime[last_b] );
    
    ret = min(dist_a + fun(now, last_b), dist_b + fun(last_a, now));
    return ret;
}

void print_trace(int last_a, int last_b) 
{
    int now = max(last_a, last_b) + 1;
    if (now > w) return;
    int dist_a = dist(crime[now], (last_a == 0) ? pii{ 1, 1 } : crime[last_a]);
    int dist_b = dist(crime[now], (last_b == 0) ? pii{ n, n } : crime[last_b]);
    // a go to now
    if (dist_a + dp[now][last_b] <= dist_b + dp[last_a][now]) {
        cout << 1 << '\n';
        print_trace(now, last_b);
    }
    else {
        cout << 2 << '\n';
        print_trace(last_a, now);
    }
}



int main()
{   
    cin >> n >> w;
    crime.emplace_back(1, 1); // idx = 0
    for (int i = 1; i <= w; ++i) {
        int r, c; cin >> r >> c;
        crime.emplace_back(r, c);
    }

    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0) << endl;
    print_trace(0, 0);
}