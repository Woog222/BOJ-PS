#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

vvi operator*(const vvi& a, const vvi& b) {
    int n = a.size();
    vvi ret(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vvi matrixPow(const vvi& base, int k) {
    int n = base.size();
    vvi ret(n, vi(n,0)); 
    for (int i = 0; i < n; ++i) ret[i][i] = 1;

    vvi temp = base;
    while (k > 0) {
        if (k % 2) ret = ret * temp;
        k /= 2;
        temp = temp * temp;
    }
    return ret;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    int d; cin >> d;
    
    vvi matrix = {
        vi{0,1,1,0,0,0,0,0},
        vi{1,0,1,1,0,0,0,0},
        vi{1,1,0,1,1,0,0,0},
        vi{0,1,1,0,1,1,0,0},
        vi{0,0,1,1,0,1,0,1},
        vi{0,0,0,1,1,0,1,0},
        vi{0,0,0,0,0,1,0,1},
        vi{0,0,0,0,1,0,1,0}
    };
    vvi mat = matrixPow(matrix, d);
    cout << mat[0][0] << el;
}
