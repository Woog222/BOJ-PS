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

    Node() {
        children[0] = children[1] = NULL;
        terminal = false;
    }
    
    void insert(const char* key) {
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
    int search(const char* key, int bit) {
        if (*key == 0) { // or, bit == -1
            return 0;
        }

        int child = toNumber(*key);
        if (children[1 - child] != NULL)
            return (1 << bit) + children[1 - child]->search(key + 1, bit - 1);
        else
            return children[child]->search(key + 1, bit-1);
    }
};


int N;
string bitString(int num);
int main()
{
    
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
 
    int t; cin >> t;
    while (t--)
    {
        cin >> N;
        Node* trie = new Node();
        int sum = 0;
        trie->insert(bitString(sum).c_str());
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int num; cin >> num;
            sum ^= num;
            string temp = bitString(sum);
            trie->insert(temp.c_str());
            ans = max(ans, trie->search(temp.c_str(), 30));
        }
        
        cout << ans << '\n';
        
    }

}

string bitString(int num) {
    vector<char> ret(31);
    for (int i = 30; i >= 0; --i) {
        if (num & (1 << i))
            ret[30 - i] = '1';
        else
            ret[30 - i] = '0';
    }

    return string(ret.begin(), ret.end());
}