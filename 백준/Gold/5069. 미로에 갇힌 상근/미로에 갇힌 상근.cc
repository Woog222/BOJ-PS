#include <iostream>
using namespace std;

int n;
int dx[] = { 0, 1, 1, 0,-1,-1 };
int dy[] = { 1, 0,-1,-1, 0, 1 };
// starting point : (15,15) not to make negative index
// n, x, y : with n move, way for get to (x,y)
int dp[15][31][31]; 

// Choose one! //
//#define METHOD1
#define METHOD2
int main()
{

/* PreProcessing*/
#ifdef METHOD1 // extract data from low_level dp
    dp[0][15][15] = 1;
    for (int i = 1; i <= 14; ++i) {
        for (int x = 1; x <= 29; ++x) {
            for (int y = 1; y <= 29; ++y) 
            {
                int temp = 0;
                for (int k = 0; k < 6; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    temp += dp[i - 1][nx][ny];
                }
                dp[i][x][y] = temp;
            }
        }
    }

#endif

#ifdef METHOD2 // pass the data up to the high_level dp from lower lovel
    dp[0][15][15] = 1;
    for (int i = 0; i <= 13; ++i) {
        for (int x = 1; x <= 29; ++x) {
            for (int y = 1; y <= 29; ++y)
            {
                for (int k = 0; k < 6; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    dp[i + 1][nx][ny] += dp[i][x][y];
                }
            }
        }
    }
#endif

    /* Query */
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n][15][15] << '\n';
    }
}