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

struct Node {
    bool valid;
    Node* children[26];

    Node() : valid(false) {
        memset(children, NULL, sizeof(children));
    }

    ~Node() {
        for (int i = 0; i < 26; ++i)
            delete children[i];
    }

    void insert(const char* key)
    {
        if (*key == 0) {
            this->valid = true;
            return;
        }


        if (children[*key - 'a'] == NULL)
            children[*key - 'a'] = new Node();

      

        children[*key - 'a']->insert(key+1);
    }

    bool search(const char* key)
    {
        if (*key == 0)
            return this->valid;

        Node* child = this->children[*key - 'a'];
        if (child == NULL)
            return false;

        return child->search(key+1);
    }
};


int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    Node* trie = new Node();
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string temp; cin >> temp;
        trie->insert(temp.c_str());
    }

    int ans = 0;
    while (m--) {
        string s; cin >> s;
        if (trie->search(s.c_str()))
            ans++;
    }

    cout << ans << endl;
}