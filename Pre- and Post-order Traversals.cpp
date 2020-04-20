#include <iostream>
#include <vector>
std::vector<int> ans;
int n, flag = 0, a[35], b[35];
int build(int p, int q)
{
    if (p + 1 == q)
    {
        ans.push_back(b[p]);
        return 0;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == b[q - 1])
            break;
    }
    int temp = a[i + 1];
    for (i = p; i < q - 1; i++)
    {
        if (b[i] == temp)
            break;
    }
    i++;
    build(p, i);
    ans.push_back(b[q - 1]);
    if (i < q - 1)
        build(i, q - 1);
    else
        flag = 1;
    return 0;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    build(0, n);
    if (flag == 1)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i];
        if (i < n - 1)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
    return 0;
}
