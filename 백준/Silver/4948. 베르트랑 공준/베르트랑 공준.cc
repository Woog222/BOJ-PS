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

    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (isPrime[i]) cnt++;
        }
        cout << cnt << el;
    }
}