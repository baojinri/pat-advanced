#include<iostream>
#include<iomanip>
using namespace std;

double a[1001]={0}, b[1001]={0},k[2];

int main()
{
    cin >> k[0];
    for (int i = 0; i < k[0]; i++)
    {
        int temp;
        cin >> temp;
        cin >> a[temp];
    }
    cin >> k[1];
    for (int i = 0; i < k[1]; i++)
    {
        int temp;
        cin >> temp;
        cin >> b[temp];
    }
    int k = 0;
    for (int i = 0; i < 1001; i++)
    {
        a[i] = a[i] + b[i];
        if (a[i]!=0)
        {
            k++;
        }
        
    }
    if (k!=0)
    {
        cout << k << " ";
    }
    else
    {
        cout << k;
    }
    for (int i = 1000; i>=0; i--)
    {
        if (a[i]!=0)
        {
            k--;
            if (k>0)
            {
                
                cout << i << " "<<setiosflags(ios::fixed)<<setprecision(1)<<a[i] << " ";
            }
            else
            {
                
                cout << i << " "<<setiosflags(ios::fixed)<<setprecision(1)<< a[i];
            }
            
        }
        
    }
    return 0;
}