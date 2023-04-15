/*
*	author:		zhouyuhao
*	created:	2023-04-03 02:12:38
*	modified:	2023-04-03 02:25:25
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> g;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        g[i].resize(n + 1);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1][v2] = g[v2][v1] = 1;
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int vn;
        cin >> vn;
        vector<int> path(vn);
        set<int> vertex;
        for (int i = 0; i < vn; i++) {
            cin >> path[i];
            vertex.insert(path[i]);
        }
        if (vertex.size() != n) {
            cout << "NO\n";
            continue;
        }
        bool isarrive = true;
        set<int> simplepath;
        for (int i = 1; i < vn; i++) {
            simplepath.insert(path[i]);
            if (g[path[i - 1]][path[i]] != 1) {
                isarrive = false;
                break;
            }
        }
        if (!isarrive || simplepath.size() != vn - 1) {
            cout << "NO\n";
            continue;
        }
        if (path[0] != path[vn - 1]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    
    return 0;
}