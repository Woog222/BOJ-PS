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
    int k; cin >> k;

    int n = 1;
    while (n * (n + 1) / 2 < k) n++;

    int nth = k - (n * (n - 1) / 2);
    if (n % 2) {
        cout << n - nth + 1 << '/' << nth << el;
    }
    else {
        cout << nth << '/' << n - nth + 1 << el;
    }
    

}
