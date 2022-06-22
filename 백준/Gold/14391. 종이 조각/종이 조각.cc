#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, m;
vector<vector<int>> paper;

int main()
{
    cin >> n >> m;
    paper.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            paper[i][j] = (int)(row[j] - '0');
        }
    }

    int case_max = 1<< (n*m);
    int max_sum = 0;
    for (int cases = 0; cases < case_max; cases++)
    {
        int temp_sum = 0;
        for (int i = 0; i < n; i++) 
        {
            int row_sum = 0;
            for (int j = 0; j < m; j++) 
            {
                if (cases & (1 << (m * i + j))) {
                    row_sum = row_sum * 10 + paper[i][j];
                }
                else {
                    temp_sum += row_sum;
                    row_sum = 0;
                }
            }
            temp_sum += row_sum;
        }

        for (int j = 0; j < m; j++)
        {
            int col_sum = 0;
            for (int i = 0; i < n; i++) 
            {
                if (cases & (1 << (i * m + j))) {
                    temp_sum += col_sum;
                    col_sum = 0;
                }
                else {
                    col_sum = col_sum * 10 + paper[i][j];
                }
            }
            temp_sum += col_sum;
        }

        max_sum = (temp_sum > max_sum) ? temp_sum : max_sum;
    }

    cout << max_sum << endl;

    return 0;
}