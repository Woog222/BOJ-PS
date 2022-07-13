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
const int MOD = 1000000007;



int main()
{
    int n; cin >> n;
    vector<pair<int, ll>> st;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int h; cin >> h;

        // 본인보다 작은거
        while (!st.empty() && st.back().first < h) {
            ans += st.back().second;
            st.pop_back();
        }
        // 같으면 합치고
        int cnt = 1;
        if (!st.empty() && st.back().first == h) {
            ans += st.back().second;
            cnt += st.back().second;
            st.pop_back();
        }
        //본인보다 큰거 (하나만)
        if (!st.empty()) ans++;

        // 삽입
        st.push_back(make_pair(h, cnt));
    }

    cout << ans << endl;
}