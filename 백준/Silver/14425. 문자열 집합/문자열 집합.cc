#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;


const int LETTER = 26;
inline int childIndex(char c) {
    return c - 'a';
}

struct Node {
    Node* children[LETTER];
    bool terminal;

    Node() : terminal(false) {
        memset(children, 0, sizeof(children));
    }
    ~Node() {
        for (int i = 0; i < LETTER; ++i)
            delete children[i];
    }

    void insert(const char* key) {
        if (*key == 0) {
            terminal = true;
            return;
        }

        int chidx = childIndex(*key);
        if (children[chidx] == NULL)
            children[chidx] = new Node();
        children[chidx]->insert(key + 1);
    }

    Node* search(const char* key) {
        if (*key == 0) return this;
        int chidx = childIndex(*key);
        if (children[chidx] == NULL) return NULL;
        return children[chidx]->search(key + 1);
    }
};





int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    Node* trie = new Node();

    while (n--) {
        string s; cin >> s;
        trie->insert(s.c_str());
    }
    int ans = 0;
    while (m--) {
        string s; cin >> s;
        Node* finded = trie->search(s.c_str());
        if (finded != NULL && finded->terminal) ans++;
    }
    cout << ans << el;
}
