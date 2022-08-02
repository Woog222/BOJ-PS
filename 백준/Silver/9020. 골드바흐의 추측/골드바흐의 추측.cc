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

    vector<bool> isPrime(300001, true);
    isPrime[0] = isPrime[1] = false;
    int a = sqrt(300000);
    for (int i = 2; i <= a; ++i) {
        if (isPrime[i]) {
            for (int temp = i * i; temp <= 300000; temp += i)
                isPrime[temp] = false;
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int x, y;
        for (int i = 1; i <= n / 2; ++i) {
            if (isPrime[i] && isPrime[n - i]) {
                x = i; y = n - i;
            }
        }
        cout << x << " " << y << el;
    }
}