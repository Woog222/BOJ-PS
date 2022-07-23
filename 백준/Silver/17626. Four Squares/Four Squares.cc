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

vi a;
int cache[50001];
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    for (int i = 1; i <= 223; ++i) 
        a.push_back(i * i);
    int num; cin >> num;
    cache[1] = 1;
    for (int i = 2; i <= num; ++i) {
        int temp = INF;
        for (int next : a) {
            if (next > i) break;
            temp = min(temp, cache[i - next] + 1);
        }
        cache[i] = temp;
    }
    cout << cache[num] << '\n';
}