#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;


const ll mx = 2e5+10;

vector<vector<int>> g(mx);

ll ans[mx];

ll num_node[mx];

ll dist[mx];
ll total_sum[mx];


void dfs(int v, int p = -1)
{

    dist[v] = 0;

    num_node[v] = 1;

    for (auto to : g[v])
    {
        if (to == p) continue;
        dfs(to, v);
        dist[v] += dist[to] + 1;
        total_sum[v] += total_sum[to] + dist[to] + 1;
        num_node[v] += num_node[to];
    }
}

void dfs2(int v, int p = -1)
{
    ans[v] = total_sum[v];

    for (auto to : g[v])
    {
        if (to == p) continue;



        total_sum[v] -=  total_sum[to] + dist[to] + 1;

        num_node[v] -= num_node[to];

        num_node[to] += num_node[v];

        dist[v] -= (dist[to]+1);

        dist[to] += (dist[v] + 1);

        total_sum[to] += total_sum[v]+ dist[v] + 1;


        dfs2(to, v);

        total_sum[to] -= total_sum[v]+ dist[v] + 1;

        dist[to] -= (dist[v] + 1);

        dist[v] += (dist[to]+1);

        num_node[to] -= num_node[v];

        num_node[v] += num_node[to];

        total_sum[v] +=  total_sum[to] + dist[to] + 1;


    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    dfs2(1);

    for(int i = 1; i <= n; i++)
    {

        cout << ans[i] << "\n";
    }


    return 0;
}
