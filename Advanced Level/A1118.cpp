/*
*	author:		zhouyuhao
*	created:	2023-04-03 00:40:19
*	modified:	2023-04-03 00:50:34
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e4 + 1;

vector<int> f(maxn);

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

int find(int x) {
    int a = x;
    while(x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) {
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb) {
        f[fa] = fb;
    }
}

int main(int argc, char const *argv[]) {

    init();
    int n;
    cin >> n;
    set<int> b;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int b1;
        cin >> b1;
        b.insert(b1);
        for (int j = 1; j < k; j++) {
            int b2;
            cin >> b2;
            joint(b1, b2);
            b.insert(b2);
        }
    }
    set<int> t;
    for (auto it : b) {
        t.insert(find(it));
    }
    cout << t.size() << " " << b.size() << "\n";
    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++) {
        int b1, b2;
        cin >> b1 >> b2;
        if (find(b1) == find(b2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}