#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans[9];
bool check[9] = { false, };
void fun(vector<int>& v, int idx, int start ) //v,0,0
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i = start; i < n; i++)
    {
        ans[idx] = v[i];
        fun(v, idx + 1, i);
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
    fun(nums, 0, 0);


    return 0;
}