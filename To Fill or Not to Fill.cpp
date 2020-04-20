#include <algorithm>
#include <iostream>
struct node
{
    double price;
    double dist;
} a[510];

bool cmp(node a, node b)
{
    return a.dist < b.dist;
}

int main()
{
    int c, dist, ave, n;
    std::cin >> c >> dist >> ave >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].price >> a[i].dist;
    }
    std::sort(a, a + n, cmp);
    if (a[0].dist != 0)
    {
        std::cout << "The maximum travel distance = 0.00";
        return 0;
    }
    double maxdist = c * ave;
    int curloc = 0;
    double currank = 0;
    double price = 0;
    double sum = 0;
    while (sum < dist)
    {
        int i = curloc + 1;
        if (i == n && a[curloc].dist + maxdist < dist)
        {
            sum = a[curloc].dist + maxdist;
            break;
        }
        if (i < n && a[i].dist > a[curloc].dist + maxdist && a[curloc].dist + maxdist < dist)
        {
            sum = a[curloc].dist + maxdist;
            break;
        }
        int flag = -1;
        while (i < n && a[i].dist <= a[curloc].dist + maxdist && a[i].dist <= dist)
        {
            if (a[i].price < a[curloc].price)
            {
                flag = i;
                break;
            }
            i++;
        }
        if (flag != -1)
        {
            sum = a[flag].dist;
            price += ((a[flag].dist - a[curloc].dist) / ave - currank) * a[curloc].price;
            currank = 0;
            curloc = flag;
        }
        else
        {
            if (a[curloc].dist + maxdist >= dist)
            {
                price += ((dist - a[curloc].dist) / ave - currank) * a[curloc].price;
                sum = dist;
                break;
            }
            else
            {
                double minp = 10000;
                int i = curloc + 1;
                int j;
                while (a[i].dist <= a[curloc].dist + maxdist)
                {
                    if (a[i].price < minp)
                    {
                        minp = a[i].price;
                        j = i;
                    }
                    i++;
                }
                sum = a[j].dist;
                price += (c - currank) * a[curloc].price;
                currank = c - (a[j].dist - a[curloc].dist) / ave;
                curloc = j;
            }
        }
    }
    if (sum == dist)
    {
        printf("%0.2f", price);
    }
    else
    {
        std::cout << "The maximum travel distance = ";
        printf("%0.2f", sum);
    }

    return 0;
}