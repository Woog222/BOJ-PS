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



int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    int n; cin >> n;
    vi v = vi(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int q; cin >> q;
    while (q--) {
        int num; cin >> num;
        auto iter = lower_bound(v.begin(), v.end(), num);
        if (iter == v.end() || *iter != num)
            cout << "0\n";
        else
            cout << "1\n";
    }
}
