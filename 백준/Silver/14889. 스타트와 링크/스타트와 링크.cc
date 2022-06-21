#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n, min_diff = INT_MAX;
vector<vector<int>> s;

inline int MIN(int a, int b) {
    return a < b ? a : b;
}

int stat(vector<int>& team)
{
    int result = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) { continue; }

            result += s[team[i]][team[j]];
        }
    }
    return result;
}

void split(int idx1, int member, vector<int> t1, vector<int> t2)
{
    if (idx1 == n / 2 && member == n + 1)
    {
        min_diff = MIN(min_diff, abs(stat(t1) - stat(t2)));
        return;
    }
    else if (idx1 == n/2 && member <= n) 
    {
        for (int i = member - idx1 - 1; i < n / 2; i++) {
            t2[i] = member++;
        }
        min_diff = MIN(min_diff, abs(stat(t1) - stat(t2)) );
        return;
    }
    else if (idx1 < n / 2 && member - idx1 - 1 == n / 2)
    {
        for (int i = idx1; i < n / 2; i++) {
            t1[i] = member++;
        }
        min_diff = MIN(min_diff, abs(stat(t1) - stat(t2)) );
        return;
    }

    t1[idx1] = member;
    split(idx1 + 1, member + 1, t1, t2);
    t2[member - idx1 - 1] = member;
    split(idx1, member + 1, t1, t2);


} // (0,1,team1, team2)

int main()
{
    cin >> n;
    s.assign(n + 1, vector<int>(n + 1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    
    vector<int> team1(n / 2);
    vector<int> team2(n / 2);

    split(0, 1, team1, team2);

 
    cout << min_diff;
    return 0;
}

