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


bool check(const vi& v);
int cost(const vi& a, const vi& v);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    vi a(9);
    for (int i = 0; i < 9; ++i)
        cin >> a[i];

    vi v(9);
    for (int i = 0; i < 9; ++i)
        v[i] = i + 1;

    int ans = INF;
    do
    {
        if (check(v)) {
            ans = min(ans, cost(a, v));
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

bool check(const vi& v)
{
    int sum = v[0] + v[1] + v[2];
    if (v[3] + v[4] + v[5] != sum)
        return false;
    if (v[6] + v[7] + v[8] != sum)
        return false;
    if (v[0] + v[3] + v[6] != sum)
        return false;
    if (v[1] + v[4] + v[7] != sum)
        return false;
    if (v[2] + v[5] + v[8] != sum)
        return false;
    if (v[0] + v[4] + v[8] != sum)
        return false;
    if (v[2] + v[4] + v[6] != sum)
        return false;
    return true;
}
int cost(const vi& a, const vi& v) {
    int ret = 0;
    for (int i = 0; i < 9; ++i)
        ret += (a[i] > v[i]) ? a[i] - v[i] : v[i] - a[i];

    return ret;
}