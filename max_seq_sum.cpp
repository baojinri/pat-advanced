#include <iostream>
int seq[10000] = {0};

int main()
{
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        std::cin >> seq[i];
    }
    int tag = 0;
    for (int i = 0; i < k; i++)
    {
        if(seq[i]>=0)
            tag = 1;
    }
    if(tag==0 )
        std::cout << '0' << " " << seq[0] << " " << seq[k - 1] << std::endl;
    else
    {int t_f = 0, t_l = 0, temp = 0;
    int f = 0, l = 0, sum = 0;
    for (int i = 0; i < k; i++)
    {
        temp = temp + seq[i];
        t_l = i;
        if (temp < 0)
        {
            temp = 0;
            t_f = i + 1;
        }
        if (temp > sum)
        {
            sum = temp;
            f = t_f;
            l = t_l;
        }
    }
    
    if (f == 0 && l == 0 && seq[0] < 0)
    {
        sum = seq[0], f = 0, l = 0;
        for (int i = 1; i < k; i++)
        {
            if (sum < seq[i])
                sum = seq[i], f = i, l = i;
        }
        std::cout << sum << " " << seq[f] << " " << seq[l] << std::endl;
    }
    else
    {

        std::cout << sum << " " << seq[f] << " " << seq[l] << std::endl;
    }}
    system("pause");
    return 0;
}