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


int fun(int n);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    int n; cin >> n;
    vi v = vi(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    stack<int> st;
    vector<char> res;
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && st.top() == v[idx]) {
            st.pop();
            idx++;
            res.push_back('-');
        }
        st.push(i);
        res.push_back('+');
    }

    while (!st.empty() && st.top() == v[idx]) {
        st.pop();
        idx++;
        res.push_back('-');
    }
    
    if (idx != n)
        cout << "NO\n";
    else
        for (char c : res) {
            cout << c << '\n';
        }
}

