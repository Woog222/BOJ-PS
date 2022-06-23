#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;
vector<int> operators(4);
vector<int> res;

void fun (int idx, int ans)
{
    if(idx == n-1) {
        res.push_back(ans);
        return;
    }
    
    if (operators[0]>0) {
        operators[0]--;
        fun(idx+1, ans + nums[idx+1]);
        operators[0]++;
    }
    
    if (operators[1]>0) {
        operators[1]--;
        fun(idx+1, ans- nums[idx+1]);
        operators[1]++;
    }
    
    
    if (operators[2]>0) {
        operators[2]--;
        fun(idx+1, ans * nums[idx+1]);
        operators[2]++;
    }
    if (operators[3]>0) {
        operators[3]--;
        fun(idx+1, ans / nums[idx+1]);
        operators[3]++;
    }
}


int main()
{
    cin >> n;
    
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    
    for(int i=0; i<4; i++) {    
           cin >> operators[i];
    }
    
    fun(0,nums[0]);
    
    auto k = minmax_element(res.begin(), res.end());
    cout << *k.second << endl;
    cout << *k.first << endl;     
}