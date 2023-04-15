/*
*	author:		zhouyuhao
*	created:	2023-04-03 11:53:38
*	modified:	2023-04-03 12:03:45
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int maxn = 1e5;

struct node {
    int id, v, next;
};

vector<node> d(maxn);

int main(int argc, char const *argv[]) {

    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        d[id].id = id;
        cin >> d[id].v >> d[id].next;
    }
    vector<node> a1, a2, a3;
    do {
        if (d[head].v < 0) {
            a1.push_back(d[head]);
        } else if (d[head].v <= k) {
            a2.push_back(d[head]);
        } else {
            a3.push_back(d[head]);
        }
        head = d[head].next;
    } while (head != -1);
    vector<node> ans;
    for (auto it : a1) {
        ans.push_back(it);
    }
    for (auto it : a2) {
        ans.push_back(it);
    }
    for (auto it : a3) {
        ans.push_back(it);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << setfill('0') << setw(5) << ans[i].id << " " << ans[i].v << " ";
        if (i < ans.size() - 1) {
            cout << setfill('0') << setw(5) << ans[i + 1].id << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}