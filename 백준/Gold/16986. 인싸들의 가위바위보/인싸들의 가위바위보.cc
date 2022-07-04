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
const int MOD = 10000000;


int N, K;
int rule[10][10];
bool aWin(const vvi& d);
bool aWin2(const vvi& d);
int main()
{
    //cin.tie(NULL); ios_base::sync_with_stdio(false);
    //cout.tie(NULL);
    
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> rule[i][j];

    // a: 1~N
    vvi d(3);
    d[0].resize(N);
    for (int i = 0; i < N; ++i)
        d[0][i] = i + 1;
    d[1].resize(20);
    for (int i = 0; i < 20; ++i)
        cin >> d[1][i];
    d[2].resize(20);
    for (int i = 0; i < 20; ++i)
        cin >> d[2][i];


    
    int ans = 0;
    do 
    {
        if (aWin(d)) {
            ans = 1;
            break;
        }

    } while (next_permutation(d[0].begin(), d[0].end()));

    cout << ans << endl;

}

int whoWin(const vi& win)
{
    for (int i = 0; i < 3; ++i) {
        if (win[i] >= K) {
            return i;
        }
    }
    return -1;

}

pii nextPlayer(int winner, int loser) {
    int other = 3 - winner - loser;
    if (winner > other)
        swap(winner, other);
    return pii(winner, other);
}

bool aWin(const vvi& d)
{
    vi win(3, 0);
    vi use(3, 0);
    pii player = { 0,1 };
    int winner = -1;
    
    // 비가 순서상 뒤
    for (int round = 0; ; round++)
    {
        int a, b; tie(a, b) = player;
        int aChoose = d[a][use[a]++];
        int bChoose = d[b][use[b]++];

        if (rule[aChoose][bChoose] == 2) {
            win[a]++;
            player = nextPlayer(a, b);
        } //awin
        else {
            win[b]++;
            player = nextPlayer(b, a);
        } // bwin

        if ((winner = whoWin(win)) >= 0)
            break;

        if (use[0] == N)break;
    }

    if (winner == 0)
        return true;
    else // OTHER WIN OR NOT YET FINISHED
        return false;
}

bool aWin2(const vvi& d)
{
    for (int i : d[0])
        cout << i << " ";
    cout << endl;

    vi win(3, 0);
    pii player = { 0,1 };
    int winner = -1;
    int use = 0;
    // 비가 순서상 뒤
    for (int round = 0; ; round++)
    {
        int a, b; tie(a, b) = player;
        int aChoose, bChoose;

        if (a == 0) {
            if (use == N)break;
            aChoose = d[0][use++];
        }
        else
            aChoose = d[a][round];
        bChoose = d[b][round];

        printf("Round %d : %d(%d) vs %d(%d) -> ", round + 1,
            a, aChoose, b, bChoose);

        if (rule[aChoose][bChoose] == 2) {
            win[a]++;
            player = nextPlayer(a, b);
            cout << "awin\n";
        } //awin
        else {
            win[b]++;
            player = nextPlayer(b, a);
            cout << "bwin\n";
        } // bwin

        if ((winner = whoWin(win)) >= 0)
            break;
    }
    cout << "winner is ! " << winner << endl;

    if (winner == 0)
        return true;
    else // OTHER WIN OR NOT YET FINISHED
        return false;
}