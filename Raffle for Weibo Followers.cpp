#include <iostream>
#include <string>
std::string a[1010];
std::string b[1010];
int count = 0;

int main()
{
    int m, n, s;
    std::cin >> m >> n >> s;
    if (m < n)
    {
        std::cout << "Keep going...";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
    }

    for (int i = s - 1; i < m;)
    {
        while (i < m)
        {
            int j;
            for (j = 0; j < count; j++)
            {
                if (b[j] == a[i])
                    break;
            }
            if (j == count)
                break;
            i++;
        }
        if (i < m)
            b[count++] = a[i];
        i = i + n;
    }
    if (count == 0)
    {
        std::cout << "Keep going...";
        return 0;
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << b[i] << std::endl;
    }

    return 0;
}