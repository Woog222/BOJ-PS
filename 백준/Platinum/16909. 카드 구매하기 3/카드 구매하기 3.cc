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

int n;
int a[1000000];
ll cal(vector<pair<ll, ll>>& Max, vector<pair<ll, ll>>& Min);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // idx넣을거야
    stack<int> st; 
    vector<pair<ll, ll>> boundary1(n);
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && a[st.top()] <= a[i]) {
            int poppedIdx = st.top(); st.pop();
            boundary1[poppedIdx].second = i - 1;
        }

        if (st.empty())
            boundary1[i].first = 0;
        else
            boundary1[i].first = st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) {
        int poppedIdx = st.top(); st.pop();
        boundary1[poppedIdx].second = n - 1;
    }

    ///////////////////////////
    vector<pair<ll, ll>> boundary2(n);
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && a[st.top()] >= a[i]) {
            int poppedIdx = st.top(); st.pop();
            boundary2[poppedIdx].second = i - 1;
        }

        if (st.empty())
            boundary2[i].first = 0;
        else
            boundary2[i].first = st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) {
        int poppedIdx = st.top(); st.pop();
        boundary2[poppedIdx].second = n - 1;
    }

    cout << cal(boundary1, boundary2) << endl;
}

ll cal(vector<pair<ll, ll>>& Max, vector<pair<ll, ll>>& Min)
{
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (i - Max[i].first + 1) * (Max[i].second - i + 1) * a[i];
        ret -= (i - Min[i].first + 1) * (Min[i].second - i + 1) * a[i];
    }

    return ret;
}