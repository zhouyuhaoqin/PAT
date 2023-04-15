/*
*	author:		zhouyuhao
*	created:	2023-04-03 00:50:51
*	modified:	2023-04-03 01:50:20
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

bool isunique = true;
vector<int> pre, in, post;

void getin(int prel, int preh, int postl, int posth) {
    if (preh == prel) {
        in.push_back(pre[prel]);
        return;
    }
    if (pre[prel] == post[posth]) {
        int i = prel + 1;
        while (i <= preh && pre[i] != post[posth - 1]) {
            i++;
        }
        if (i - prel > 1) {
            getin(prel + 1, i - 1, postl, postl + i - prel - 1 - 1);
        } else {
            isunique = false;
        }
        in.push_back(post[posth]);
        getin(i, preh, postl + i - prel - 1 , posth - 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    getin(0, n - 1, 0, n - 1);
    if (isunique) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i];
        if (i < n - 1) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    
    return 0;
}