/*
*	author:		zhouyuhao
*	created:	2023-04-01 20:10:27
*	modified:	2023-04-02 22:27:58
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct peo {
    string id;
    int h;
};

bool cmp(peo a, peo b) {
    if (a.h != b.h) {
        return a.h > b.h;
    } else {
        return a.id < b.id;
    }
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<peo> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].h;
    }
    sort(p.begin(), p.end(), cmp);
    int rc = n / k;
    int lrc = n - (k - 1) * rc;
    queue<string> q;
    stack<string> s;
    for (int i = 0; i < lrc; i++) {
        if (i % 2 == 0) {
            q.push(p[i].id);
        } else {
            s.push(p[i].id);
        }
    }
    vector<string> row;
    while (!s.empty()) {
        row.push_back(s.top());
        s.pop();
    }
    while (!q.empty()) {
        row.push_back(q.front());
        q.pop();
    }
    for (int i = 0; i < row.size(); i++) {
        cout << row[i];
        if (i < row.size() - 1) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    for (int i = 0; i < k - 1; i++) {
        queue<string> q;
        stack<string> s;
        for (int j = lrc + i * rc; j < lrc + (i + 1) * rc; j++) {
            if ((j - lrc + i * rc) % 2 == 0) {
                q.push(p[j].id);
            } else {
                s.push(p[j].id);
            }
        }
        vector<string> row;
        while (!s.empty()) {
            row.push_back(s.top());
            s.pop();
        }
        while (!q.empty()) {
            row.push_back(q.front());
            q.pop();
        }
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }

    return 0;
}