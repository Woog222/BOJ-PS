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
const int MAX = 10001;

vi adj[MAX]; //init
int discovered[MAX], iscut[MAX]; // init
int N, cnt;

bool readInput();
int dfsCut(int here, bool isRoot);
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    while (readInput())
    {
        int grp = 0;
        for (int i = 0; i < N; ++i) 
            if (discovered[i] == -1) {
                dfsCut(i, true);
                grp++;
            }

        int temp = *max_element(iscut, iscut + N);
        cout << grp + temp - 1 << el;

    }
}

int dfsCut(int here, bool isRoot) {
    int ret = discovered[here] = cnt++;

    // 루트인경우, 자식이 2개 이상이면 절단점이다.
    int cut = 1;
    int child = 0;
    for (int go : adj[here]) {

        if (discovered[go] == -1) {
            child++;
            int highest = dfsCut(go, false);
            if (!isRoot && discovered[here] <= highest)
                cut++;
            ret = min(ret, highest);
        }
        else
            ret = min(ret, discovered[go]);
    }

    if (isRoot)
        iscut[here] = child;
    else
        iscut[here] = cut;
    return ret;
}

bool readInput()
{
    int e; cin >> N >> e;
    if (N == 0 && e == 0) return false;
    // init
    cnt = 0;
    memset(iscut, 0, sizeof(iscut));
    memset(discovered, -1, sizeof(discovered));
    for (int i = 0; i < N; ++i) adj[i].clear();

    while (e--) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    return true;
}