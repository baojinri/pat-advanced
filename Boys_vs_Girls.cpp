#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::string name, id, mname, mid, fname, fid;
    int mgrade = 101, fgrade = -1, grade;
    for (int i = 0; i < n; i++)
    {
        std::string sex;
        std::cin >> name >> sex >> id >> grade;
        if (sex == "M" && grade < mgrade)
        {
            mname = name;
            mid = id;
            mgrade = grade;
        }
        else if (sex == "F" && grade > fgrade)
        {
            fname = name;
            fid = id;
            fgrade = grade;
        }
    }
    if(fgrade==-1)
    {
        std::cout << "Absent" << std::endl;
    }
    else
    {
        std::cout << fname << " " << fid << std::endl;
    }
    if(mgrade==101)
    {
        std::cout << "Absent" << std::endl;
    }
    else
    {
        std::cout << mname << " " << mid << std::endl;
    }
    if(fgrade!=-1&&mgrade!=101)
    {
        std::cout << fgrade - mgrade<<std::endl;
    }
    else
    {
        std::cout << "NA" << std::endl;
    }
    
    return 0;
}