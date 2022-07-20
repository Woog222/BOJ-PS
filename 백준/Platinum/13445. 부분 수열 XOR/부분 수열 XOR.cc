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
const int MAX = 1000; // 백만

int toNumber(char c) {
    return c - '0';
}

struct Node {
    Node* children[2];
    bool terminal;
    int size;

    Node() {
        children[0] = children[1] = NULL;
        terminal = false;
        size = 0;
    }
    ~Node() {
        delete children[0];
        delete children[1];
    }
    
    void insert(const char* key) {
        this->size++;
        if (*key == 0) {
            terminal = true;
            return;
        }
        int child = toNumber(*key);

        if (children[child] == NULL)
            children[child] = new Node();

        children[child]->insert(key + 1);
    }
    // 31번째 비트부터 시작, idx는 30부터 시작
    int search(const char* key, const char* k) {
        if (*key == 0) { // or, bit == -1
            return 0;
        }

        int child = toNumber(*key);
        int kchild = toNumber(*k);
        if (kchild == 0) {
            if (child == 0 && children[0] != NULL)
                return children[0]->search(key + 1, k + 1);
            if (child == 1 && children[1] != NULL)
                return children[1]->search(key + 1, k + 1);
            return 0;
        }
        else // kchild == 1
        {
            int ret = 0;
            if (children[child] != NULL)
                ret += children[child]->size;
            if (children[1-child] != NULL)
                ret += children[1-child]->search(key + 1, k + 1);

            return ret;
        }
    }
};


string bitString(int num);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
 


    int n, k;
    cin >> n >> k;
    string kstring = bitString(k);
    Node* trie = new Node();
    trie->insert(bitString(0).c_str());
    int sum=0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        sum ^= num;
        string temp = bitString(sum);
        ans += (ll)trie->search(temp.c_str(), kstring.c_str());
        // 계산 후에 넣는다
        trie->insert(temp.c_str());
    }
        
    cout << ans << '\n';
    delete(trie);
 

}

string bitString(int num) {
    vector<char> ret(22);
    for (int i = 21; i >= 0; --i) {
        if (num & (1 << i))
            ret[21 - i] = '1';
        else
            ret[21 - i] = '0';
    }

    return string(ret.begin(), ret.end());
}