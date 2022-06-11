#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = -987654321;
const int NORESULT = -987654320;

int n, m, k;
int cache[301][301];
int way[301][301];




int fun(int now, int use) 
{
    if (now == n) {
        return 0;
    }
    if (use >= m)
        return -2;

    int& ret = cache[now][use];
    if (ret != -1)
        return ret;

    ret = -2;
    for (int next = now + 1; next <= n; ++next) 
    {
        if (way[now][next] == -1)
            continue;
            
        int temp  = fun(next, use + 1);
        if (temp != -2) {
            ret = max(ret, temp + way[now][next]);
        }

        
    }
    return ret;


}




int main() 
{
    cin >> n >> m >> k;

    memset(way, -1, sizeof(way));
    memset(cache, -1, sizeof(cache));
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        way[a][b] = max(way[a][b], c);
    }

    cout << fun(1, 1) << endl;

}