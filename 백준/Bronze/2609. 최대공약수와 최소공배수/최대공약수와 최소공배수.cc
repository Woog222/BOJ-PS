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
    
    int a, b; cin >> a >> b;
    int c = a, d = b;
    //a>b
    if (a < b) swap(a, b);
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    cout << a << '\n'
        << c * d / a << '\n';
}
