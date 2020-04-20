#include <iostream>
#include<queue>
int s[1290][130][70];
int m, n, l, t;
struct node
{
    int x, y, z;
    node operator+(node a)
    {
        a.x += this->x;
        a.y += this->y;
        a.z += this->z;
        return a;
    }
    node(int x1,int y1,int z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }
    node()
    {
    }
};
int ans = 0;
node fx[6];

int bfs(int x, int y, int z)
{
    int count = 1;
    std::queue<node> que;
    que.push(node(x,y,z));
    s[x][y][z] = 0;
    while (!que.empty())
    {
        node temp = que.front();
        for (int i = 0; i < 6; i++)
        {
            node a = temp + fx[i];
            if (a.x >= 0 && a.x < m && a.y >= 0 && a.y < n && a.z >= 0 && a.z < l && s[a.x][a.y][a.z] == 1)
            {
                count++;
                s[a.x][a.y][a.z]=0;
                que.push(a);
            }
        }
        que.pop();
    }
    if (count >= t)
        ans += count;
    return 0;
}

int main()
{
    std::cin >> m >> n >> l >> t;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                std::cin >> s[j][k][i];
            }
        }
    }
    fx[0].x = 0, fx[0].y = 0, fx[0].z = -1;
    fx[1].x = 0, fx[1].y = 0, fx[1].z = 1;
    fx[2].x = 0, fx[2].y = -1, fx[2].z = 0;
    fx[3].x = 0, fx[3].y = 1, fx[3].z = 0;
    fx[4].x = -1, fx[4].y = 0, fx[4].z = 0;
    fx[5].x = 1, fx[5].y = 0, fx[5].z = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (s[j][k][i] == 1)
                    bfs(j, k, i);
            }
        }
    }
    std::cout << ans;
    return 0;
}
