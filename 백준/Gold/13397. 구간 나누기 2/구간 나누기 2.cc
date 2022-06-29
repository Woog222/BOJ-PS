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
typedef pair<ll, ll> pii;
const ll INF = 1987654321;




int N, M;
bool check(const vi& len, int size);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);


    cin >> N >> M;
    vi len(N);
    for (int i = 0; i < N; ++i)
        cin >> len[i];

    ll lo = 0, hi = 10000;
    ll ans = INF;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if (check(len, mid)) {
            hi = mid - 1;
            ans = min(ans, mid);
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

bool check(const vi& len, int size)
{
    int MIN = len[0], MAX = len[0];
    int use = 1;

    for (int i = 0; i < len.size(); ++i)
    {
        MIN = min(MIN, len[i]);
        MAX = max(MAX, len[i]);

        if (MAX - MIN > size) {
            use++;
            MIN = len[i];
            MAX = len[i];
        }

        if (use > M)
            return false;
    }

    return true;
}