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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int N, M;
int joy[1000][1000];


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> joy[i][j];
        }
    }

    if (N % 2 == 1) 
    {
        for (int i = 0; i < (N - 1) / 2; ++i) {
            for (int j = 0; j < M - 1; ++j)
                cout << 'R';
            cout << 'D';
            for (int j = 0; j < M - 1; ++j)
                cout << 'L'; 
            cout << 'D';
        }
        for (int j = 0; j < M - 1; ++j)
            cout << 'R';
        
        return 0;
    }
    else if (M % 2 == 1)
    {
        for (int i = 0; i < (M - 1) / 2; ++i) {
            for (int j = 0; j < N - 1; ++j)
                cout << 'D';
            cout << 'R';
            for (int j = 0; j < N - 1; ++j)
                cout << 'U';
            cout << 'R';
        }
        for (int j = 0; j < N - 1; ++j)
            cout << 'D';

        return 0;
    }
    
    // both even
    int r = 0, c = 1;
    int min_val = INF;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) 
        {
            if ((i + j) % 2 == 0) continue;
            if (joy[i][j] < min_val) {
                min_val = joy[i][j];
                r = i;
                c = j;
            }
        }
    }

    int before = r / 2;
    int after = N / 2 - r / 2 - 1;
    int c_before = c / 2;
    int c_after = M / 2 - c / 2 - 1;

    while (before-- > 0) {
        for (int i = 0; i < M - 1; ++i)
            cout << 'R';
        cout << 'D';
        for (int i = 0; i < M - 1; ++i)
            cout << 'L';
        cout << 'D';
    }

    while (c_before-- > 0) {
        cout << "DRUR";
    }

    //////////////
    if (c % 2 == 0)
        cout << "RD";
    else
        cout << "DR";
    ////////////

    while (c_after-- > 0) {
        cout << "RURD";
    }


    while (after-- > 0) {
        cout << 'D';
        for (int i = 0; i < M - 1; ++i)
            cout << 'L';
        cout << 'D';
        for (int i = 0; i < M - 1; ++i)
            cout << 'R';
        
    }
    
    cout << endl;
}