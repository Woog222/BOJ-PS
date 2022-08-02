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
const int MOD = 1000000007;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int h, m; cin >> h >> m;
    int take; cin >> take;
    int dh = (take + m) / 60;
    int dm = (take + m) % 60;
    cout << (h + dh) % 24 << " " << dm << el;
}