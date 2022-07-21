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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const double PI = acos(-1.0);

struct Vector2 {
    ll x, y;

    explicit Vector2(ll _x=0, ll _y=0) :
        x(_x), y(_y){}

    ll cross(const Vector2& b) const {
        return x * b.y - y * b.x;
    }

    Vector2 operator - (const Vector2& b) const {
        return Vector2(x - b.x, y - b.y);
    }

    bool operator <(const Vector2& b) const {
        return x < b.x ? true : (x > b.x ? false : y < b.y);
    }
};

bool segmentIntersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);
bool isInside(const vector<Vector2>& edges, Vector2 p);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<Vector2> edges;
    while (n--) {
        ll x, y; cin >> x >> y;
        edges.emplace_back(x, y);
    }

    for (int i = 0; i < 3; ++i) {
        ll x, y; cin >> x >> y;
        cout << (isInside(edges, Vector2(x,y)) ? 1 : 0 ) << '\n';
    }

}

int ccw(Vector2 a, Vector2 b, Vector2 c) {
    ll temp = (b - a).cross(c - a);
    return temp > 0LL ? 1 : (temp == 0LL ? 0 : -1 );
}

bool isInside(const vector<Vector2>& edges, Vector2 p)
{
    for (int i = 0; i < edges.size(); ++i) {
        int j = (i + 1) % (int)edges.size();
      
        if (ccw(edges[i], edges[j], p) == 0) {
            ll minx = min(edges[i].x, edges[j].x);
            ll maxx = max(edges[i].x, edges[j].x);
            ll miny = min(edges[i].y, edges[j].y);
            ll maxy = max(edges[i].y, edges[j].y);
            if (minx <= p.x && p.x <= maxx && miny<=p.y && p.y<=maxy)
                return true;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int j = (i + 1) % (int)edges.size();
        // 선분 아에 겹침
        if ((edges[i].y > p.y) == (edges[j].y > p.y))
            continue;

        // 선분의 일부가 겹치거나, 끝점에서 교차하는 경우 전부 배제했다.
        Vector2 q(1000000001LL, p.y);
        if (segmentIntersects(edges[i], edges[j], p, q))
            cnt++;
    }

    return cnt % 2;
}

bool segmentIntersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2)
{
    int ccw1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int ccw2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

    /*
    if (ccw1 == 0 && ccw2 == 0) {
        if (a2 < a1) swap(a1, a2);
        if (b2 < b1) swap(a1, a2);

    }*/

    return ccw1 <= 0 && ccw2 <= 0;
}