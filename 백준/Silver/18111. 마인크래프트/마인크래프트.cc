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

int grid[500][500];
int n, m, b;
int cost(int h);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    
    cin >> n >> m >> b;

    int totalBlcok = b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            totalBlcok += grid[i][j];
        }
    }

    int maxHeight = totalBlcok / (n * m);

    vector<pii> cand; // (cost, height)
    for (int i = 0; i <= maxHeight; ++i) {
        cand.emplace_back(cost(i), -i);
    }

    sort(cand.begin(), cand.end());
    cout << cand[0].first << " " << -cand[0].second << '\n';
    
}

int cost(int h) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = h - grid[i][j];
            if (d > 0)
                ret += d;
            else
                ret -= 2 * d;
        }
    }

    return ret;
}