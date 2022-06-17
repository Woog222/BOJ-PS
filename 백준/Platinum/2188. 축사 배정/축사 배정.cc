#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;

int START = 401;
int DEST = 402;

int v, e;
int cap[405][405];
int flow[405][405];
int parent[405];

// A : 1~26 // a : 27~52
int c2i(char c) 
{
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 1;
    else
        return c - 'a' + 27;
}
void add_edge(int from, int to, int c)
{
    cap[from][to] += c;
}
int cal_amt() // this case, just one..but practice!
{
    int amt = INF;
    int here = DEST;
    while (parent[here] != here)
    {
        amt = min(amt, cap[parent[here]][here] - flow[parent[here]][here]);
        here = parent[here];
    }

    return amt;
}
bool bfs() // true: success to get DIST, or false
{
    memset(parent, 0, sizeof(parent));
    queue<int> q;
    q.push(START);
    parent[START] = START;

    int amt = INF;
    while (!q.empty())
    {
        int here = q.front(); q.pop();

        for (int next = 1; next <= v; ++next) {
            if (parent[next] != 0 || cap[here][next] - flow[here][next] <= 0)
                continue;

            q.push(next);
            parent[next] = here;
        }
       
    }

    // fail to get dest
    if (parent[DEST] == 0)
        return false;
    else
        return true;
}
void send(int amt) 
{
    int here = DEST;
    while (parent[here] != here)
    {
        flow[parent[here]][here] += amt;
        flow[here][parent[here]] -= amt;
        here = parent[here];
    }
}


int main()
{
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> v >> e;
    START = v + e + 1;
    DEST = v + e + 2;
    for (int from = 1; from <= v; ++from) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int to; cin >> to;
            add_edge(from, to+v, 1);
        }
        add_edge(START, from, 1);
    }    

    for (int i = 1; i <= e; ++i) {
        add_edge(i + v, DEST, 1);
    }
    v += e+2;
    

    int ans = 0;
    while ( bfs() )
    {
        // cal max possible amount
        int max_amount = cal_amt();
        send(max_amount);
        ans += max_amount;
    }

    cout << ans << endl;
}