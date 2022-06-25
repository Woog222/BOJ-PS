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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

string goal;
bool fun(string cur);
int main()
{
    cin >> goal;
    string now; cin >> now;

    cout << (fun(now) ? 1 : 0) << endl;
    
}


bool fun(string cur) 
{
    if (cur.size() == goal.size()) {
        if (cur == goal)
            return true;
        else
            return false;
    }

    int n = cur.size();
    char front = cur[0];
    char back = cur[n - 1];

    string temp = string(cur.rbegin(), cur.rend() - 1);
    // a..a
    if (front == 'A' && back == 'A') {
        if (fun(cur.substr(0, n - 1)))
            return true;
    }
    else if (front == 'B' && back == 'B') {
        if (fun(temp))
            return true;
    }
    else if (front == 'B' && back == 'A') {
        if (fun(temp) || fun(cur.substr(0, n - 1)))
            return true;
    }

    return false;
}
