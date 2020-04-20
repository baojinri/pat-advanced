#include <algorithm>
#include <iostream>
#include <string>

int stack[100010];
int top = 0;
int a[100010] = {0};
int block[317] = {0};

int PeekMedian()
{
    int median = (top + 1) / 2;
    int sum = 0;
    int i;
    for (i = 0; i < 317; i++)
    {
        sum += block[i];
        if (sum >= median)
            break;
    }
    sum = sum - block[i];
    for (int j = i * 316; j < (i + 1) * 316; j++)
    {
        sum += a[j];
        if (sum >= median)
        {
            std::cout << j << std::endl;
            return 0;
        }
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if (s == "Pop")
        {
            if (top == 0)
            {
                std::cout << "Invalid" << std::endl;
            }
            else
            {
                std::cout << stack[--top] << std::endl;
                block[stack[top] / 316]--;
                a[stack[top]]--;
            }
        }
        else if (s == "Push")
        {
            std::cin >> stack[top++];
            block[stack[top - 1] / 316]++;
            a[stack[top - 1]]++;
        }
        else
        {
            if (top == 0)
            {
                std::cout << "Invalid" << std::endl;
            }
            else
            {
                PeekMedian();
            }
        }
    }

    return 0;
}