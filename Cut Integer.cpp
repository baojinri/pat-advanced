#include<iostream>
#include<string>
#include<cmath>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        std::string s = std::to_string(temp);
        int k = s.size() / 2;
        int z = pow(10, k);
        int x = temp % z;
        int y = temp / z;
        if(temp%(x*y)==0)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}