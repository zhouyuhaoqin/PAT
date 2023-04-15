/*
*	author:		zhouyuhao
*	created:	2023-04-03 10:38:51
*	modified:	2023-04-03 19:16:53
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

struct node {
    string v;
    int lc, rc;
};

vector<node> t;
vector<string> ans;

void dfs(int r) {
    if (t[r].lc != -1 || t[r].rc != -1) {
        ans.push_back("(");
    }
    if (t[r].lc != -1) {
        dfs(t[r].lc);
    }
    ans.push_back(t[r].v);
    if (t[r].rc != -1) {
        dfs(t[r].rc);
    }
    if (t[r].lc != -1 || t[r].rc != -1) {
        ans.push_back(")");
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n + 1);
    vector<bool> isroot(n + 1);
    fill(isroot.begin(), isroot.end(), true);
    for (int i = 1; i <= n; i++) {
        cin >> t[i].v >> t[i].lc >> t[i].rc;
        if (t[i].lc != -1) isroot[t[i].lc] = false;
        if (t[i].rc != -1) isroot[t[i].rc] = false;
    }
    int r = 1;
    while (!isroot[r++]) {};
    dfs(r - 1);
    if (ans[0] == "(") {
        for (int i = 1; i < ans.size() - 1; i++) {
            cout << ans[i];
        }
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    }
    cout << "\n";
    
    return 0;
}