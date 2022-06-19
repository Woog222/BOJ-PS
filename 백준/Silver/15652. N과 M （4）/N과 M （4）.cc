#include <iostream>

using namespace std;

int n, m;
int ans[9];
void fun(int idx, int start)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return ;
    }
    if (start > n) { return; }

    for (int i = start; i <= n; i++)
    {
        ans[idx] = i;
        fun(idx + 1, i);
    }
}



int main()
{

    cin >> n >> m;
    fun(0, 1);

    return 0;
}