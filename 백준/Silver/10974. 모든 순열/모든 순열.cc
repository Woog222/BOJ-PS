#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int n;
bool check[10001] = { false, };
int ans[10001];

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void fun(int idx)
{
    if (idx == n+1) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (check[i]) { continue; }

        ans[idx] = i;
        check[i] = true;
        fun(idx + 1);
        check[i] = false;
    }
}

int main()
{
    cin >> n;
   

    fun(1);
    cout << endl;
    return 0;
}