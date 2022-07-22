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
const double PI = acos(-1.0);


int N, M;
int grid[1000][1000];
int histogram(const vector<int>& height);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<int> h(M, 0);
        int ans = 0;
        while (N--) {
            for (int i = 0; i < M; ++i) {
                int num; cin >> num;
                if (num == 0)
                    h[i] = 0;
                else
                    h[i]++;
            }
            ans = max(ans, histogram(h));
        }

        cout << ans << '\n';
    }
    
    


    
}

int histogram(const vector<int>& height) 
{
    int n = height.size();
    // idx 넣을거임
    stack<int> st;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[st.top()] >= height[i]) {
            int h = height[st.top()]; st.pop();
            int left = st.empty() ? 0 : st.top()+1;
            int right = i;
            ret = max(ret, h * (right - left));
        }

        st.push(i);
    }

    while (!st.empty()) {
        int h = height[st.top()]; st.pop();
        int left = st.empty() ? 0 : st.top() + 1;
        int right = n;
        ret = max(ret, h * (right - left));
    }

    return ret;
}
