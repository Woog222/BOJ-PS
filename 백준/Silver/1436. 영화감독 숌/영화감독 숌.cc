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


int fun(int n);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    int n; cin >> n;
    cout << fun(n) << '\n';
    
}

bool check(int num)
{
    string numStr = to_string(num);
    
    int cnt = 0;
    for (int i = 0; i < numStr.length(); ++i) {
        if (numStr[i] == '6') {
            if (++cnt == 3)
                return true;
        }
        else
            cnt = 0;
    }
    return false;
}

int fun(int n)
{
    for (int i = 1; i <= 10000666; ++i) {
        if (check(i)) {
            if (--n == 0)
                return i;
        }
    }
}