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
const int MOD = 1000000007;

int dr[] = { -1,   -1, 1, 0, 0 };
int dc[] = { -1,    0, 0, 1,-1 };
int opposite[] = { 0,2,1,4,3 };
int N, M;


inline bool valid(int r, int c) {
    return r >= 1 && r <= N && c >= 1 && c <= M;
}

struct Shark {
    int r, c, s, d, z;
    Shark(int _r, int _c, int _s, int _d, int _z) :
        r(_r), c(_c), s(_s), d(_d), z(_z) 
    {
        if (d == 1 || d == 2) 
            s %= (N - 1) * 2;
        else
            s %= ( M- 1) * 2;
    }

    bool operator == (const Shark& b) const {
        return (r == b.r) && (c == b.c);
    }
    bool operator < (const Shark& b) const {
        return (r == b.r) ? (c < b.c) : r < b.r;
    }

    void move() {
        int cnt = s;
        while (cnt--) {
            r += dr[d];
            c += dc[d];
            if (!valid(r, c)) {
                r -= 2 * dr[d];
                c -= 2 * dc[d];
                d = opposite[d];
            }
        }
    }
};

vector<Shark> sharks;


int main()
{
    cin >> N >> M;
    int k; cin >> k;
    while (k--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.emplace_back(r, c, s, d, z);
    }
    sort(sharks.begin(), sharks.end());
    int ans = 0;
    for (int j = 1; j <= M; ++j) {
        // 잡고
        for (int i = 0; i < sharks.size(); ++i) {
            if (sharks[i].c == j) {
                ans += sharks[i].z;
                sharks.erase(sharks.begin() + i);
                break;
            }
        }

        // 상어들 이동
        for_each(sharks.begin(), sharks.end(), [](Shark& shark) {shark.move(); });
        sort(sharks.begin(), sharks.end());
        // 상어 중복 제거
        vi delidx;
        for (int i = 0; i < sharks.size(); ++i) {
            int lo = i, hi = i;
            int big = sharks[lo].z;
            int idx = lo;
            while (hi + 1 < sharks.size() && sharks[hi + 1] == sharks[lo]) {
                hi++;
                if (sharks[hi].z > big) {
                    idx = hi;
                    big = sharks[hi].z;
                }
            }
            if (lo < hi) {
                for (int k = lo; k <= hi; ++k)
                    if (k != idx)
                        delidx.push_back(k);
                i = hi;
            }
        } // for
        for (int i = (int)delidx.size() - 1; i >= 0; --i)
            sharks.erase(sharks.begin() + delidx[i]);
    }

    cout << ans << el;
}