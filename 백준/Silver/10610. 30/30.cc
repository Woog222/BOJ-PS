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
    string num;
    cin >> num;

    int digit_sum = 0;
    int zero_idx = -1;
    for (int i = 0; i<num.size(); ++i) {

        digit_sum += num[i] - '0';
        if (num[i] == '0') {
            zero_idx = i;
        }
    }

    if (digit_sum % 3 != 0 || zero_idx == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<char> ans(num.size());
    for (int i = 0; i < num.size()-1; ++i) {
        if (i != zero_idx)
            ans[i] = num[i];
        else {
            ans[i] = num.back();
        }
    }
    ans[num.size() - 1] = '0';


    sort(ans.begin(), ans.end() - 1, greater<char>());
    for (char c : ans)
        cout << c;
    cout << endl;

}