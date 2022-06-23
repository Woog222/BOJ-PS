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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 20091101;

int N, K;
ll fun(const vector<ll>& h);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {       
        cin >> N;
        if (N == 0) break;

        vector<ll> h(N + 2);
        for (int i = 1; i <= N; ++i)
            cin >> h[i];
        h[N + 1] = 0;

        cout << fun(h) << '\n';
    }
}

ll fun(const vector<ll>& h)
{
    ll ans = 0;

    stack<ll> st;
    for (int i = 1; i <= N + 1; ++i) 
    {
        while (!st.empty() && h[st.top()] >= h[i]) {
            ll height = h[st.top()]; st.pop();
            ll left;
            if (st.empty())
                left = 0;
            else
                left = st.top();
            ans = max(ans, height * (i - left-1));

        }
        st.push(i);
    }

    return ans;
}
