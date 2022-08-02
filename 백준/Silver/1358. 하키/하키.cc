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
const double PI = acos(-1.0);


int W, H, X, Y, P;
bool isInside(int x, int y);
int main() {
    cin >> W >> H >> X >> Y >> P;
    int ans = 0;
    while (P--) {
        int x, y; cin >> x >> y;
        ans += isInside(x, y);
    }
    cout << ans << el;
}


bool isInside(int x, int y)
{
    int sqr = (H / 2) * (H / 2);
    if (X <= x && x <= X + W) {
        return Y <= y && y <= Y + H;
    }
    else if (x < X) {
        int dx = X - x;
        int dy = Y + H / 2 - y;
        return dx * dx + dy * dy <= sqr;
    }
    else {
        int dx = X+W - x;
        int dy = Y + H / 2 - y;
        return dx * dx + dy * dy <= sqr;
    }
}
