#include <iostream>

int main()
{
    int m, n, k;
    std::cin >> m >> n >> k;
    int stack[1010];
    int a[1010];
    for (int i = 0; i < k; i++)
    {
        int p = 1;
        int top = 0;
        int current = 0;
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j];
        }
        while (p < n+1)
        {
            stack[top] = p;
            top++;
            if (top == m+1)
                break;
            while (top != 0 && stack[top - 1] == a[current])
            {
                top--;
                current++;
            }
            p++;
        }

        if (current == n)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}