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

int a[15][15];

int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t; cin >> t;
   
    vector<pair<pii, int>> a(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }

    // x, y값 순으로 정렬
    sort(a.begin(), a.end());
    vi ans(t);

    for (int i = 0; i < t; ++i) {
        int betterThanMe = t-i;
        int x = a[i].first.first;
        int y = a[i].first.second;
        for (int j = i + 1; j < t; ++j) {
            int tempx = a[j].first.first;
            int tempy = a[j].first.second;
            if (tempx ==x || tempy <= y)
                betterThanMe--;
        }

        ans[a[i].second] = betterThanMe;
    }

    for (int t : ans)
        cout << t << " ";
    cout << '\n';


}