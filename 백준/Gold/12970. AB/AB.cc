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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N, K;


int main()
{
    cin >> N >> K;
    
    int limit = 0;
    if (N % 2) {
        limit = (N / 2 + 1) * (N / 2);
    }
    else {
        limit = (N / 2) * (N / 2);
    }

    if (K > limit) {
        cout << -1 << endl;
        return 0;
    }


    char ans[50 + 1];
    int AFront = K / (N / 2);
    int Ashift = ((N / 2) - K % (N / 2)) % (N / 2);
    int idx = 0;
    int a = (N % 2 == 1) ? N / 2 + 1 : N / 2;
    int b = N / 2;
    
    for (int i = 0; i < AFront; ++i) {
        ans[idx++] = 'A';
        a--;
    }
        

    for (int i = 0; i < Ashift; ++i) {
        ans[idx++] = 'B';
        b--;
    }

    // 중간에 a가 껴야된다면
    if (Ashift > 0) {
        ans[idx++] = 'A';
        a--;
    }
        
    while (idx < N && (a > 0 || b > 0)) {
        if (b > 0) {
            ans[idx++] = 'B';
            b--;
        }
        else {
            ans[idx++] = 'A';
            a--;
        }
    }

    ans[N] = 0;

    printf("%s\n", ans);



}
