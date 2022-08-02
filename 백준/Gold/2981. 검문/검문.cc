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
const double PI = acos(-1.0);

int gcd(int x, int y) {
    // x > y
    if (x < y) swap(x, y);

    while (y) {
        int temp = x%y;
        x = y;
        y = temp;
    }
    return x;
}

int main() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int num = a[1] - a[0];
    for (int i = 2; i < n; ++i) 
        num = gcd(num, a[i] - a[i-1]);

    vi ans;
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            ans.push_back(i);
            ans.push_back(num / i);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i : ans) {
        if (i != 1) cout << i << " ";
    }
    cout << el;
}