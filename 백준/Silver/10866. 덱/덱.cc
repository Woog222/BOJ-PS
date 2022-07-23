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


int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    deque<int> dq;
    int n; cin >> n;
    while (n--)
    {
        string command; int num;
        cin >> command;
        if (command == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        else if (command == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if (command == "pop_front") {
            cout << ((dq.empty()) ? -1 : dq.front()) << '\n';
            if (!dq.empty())
                dq.pop_front();
        }
        else if (command == "pop_back") {
            cout << ((dq.empty()) ? -1 : dq.back()) << '\n';
            if (!dq.empty())
                dq.pop_back();
        }
        else if (command == "size") {
            cout << dq.size() << '\n';
        }
        else if (command == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (command == "front") {
            cout << ((dq.empty()) ? -1 : dq.front()) << '\n';
        }
        else if (command == "back") {
            cout << ((dq.empty()) ? -1 : dq.back()) << '\n';
        }
    }

}