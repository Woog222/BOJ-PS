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


bool fun(const string& s);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
   
    // n 포켓몬의 개수
    // m 질문의 개수
    int n, m; cin >> n >> m;
    vector<string> a(n);
    vector<pair<string, int>> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i + 1;
    }
    sort(b.begin(), b.end());
        


    while (m--)
    {
        string s; cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            int idx = atoi(s.c_str());
            cout << a[idx - 1] << '\n';
        }
        else {
            auto iter = lower_bound(b.begin(), b.end(), pair<string,int>(s, 0));
            cout << iter->second << '\n';
        }
    }
}