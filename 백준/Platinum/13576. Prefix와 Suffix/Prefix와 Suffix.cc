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
const int INF = 987654321;

vi makeFail(const string& s);
int kmp(const string& s, const string& t);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    string a; cin >> a;
    vi fail = makeFail(a);
    vi cnt(a.length()+1, 0);
    for (int i = 0; i < a.length(); ++i) {
        cnt[fail[i]]++;
    }

    for (int i = a.length(); i > 0; --i) {
        cnt[fail[i - 1]] += cnt[i];
    }

    vector<pii> ans; // (length, freq)

    int len = a.length();
    while (len != 0) {
        ans.emplace_back(len, cnt[len]+1);
        len = fail[len - 1];
    }

    cout << ans.size() << '\n';
    for (auto riter = ans.rbegin(); riter != ans.rend(); ++riter) {
        cout << riter ->first << " " <<  riter->second << '\n';
    }
}

vi makeFail(const string& s)
{
    int n = s.length();
    vi fail(n, 0);

    int matched = 0;
    for (int i = 1; i < n; ++i) {
        while (matched > 0 && s[matched] != s[i])
            matched = fail[matched - 1];

        if (s[matched] == s[i])
            fail[i] = ++matched;
        else
            fail[i] = 0;
    }

    return fail;
}

int kmp(const string& s, const string& t) {
    vi fail = makeFail(t);

    int n = s.length();
    int ret = 0;
    int matched = 0;
    for (int i = 0; i < n; ++i) {
        while (matched > 0 && s[i] != t[matched])
            matched = fail[matched - 1];

        if (s[i] == t[matched])
        {
            matched++;
            if (matched == t.length()) {
                matched = fail[matched - 1];
                ret++;
            }
        }
    }

    return ret;
}