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
inline int dist(const Vector2& a, const Vector2& b);
int ccw(Vector2 a, Vector2 b, Vector2 c);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<Vector2> edges;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        edges.emplace_back(x, y);
    }

    Vector2 p = edges[0];
    for (int i = 1; i < n; ++i) {
        if (edges[i].y < p.y) {
            p = edges[i];
        }
        else if (edges[i].y == p.y && edges[i].x < p.x)
            p = edges[i];
    }

    sort(edges.begin(), edges.end(),
        [p](const Vector2& a, const Vector2& b) {
            int temp = ccw(p, a, b);
            if (temp == 0) {
                return dist(p, a) <= dist(p, b);
            }
            else {
                return temp > 0;
            }
        }
        );

    vector<Vector2> st;
    int i = 0;
    while (i<n) {
        while (st.size() < 2) st.push_back(edges[i++]);

        int temp = ccw(st[(int)st.size() - 2], st.back(), edges[i]);
        if (temp > 0) {
            st.push_back(edges[i++]);
        }
        else {
            st.pop_back();
        }
    }

    cout << st.size() << '\n';

}

inline int dist(const Vector2& a, const Vector2& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int ccw(Vector2 a, Vector2 b, Vector2 c) {
    ll temp = (b - a).cross(c - a);
    return temp > 0LL ? 1 : (temp == 0LL ? 0 : -1 );
}
