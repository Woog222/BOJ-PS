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



bool bad[201][201];

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        bad[a][b] = bad[b][a] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1 ; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (bad[i][j] || bad[j][k] || bad[i][k])
                    continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
}