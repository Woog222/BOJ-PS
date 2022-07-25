#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


inline int MAX(int a, int b)
{
    return (a > b) ? a : b;
}

int n, max_weight;

int main()
{
    cin >> n >> max_weight;
    vector<pair<int, int>> goods(n+1, { 0,0 });
    /* first : weight , second : value */
    for (int i = 1; i <= n; i++)
    {
        cin >> goods[i].first >> goods[i].second;
    }

    /* [i] = v -> sum_weight is i, and max value of that weight */
    vector<vector<int>> best_pack(2, vector<int>(max_weight+1,0) );
    int row_idx;
    for (int i = 1; i <= n; i++)
    {
        int weight = goods[i].first;
        int value = goods[i].second;
        row_idx = i & 1;

        for (int j = 0; j <= max_weight-weight; j++) {
            best_pack[row_idx][j + weight] =
                MAX(best_pack[!row_idx][j+weight], best_pack[!row_idx][j]+value);
        }
        for (int j = 0; j < weight; j++)
        {
            best_pack[row_idx][j] = best_pack[!row_idx][j];
        }
    }

    cout << best_pack[row_idx][max_weight] << endl;

    return 0;
}