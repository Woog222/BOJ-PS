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


vi fun(const string& s);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int t; cin >> t;
    while (t--)
    {
        multiset<int> s;
        int n; cin >> n;
        while (n--) {
            char c; cin >> c;
            int num; cin >> num;
            // insert
            if (c == 'I') {
                s.insert(num);
            }
            else if (!s.empty()) {
                if (num == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            auto ans = minmax_element(s.begin(), s.end());
            cout << *(ans.second) << " " << *(ans.first) << '\n';
        }
    }

}
