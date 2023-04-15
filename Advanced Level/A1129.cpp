/*
*	author:		zhouyuhao
*	created:	2023-04-03 10:15:56
*	modified:	2023-04-03 10:38:41
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int id;
    int freq;
};

bool cmp(node a, node b) {
    if (a.freq != b.freq) {
        return a.freq > b.freq;
    } else {
        return a.id < b.id;
    }
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        vector<node> rec;
        for (auto it : cnt) {
            rec.push_back({it.first, it.second});
        }
        if (rec.size() != 0) {
            cout << id << ": ";
            sort(rec.begin(), rec.end(), cmp);
            int size = min((int) rec.size(), k);
            for (int j = 0; j < size; j++) {
                cout << rec[j].id;
                if (j < size - 1) {
                    cout << " ";
                } else {
                    cout << "\n";
                }
            }
        }
        cnt[id]++;
    }
    
    return 0;
}