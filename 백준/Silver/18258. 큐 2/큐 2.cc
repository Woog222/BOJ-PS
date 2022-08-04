#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX = 1000;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    queue<int> q;

    int k; cin >> k;
    while (k--) {
        string com; cin >> com;
        if (com == "push") {
            int num; cin >> num;
            q.push(num);
        }
        else if (com == "pop") {
            if (q.empty()) {
                cout << -1 << el;
                continue;
            }
            cout << q.front() << el;
            q.pop();
        }
        else if (com == "size") {
            cout << q.size() << el;
        }
        else if (com == "empty") {
            cout << q.empty() << el;
        }
        else if (com == "front") {
            if (q.empty()) {
                cout << -1 << el;
                continue;
            }
            cout << q.front() << el;
        }
        else if (com == "back") {
            if (q.empty()) {
                cout << -1 << el;
                continue;
            }
            cout << q.back() << el;
        }

    }
}