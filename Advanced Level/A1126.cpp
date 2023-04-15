/*
*	author:		zhouyuhao
*	created:	2023-04-03 02:59:48
*	modified:	2023-04-03 19:08:12
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void dfs(int s) {
    vis[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        if (!vis[g[s][i]]) {
            dfs(g[s][i]);
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n + 1);
    g.resize(n + 1);
    vector<int> d(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 != 0) {
            odd++;
        } else {
            even++;
        }
        cout << d[i];
        if (i < n) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    fill(vis.begin(), vis.end(), false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt == 1) {
        if (even == n && odd == 0) {
            cout << "Eulerian\n";
        } else if (odd == 2) {    
        // } else if (even > 0 && odd == 2) {
            cout << "Semi-Eulerian\n";
        } else {
            cout << "Non-Eulerian\n";
        }
    } else {
        cout << "Non-Eulerian\n";
    }
    
    return 0;
}