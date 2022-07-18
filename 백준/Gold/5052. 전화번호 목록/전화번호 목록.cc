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

    int terminal;
    Node* children[10];

    Node() {
        terminal = -1;
        memset(children, 0, sizeof(children));
    }

    void insert(const char* key, int num) {
        if (*key == 0) {
            this->terminal = num;
            return;
        }

        int child = toNumber(*key);
        if (children[child] == NULL)
            children[child] = new Node();

        children[child] -> insert(key + 1, num);
    }

    Node* search(const char* key) {
        if (*key == 0)
            return this;

        int child = toNumber(*key);
        if (children[child] != NULL)
            return children[child]->search(key + 1);
        else
            return NULL;
    }
};

const int scores[9] = { 0,0,0,1,1,2,3,5,11 };
const int dr[] = { -1,-1,-1,0,0,1,1,1 };
const int dc[] = { -1,0,1,-1,1,-1,0,1 };
string grid[4]; // input injected
Node* trie; // reused
vector<string> words; //swapped every test case
char temp[9];

bool isConsistency(Node* trie, const vector<string>& words);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int t; cin >> t;
    while (t-- > 0)
    {
        Node* trie = new Node();
        int n; cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
            trie->insert(words[i].c_str(), i);
        }
        if (isConsistency(trie, words))
            cout << "YES\n";
        else
            cout << "NO\n";

        



        delete(trie);
    }

    
}

bool isConsistency( Node* trie, const vector<string>& words)
{
    for (const string& word : words) {
        Node* terminal = trie->search(word.c_str());
        for (int i = 0; i < 10; ++i) {
            if (terminal->children[i] != NULL)
                return false;
        }
    }

    return true;
}