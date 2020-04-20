#include <iostream>
#include <map>
std::map<int, bool> s;
int pre[10010];

int main()
{
    int n, m;
    std::cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> pre[i];
        s[pre[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (!s[x] && !s[y])
            std::cout << "ERROR: " << x << " and " << y << " are not found." << std::endl;
        else if (!s[x] && s[y])
            std::cout << "ERROR: " << x << " is not found." << std::endl;
        else if (s[x] && !s[y])
            std::cout << "ERROR: " << y << " is not found." << std::endl;
        else
        {
            int temp;
            for (int i = 0; i < n; i++)
            {
                if (pre[i] >= x && pre[i] <= y || pre[i] >= y && pre[i] <= x)
                {
                    temp = pre[i];
                    break;
                }
            }
            if (temp == x)
                std::cout << x << " is an ancestor of " << y << "." << std::endl;
            else if (temp == y)
                std::cout << y << " is an ancestor of " << x << "." << std::endl;
            else
                std::cout << "LCA of " << x << " and " << y << " is "
                          << temp << "." << std::endl;
        }
    }
    return 0;
}