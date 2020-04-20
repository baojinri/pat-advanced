#include<iostream>
#include<vector>
int a[110];

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = 1; k < n+1; k++)
            {
                a[k] = 1;
            }
            a[i + 1] = -1;
            a[j + 1] = -1;
            std::vector<int> lie;
            for (int k = 0; k < n; k++)
            {
                if(a[abs(v[k])]*v[k]<0)
                {
                    lie.push_back(k + 1);
                }
            }
            if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0)
            {
                std::cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
        
    }
    std::cout << "No Solution";
    return 0;
}