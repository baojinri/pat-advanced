#include <iostream>
#include <string>
void transfer(int);
using namespace std;
int main()
{   
    std::string str;
    std::cin >> str;
    int n = str.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + str[i] - '0';
    }
    int a = 0, b = 0, c = 0;
    a = sum / 100;
    b = sum % 100 / 10;
    c = sum % 10;
    if (a != 0)
    {
        transfer(a);
        std::cout << " ";
        transfer(b);
        std::cout << ' ';
        transfer(c);
    }

    else if (b != 0)
    {
        transfer(b);
        std::cout << ' ';
        transfer(c);
    }
    else transfer(c);
    std::cout << std::endl;
    system("pause");
    return 0;
}
void transfer(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "zero";
        break;
    case 1:
        std::cout << "one";
        break;
    case 2:
        std::cout << "two";
        break;
    case 3:
        std::cout << "three";
        break;
    case 4:
        std::cout << "four";
        break;
    case 5:
        std::cout << "five";
        break;
    case 6:
        std::cout << "six";
        break;
    case 7:
        std::cout << "seven";
        break;
    case 8:
        std::cout << "eight";
        break;
    case 9:
        std::cout << "nine";
        break;
    }
}