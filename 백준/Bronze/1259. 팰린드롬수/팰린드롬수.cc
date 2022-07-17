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


bool isPalindrome(const string& s);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
   
    string s;
    while (cin >> s) {
        if (s == "0")
            break;
        if (isPalindrome(s))
            cout << "yes\n";
        else
            cout << "no\n";

    }
    
}

bool isPalindrome(const string& s)
{
    string reversed = string(s.rbegin(), s.rend());
    if (s == reversed)
        return true;
    else
        return false;
}