/*
*	author:		zhouyuhao
*	created:	2023-03-28 20:32:52
*	modified:	2023-03-28 22:13:59
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> pre, in, ans;

void post(int r, int s, int e) {
	if (s > e) {
		return;
	}
	int i = s;
	while (i <= e && in[i] != pre[r]) {
		i++;
	}
	post(r + 1, s, i - 1);
	post(r + i - s + 1, i + 1, e);
	ans.push_back(pre[r]);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
	    string ss;
	    cin >> ss;
	    if (ss.size() == 4) {
	    	int num;
	    	cin >> num;
	    	s.push(num);
	    	pre.push_back(num);
	    } else {
	    	in.push_back(s.top());
	    	s.pop();
	    }
	}
	post(0, 0, n - 1);
	for (int i = 0; i < n; i++) {
	    cout << ans[i];
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}