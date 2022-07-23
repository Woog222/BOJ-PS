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
const int MOD = 10007;


string grid[64];
int N;
void fun(int r, int c, int len);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
   
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];
    fun(0, 0, N);

}

// -1이면
//0,0,N
void fun(int r, int c, int len)
{
    if (len == 1) {
        cout << grid[r][c];
        return;
    }
    bool ok = true;
    char letter = grid[r][c];
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (grid[r + i][c + j] != letter) {
                ok = false;
                i = len;
                break;
            }
        }
    }
    if (ok) {
        cout << letter;
        return;
    }
    
    cout << '(';
    fun(r, c, len / 2);
    fun(r, c + len / 2, len / 2);
    fun(r + len / 2, c, len / 2);
    fun(r + len / 2, c + len / 2, len / 2);
    cout << ')';
}