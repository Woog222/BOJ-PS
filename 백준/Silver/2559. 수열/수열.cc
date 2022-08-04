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


int psum[100001];

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int temp; cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }

    int ans = -INF;
    for (int i = 1; i + k <= n + 1; ++i) {
        ans = max(ans, psum[i + k - 1] - psum[i - 1]);
    }
    cout << ans << el;

}
