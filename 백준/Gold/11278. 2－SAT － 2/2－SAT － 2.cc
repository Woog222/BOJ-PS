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

int N, M;
int cnf[101][2];
int temp[101];


bool fun(int idx) {
    if (idx > N) {
        for (int i = 0; i < M; ++i) {
            int a = cnf[i][0];
            int b = cnf[i][1];
            if (temp[abs(a)] * a < 0 && temp[abs(b)] * b < 0)
                return false;
        }

        return true;
    }

    temp[idx] = 1;
    if (fun(idx + 1)) return true;
    temp[idx] = -1;
    if (fun(idx + 1)) return true;
    return false;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) 
        cin >> cnf[i][0] >> cnf[i][1];
    cout << fun(1) << el;
    for (int i = 1; i <= N; ++i)
        cout << (temp[i] > 0 ? 1 : 0) << " ";
    cout << el;
}