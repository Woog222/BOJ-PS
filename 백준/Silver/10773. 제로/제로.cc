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

    int n; cin >> n;

    stack<int> st;

    while (n--) {
        int num; cin >> num;
        if (num == 0)
            st.pop();
        else
            st.push(num);
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
        
    cout << ans << '\n';
    
}