#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct node
{
    std::string platenum, time, tag;
};
std::vector<node> car,car1;

bool cmp1(node a, node b)
{
    if (a.platenum == b.platenum)
        return a.time < b.time;
    return a.platenum < b.platenum;
}

bool cmp2(node a, node b)
{
    return a.time < b.time;
}

int caltime(std::string a, std::string b)
{
    int time1 = stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 2)) * 60 + stoi(a.substr(6, 2));
    int time2 = stoi(b.substr(0, 2)) * 3600 + stoi(b.substr(3, 2)) * 60 + stoi(b.substr(6, 2));
    return time2 - time1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    node temp;
    temp.platenum.resize(7);
    temp.time.resize(8);
    temp.tag.resize(2);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", &temp.platenum[0], &temp.time[0],&temp.tag[0]);
        car.push_back(temp);
    }
    std::sort(car.begin(), car.end(), cmp1);
    std::map<std::string, int> ans;
    int max = 0;
    for (int i = 0; i < car.size(); i++)
    {
        if (car[i].platenum == car[i + 1].platenum && car[i].tag == "in" && car[i + 1].tag == "ou")
        {
            ans[car[i].platenum] += caltime(car[i].time, car[i + 1].time);
            if (max < ans[car[i].platenum])
                max = ans[car[i].platenum];
            car1.push_back(car[i]);
            car1.push_back(car[i + 1]);
            i++;
        }
        /*else
        {
            car.erase(car.begin() + i);
            i--;
        }*/
    }
    std::sort(car1.begin(), car1.end(), cmp2);
    int count = 0;
    int j = 0;
    std::string time;
    time.resize(8);
    for (int i = 0; i < k; i++)
    {

        scanf("%s", &time[0]);
        while (j < car1.size() && car1[j].time <= time)
        {
            if (car1[j].tag == "in")
                count++;
            else
                count--;
            j++;
        }
        printf("%d\n", count);
    }
    for (std::map<std::string, int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        if (it->second == max)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", max / 3600,(max % 3600) / 60, max % 60);
    return 0;
}