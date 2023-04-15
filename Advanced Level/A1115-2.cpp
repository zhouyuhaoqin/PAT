/*
*	author:		zhouyuhao
*	created:	2023-04-02 18:45:52
*	modified:	2023-04-02 18:54:21
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

struct node {
    int v;
    node *lc, *rc;
};

node* insert(node* r, int v) {
    if (r == NULL) {
        r = new node;
        r->v = v;
        r->lc = r->rc = NULL;
        return r;
    }
    if (v <= r->v) {
        r->lc = insert(r->lc, v);
    } else {
        r->rc = insert(r->rc, v);
    }
    return r;
}

int maxl = -1;
map<int, int> cnt;
void dfs(node* r, int l) {
    if (r == NULL) {
        return;
    }
    cnt[l]++;
    maxl = max(maxl, l);
    dfs(r->lc, l + 1);
    dfs(r->rc, l + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node* r = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        r = insert(r, v);
    }
    dfs(r, 1);
    cout << cnt[maxl] << " + " << cnt[maxl - 1] << " = " << cnt[maxl] + cnt[maxl - 1] << "\n";
    
    return 0;
}