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
const double MAX = 500000000000.0;

struct Vector {
    double x, y;

    explicit Vector(double x=0, double y=0) :x(x), y(y) {}

    double norm() {
        return hypot(x, y);
    }

    Vector operator + (const Vector& b) const {
        return Vector(x + b.x, y + b.y);
    }
    Vector operator - (const Vector& b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector operator * (double r) const {
        return Vector(x *r, y *r);
    }
};

int N;
vector<pii> locs;
int ALLSELECTED;

double fun(int idx, int selected, Vector res);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(12);
    int t; cin >> t;
    while (t--)
    {
        cin >> N; locs.resize(N);
        ALLSELECTED = (1 << N) - 1;
        for (int i = 0; i < N; ++i) 
            cin >> locs[i].first >> locs[i].second;
        vector<Vector> lines;
        cout << fun(0, 0, Vector(0,0)) << el;
    }
}


// 0,0
double fun(int idx, int selected, Vector res)
{
    if (idx == N) {
        if (selected == N / 2)
            return res.norm();
        else
            return MAX;
    }

    Vector now = Vector(locs[idx].first, locs[idx].second);
    double ret = fun(idx + 1, selected, res - now);
    if (selected == N/2) 
        return ret;
    ret = min(ret, fun(idx + 1, selected + 1, res + now));

    return ret;
}
