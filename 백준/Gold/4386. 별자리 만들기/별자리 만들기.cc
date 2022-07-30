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
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

pair<double, double> loc[101];
double dist[101];
bool included[101];
int N;

double cal(int a, int b) {
    double dx = loc[a].first - loc[b].first;
    double dy = loc[a].second - loc[b].second;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) 
        cin >> loc[i].first >> loc[i].second;
    for (int i = 1; i <= N; ++i) dist[i] = INF;
   
    queue<int> q;
    dist[1] = 0.0;
    included[1] = true;
    q.push(1);

    double ans = 0;
    while (!q.empty()) {
        int here = q.front(); q.pop();

        int there = -1;
        for (int next = 1; next <= N; ++next) {
            if (included[next]) continue;

            dist[next] = min(dist[next], cal(here, next));
            if (there == -1 || dist[next] < dist[there]) 
                there = next;
        }

        if (there == -1) break;
        ans += dist[there];
        included[there] = true;
        q.push(there);
    }

    cout << fixed; cout.precision(2);
    cout << ans << el;

}