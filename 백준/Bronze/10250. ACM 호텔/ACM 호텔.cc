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


bool fun(const string& s);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
   
    int t; cin >> t;
    while (t--)
    {
        int h, w, n; cin >> h >> w >> n;
        vector<pii> a; //{호수, 층}
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                a.emplace_back(j, i);

        sort(a.begin(), a.end());
        pii ans = a[n - 1];
        if (ans.first < 10) {
            cout << to_string(a[n - 1].second) + "0"+  to_string(a[n - 1].first) << '\n';
        }
        else 
            cout << to_string(a[n - 1].second) + to_string(a[n - 1].first) << '\n';
    }
}