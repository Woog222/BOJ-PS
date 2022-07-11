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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const ll INF = 1LL << 62;

void input(vector<pair<pii, pii>>& teleport, pii& st, pii& end);
inline ll dist(pii a, pii b);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    vector<pair<pii, pii>> teleport(3);
    pii st, end;
    input(teleport, st, end);


    ll ans = dist(st, end);

    // 1
    for (int i = 0; i < 3; ++i) {
        ll temp = dist(st, teleport[i].first) + dist(end, teleport[i].second);
        ll temp2 = dist(st, teleport[i].second) + dist(end, teleport[i].first);
        ans = min(ans, min(temp, temp2) + 10);
    }

    // 2
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) continue;

            // st -> i -> j -> end
            pair<pii, pii>& a = teleport[i];
            pair<pii, pii>& b = teleport[j];

            ll st2af = dist(st, a.first);
            ll st2as = dist(st, a.second);
            ll end2bf = dist(end, b.first);
            ll end2bs = dist(end, b.second);
            ll af2bf = dist(a.first, b.first);
            ll af2bs = dist(a.first, b.second);
            ll as2bf = dist(a.second, b.first);
            ll as2bs = dist(a.second, b.second);

            ll temp = INF;
            temp = min(temp, st2af + as2bf + end2bs);
            temp = min(temp, st2af + as2bs + end2bf);
            temp = min(temp, st2as + af2bf + end2bs);
            temp = min(temp, st2as + af2bs + end2bf);

            ans = min(ans, temp + 20);
        }
    }

    // 3
    vector<int> order= { 0,1,2 };

    do {

        // c가 중간 (a -> c -> b)
        pair<pii, pii>& a = teleport[order[0]];
        pair<pii, pii>& b = teleport[order[1]];
        pair<pii, pii>& c = teleport[order[2]];

        ll st2af = dist(st, a.first);
        ll st2as = dist(st, a.second);
        ll end2bf = dist(end, b.first);
        ll end2bs = dist(end, b.second);
        ll af2bf = dist(a.first, b.first);
        ll af2bs = dist(a.first, b.second);
        ll as2bf = dist(a.second, b.first);
        ll as2bs = dist(a.second, b.second);

        ll temp = INF;
        temp = min(temp, st2af + end2bs
            + min(dist(a.second, c.first) + dist(c.second, b.first), dist(a.second, c.second) + dist(c.first, b.first))
        );
        temp = min(temp, st2af + end2bf
            + min(dist(a.second, c.first) + dist(c.second, b.second), dist(a.second, c.second) + dist(c.first, b.second))
        );
        temp = min(temp, st2as + end2bs
            + min(dist(a.first, c.first) + dist(c.second, b.first), dist(a.first, c.second) + dist(c.first, b.first))
        );
        temp = min(temp, st2as + end2bf
            + min(dist(a.first, c.first) + dist(c.second, b.second), dist(a.first, c.second) + dist(c.first, b.second))
        );

        ans = min(ans, temp + 30);

    } while ( next_permutation(order.begin(), order.end()) );

    cout << ans << endl;
}

inline ll dist(pii a, pii b)
{
    return (int)abs(a.first - b.first) + (int)abs(a.second - b.second);
}

void input(vector<pair<pii, pii>>& teleport, pii& st, pii& end)
{
    int x, y;
    cin >> x >> y;
    st = make_pair(x, y);
    cin >> x >> y;
    end = make_pair(x, y);


    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        teleport[i].first = pii(x, y);
        cin >> x >> y;
        teleport[i].second = pii(x, y);
    }
}