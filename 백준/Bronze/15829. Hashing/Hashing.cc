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

    ll r = 31ll, M = 1234567891ll;
    
    int n; cin >> n;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (char c : s) {
        ll num = c - 'a' + 1;
        ans = (ans * r + num) % M;
    }
    cout << ans << endl;

    
    
}