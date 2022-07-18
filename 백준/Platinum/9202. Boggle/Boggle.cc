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
    return c - 'A';
}

struct Node {

    int terminal;
    Node* children[26];

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

void fun(int r, int c, Node* node, int len, vector<vector<bool>>& visited);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int w; cin >> w;
    trie = new Node();
    for (int i = 0; i < w; ++i) {
        string s;  cin >> s;
        trie->insert(s.c_str(), i);
    }

    int t; cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; ++i)
            cin >> grid[i];

        // words에 찾은 단어들 들어있음.
        vector<string>().swap(words);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                vector<vector<bool>> visited(4, vector<bool>(4, false));
                visited[i][j] = true;
                fun(i, j, trie, 1, visited);
            }
        }
        sort(words.begin(), words.end(),
            [](const string& a, const string& b) {
                if (a.size() == b.size())
                    return a < b;
                else
                    return a.size() > b.size();
            }
        );
        words.erase(unique(words.begin(), words.end()), words.end());

        int score = 0;
        for (string& word : words)
            score += scores[word.size()];
        cout << score << " " << words.front() << " " << words.size() << '\n';
    }

    
}
inline bool valid(int r, int c) {
    return r >= 0 && r < 4 && c >= 0 && c < 4;
}
// len : 0으로 시작, 지금 길이 len만들 차례
void fun(int r, int c, Node* node, int len, vector<vector<bool>> &visited) 
{
    if (len > 8) {
        return;
    }

    // 우선 여기까지
    
    Node* next = node->children[toNumber(grid[r][c]) ];
    if (next == NULL)
        return;
    temp[len - 1] = grid[r][c];
    temp[len] = 0;
    if (next->terminal != -1) {
        words.emplace_back(temp, temp + len);
    }
        
  
    // next
    for (int k = 0; k < 8; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (!valid(nr, nc) || visited[nr][nc])
            continue;

        visited[nr][nc] = true;
        fun(nr, nc, next, len + 1, visited);
        visited[nr][nc] = false;
    }

}