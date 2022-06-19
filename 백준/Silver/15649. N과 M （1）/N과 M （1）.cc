#include <iostream>
using namespace std;

int n, m;
bool use_check[9] = {false};
int ans[9];
void fun(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        if (use_check[i]) { continue; }

        ans[idx] = i;
        use_check[i] = true;
        fun(idx + 1);
        use_check[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    fun(0);
    return 0;
}