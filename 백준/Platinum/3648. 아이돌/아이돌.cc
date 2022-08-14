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
const int MAX = 2004;


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

//bool dfs(int here, vi& temp, vector<bool>& visit) {
//    visit[here] = true;
//
//    int v = here / 2;
//    bool isTrue = here % 2 == 0;
//    if (temp[v] == -1) temp[v] = !isTrue;
//    
//    bool now = (temp[v] == 1 && isTrue) || (temp[v] == 0 && !isTrue);
//    for (int there : adj[here]) {
//        if (!now) {
//            if (!visit[there]) 
//                if (!dfs(there, temp, visit)) return false;
//            continue;
//        }
//
//        int nv = there / 2;
//        bool isTrue2 = there % 2 == 0;
//        if (now && temp[nv] == -1) {
//            temp[nv] = isTrue2;
//            if (!visit[there])
//                if (!dfs(there, temp, visit)) return false;
//            continue;
//        }
//
//        bool near = (temp[nv] == 1 && isTrue2) || (temp[nv] == 0 && !isTrue2);
//        if (now && !near) return false;
//        if (!visit[there]) {
//            if (!dfs(there, temp, visit)) return false;
//        }
//    }
//    return true;
//}


bool readInput();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    while (readInput()) {
        for (int i = 2; i <= 2 * N + 1; ++i) if (order[i] == -1) dfsScc(i);

        // 1. no contradiction
        bool ok = true;
        for (int i = 1; i <= N; ++i) {
            if (sccId[i * 2] == sccId[i * 2 + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "yes" << el;
        else cout << "no" << el;
    }
}

bool readInput() {
    memset(sccId, -1, sizeof(sccId));
    memset(order, -1, sizeof(order));
    vcnt = scccnt = 0;
    cin >> N; if (cin.eof()) return false;
    cin >> M;
    for (int i = 0; i <= 2 * N + 1; ++i) adj[i].clear();
    stack<int>().swap(st);

    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        a = (a < 0) ? (-a) * 2 + 1 : 2 * a;
        b = (b < 0) ? (-b) * 2 + 1 : 2 * b;

        adj[(a % 2) ? a - 1 : a + 1].push_back(b);
        adj[(b % 2) ? b - 1 : b + 1].push_back(a);
    }

    adj[3].push_back(2);
    return true;
}