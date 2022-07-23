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


int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            for (int k = j + 1; k < n; ++k) {
                int num = a[i] + a[j] + a[k];
                if (num > ans && num <= m)
                    ans = num;
            }
    cout << ans << '\n';
    
}