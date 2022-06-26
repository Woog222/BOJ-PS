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
const int INF = 987654321;


int N;
int a[500000];
ll merge_sort(int lo, int hi);
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    cout << merge_sort(0, N - 1) << endl;
}

ll merge(int lo, int mid, int hi)
{
    vi temp(hi - lo + 1); 

    int i = lo;
    int j = mid + 1;
    int idx = 0;
    ll ret = 0;

    while (i <= mid && j <= hi) 
    {
        if (a[i] <= a[j]) {
            temp[idx++] = a[i++];
            ret += (ll)(j - mid - 1);
        }
        else {
            temp[idx++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[idx++] = a[i++];
        ret += (ll)(j - mid - 1);
    }
        
    while (j <= hi)
        temp[idx++] = a[j++];

    for (int i = 0; i < temp.size(); ++i)
        a[i + lo] = temp[i];

    return ret;
}

ll merge_sort(int lo, int hi)
{
    if (lo == hi)
        return 0;

    ll ret = 0;
    int mid = (lo + hi) / 2;

    ret += merge_sort(lo, mid);
    ret += merge_sort(mid + 1, hi);
    ret += merge(lo, mid, hi);

    return ret;
}