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
    cout.tie(nullptr);
    
    map<string, string> m;
    int a, b; cin >> a >> b;
    while (a--) {
        string addr, pwd;
        cin >> addr >> pwd;
        m.emplace(addr, pwd);
    }

    while (b--) {
        string addr; cin >> addr;
        auto iter = m.find(addr);
        cout << iter->second << '\n';
    }

}
