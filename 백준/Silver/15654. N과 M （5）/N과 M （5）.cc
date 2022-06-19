#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans[9];
bool check[9] = { false, };
void fun(vector<int>& v, int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) { continue; }

        ans[idx] = v[i];
        check[i] = true;
        fun(v, idx + 1);
        check[i] = false;
    }
}



int main()
{

    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    fun(nums, 0);


    return 0;
}