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

struct Point {
    int x, y, r;
    Point(int _x=0, int _y=0, int _r=0) :
        x(_x), y(_y), r(_r) {}
};

int x1, y11, x2, y2;
vector<Point> p;
void readInput();
bool isInside(Point point, int x, int y);
int main() {
    int t;  cin >> t;
    while (t--) {
        readInput();

        vi a, b;
        for (int i = 0; i < p.size(); ++i) {
            if (isInside(p[i], x1, y11)) a.push_back(i);
        }
        for (int i = 0; i < p.size(); ++i) {
            if (isInside(p[i], x2, y2)) b.push_back(i);
        }

        int dup = 0;
        for (int i = 0; i < a.size(); ++i) {
            int val = a[i];
            if (find(b.begin(), b.end(), val) != b.end())
                dup++;
        }
        cout << (int)a.size() + (int)b.size() - dup*2 << el;
    }

}

bool isInside(Point point, int x, int y) {
    int sqr = point.r * point.r;
    int dx = x - point.x, dy = y - point.y;
    if (dx * dx + dy * dy <= sqr) return true;
    return false;
}

void readInput()
{
    cin >> x1 >> y11 >> x2 >> y2;

    p.clear();
    int n; cin >> n;
    while (n--) {
        int x, y, r; cin >> x >> y >> r;
        p.emplace_back(x, y, r);
    }
}