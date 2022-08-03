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
const ll INF = numeric_limits<ll>::min();


int start[1000], adj[1000][1000]; // i-j 간선의 수
int N;
deque<int> circuit;

void dfsEuler(int here) {
    for (int there = start[here]; there < N; ++there) {
        start[here] = there;
        while (adj[here][there] > 0) {
            adj[here][there]--;
            // 방향그래프인 경우 아래코드 사용하지 않음
            adj[there][here]--;
            dfsEuler(there);
        }
    }
    circuit.push_front(here);
}
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N;
    int e = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            e += adj[i][j];
        }
    e /= 2;

    dfsEuler(0);
    if (circuit.front() != circuit.back() || circuit.size() != e+1 ) {
        cout << -1 << el;
    }
    else {
        for (int v : circuit) cout << v+1 << " ";
        cout << el;
    }
}