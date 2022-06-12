#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;



void add_num(string &ret, string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.length() != b.length()) {
        if (a.length() < b.length()) {
            a += "0";
        }
        else {
            b += "0";
        }
    }

    int len = a.length();
    int carry = 0;
    ret = "";
    for (int i = 0; i < len; ++i) {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        ret += (char)(temp % 10 + '0');
        carry = temp / 10;
    }

    if (carry > 0)
        ret += (char)(carry + '0');

    reverse(ret.begin(), ret.end());
}

int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    vector<string> f(10001);
    f[1] = "1";
    f[2] = "3";
    for (int i = 3; i <= 10000; ++i) {
        add_num( f[i], f[i - 1],  f[i - 2]);
    }

    int n;
    while (cin >> n) {
        cout << f[n] << '\n';
    }
}