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
    return c - 'a';
}

struct Node {
    int terminal;
    Node* children[26];
    
    //aho corasick fail
    Node* fail;
    vector<int> res;

    Node() : terminal( -1) {
        memset(children, 0, sizeof(children));
    }

    ~Node() {
        for (int i = 0; i < 26; ++i)
            delete children[i];
    }

    void insert(const char* key, int idx)
    {
        if (*key == 0) {
            this->terminal = idx;
            return;
        }

        int child = toNumber(+*key);
        if (children[child] == NULL)
            children[child] = new Node();

        children[child]->insert(key+1, idx);
    }

    bool search(const char* key)
    {
        if (*key == 0)
            return this;
        int child = toNumber(+*key);
        
        if (children[child] == NULL)
            return false;

        return children[child]->search(key + 1);
    }
};


void makeFail(Node* root);
bool AhoCorasick(Node* root, const string& h);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    Node* trie = new Node();
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        trie->insert(s.c_str(), i);
    }
    makeFail(trie);

    cin >> n;
    while (n--)
    {
        string h; cin >> h;
        if (AhoCorasick(trie, h))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    
}

bool AhoCorasick(Node* root, const string& h)
{
    int n = h.length();

    Node* matched = root;
    for (int i = 0; i < n; ++i)
    {
        int temp = toNumber(h[i]);
        while (matched != root && matched->children[temp] == NULL)
            matched = matched->fail;

        if (matched->children[temp] != NULL) {
            matched = matched->children[temp];
            if (matched->res.size() > 0)
                return true;
        }
    }

    return false;
}

void makeFail(Node* root)
{
    queue<Node*> q;
    root->fail = root;
    q.push(root);

    while (!q.empty())
    {
        Node* cur = q.front(); q.pop();
        
        for (int i = 0; i < 26; ++i)
        {
            if (cur->children[i] == NULL)
                continue;

            Node* child = cur->children[i];
            if (cur == root) {
                child->fail = root;
                if (child->terminal != -1)
                    child->res.push_back(child->terminal);
                q.push(child);
                continue;
            }

            // calculating fail Node
            Node* fail = cur->fail;
            while (fail != root && fail->children[i] == NULL)
                fail = fail->fail;
            if (fail->children[i] != NULL)
                fail = fail->children[i];
            child->fail = fail;
            // output process
            child->res = fail->res;
            if (child->terminal != -1)
                child->res.push_back(child->terminal);
            // 
            q.push(child);
        }
    }
}
