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

string t, a;
bool fun(vector<char>& lst, deque<char>& rst);
string merge(const vector<char>& lst, const deque<char>& rst);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    cin >> a >> t;

    vector<char> lst;
    deque<char> rst;
    int left = 0, right = t.size() - 1;

    while (fun(lst, rst)) {
        t = merge(lst, rst);
        lst.clear();
        rst.clear();
    }
        



    cout << merge(lst, rst) << endl;
}

string merge(const vector<char>& lst, const deque<char>& rst) 
{
    vector<char> ret;
    for (char c : lst)
        ret.push_back(c);
    for (int i = 0; i < rst.size(); ++i)
        ret.push_back(rst[i]);

    return string(ret.begin(), ret.end());
}

bool fun(vector<char>& lst, deque<char>& rst)
{
    bool deleted = false;
    int left = 0, right = (int)t.size() - 1;
    while (left <= right)
    {
        // left
        while (left <= right) {
            lst.push_back(t[left++]);
            if (lst.size() < a.size()) continue;

            int n = lst.size();
            bool find = true;
            for (int i = 0; i < a.size(); ++i) {
                if (lst[n - a.size() + i] != a[i]) {
                    find = false;
                    break;
                }
            }

            if (find) {
                deleted = true;
                int cnt = a.size();
                while (cnt--)
                    lst.pop_back();
                break;
            }
        }

        // right
        while (left <= right) {
            rst.push_front(t[right--]);
            if (rst.size() < a.size()) continue;

            int n = rst.size() - 1;
            bool find = true;
            for (int i = 0; i < a.size(); ++i) {
                if (rst[i] != a[i]) {
                    find = false;
                    break;
                }
            }

            if (find) {
                deleted = true;
                int cnt = a.size();
                while (cnt--)
                    rst.pop_front();
                break;
            }
        } //right while
    } // big while

    return deleted;
}
