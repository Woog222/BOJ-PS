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
const int INF = -987654321;
const int NO_RESULT = -987654320;

ll cache[101][4][4][2];
string word;

bool is_vowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}

// 지금 idx이고, 직전까지 모음이 vowel개, 자음이 consonant개 연속되어 있었다.
// 전에 L이 포함되어 있었으면 TRUE
ll fun(int idx, int vowel, int consonant, bool L) 
{
    if (vowel >= 3 || consonant >= 3) {
        return 0;
    }
    if (idx == word.length()) {
        if (L)
            return 1;
        else
            return 0;
    }
    

    ll& ret = cache[idx][vowel][consonant][L ? 1 : 0];
    if (ret != -1)
        return ret;

    char now = word[idx];
    if ( now == '_')
    {
        ll temp_ret = 0;
        // vowel
        if (vowel <= 1)
            temp_ret += 5 * fun(idx + 1, vowel + 1, 0, L);
        // consonant
        if (consonant <= 1) {
            temp_ret += 20 * fun(idx + 1, 0, consonant + 1, L);
            temp_ret += fun(idx + 1, 0, consonant + 1, true);
        }
        return ret = temp_ret;
    }
    else
    {
        if (is_vowel(now)) {
            return ret = fun(idx + 1, vowel + 1, 0, L);
        }
        else if (now == 'L')
            return ret = fun(idx + 1, 0, consonant + 1, true);
        else 
            return ret = fun(idx + 1, 0, consonant + 1, L);
    }
}

int main() 
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> word;

    memset(cache, -1, sizeof(cache));
    cout << fun(0, 0, 0, false) << endl;
}