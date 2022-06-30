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
const int ALPHABET = 2;


struct TrieNode {

    TrieNode* child[ALPHABET];

    TrieNode() {
        memset(child, 0, sizeof(child));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABET; ++i)
            delete child[i];
    }
    // from 28
    void insert(int num, int idx) 
    {
        if (idx == -1) {
            return;
        }

        int bit = num & (1 << idx);
        bit = bit >> idx;

        if (child[bit] == NULL)
            child[bit] = new TrieNode();

        child[bit]->insert(num, idx - 1);
    }
    // from 28
    int  find(int num, int idx, int res) {
        if (idx == -1)
            return res;

        int bit = num & (1 << idx);
        bit = bit >> idx;

        if (child[1 - bit] != NULL)
            return child[1-bit] -> find(num, idx - 1, res + (1 << idx));
        else if (child[bit] != NULL)
            return child[bit]->find(num, idx - 1, res);
        // only when no element in trie
        return -1;
    }
};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    TrieNode* trie = new TrieNode();
    for (int i = 0; i < n; ++i)
    {
        int num; cin >> num;

        trie->insert(num, 29);
        ans = max(ans, trie->find(num, 29, 0));
    }

    delete trie;
    cout << ans << endl;
}
