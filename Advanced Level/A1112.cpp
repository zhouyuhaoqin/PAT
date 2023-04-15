/*
*	author:		zhouyuhao
*	created:	2023-04-02 19:48:22
*	modified:	2023-04-02 20:09:08
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    string s;
    cin >> s;
    set<char> stucked, unstucked;
    vector<char> ans;
    for (int i = 0; i < s.size(); i++) {
        bool flag = true;
        for (int j = 0; j < k; j++) {
        // for (int j = 0; j < k && i + j < s.size(); j++) {
            if (s[i + j] != s[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (unstucked.find(s[i]) == unstucked.end()) {
                stucked.insert(s[i]);
                ans.push_back(s[i]);
            }
            i += k - 1;
        } else {
            unstucked.insert(s[i]);
        }
    }
    stucked.clear();
    for (auto it : ans) {
        if (unstucked.find(it) == unstucked.end()) {
            if (stucked.find(it) == stucked.end()) {
                stucked.insert(it);
                cout << it;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < s.size(); i++) {
        bool flag = true;
        for (int j = 1; j < k && i + j < s.size(); j++) {
            if (s[i + j] != s[i]) {
                flag = false;
                break;
            }
        }
        if (flag && unstucked.find(s[i]) == unstucked.end()) {
            cout << s[i];
            i += k - 1;
            continue;
        }
        cout << s[i];
    }
    cout << "\n";
    
    return 0;
}