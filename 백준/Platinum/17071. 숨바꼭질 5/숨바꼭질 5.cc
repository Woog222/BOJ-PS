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
typedef pair<int, int> pii;


int N, K;
int dist[500001][2];

int bfs()
{
    memset(dist, -1, sizeof(dist));
    queue<pii> q; // 위치 , 시간홀짝
    q.emplace(N, 0);
    dist[N][0] = 0;

    while (!q.empty()) {
        int here, d;
        tie(here,d) = q.front(); q.pop();

        int nd = d + 1;
        for (int next : {here - 1, here + 1, here * 2}) {
            if (0 <= next && next <= 500000 && dist[next][nd % 2] == -1) {
                dist[next][nd % 2] = nd;
                q.emplace(next, nd);
            }
        }
    }

    for (int t = 0, now = K; ; ++t) {
        now += t;
        if (now > 500000) return -1;
        int spent = dist[now][t % 2];
        if (spent != -1 && spent <= t) return t;
    }
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N >> K;
    cout << bfs() << el;
}