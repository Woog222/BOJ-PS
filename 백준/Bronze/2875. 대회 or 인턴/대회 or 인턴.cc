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

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int team = min(n / 2, m);
    int left = n - team * 2 + m - team;
    
    if (k > left) {
        team -= ((k - left) + 2) / 3;
    }

    cout << team << endl;
}