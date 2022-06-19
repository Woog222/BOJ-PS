#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans[9];
bool check[9] = { false, };
void fun(vector<int>& v, int num, int selected_num) //v,1,0
{
    if (selected_num == m)
    {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    if (num >= n) { return; }


    ans[selected_num] = v[num];
    fun(v, num + 1, selected_num + 1);

    fun(v, num + 1, selected_num);
   
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