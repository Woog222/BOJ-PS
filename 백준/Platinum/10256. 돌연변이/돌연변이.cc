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
const int ALPHABET = 4;

int idx[26];
int N, M;

inline int toNumber(char c) { return idx[c - 'A']; }
struct TrieNode {

    TrieNode* child[ALPHABET];
    int terminal;
    TrieNode* fail;
    int output;

    TrieNode() : terminal(-1), fail(NULL), output(0) {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABET; ++i)
            delete child[i];
    }

    bool insert(const char* key, int id) 
    {
        if (*key == 0) {
            if (terminal != -1)
                return false;
            else
                return terminal = id; //true
        }

        int next = toNumber(*key);
        if (child[next] == NULL)
            child[next] = new TrieNode();

        return child[next]->insert(key + 1, id);
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
int AhoCorasick(TrieNode* root, const string& h);
TrieNode* makeTrie(const string& marker);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    idx['A' - 'A'] = 0;
    idx['G' - 'A'] = 1;
    idx['T' - 'A'] = 2;
    idx['C' - 'A'] = 3;

    int t; cin >> t;
    while (t-- > 0){
        cin >> N >> M; // N : DNA길이, M :마커길이
        string dna, marker;
        cin >> dna >> marker;

        TrieNode* trie = makeTrie(marker);
        cout << AhoCorasick(trie, dna) << '\n';
        delete(trie);
    }
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
                    child->output = 1;
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
            child->output = child->fail->output;
            if (child->terminal != -1)
                child->output++;

            // bfs push
            q.push(child);
        } // child for
    } // bfs while
}

int AhoCorasick(TrieNode* root, const string& h)
{
    int len = h.length();

    int ret = 0;
    TrieNode* matched = root;
    for (int i = 0; i < len; ++i)
    {
        int chld = toNumber(h[i]);
        while (matched != root && matched->child[chld] == NULL)
            matched = matched->fail;

        if (matched->child[chld] != NULL)
            matched = matched->child[chld];

        ret += matched->output;
    }

    return ret;
}

TrieNode* makeTrie(const string& marker)
{
    int n = marker.size();
    char temp[101];
    strncpy(temp, marker.c_str(), n);
    temp[n] = 0;

    TrieNode* root = new TrieNode();
    int order = 0;

    // MY SELF
    if (root->insert(temp, order))
        order++;
    

    for (int mid = 2; mid <= n; ++mid) {
        for (int from = 0; from + mid <= n; ++from) {
            reverse(temp + from, temp + from + mid);
            if (root->insert(temp, order))
                order++;
            reverse(temp + from, temp + from + mid);
        }
    }

    make_fail(root);

    return root;
}