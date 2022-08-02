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
    vi x, y;

    for (int i = 0; i < 3; ++i) {
        int a, b; cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int xa = x[1];
    int ya = y[1];

    if (xa == x.front()) cout << x.back();
    else cout << x.front();
    cout << " ";
    if (ya == y.front()) cout << y.back();
    else cout << y.front();
    cout << el;
}