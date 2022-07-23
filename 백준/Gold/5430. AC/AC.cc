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


void makeDeque(deque<int>& dq);
bool fun(deque<int>& dq, const string& s);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        deque<int> dq;
        makeDeque(dq);
        if (!fun(dq, s)) {
            cout << "error\n";
            continue;
        }
        if (dq.empty()) {
            cout << "[]\n";
            continue;
        }

        cout << '[';
        for (int i = 0; i < (int)dq.size() - 1; ++i) {
            cout << dq[i] << ',';
        }
        cout << dq.back() << "]\n";

    }
}

bool fun(deque<int> &dq, const string& s)
{
    bool back = false;

    for (char c : s) {
        if (c == 'R') {
            back = !back;
        }
        else {
            if (dq.empty())
                return false;
            if (back)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }

    if (back)
        reverse(dq.begin(), dq.end());
    return true;
}

void makeDeque(deque<int>& dq) {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 0)
        return;

    int temp = 0;
    for (int i = 1; i < (int)s.size() ; ++i) {
        if (s[i] == ',' || s[i] == ']') {
            dq.push_back(temp);
            temp = 0;
        }
        else {
            temp = temp * 10 + (s[i] - '0');
        }
    }

}