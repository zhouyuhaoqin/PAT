/*
*	author:		zhouyuhao
*	created:	2023-04-02 22:17:15
*	modified:	2023-04-02 22:20:30
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct node {
    int lc, rc;
};

vector<bool> isroot;
vector<node> t;

int getid(string s) {
    if (isdigit(s[0])) {
        isroot[stoi(s)] = false;
        return stoi(s);
    } else {
        return -1;
    }
}

int maxid = -1, lastnode = -1;
void dfs(int r, int id) {
    if (id > maxid) {
        maxid = id;
        lastnode = r;
    }
    if (t[r].lc == -1 && t[r].rc == -1) {
        return;
    }
    if (t[r].lc != -1) {
        dfs(t[r].lc, 2 * id + 1);
    }
    if (t[r].rc != -1) {
        dfs(t[r].rc, 2 * id + 2);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n);
    isroot.resize(n);
    fill(isroot.begin(), isroot.end(), true);
    for (int i = 0; i < n; i++) {
        string lc, rc;
        cin >> lc >> rc;
        t[i].lc = getid(lc);
        t[i].rc = getid(rc);
    }
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (isroot[i]) {
            r = i;
            break;
        }
    }
    dfs(r, 0);
    if (maxid >= n) {
        cout << "NO " << r << "\n";
    } else {
        cout << "YES " << lastnode << "\n";
    }
        
    return 0;
}