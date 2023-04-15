/*
*	author:		zhouyuhao
*	created:	2023-04-03 12:04:27
*	modified:	2023-04-03 12:17:29
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(i);
        e[b].push_back(i);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int nv;
        cin >> nv;
        unordered_set<int> edge;
        for (int i = 0; i < nv; i++) {
            int v;
            cin >> v;
            for (auto it : e[v]) {
                edge.insert(it);
            }
        }
        if (edge.size() == m) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}