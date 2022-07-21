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

struct Vector2{
   
    double x, y;

    explicit Vector2(double x_=0, double y_=0) : 
        x(x_), y(y_) {}

    bool operator ==(const Vector2& b) const {
        return x == b.x && y == b.y;
    }

    bool operator <(const Vector2& b) const {
        return x != b.x ? x < b.x : y < b.y;
    }

    Vector2 operator + (const Vector2 & b) const {
        return Vector2(x + b.x, y + b.y);
    }

    Vector2 operator - (const Vector2& b) const {
        return Vector2(x - b.x, y - b.y);
    }

    Vector2 operator *(double b) const {
        return Vector2(b * x, b * y);
    }

    inline double norm() const {
        return hypot(x, y);
    }

    Vector2 normalize() const {
        return Vector2(x / norm(), y / norm());
    }

    double polar() const {
        return fmod(atan2(y, x) + 2 * PI, 2 * PI);
    }

    double dot(const Vector2& b) const {
        return x * b.x + y * b.y;
    }

    double cross(const Vector2& b) const {
        return x * b.y - y * b.x;
    }

    Vector2 projection(const Vector2& b) const {
        Vector2 normed = b.normalize();
        return normed * normed.dot(*this);
    }
};

double ccw(Vector2 a, Vector2 b) {
    return a.cross(b);
}
// a-c vs b-c
double ccw(const Vector2& a, const Vector2& b, const Vector2& c) {
    return ccw(b - a, c - a);
}
bool segmentIntersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Vector2 a1 = Vector2(x1, y1);
    Vector2 a2 = Vector2(x2, y2);
    Vector2 b1 = Vector2(x3, y3);
    Vector2 b2 = Vector2(x4, y4);

    cout << segmentIntersects(a1, a2, b1, b2) << '\n';

}

bool segmentIntersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2) {
    double ccw1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    double ccw2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
    // 두 선분이 한직선
    if (ccw1 == 0 && ccw2 == 0) {
        // a1<a2 and b1<b2
        if (a2 < a1) swap(a1, a2);
        if (b2 < b1) swap(b1, b2);
        return !(a2 < b1 || b2 < a1);
    }
    // 평행하지 않은 case(둘다 0아님) + 한점에서 만나는 케이스 (둘중 하나만 0)
    else
        return ccw1 <= 0.0 && ccw2 <= 0.0;
}