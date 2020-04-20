#include <iostream>
int a[10000];
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int count = 0;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ans = a[i];
            count++;
        }
        else
        {
            if (ans == a[i])
                count++;
            else
                count--;
        }
    }
    if (count > 0)
        std::cout << ans;
    else
        std::cout << "No";
    return 0;
}