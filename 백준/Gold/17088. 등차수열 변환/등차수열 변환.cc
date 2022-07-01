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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int dir[6][4] = { // 1~5
    {0,0,0,0},
    {1,0,0,0}, 
    {1,0,1,0}, 
    {1,1,0,0},
    {1,1,1,0},
    {1,1,1,1}
};


int N;
int b[100000];
int fun(int idx, int before, int d);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    // 1
    if (N <= 2) {
        cout << 0 << endl;
        return 0;
    }

        

    int ans = INF;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int d = (b[1] + j) - (b[0] + i);
            int use = (i ? 1 : 0) + (j ? 1 : 0);
            int temp = fun(2, b[1] + j, d);
            if (temp != -1)
                ans = min(ans, temp + use);
        }
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}

// idx from 2
int fun(int idx, int before, int d)
{
    if (idx == N)
        return 0;

    int need = d - (b[idx] - before);
    if (need > 1 || need < -1)
        return -1;

    int temp = fun(idx + 1, b[idx] + need, d);
    if (temp == -1)
        return -1;
    else
        return fun(idx + 1, b[idx] + need, d) + (need ? 1 : 0);
}