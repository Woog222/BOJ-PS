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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const double PI = acos(-1.0);

int makeFail(const string& s);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, makeFail(s.substr(i, n - i)));
    }

    cout << ans << '\n';
}

int makeFail(const string& s)
{
    int n = s.length();
    vi ret = vi(n, 0);
    
    int ans = 0;
    int matched = 0;
    for (int i = 1; i < n; ++i) {
        while (matched > 0 && s[i] != s[matched])
            matched = ret[matched - 1];

        if (s[i] == s[matched]) {
            ret[i] = ++matched;
        }
        else {
            ret[i] = 0;
        }
        ans = max(ans, matched);
    }

    return ans;
}
