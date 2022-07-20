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
const int CHILD = 26;

inline int toNumber(char c) {
    return c - 'a';
}
struct Node;
int newNode();
vector<Node> trie;

struct Node {
    map<int, int> children;
    // aho-corasick
    int fail;
    int maxLen;

    Node() {
        fail = -1;
        maxLen = 0;
        children = map<int, int>();
    } 
};
void insert(int node, const char* key, int len) {
    if (*key == 0) {
        trie[node].maxLen = len;
        return;
    }
    int child = toNumber(*key);

    if (trie[node].children.count(child) == 0)
        trie[node].children[child] = newNode();

    insert(trie[node].children[child], key + 1, len);
}
int newNode() {
    trie.push_back(Node());
    return (int)trie.size() - 1;
}

int N, M;
void makeFail(int root);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    cin >> N;
    string s; cin >> s;
    cin >> M;
    int root = newNode();

    for (int i = 0; i < M; ++i) {
        string temp;
        cin >> temp;
        insert(root ,temp.c_str(), temp.length());
    }
    makeFail(root);

    vector<bool> canReplace(s.size(), false);

    int matched = root;
    for (int i = 0; i < s.length(); ++i) {
        int c  = toNumber(s[i]);
        while (matched != root && trie[matched].children.count(c) == 0)
            matched = trie[matched].fail;

        if (trie[matched].children.count(c) > 0) {
            matched = trie[matched].children[c];
        }
        
        for (int j = 0; j < trie[matched].maxLen; ++j)
            canReplace[i - j] = true;
    }

    int cnt = 0;
    for_each(canReplace.begin(), canReplace.end(),
        [&cnt](bool b) {cnt += (b == false); });
    cout << cnt << '\n';
}

void makeFail(int root)
{
    trie[root].fail = root;

    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (int i = 0; i < CHILD; ++i) {
            if (trie[here].children.count(i) ==0)
                continue;
            int child = trie[here].children[i];

            // fail
            if (here == root) {
                trie[child].fail = root;
            }
            else {
                int fail = trie[here].fail;
                while (fail != root && trie[fail].children.count(i) == 0 )
                    fail = trie[fail].fail;

                if (trie[fail].children.count(i) >0)
                    fail = trie[fail].children[i];
                trie[child].fail = fail;
            }
            // res
            trie[child].maxLen = max(trie[child].maxLen, trie[trie[child].fail].maxLen);
            q.push(child);
        }
    }
}