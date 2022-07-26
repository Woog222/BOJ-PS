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

int group[500001];
int t = 1;

struct Comp {
    const vector<int>& group;
    int t;
    Comp(const vector<int>& _group, int _t) : group(_group), t(_t) {}

    bool operator() (int i, int j) {
        return (group[i] == group[j])
            ? group[i + t] < group[j + t]
            : group[i] < group[j];
    }
};

vi suffixArray(const string& s);
vi commonPrefix(const string& s, const vi& sa);
int main() 
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    string s; cin >> s;
    vi sa = suffixArray(s);
    vi cp = commonPrefix(s, sa);

    for (int i : sa) cout << i+1 << " ";
    cout << el;
    for_each(cp.begin(), cp.end(), [](int a) {
        if (a == -1) cout << 'x' << " ";
        else cout << a << " "; });
    cout << el;
}


vector<int> suffixArray(const string& s)
{
    int n = s.size(), m = max(256, n) + 1;
    vector<int> ret(n), group(2 * n), nextGroup(2 * n), cnt(m), idx(n);

    for (int i = 0; i < n; ++i)
        ret[i] = i, group[i] = s[i];

    int t = 1;
    while (true) {
        // 이번엔 람다로 구현
        auto comp = [&](int i, int j) {
            return (group[i] == group[j])
                ? (group[i + t] < group[j + t])
                : (group[i] < group[j]);
        };
        // group[i+t]
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) cnt[group[i + t]]++;
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) idx[--cnt[group[i + t]]] = i;
        // group[i]
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) cnt[group[i]]++;
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) ret[--cnt[group[idx[i]]]] = idx[i];

        nextGroup[ret[0]] = 1;
        for (int i = 1; i < n; ++i)
            nextGroup[ret[i]] = nextGroup[ret[i - 1]] + comp(ret[i - 1], ret[i]);
        
        t *= 2;
        swap(group, nextGroup);
        if (group[ret[n - 1]] == n) break;
    }

    return ret;
}

vi commonPrefix(const string& s, const vi& sa)
{
    int n = sa.size();
    vi isa(n);
    for (int i = 0; i < n; ++i) isa[sa[i]] = i;

    vi ret(n);
    ret[0] = -1;
    for (int i = 0, k = 0; i < n; ++i, k = max(k - 1, 0)) {
        if (isa[i] == 0) continue;

        int j = sa[isa[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        ret[isa[i]] = k;
    }

    return ret;
}