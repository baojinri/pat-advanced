#include<iostream>
#include<string>

int main()
{
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    int length1 = s1.size();
    int length2 = s2.size();
    for (int i = 0; i <length1 ; i++)
    {
        int j;
        for ( j = 0; j < length2; j++)
        {
            if(s1[i]==s2[j])
            {
                break;
            }
        }
        if(j==length2)
        {
            std::cout << s1[i];
        }
    }

    return 0;
}
