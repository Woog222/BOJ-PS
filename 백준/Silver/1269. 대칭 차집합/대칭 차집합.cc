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

int main() {
    int n, m; cin >> n >> m;

    set<int> a;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        a.insert(num);
    }
    for (int i = 0; i < m; ++i) {
        int num; cin >> num;
        auto iter = a.lower_bound(num);
        if (iter == a.end() || *iter != num) a.insert(num);
        else a.erase(iter);
        
    }

    cout << a.size() << el;
}