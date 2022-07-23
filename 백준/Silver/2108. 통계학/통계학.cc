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
    
    int n; cin >> n;
    int sum = 0;
    vi a(n);
    vector<pii> freq(8001);
    for (int i = 0; i <= 8000; ++i)
        freq[i] = pii(0, -4000 + i);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        freq[a[i] + 4000].first++;
    }
    sort(a.begin(), a.end());
    // avg
    cout << (int)(round((double)sum/n)) << '\n';
    // median
    cout << a[n / 2] << '\n';
    // (-cnt, key)
    sort(freq.begin(), freq.end(), 
        [](const pii& a, const pii& b) {
            return (a.first == b.first) ? a.second<b.second : a.first > b.first;
        }
    );

    if (freq[0].first == freq[1].first) {
        cout << freq[1].second << '\n';
    }
    else
        cout << freq[0].second << '\n';
    // range
    cout << a.back() - a.front() << '\n';
    
}