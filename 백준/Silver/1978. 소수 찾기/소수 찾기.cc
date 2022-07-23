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

    vector<bool> isPrime(1001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 1000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000; j += i)
                isPrime[j] = false;
        }
    }


    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int num; cin >> num;
        if (isPrime[num])
            ans++;
    }

    cout << ans << '\n';
    
}