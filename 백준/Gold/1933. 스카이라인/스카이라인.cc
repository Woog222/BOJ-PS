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
#include <ctime>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
const ll INF = 1987654321;
const ll MOD = 20090711;

struct Building {
    ll l, r, h;

    Building(ll _l=0, ll _r=0, ll _h=0) :
        l(_l), r(_r), h(_h) {}

    friend bool operator<(const Building& a, const Building& b) {
        return a.l < b.l;
    }
};


ll N;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    vector<Building> buildings(N);
    for (ll i = 0; i < N; ++i)
    {
        ll l, h, r;
        cin >> l >> h >> r;
        buildings[i].l = l;
        buildings[i].h = h;
        buildings[i].r = r;
    }

    sort(buildings.begin(), buildings.end());

    priority_queue<pii> pq;

    ll h, cur;
    auto iter = buildings.begin();
    h = cur = 0;

    while (!pq.empty() || iter != buildings.end())
    {
       
        // 바닥인 경우(pq 비어있음)
        if (h == 0) 
        {
            cur = iter->l;
            while (iter != buildings.end() && iter->l == cur) {
                pq.emplace(iter->h, iter->r);
                ++iter;
            }

            h = pq.top().first;
            cout << cur << " " << h << " ";
            continue;
        }

        // 현재 건물인 경우 (pq 차있음)
        ll end = pq.top().second;

        // 새 빌딩만 만남
        if (iter != buildings.end() && iter->l < end) 
        {
            cur = iter->l;
            // cur에서 시작하는 건물 다 넣고
            while (iter != buildings.end() && iter->l == cur) {
                pq.emplace(iter->h, iter->r);
                ++iter;
            }
            // 더 높은 건물 있으면 출력
            if (h < pq.top().first) {
                h = pq.top().first;
                cout << cur << " " << h << " ";
            }
        }
        // 끝만 만남 (건물 이미 다 지나갔거나 끝이 더 가까움)
        // 건물 다 지나가고 후처리만 하는 경우도 여기서 처리됨
        else if (iter == buildings.end() || end < iter->l) 
        {
            cur = end;
            // 여기서 끝이거나 이미 끝난거 다 빼기
            while (!pq.empty() && pq.top().second <= cur) 
                pq.pop();
            
            ll prev_h = h;
            if (pq.empty())
                h = 0;
            else
                h = pq.top().first;

            if (h < prev_h) {
                cout << cur << " " << h << " ";
            }
        }
        // 둘다 같이 만남 (iter아직 남아있고 end == iter->l)
        else
        {
            cur = end;

            // 우선 새거 다 넣자
            while (iter != buildings.end() && iter->l == cur) {
                pq.emplace(iter->h, iter->r);
                ++iter;
            }
            // 그리고 여기서 끝나는 거 다 빼자
            while (!pq.empty() && pq.top().second <= cur)
                pq.pop();

            // pq가 비어있을 수는 없다, 새거 넣엇으므로.
            if (h != pq.top().first) {
                h = pq.top().first;
                cout << cur << " " << h << " ";
            }
        }
    }// while

    cout << endl;
}