#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> sign_matrix; //1~n * 2
vector<int> ans; // 1~n

bool sign_check(int sign, int num)
{
    if (sign == 0) {
        return num == 0 ? true : false;
    }
    else {
        return (sign * num > 0) ? true : false;
    }
}

void bound_check(int& from, int& to, int j)
{
    if (sign_matrix[j][j] == 0) {
        from = 0; to = 0;
        return;
    }

    int temp_sum;
    int temp_from=11, temp_to=-11;
    bool ok;

    if (sign_matrix[j][j] > 0) 
    {
        for (int num = 1; num <= 10; num++) 
        {
            ok = true;
            temp_sum = num;
            for (int i = j-1; i >= 1; i--) {
                temp_sum += ans[i];
                if ( !sign_check(sign_matrix[i][j], temp_sum) )
                {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                temp_from = (num < temp_from) ? num : temp_from;
                temp_to = (num > temp_to) ? num : temp_to;
            }
        }
    }
    else
    {
        for (int num = -10; num <= -1; num++)
        {
            ok = true;
            temp_sum = num;
            for (int i = j - 1; i >= 1; i--) {
                temp_sum += ans[i];
                if (!sign_check(sign_matrix[i][j], temp_sum))
                {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                temp_from = (num < temp_from) ? num : temp_from;
                temp_to = (num > temp_to) ? num : temp_to;
            }
        }
    }
    from = temp_from;
    to = temp_to;
}

bool fun(int idx)
{
    if (idx == n+1) {
        return true;
    }

    int start_num, last_num;
    bound_check(start_num, last_num, idx);
    
    for (int i = start_num; i <= last_num; i++)
    {
        ans[idx] = i;
        if (fun(idx + 1)) { return true; }
    }
    return false;
} // 1 ~ n


int main()
{
    cin >> n;
    sign_matrix.assign(n + 1, vector<int>(n + 1, 0));
    ans.assign(n+1, 0);

    char temp;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> temp;
            if (temp == '+') {
                sign_matrix[i][j] = 1;
            }
            else if (temp == '-') {
                sign_matrix[i][j] = -1;
            }
            else {
                sign_matrix[i][j] = 0;
            }
        }
    }
    
    fun(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}