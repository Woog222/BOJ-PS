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

struct Pred {
    bool operator() (int a, int b) {
        int aa = abs(a), bb = abs(b);
        return (aa == bb) ? (a > b) : (aa > bb);
    }
};

int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    priority_queue<int, vi, Pred> pq;
    int n; cin >> n;
    while (n--) {
        int num; cin >> num;
        if (num != 0)
            pq.push(num);
        else {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else 
                cout << "0\n";
        }
    }

}
