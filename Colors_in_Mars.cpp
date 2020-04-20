#include<iostream>

int trans(int n)
{
    int temp;
    temp = n % 13;
    n = n / 13;
    if(n>=10)
    {
        switch (n)
        {
        case 10:
            std::cout << "A";
            break;
        case 11:
            std::cout << "B";
            break;
        case 12:
            std::cout << "C";
            break;
        }
    }
    else
    {
        std::cout << n;
    }
    if(temp>=10)
    {
        switch (temp)
        {
        case 10:
            std::cout << "A";
            break;
        case 11:
            std::cout << "B";
            break;
        case 12:
            std::cout << "C";
            break;
        }
    }
    else
    {
        std::cout << temp;
    }
    
    return 0;
}

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << "#";
    trans(x);
    trans(y);
    trans(z);
    return 0;
}