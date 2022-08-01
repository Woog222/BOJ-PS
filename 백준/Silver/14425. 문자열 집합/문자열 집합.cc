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

struct Trie {
    struct Node {
        int children[LETTER];
        bool terminal;
        Node() : terminal(false) {
            memset(children, -1, sizeof(children));
        }
    };

    vector<Node> trie;
    int root;

    Trie() {
        root = newNode();
    }

    int newNode() {
        trie.push_back(Node());
        return (int)trie.size() - 1;
    }

    void insert(const string& s) {
        insert(s.c_str(), root);
    }

    void insert(const char* key, int node) {
        if (*key == 0) {
            trie[node].terminal = true;
            return;
        }
        int chidx = childIndex(*key);
        if (trie[node].children[chidx] == -1)
            trie[node].children[chidx] = newNode();

        insert(key + 1, trie[node].children[chidx]);
    }

    bool search(const string& s) {
        int idx = search(s.c_str(), root);
        if (idx == -1 || !trie[idx].terminal) return false;
        return true;
    } 

    int search(const char* key, int node) {
        if (*key == 0) return node;

        int chidx = childIndex(*key);
        if (trie[node].children[chidx] == -1) return -1;
        return search(key + 1, trie[node].children[chidx]);
    }

};





int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    Trie trie;

    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }
    int ans = 0;
    while (m--) {
        string s; cin >> s;
        if (trie.search(s)) ans++;
    }

    cout << ans << el;
}