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
const int MOD = 1000000007;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int n; cin >> n;

    priority_queue<int> q;
    while (n--)
    {
        int a; cin >> a;
        if (a == 0) {
            if (q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(a);
    }
}
