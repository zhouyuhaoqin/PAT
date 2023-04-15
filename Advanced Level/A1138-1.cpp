/*
*	author:		zhouyuhao
*	created:	2023-04-03 13:18:46
*	modified:	2023-04-03 13:27:07
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in, post;

void posttra(int r, int s, int e) {
    if (s > e) {
        return;
    }
    int i = s;
    while (i <= e && in[i] != pre[r]) {
        i++;
    }
    posttra(r + 1, s, i - 1);
    posttra(r + i - s + 1, i + 1, e);
    post.push_back(pre[r]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    posttra(0, 0, n - 1);
    cout << post[0] << "\n";
    
    return 0;
}