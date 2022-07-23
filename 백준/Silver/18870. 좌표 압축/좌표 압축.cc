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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;


int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    int val = 0, cur = a[0].first;
    for (int i = 0; i < n; ++i) {
        if (cur == a[i].first) {
            a[i].first = val;
        }
        else {
            cur = a[i].first;
            a[i].first = ++val;
        }
    }
       

    sort(a.begin(), a.end(), [](const pii& a, const pii& b) {
        return a.second < b.second;
        }
    );

    for (pii& p : a)
        cout << p.first << " ";
    cout << '\n';
}