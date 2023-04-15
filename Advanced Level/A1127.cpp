/*
*	author:		zhouyuhao
*	created:	2023-04-03 03:19:31
*	modified:	2023-04-03 03:41:20
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    node *lc, *rc;
};

vector<int> in, post;
map<int, vector<int>> t;

node* create(int r, int s, int e, int l) {
    if (s > e) {
        return NULL;
    }
    node* root = new node;
    t[l].push_back(post[r]);
    int i = s; // i = s
    while (i <= e && in[i] != post[r]) {
        i++;
    }
    root->lc = create(r - e + i - 1, s, i - 1, l + 1);
    root->rc = create(r - 1, i + 1, e, l + 1);
    return root;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    node* root = create(n - 1, 0, n - 1, 1);
    vector<int> ans;
    for (auto it : t) {
        if (it.first % 2 != 0) {
            reverse(it.second.begin(), it.second.end());
        }
        for (auto is : it.second) {
            ans.push_back(is);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    
    return 0;
}