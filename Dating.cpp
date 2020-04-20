#include<iostream>
#include<string>

int main()
{
    std::string str1, str2, str3, str4;
    std::cin >> str1 >> str2 >> str3 >> str4;
    int i;
    for ( i = 0; i < str1.size(); i++)
    {
        if(str1[i]==str2[i] &&str1[i]>='A'&&str1[i]<='G')
        {
            break;
        }
    }
    int xq = str1[i] - 'A' + 1;
    switch (xq)
    {
    case 1:
        std::cout << "MON"
                  << " ";
        break;
    case 2:
        std::cout << "TUE"
                  << " ";
        break;
    case 3:
        std::cout << "WED"
                  << " ";
        break;
    case 4:
        std::cout << "THU"
                  << " ";
        break;
    case 5:
        std::cout << "FRI"
                  << " ";
        break;
    case 6:
        std::cout << "SAT"
                  << " ";
        break;
    case 7:
        std::cout << "SUN"
                  << " ";
        break;
    }
    for ( i = i+1; i < str1.size(); i++)
    {
        if(str1[i]==str2[i]&&((str1[i]>='A'&&str1[i]<='N')||(str1[i]>='0'&&str1[i]<='9')))
        {
            break;
        }
    }
    if(str1[i]<='9')
    {
        std::cout << 0 << str1[i]-'0' << ":";
    }
    else
    {
        std::cout << str1[i]-'A'+10 << ":";
    }
    
    for (int i = 0; i < str3.size(); i++)
    {
        if(str3[i]==str4[i]&&((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')))
            {
                if(i<10)
                {
                    std::cout << 0 << i;
                }
                else
                {
                    std::cout << i;
                }
                
            }
    }

    return 0;
}