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
#define el '\n';
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N;
int grid[10][10]; // 1 :can put, 0 : can't
int diag1[20]; // r+c
int diag2[20]; // n-r-1  +  c

int fun(int k, int mod);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            cin >> grid[i][j];

    cout <<fun(0, 0) + fun(0,1) << el;
}

int fun(int k, int mod)
{
    if (k >= N * N) {
        return 0;
    }
    int r = k / N;
    int c = k % N;
    if (grid[r][c] == 0 || (r+c)%2 != mod ) {
        return fun(k + 1, mod);
    }

    int ret = 0;
    if (diag1[r + c]==0 && diag2[N - r - 1 + c]==0) {
        diag1[r + c] = diag2[N - r - 1 + c] = 1;
        ret = max(ret, fun(k + 1, mod)+1);
        diag1[r + c] = diag2[N - r - 1 + c] = 0;
    }
    ret = max(ret, fun(k + 1, mod));
    return ret;
}
