#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
#include <climits>
#define el '\n';
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;


int dist[101][101];
int items[101];
int N, M;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int r;
    cin >> N >> M >> r;
    for (int i = 1; i <= N; ++i)
        cin >> items[i];

    for (int i = 1; i <= N; ++i) 
        for (int j = 1; j <= N; ++j) 
            if (i != j)
                dist[i][j] = INF;
    while (r--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        dist[a][b] = dist[b][a] = cost;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int temp = 0;
        for (int j=1; j<=N; ++j) {
            if (dist[i][j] <= M)
                temp += items[j];
        }
        ans = max(ans, temp);
    }
    cout << ans << el;
   
}