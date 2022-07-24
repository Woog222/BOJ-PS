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
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<ll> plus, minus;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num > 0) plus.push_back(num);
        else minus.push_back(num);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    vector<ll> vals(3);
    ll ans = LLONG_MAX;
    if (plus.size() >= 3) {
        if (ans > plus[0] + plus[1] + plus[2]) {
            ans = plus[0] + plus[1] + plus[2];
            vals[0] = plus[0];
            vals[1] = plus[1];
            vals[2] = plus[2];
        }
    }
    if (minus.size() >= 3) {
        int idx = (int)minus.size() - 1;
        if ( ans > abs(minus[idx] + minus[idx - 1] + minus[idx-2])) {
            ans = abs(minus[idx] + minus[idx - 1] + minus[idx-2]);
            vals[0] = minus[idx - 2];
            vals[1] = minus[idx - 1];
            vals[2] = minus[idx];
        }
    }

    n = plus.size();
    int m = minus.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int p = plus[i] + plus[j];
            int idx = lower_bound(minus.begin(), minus.end(), -p) - minus.begin();
            if (idx < m && abs(p + minus[idx]) < ans) {
                ans = abs(p + minus[idx]);
                vals[0] = minus[idx];
                vals[1] = plus[i];
                vals[2] = plus[j];
            }
            if (idx > 0 && abs(p + minus[idx - 1]) < ans) {
                ans = abs(p + minus[idx-1]);
                vals[0] = minus[idx-1];
                vals[1] = plus[i];
                vals[2] = plus[j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int p = minus[i] + minus[j];
            int idx = lower_bound(plus.begin(), plus.end(), -p) - plus.begin();
            if (idx < n && abs(p + plus[idx]) < ans) {
                ans = abs(p + plus[idx]);
                vals[0] = plus[idx];
                vals[1] = minus[i];
                vals[2] = minus[j];
            }
            if (idx > 0 && abs(p + plus[idx - 1]) < ans) {
                ans = abs(p + plus[idx - 1]);
                vals[0] = plus[idx - 1];
                vals[1] = minus[i];
                vals[2] = minus[j];
            }
        }
    }

    sort(vals.begin(), vals.end());
    for (int i : vals)
        cout << i << " ";
    cout << el;
}