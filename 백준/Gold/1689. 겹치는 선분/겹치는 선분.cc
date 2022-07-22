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
const double PI = acos(-1.0);



int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    vi s(n), e(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> e[i];

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());

    int st = -1, end = -1;
    int cnt = 0, ans = 0;
    while (st < n - 1) 
    {
        int here = min(s[st + 1], e[end + 1]);

        while (st+1 < n && s[st + 1] == here) {
            cnt++;
            st++;
        }
        while (end+1 <n && e[end + 1] == here) {
            cnt--;
            end++;
        }

        //cout << here << " : " << cnt << '\n';
        ans = max(ans, cnt);
    }
   
    cout << ans << '\n';
}