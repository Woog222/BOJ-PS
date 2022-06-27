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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 1987654321;
const int MOD = 20090711;


struct RMQ {

    int n;

    vi rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(4 * n);
        init(array, 0, n - 1, 1);
    }

    int query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1);
    }

    void update(int idx, int nval) {
        update(idx, nval, 1, 0, n - 1);
    }

private:
    int init(const vi& array, int lo, int hi, int idx) 
    {
        if (lo == hi)
            return rangeMin[idx] = array[lo];

        int mid = (lo + hi) / 2;
        int leftMin = init(array, lo, mid, idx * 2);
        int rightMin = init(array, mid + 1, hi, idx * 2 + 1);

        return rangeMin[idx] = min(leftMin, rightMin);
    }

    int query(int lo, int hi, int node, int nodeLeft, int nodeRight)
    {
        if (lo <= nodeLeft && nodeRight <= hi)
            return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        int ret = INF;

        if (lo <= mid) {
            ret = min(ret, query(lo, hi, node * 2, nodeLeft, mid) );
        }
        if (mid < hi) {
            ret = min(ret, query(lo, hi, node * 2 + 1, mid + 1, nodeRight));
        }
        return ret;
    }

    int update(int idx, int nval, int node, int nodeLeft, int nodeRight) 
    {
        if (nodeLeft == nodeRight)
            return rangeMin[node] = nval;

        int mid = (nodeLeft + nodeRight) / 2;
        if (idx <= mid)
            rangeMin[node] = min(rangeMin[node], 
                                update(idx, nval, node * 2, nodeLeft, mid));
        else
            rangeMin[node] = min(rangeMin[node],
                update(idx, nval, node * 2+1, mid+1, nodeRight));

        return rangeMin[node];
    }
};



int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    RMQ seg = RMQ(arr);

    while (m--) {
        int lo, hi; cin >> lo >> hi;
        cout << seg.query(lo - 1, hi - 1) << '\n';
    }
}