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
    while (t--)
    {
        int k, n; cin >> k >> n;
        for (int j = 1; j <= n; ++j) {
            a[0][j] = j;
        }
        for (int i = 1; i <= k; ++i) {
            int sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += a[i - 1][j];
                a[i][j] = sum;
            }
        }

        cout << a[k][n] << '\n';

    }


}