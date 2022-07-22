#include<iostream>
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

struct Point {
    int x, y;
    explicit Point(int _x=0,int _y=0 ) : x(_x), y(_y) {}

    friend bool operator < (const Point& a, const Point& b)  {
        return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
    }
};
int dist(Point a, Point b);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    // NlogN
    sort(points.begin(), points.end(), 
        [](const Point& a, const Point& b) {
            return a.x < b.x;
        });

    set<Point> cand = { points[0], points[1] };
    int ans = dist(points[0], points[1]);
    int from = 0;
    for (int i = 2; i < n; ++i) {
        auto now = points[i];
        while (from < i) {
            int dx = points[from].x - now.x;
            if (dx * dx > ans) 
                cand.erase(points[from++]);
            else
                break;
        }
        
        int dy = (int)sqrt(ans) + 1;
        auto iter = cand.lower_bound(Point(-100000, now.y-dy));
        auto until = cand.upper_bound(Point(100000, now.y+dy));
        while (iter != until) {
            ans = min(ans, dist(now, *(iter++)));
        }

        cand.insert(now);
    }

    cout << ans << '\n';
}

int dist(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

