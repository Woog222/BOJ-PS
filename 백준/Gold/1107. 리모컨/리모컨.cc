#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int arr[10];
int check(int n);

int main()
{
    int c, n, num;

    for (int i = 0; i < 10; i++) { arr[i] = 1; }
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num] = 0;
    }

    int min = abs(c-100), temp;

    for (int i = 0; i <= 1000000; i++)
    {
        if (temp = check(i)) {
            temp += abs(c - i);
            min = (min <= temp) ? min : temp;
        }
    }

    cout << min;
    return 0; 
}

int check(int n)
{
    if (n == 0) {
        return arr[0] ? 1 : 0;
    }

    int result = 0;
    while (arr[n % 10] && n > 0)
    {
        n /= 10;
        result++;
    }
    if (n == 0) {
        return result;
    }
    else {
        return 0;
    }
}