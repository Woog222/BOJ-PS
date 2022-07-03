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

struct Block {
    vi h;
    int len;

    Block(vi temp) {
        h = temp;
        len = h.size();
    }
};

vector<Block> a[8];
bool flat(const vi& h, Block& block, int idx);
void makeBlock();
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    makeBlock();

    int c, b; cin >> c >> b;
    vi h(c);
    for (int i = 0; i < c; ++i)
        cin >> h[i];

    int ans = 0;
    for (Block block : a[b]) {
        for (int i = 0; i + block.len <= c; ++i) {
            if (flat(h, block, i))
                ans++;
        }
    }

    cout << ans << endl;
}

bool flat(const vi& h, Block& block, int idx)
{
    int temp = h[idx] - block.h[0];
    for (int i = 0; i < block.len; ++i) {
        if (h[idx + i] - block.h[i] != temp)
            return false;
    }
    return true;
}

void makeBlock()
{
    a[1].emplace_back(vi{ 0 });
    a[1].emplace_back(vi{ 0,0,0,0 });

    a[2].emplace_back(vi{ 0,0 });

    a[3].emplace_back(vi{ 0,0,1 });
    a[3].emplace_back(vi{ 1,0 });

    a[4].emplace_back(vi{ 1,0,0 });
    a[4].emplace_back(vi{ 0,1 });

    a[5].emplace_back(vi{ 0,0,0 });
    a[5].emplace_back(vi{ 0,1 });
    a[5].emplace_back(vi{ 1,0 });
    a[5].emplace_back(vi{ 1,0,1 });

    a[6].emplace_back(vi{ 0,0,0 });
    a[6].emplace_back(vi{ 2,0 });
    a[6].emplace_back(vi{ 0,1,1 });
    a[6].emplace_back(vi{ 0,0 });

    a[7].emplace_back(vi{ 0,0,0 });
    a[7].emplace_back(vi{ 0,0 });
    a[7].emplace_back(vi{ 1,1,0 });
    a[7].emplace_back(vi{ 0,2 });
}