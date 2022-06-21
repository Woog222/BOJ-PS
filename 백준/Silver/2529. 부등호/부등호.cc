#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int k;
long long max_num = LLONG_MIN, min_num = LLONG_MAX;
vector<char> inequalities;
vector<int> min_vec;
vector<int> max_vec;
bool check[10] = { false, };
 
inline long long MIN(long long a, long long b) {
    return a < b ? a : b;
}
inline long long MAX(long long a, long long b) {
    return a > b ? a : b;
}

void fun(int idx, vector<int>& nums)
{
    if (idx == k + 1) {
        long long temp = 0;
        for (int i = 0; i <= k; i++) {
            temp += nums[i] * (long long)pow(10, k - i);
        }
        min_num = MIN(min_num, temp);
        max_num = MAX(max_num, temp);

        if (min_num == temp) {
            min_vec.assign(nums.begin(), nums.begin() + k + 1);
        }
        if (max_num == temp) {
            max_vec.assign(nums.begin(), nums.begin() + k + 1);
        }

        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (check[i]) { continue; }

        if (idx >= 1 && inequalities[idx - 1] == '>') {
            if (nums[idx - 1] <= i) {
                continue;
            }
        }
        else if (idx >= 1 && inequalities[idx - 1] == '<') {
            if (nums[idx - 1] >= i) {
                continue;
            }
        }

        check[i] = true;
        nums[idx] = i;
        fun(idx + 1, nums);
        check[i] = false;
    }
}

int main()
{
    cin >> k;
    inequalities.assign(k, '0');
    for (int i = 0; i < k; i++)
    {
        cin >> inequalities[i];
    }

    vector<int> nums(k + 1, 0);
    min_vec.assign(k + 1, 0);
    max_vec.assign(k + 1, 0);
    fun(0, nums);

  

    for (int i = 0; i <= k; i++) {
        cout << max_vec[i];
    }
    cout << '\n';
    for (int i = 0; i <= k; i++) {
        cout << min_vec[i];
    }
    cout << '\n';
    return 0;
}
