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
    string s;
    cin >> s;

    int ans = 0;
    int temp = 0;
    bool minus = false;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if ( is_digit(c) ) 
        {
            temp *= 10;
            temp += c - '0';
        }
        else if ( c == '+') 
        {
            if (minus)
                ans -= temp;
            else
                ans += temp;

            temp = 0;
        }
        else if (c == '-') 
        {
            if (minus) 
                ans -= temp;            
            else
                ans += temp;

            temp = 0;
            minus = true;
        }
    }

    if (minus)
        ans -= temp;
    else
        ans += temp;


    cout << ans << endl;
}