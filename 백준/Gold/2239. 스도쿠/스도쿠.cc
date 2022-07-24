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
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


string grid[9];
bool row[9][10];
bool col[9][10];
bool sq[9][10];

bool fun(int k);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < 9; ++i)
        cin >> grid[i];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] != '0') {
                int num = grid[i][j] - '0';
                row[i][num] = true;
                col[j][num] = true;
                sq[ (i/3)*3 + (j/3)][num] = true;
            }
        }
    }
    fun(0);
}

bool fun(int k)
{
    if (k == 81) {
        // print
        for (int i = 0; i < 9; ++i) 
            cout << grid[i] << el;
        return true;
    }
    int r = k / 9;
    int c = k % 9;
    if (grid[r][c] != '0')
        return fun(k + 1);

    int sqidx = (r / 3) * 3 + (c / 3);
    for (int cur = 1; cur <= 9; ++cur) {
        if (!row[r][cur] && !col[c][cur] && !sq[sqidx][cur]) {
            row[r][cur] = col[c][cur] = sq[sqidx][cur] = true;
            grid[r][c] = cur + '0';
            if (fun(k + 1))
                return true;
            grid[r][c] = '0';
            row[r][cur] = col[c][cur] = sq[sqidx][cur] = false;
        }
    }
    return false;
}