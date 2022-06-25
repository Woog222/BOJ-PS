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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N;
string grid[20];


int main()
{
    
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << min(4, (m + 1) / 2) << endl;
        return 0;
    }

    // n>=3 
    if (m < 7)
    {
        cout << min(4, m) << endl;
        return 0;
    }
    
    // m >= 7
    cout << 4 + m - 6 << endl;
}