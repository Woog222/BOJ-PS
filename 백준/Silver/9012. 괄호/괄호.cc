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
    int n; cin >> n;
    while (n--)
    {
        string s; cin >> s;
        if (fun(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
  
}

bool fun(const string& s)
{
    stack<char> st;
    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];
        if (c == '(')
            st.push(c);
        else {
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}