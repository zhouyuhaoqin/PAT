/*
*	author:		zhouyuhao
*	created:	2023-04-03 02:54:39
*	modified:	2023-04-03 02:59:32
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    stack<int> s;
    s.push(d[0]);
    for (int i = 1; i < n; i++) {
        int r = s.top();
        s.pop();
        s.push((r + d[i]) / 2);
    }
    cout << s.top() << "\n";
    
    return 0;
}