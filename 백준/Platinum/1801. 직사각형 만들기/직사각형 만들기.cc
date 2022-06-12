#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int n;
int stick[17];
bool dp[80][80][80][80];




int main()
{   
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> stick[i];
    }

    dp[0][0][0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int a = 79; a >=0; --a) {
            for (int b = 79; b >= 0; --b) {
                for (int c = 79; c >= 0; --c) {
                    for (int d = 79; d >=0; --d) 
                    {
                        if (!dp[a][b][c][d]) continue;
                        // not include
                        
                        // include ith stick
                        if (a + stick[i] < 80) {
                            dp[a + stick[i]][b][c][d] = true;
                        }
                        if (b + stick[i] < 80) {
                            dp[a][b + stick[i]][c][d] = true;
                        }
                        if (c + stick[i] < 80) {
                            dp[a][b][c + stick[i]][d] = true;
                        }
                        if (d + stick[i] < 80) {
                            dp[a][b][c][d + stick[i]] = true;
                        }
                    } //d
                } //c
            }//b
        } //a
    } //i

    int ans = -1;
    for (int i = 1; i < 80; ++i) {
        for (int j = 1; j < 80; ++j) {
            if (dp[i][i][j][j]) {
                ans = max(ans, i * j);
            }
        }
    }

    cout << ans << endl;
}