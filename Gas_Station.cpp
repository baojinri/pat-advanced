#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
const int INF = 1000000;
int edage[1100][1100];
int n;

int trans(std::string s)
{
    if (s[0] == 'G')
    {
        s.erase(s.begin());
        int sum = 0;
        for (int i = s.size() - 1; i > -1; i--)
        {
            sum += (s[i] - '0') * pow(10, s.size() - 1 - i);
        }
        return n + sum;
    }
    int sum = 0;
    for (int i = s.size() - 1; i > -1; i--)
    {
        sum += (s[i] - '0') * pow(10, s.size() - 1 - i);
    }
    return sum;
}

int main()
{
    int m, k, d;
    std::cin >> n >> m >> k >> d;
    for (int i = 0; i < 1100; i++)
    {
        for (int j = 0; j < 1100; j++)
        {
            edage[i][j] = INF;
        }
    }
    for (int i = 0; i < k; i++)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        std::cin >> edage[trans(str1)][trans(str2)];
        edage[trans(str2)][trans(str1)] = edage[trans(str1)][trans(str2)];
    }
    int dist[1100];
    int visited[1100] = {0};
    int number[11];
    double ave[11];
    for (int i = n + 1; i < n + m + 1; i++)
    {
        for (int j = 1; j < n + m + 1; j++)
        {
            dist[j] = edage[j][i];
        }
        visited[i] = 1;
        for (int j = 0; j < n + m; j++)
        {
            int min = INF;
            int v = 0;
            for (int k = 1; k < n + m + 1; k++)
            {
                if (dist[k] < min && visited[k] == 0)
                {
                    min = dist[k];
                    v = k;
                }
            }
            visited[v] = 1;
            for (int k = 1; k < n + m + 1; k++)
            {
                if (dist[k] > dist[v] + edage[v][k] && visited[k] == 0)
                {
                    dist[k] = dist[v] + edage[v][k];
                }
            }
        }
        int min = INF;
        int j;
        double sum = 0;
        for (j = 1; j < n + 1; j++)
        {
            if (dist[j] > d)
                break;
            if (min > dist[j])
                min = dist[j];
            sum += dist[j];
        }
        if (j == n + 1)
            number[i - n] = min;
        else
        {
            number[i - n] = INF;
        }
        ave[i - n] = sum / n;
        for (j = 0; j < 1100; j++)
        {
            visited[j] = 0;
        }
    }
    int max = 0;
    int j = 0;
    for (int i = 1; i < m + 1; i++)
    {
        if (number[i] > max && number[i] != INF)
        {
            max = number[i];
            j = i;
        }
        else if (number[i] == max && ave[i] < ave[j])
        {
            j = i;
        }
    }
    if (max == 0)
    {
        std::cout << "No Solution";
    }
    else
    {
        std::cout << "G" << j << std::endl;
        std::cout << number[j] << ".0 " << std::setiosflags(std::ios::fixed) << std::setprecision(1) << ave[j];
    }

    return 0;
}