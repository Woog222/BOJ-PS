#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0, len = 1, k = 9;
    for (;;)
    {
        if (n - k <= 0) {
            sum += n * len;
            break;
        }
        n -= k;
        sum += k * len++;
        k *= 10;
    }

    cout << sum << endl;
    return 0;
}