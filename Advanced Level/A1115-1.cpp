/*
*	author:		zhouyuhao
*	created:	2023-04-02 17:34:14
*	modified:	2023-04-02 18:42:09
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

void insert(node* &r, int v) {
    if (r == NULL) {
        r = new node;
        r->v = v;
        r->lc = r->rc = NULL;
        return;
    }
    if (v <= r->v) {
        insert(r->lc, v);
    } else {
        insert(r->rc, v);
    }
}

int maxl = -1;
map<int, int> cnt;
// void dfs(node *r, int l) {
//     if (r == NULL) {
//         return;
//     }
//     cnt[l]++;
//     if (l > maxl) {
//         maxl = l;
//     }
//     dfs(r->lc, l + 1);
//     dfs(r->rc, l + 1);
// }
void dfs(node* r, int l) {
    cnt[l]++;
    if (l > maxl) {
        maxl = l;
    }
    if (r->lc != NULL) {
        dfs(r->lc, l + 1);
    }
    if (r->rc != NULL) {
        dfs(r->rc, l + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node* r = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        insert(r, v);
    }
    dfs(r, 1);
    cout << cnt[maxl] << " + " << cnt[maxl - 1] << " = " << cnt[maxl] + cnt[maxl - 1] << "\n";
    
    return 0;
}