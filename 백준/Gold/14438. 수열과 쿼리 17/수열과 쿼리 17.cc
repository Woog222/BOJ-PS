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
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

struct SegTree {
    int n;
    vi tree;

    //Constructor
    SegTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(n * 4); // 1<<(log2(n)+1)로 해도된다
        init(arr, 0, n - 1, 1);
    }

    // 전처리 O(NlogN)
    int init(const vector<int>& arr, int lo, int hi, int node) {
        if (lo == hi)
            return tree[node] = arr[lo];

        int mid = (lo + hi) / 2;
        int leftVal = init(arr, lo, mid, node * 2);
        int rightVal = init(arr, mid + 1, hi, node * 2 + 1);
        return tree[node] = min(leftVal, rightVal);
    }

    // Query O(logN)
    int query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1);
    }
    int query(int lo, int hi, int node, int nodelo, int nodehi) {
        if (nodehi < lo || hi < nodelo) return INF;
        if (lo <= nodelo && nodehi <= hi) {
            return tree[node];
        }

        int mid = (nodelo + nodehi) / 2;
        int leftVal = query(lo, hi, node * 2, nodelo, mid);
        int rightVal = query(lo, hi, node * 2 + 1, mid + 1, nodehi);
        return min(leftVal, rightVal);
    }

    // Update(log N)
    void update(int idx, int newVal) {
        update(idx, newVal, 1, 0, n - 1);
    }
    void update(int idx, int newVal, int node, int nodelo, int nodehi) {
        if (idx < nodelo || nodehi < idx) return;
        if (nodelo == nodehi) {
            tree[node] = newVal;
            return;
        }
        

        int mid = (nodelo + nodehi) / 2;
        update(idx, newVal, node * 2 + 1, mid + 1, nodehi);
        update(idx, newVal, node * 2, nodelo, mid);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
};

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegTree segtree(a);

    int q; cin >> q;
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 1) segtree.update(y - 1, z);
        else cout << segtree.query(y - 1, z - 1) << el;
    }
}
