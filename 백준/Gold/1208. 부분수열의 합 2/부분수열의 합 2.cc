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
const int MOD = 1000000007;


int a_hidden[4000001];
int b_hidden[4000001];
int* const a = a_hidden + 2000000;
int* const b = b_hidden + 2000000;

int arr[40];
void fun(int* const v, int idx, int sum, int to, bool);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    fun(a, 0, 0, n / 2 - 1, false);
    fun(b, n / 2 , 0, n-1, false);

    ll ans = (ll)a[s] + b[s];
    for (int i = -2000000; i <= 2000000; ++i) {
        int j = s - i;
        if (j >= -2000000 && j <= 2000000)
            ans += (ll)a[i] * b[j];
    }

    cout << ans << endl;
}

void fun(int* const v, int idx, int sum, int to, bool selected)
{
    if (idx > to) {
        if (selected)
            v[sum]++;
        return;
    }

    fun(v,idx + 1, sum, to, selected);
    fun(v,idx + 1, sum + arr[idx], to, true);
}