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

vi getSuffixArray(const string& s);
vi commonPrefix(const string& s, const vi& sa);
int main() {
    string s; cin >> s;
    vi sa = getSuffixArray(s);
    vi cp = commonPrefix(s, sa);

    ll ans = s.length();
    ans = ans * (ans + 1) / 2;

    for (int i = 1; i < s.length(); ++i) {
        ans -= cp[i];
    }
    cout << ans << el;
}
vi commonPrefix(const string& s, const vi& sa) {
    int n = sa.size();
    vi isa(n), ret(n);
    for (int i = 0; i < n; ++i) isa[sa[i]] = i;

    ret[0] = -1;
    for (int i = 0, k = 0; i < n; ++i, k = max(k - 1, 0)) {
        if (isa[i] == 0) continue;

        int j = sa[isa[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        ret[isa[i]] = k;
    }
    return ret;
}

vi getSuffixArray(const string& s)
{
    int n = s.size();
    vi ret(n), group(n + 1), ngroup(n + 1);

    group[n] = -1;
    for (int i = 0; i < n; ++i) ret[i] = i;
    for (int i = 0; i < n; ++i) group[i] = s[i];

    int t = 1;
    while (true) {
        auto comp = [&](int i, int j) {
            if (group[i] == group[j]) return group[i + t] < group[j + t];
            else return group[i] < group[j];
        };

        sort(ret.begin(), ret.end(), comp);

        ngroup[n] = -1;
        ngroup[ret[0]] = 0;
        for (int i = 1; i < n; ++i) {
            ngroup[ret[i]] = ngroup[ret[i-1]] + comp(ret[i - 1], ret[i]);
        }

        swap(group, ngroup);
        t *= 2;
        if (group[ret[n - 1]] == n-1) break;
    }

    return ret;
}