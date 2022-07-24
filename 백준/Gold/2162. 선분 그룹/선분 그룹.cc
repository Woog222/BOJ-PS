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
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

struct Vector {
    int x, y;
    explicit Vector(int x=0, int y=0) : x(x), y(y) {}

    double cross(const Vector& b) const {
        return x * b.y - y * b.x;
    }

    Vector operator - (const Vector& b) const {
        return Vector(x - b.x, y - b.y);
    }

    bool operator <(const Vector& b) const {
        return (x == b.x) ? (y < b.y) : (x < b.x);
    }
};
int ccw(Vector a, Vector b, Vector c) {
    int temp = (b - a).cross(c - a);
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}
struct Line {
    Vector v1, v2;

    explicit Line(Vector a, Vector b) : v1(a), v2(b) {}

    bool intersect(const Line& b) const {
        int ccw1 = ccw(v1, v2, b.v1) * ccw(v1, v2, b.v2);
        int ccw2 = ccw(b.v1, b.v2, v1) * ccw(b.v1, b.v2, v2);
        if (ccw1 == 0 && ccw2 == 0) {
            Vector a1 = v1, a2 = v2;
            Vector b1 = b.v1, b2 = b.v2;
            if (a2 < a1) swap(a1, a2);
            if (b2 < b1) swap(b1, b2);
            if (a2 < b1 || b2 < a1)
                return false;
            return true;
        }
        else
            return ccw1 <= 0 && ccw2 <= 0;
    }
};

vi adj[3000];
bool visit[3000];
int dfs(int here);

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    vector<Line> lines;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.emplace_back(Vector(x1, y1), Vector(x2, y2));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Line& a = lines[i];
            Line& b = lines[j];
            if (a.intersect(b)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int groupSize = 0;
    int group = 0;
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            groupSize = max(groupSize, dfs(i));
            group++;
        }
    }
    cout << group << el 
         << groupSize << el;
}

int dfs(int here)
{
    visit[here] = true;
    int ret = 1;
    for (int next : adj[here]) {
        if (!visit[next])
            ret += dfs(next);
    }
    return ret;
}