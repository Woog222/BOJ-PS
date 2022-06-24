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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;


vi make_fail(const string& p);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string h, n;
    getline(cin, h);
    getline(cin, n);

    vi fail = make_fail(n);

    vi ans;
    int j = 0;
    for (int i = 0; i < h.size(); ++i) {

        while (j > 0 && h[i] != n[j]) j = fail[j - 1];

        if (h[i] == n[j]) {
            j++;
            if (j == n.size()) {
                ans.push_back(i - j + 1);
                j = fail[j - 1];
            }
                
        }
        else {
            //pass, i incrementing automatically
        }
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i+1 << '\n';


}

vi make_fail(const string& p)
{
    int N = p.size();
    vi fail(N);
    fail[0] = 0;

    int j = 0;
    for (int i = 1; i < N; ++i) 
    {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
        else // j=0 & not matched
            fail[i] = 0;
    }

    return fail;
}