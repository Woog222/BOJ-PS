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
    vi plus, minus;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num > 0) plus.push_back(num);
        else minus.push_back(num);
    }

    int a = 0, b = 0;
    int ans = INT_MAX;
    if (plus.size() >= 2) {
        if (ans > plus[0] + plus[1]) {
            ans = plus[0] + plus[1];
            a = plus[0];
            b = plus[1];
        }
    }
    if (minus.size() >= 2) {
        int idx = (int)minus.size() - 1;
        if ( ans > abs(minus[idx] + minus[idx - 1]) ) {
            ans = abs(minus[idx] + minus[idx - 1]);
            a = minus[idx - 1];
            b = minus[idx];
        }
    }

    for (int p : plus) {
        int idx = lower_bound(minus.begin(), minus.end(), -p) - minus.begin();

        if (idx < (int)minus.size() && ans > abs(p + minus[idx])) {
            ans = abs(p + minus[idx]);
            a = minus[idx]; b = p;
        }
        if (idx >0 ) {
            --idx;
            if (ans > abs(p +minus[idx])) {
                ans = abs(p + minus[idx]);
                a = minus[idx]; b = p;
            }
        }
    }

    cout << min(a, b) << " " <<max(a, b) << el;
}
