#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = -987654321;
const ll MOD = 1000000007;

ll cache[101][101][101];





int main() 
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, l, r; cin >> n >> l >> r;

    memset(cache, 0, sizeof(cache));
    
    cache[1][1][1] = 1LL;
    for (int N = 2; N <= n; ++N) {
        for (int L = 1; L <= n; ++L) {
            for (int R = 1; R <= n; ++R) {
                cache[N][L][R] = (cache[N - 1][L - 1][R] + cache[N - 1][L][R - 1]
                    + (N - 2) * cache[N - 1][L][R] ) % MOD;
            }
        }
    }

    cout << cache[n][l][r] << endl;
}

