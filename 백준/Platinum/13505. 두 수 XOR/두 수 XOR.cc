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

inline int toNumber(char c) {
    return c - '0';
}

struct Node {
    bool valid;
    Node* children[2];

    Node() : valid(false) {
        memset(children, 0, sizeof(children));
    }

    ~Node() {
        for (int i = 0; i < 2; ++i)
            delete children[i];
    }

    void insert(const char* key)
    {
        if (*key == 0) {
            this->valid = true;
            return;
        }

        int child = toNumber(+*key);
        if (children[child] == NULL)
            children[child] = new Node();

      

        children[child]->insert(key+1);
    }

    bool search(const char* key)
    {
        if (*key == 0)
            return true;
        int child = toNumber(+*key);
        
        if (children[child] == NULL)
            return false;

        return children[child]->search(key + 1);
    }
    // exp : key.size()-1로 시작, 마지막에 -1로 끝남
    int cal(const char* key, int exp) {
        if (*key == 0)
            return 0;

        int cur = toNumber(*key);
        if (children[1 - cur] != NULL)
            return (1 << exp) + children[1 - cur]->cal(key + 1, exp - 1);
        else 
            return children[cur]->cal(key + 1, exp - 1);
        
    }
};

string int2bit(int n);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    Node* trie = new Node();
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        string s = int2bit(num);
        trie -> insert(s.c_str());
        ans = max(ans, trie-> cal(s.c_str(), s.size()-1) );
    }

    cout << ans << '\n';
}

string int2bit(int n)
{
    vector<char> ret;
    for (int i = 29; i >= 0; --i)
        ret.push_back(!!(n & (1<<i)) + '0');

    return string(ret.begin(), ret.end());
}
