#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int left, right, now;
    int ans = 0;
    int a = 1;
    while (n / a != 0)
    {
        left = n / (a * 10);
        right = n % a;
        now = n % (a * 10) / a;
        if (now == 0)
            ans += left * a;
        else if (now == 1)
            ans += left * a + right + 1;
        else
            ans += (left + 1) * a;
        a = a * 10;
    }
    std::cout << ans;
    return 0;
}