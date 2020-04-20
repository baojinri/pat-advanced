#include<iostream>
struct bnode
{
    int k;
    int n;
};
struct temp_node
{
    int k;
    int id[100];
};


int main()
{
    int N,M;
    std::cin >> N>>M;
    bnode *n = new bnode[N+1];
    temp_node *t_n = new temp_node[N + 1];
    for (int i = 0; i < N+1; i++)
    {
        n[i].k = 0;
        n[i].n = 0;
        t_n[i].k = 0;
        for (int j = 0; j < 100; j++)
        {
            t_n[i].id[j] = 0;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int temp;
        std::cin >> temp; 
        std::cin >> t_n[temp].k;
        for (int j = 0; j < t_n[temp].k; j++)
        {
            int t;
            std::cin >> t;
            t_n[temp].id[t] = 1;
        }
               
    }
    
    n[1].n = 1;
    for (int i = 1; i < N+1; i++)
    {
        if(t_n[i].k!=0)
            {
                n[i].k = t_n[i].k;
                for (int j = 0; j < 100; j++)
                {
                    if(t_n[i].id[j]!=0)
                        {
                            n[j].n = n[i].n + 1;
                        }
                }
                
            }
    }
    int max = 0;
    for (int i = 1; i < N+1; i++)
    {
       if(n[i].n>max)
       {
           max = n[i].n;
       } 
    }
    int sum[max+1]={0};
    for (int i = 1; i <N+1 ; i++)
    {
        if(n[i].k==0)
        {
            sum[n[i].n]++;
        }
    }
    for (int i = 1; i < max; i++)
    {
        std::cout << sum[i] << " ";
    }
    std::cout << sum[max] << std::endl;
    system("pause");
    return 0;
}