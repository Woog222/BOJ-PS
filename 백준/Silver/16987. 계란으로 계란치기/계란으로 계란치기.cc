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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int fun(int idx, vector<pii>& eggs);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n; 
    cin >> n;
    vector<pii> eggs(n);
    for (int i = 0; i < n; ++i) {
        int weight, stat;
        cin >> stat >> weight;
        eggs[i] = make_pair(stat, weight);
    }

    cout << fun(0, eggs) << endl;
}

int fun(int idx, vector<pii>& eggs)
{
    if (idx == eggs.size())
    {
        int ret = 0;
        for (pii egg : eggs)
            if (egg.first <= 0)
                ret++;

        return ret;
    }
    // 깨졌으면 다음거 들기
    if (eggs[idx].first <= 0)
        return fun(idx+1, eggs);

    bool hit = false;
    int ret = 0;
    for (int i = 0; i < eggs.size(); ++i) {
        if (i == idx || eggs[i].first<=0 ) continue;

        eggs[i].first -= eggs[idx].second;
        eggs[idx].first -= eggs[i].second;
        hit = true;
        ret = max(ret, fun(idx + 1, eggs));
        eggs[i].first += eggs[idx].second;
        eggs[idx].first += eggs[i].second;
    }

    if (hit == false)
        return fun(idx + 1, eggs);
    else
        return ret;
}