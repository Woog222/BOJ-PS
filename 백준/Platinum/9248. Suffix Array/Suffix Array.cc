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

}

vi suffixArray(const string& s)
{
    int n = s.size();
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = i;

    vector<int> group(n + 1);
    group[n] = -1; // 이걸 이해하면 전부 이해한 것
    // 우선 길이 1만큼만 정렬돼있음 (아스키코드값 그대로 넣기)
    for (int i = 0; i < n; ++i)
        group[i] = s[i];

    int t = 1;
    while (true) {
        Comp comp(group, t);
        // 현재 t길이까지 정렬돼있고, 이정보를이용해 2t까지 정렬
        sort(ret.begin(), ret.end(), comp);
        t *= 2;
        if (t >= n) break;

        // 2*t까지 정렬한 정보를 갱신
        vector<int> newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[ret[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (comp(ret[i - 1], ret[i]))
                newGroup[ret[i]] = newGroup[ret[i - 1]] + 1;
            else
                newGroup[ret[i]] = newGroup[ret[i - 1]];
        }
        swap(group, newGroup);
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