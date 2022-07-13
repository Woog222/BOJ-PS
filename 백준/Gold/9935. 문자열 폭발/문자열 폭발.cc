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

int N;
int cache[51][51];
int fun(const deque<int>& arr, int from, int to);

int main()
{
    string a, b;
    cin >> a >> b;

    vector<char> st;
    for (char c : a) {
        st.push_back(c);
        if (st.size() < b.size())
            continue;

        bool match = true;
        for (int i = 0; i < b.length(); ++i) {
            if (st[st.size() - b.length() + i] != b[i]) {
                match = false;
                break;
            }
        }

        if (match) {
            int cnt = b.length();
            while (cnt--) st.pop_back();
        }
    }
  
    for (char c : st)
        cout << c;
    if (st.size() == 0)
        cout << "FRULA";
    cout << endl;
}