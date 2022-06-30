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
#include <ctime>
#include <climits>


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 1987654321;
const int ALPHABET = 26;


int N;

inline int toNumber(char c) { return c - 'a'; }
struct TrieNode {

    TrieNode* child[ALPHABET];
    int terminal;
    TrieNode* fail;
    bool output;

    TrieNode() : terminal(-1), fail(NULL), output(false) {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABET; ++i)
            delete child[i];
    }

    void insert(const char* key, int id) 
    {
        if (*key == 0) {
            terminal = id;
            return;
        }

        int next = toNumber(*key);
        if (child[next] == NULL)
            child[next] = new TrieNode();

        child[next]->insert(key + 1, id);
    }

    TrieNode* find(const char* key) {
        if (*key == 0)
            return this;

        int next = toNumber(*key);
        if (child[next] == NULL)
            return NULL;
        return child[next]->find(key + 1);
    }
};

void make_fail(TrieNode* root);
bool AhoCorasick(TrieNode* root, const string& h);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    TrieNode* trie = new TrieNode();
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        trie->insert(words[i].c_str(), i);
    }
    make_fail(trie);


    // queries
    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        if (AhoCorasick(trie, s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    delete trie;
}

void make_fail(TrieNode* root)
{
    root->fail = root;

    queue<TrieNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TrieNode* here = q.front(); q.pop();

        for (int i = 0; i < ALPHABET; ++i) 
        {
            if (here->child[i] == NULL) continue;

            TrieNode* child = here->child[i];
            if (here == root) {
                child->fail = root;
                if (child->terminal != -1)
                    child->output = true;
                q.push(child);
                continue;
            }

            // find
            TrieNode* temp = here->fail;
            while (temp!=root && temp->child[i] == NULL)
                temp = temp->fail;
            if (temp->child[i] != NULL) temp = temp->child[i];

            // processing
            child->fail = temp;
            if (child->terminal != -1 || child->fail->output)
                child->output = true;

            // bfs push
            q.push(child);
        } // child for
    } // bfs while
}

bool AhoCorasick(TrieNode* root, const string& h)
{
    int len = h.length();
    TrieNode* matched = root;
    for (int i = 0; i < len; ++i)
    {
        int chld = toNumber(h[i]);
        while (matched != root && matched->child[chld] == NULL)
            matched = matched->fail;

        if (matched->child[chld] != NULL)
            matched = matched->child[chld];

        if (matched->output)
            return true;
    }

    return false;
}