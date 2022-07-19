#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N = 3;
double findIntegerRoot(const vector<ll>& coef);
ll determinant(const vector<ll>& coef);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(4);

    int t; cin >> t;
    while (t--)
    {
        vector<ll> coef(4);
        for (int i = 0; i <= 3; ++i)
            cin >> coef[3 - i];
        
        
        double root = findIntegerRoot(coef);

        vector <ll> ncoef(3);
        ncoef[0] = (root == 0.0) ? coef[1] : -coef[0] / (ll)root;
        ncoef[1] = coef[2] + coef[3] * root;
        ncoef[2] = coef[3];

        vector<double> ans;
        ans.push_back(root);
        ll deter = determinant(ncoef);
        if (deter > 0) {

            double a = (-ncoef[1] + sqrt(deter)) / (2.0 * ncoef[2]);
            double b = (-ncoef[1] - sqrt(deter)) / (2.0 * ncoef[2]);
            if (fabs(a-root) > 1e-4)
                ans.push_back(a);
            if (fabs(b-root) > 1e-4)
                ans.push_back(b);
        }
        else if (deter == 0) {
            

            double a = -ncoef[1] / (2.0 * ncoef[2]);
            if (fabs(a - root) > 1e-4)
                ans.push_back(a);
        }

        sort(ans.begin(), ans.end());
        for (double d : ans)
            cout << d << " ";
        cout << '\n';
    }
}

ll determinant(const vector<ll>& coef) {
    
    
    ll a = coef[2], b = coef[1], c = coef[0];
    //cout << a << " " << b << " " << c << endl;
    return (b * b - 4.0 * a * c);
}

double findIntegerRoot(const vector<ll>& coef)
{
    for (ll i = -1000000ll; i <= 1000000ll; ++i) {
        if (i == 0LL) {
            if (coef[0] == 0)
                return 0;
            continue;
        }

        if ((coef[0] % i) == 0) {
            ll val = coef[0] / i + coef[1] + coef[2] * i + coef[3] * i * i;
            if (val == 0)
                return (double)i;
        }
    }
    // never reach here
    assert(0);
    return -1.0;
}