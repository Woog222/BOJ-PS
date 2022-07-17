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
   
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        deque<pii> prio(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> prio[i].second;
            prio[i].first = i;
        }
        vi order = vi(n, -1);

        int nth = 0;
        while (!prio.empty()) {
            int maxPrio = max_element(prio.begin(), prio.end(),
                [](const pii& a, const pii& b) {
                    return a.second < b.second;
                }
            )->second;
            int cur = prio.front().second;
            if (cur < maxPrio) {
                prio.emplace_back(prio.front());
                prio.pop_front();
            }
            else {
                order[prio.front().first] = ++nth;
                prio.pop_front();
            }
        }
        cout << order[m] << '\n';
    }
}
