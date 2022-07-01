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
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N, M;
bool possible(int a, int b, int x, int y);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N >> M;

    int n;
    cin >> n;
    vector<pii> st(n);
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        st[i] = make_pair(r, c);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) 
        {
            int a, b, x, y;
            // 
            a = st[i].first;
            b = st[i].second;
            x = st[j].first;
            y = st[j].second;
            int area = a * b + x * y;
            if (possible(a, b, x, y)) {
                ans = max(ans, area);
                continue;
            }
                

            // i 
            a = st[i].second;
            b = st[i].first;
            x = st[j].first;
            y = st[j].second;
            if (possible(a, b, x, y)) {
                ans = max(ans, area);
                continue;
            }

            // j
            a = st[i].first;
            b = st[i].second;
            x = st[j].second;
            y = st[j].first;
            if (possible(a, b, x, y)) {
                ans = max(ans, area);
                continue;
            }

            // i ,j
            a = st[i].second;
            b = st[i].first;
            x = st[j].second;
            y = st[j].first;
            if (possible(a, b, x, y)) {
                ans = max(ans, area);
                continue;
            }

        }
    } // for

    cout << ans << endl;

}

bool possible(int a, int b, int x, int y)
{
    if (a + x <= N && max(b, y) <= M)
        return true;
    if (b + y <= M && max(a, x) <= N)
        return true;

    return false;
}