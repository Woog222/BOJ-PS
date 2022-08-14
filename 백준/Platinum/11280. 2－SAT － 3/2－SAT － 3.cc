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
const int MAX = 20005;


int N, M;
vi adj[MAX]; // (2,3) ~~ (2n, 2n+1) (+, -)
stack<int> st;
int sccId[MAX], order[MAX]; // memset to -1
int vcnt, scccnt;

int dfsScc(int here) {
    int ret = order[here] = vcnt++;
    st.push(here);

    for (int there : adj[here]) {
        if (order[there] == -1) 
            ret = min(ret, dfsScc(there));
        else if (sccId[there] == -1) 
            ret = min(ret, order[there]);
    }

    if (ret == order[here]) {
        while (true) {
            int temp = st.top(); st.pop();
            sccId[temp] = scccnt;
            if (temp == here) break;
        }
        scccnt++;
    }
    return ret;
}


void readInput();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    readInput();
    memset(sccId, -1, sizeof(sccId));
    memset(order, -1, sizeof(order));
    for (int i = 2; i <= 2 * N + 1; ++i) if (order[i] == -1) dfsScc(i);

    for (int i = 1; i <= N; ++i) {
        if (sccId[i * 2] == sccId[i * 2+1]) {
            cout << 0 << el;
            return 0;
        }
    }
    cout << 1 << el;
}

void readInput() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        a = (a < 0) ? (-a) * 2 + 1 : 2 * a;
        b = (b < 0) ? (-b) * 2 + 1 : 2 * b;

        adj[(a % 2) ? a - 1 : a + 1].push_back(b);
        adj[(b % 2) ? b - 1 : b + 1].push_back(a);
    }
}