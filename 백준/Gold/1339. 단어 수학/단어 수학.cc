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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX = 50000000;

struct MY
{
    int bridge[26];

public:
    MY (const vector<char>& chars) 
    {
        memset(bridge, -1, sizeof(bridge));
        for (int i = 0; i < chars.size(); ++i) {
            char c = chars[i];
            bridge[c - 'A'] = i;
        }
    }

    inline int ctoidx(char c) {
        return bridge[c - 'A'];
    }


};
vector<int> perm;
int N;

int fun(const vector<string>& words, MY& my);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i)
        cin >> words[i];

    vector<char> chars;
    for (int i = 0; i < N; ++i) {
        for (char c : words[i])
            chars.push_back(c);
    }

    sort(chars.begin(), chars.end());
    chars.erase(unique(chars.begin(), chars.end()), chars.end());

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    MY my(chars);

    perm.resize(chars.size(), 0);
    int num = 9;
    for (int i = perm.size() - 1; i >= 0; --i) {
        perm[i] = num--;
    }


    int ans = 0;
    do {
        
        ans = max(ans, fun(words, my));
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;
}

int fun(const vector<string>& words, MY &my)
{
    int ret = 0;

    for (string word : words) 
    {
        int temp = 0;

        for (char c : word) {
            temp *= 10;
            temp += perm[my.ctoidx(c)];
        }

        ret += temp;
    }

    return ret;
}
