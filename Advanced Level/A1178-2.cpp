/*
*	author:		zhouyuhao
*	created:	2023-04-14 22:53:15
*	modified:	2023-04-14 23:18:52
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <iomanip>

using namespace std;

const int maxn = 1e4;

vector<int> f(maxn, -1); // father

void dfs(int v, vector<int> &ans) { // &
	if (v == 0) {
		ans.push_back(v);
		return;
	}
	dfs(f[v], ans);
	ans.push_back(v);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int r;
	cin >> r;
	getchar();
	f[r] = r;
	stack<int> st;
	st.push(r);
	map<int, int> level;
	level[r] = 0;
	for (int i = 0; i < n - 1; i++) {
		string s;
		getline(cin, s);
		int l = 0;
		while (isspace(s[0])) {
			s.erase(0, 1);
			l++;
		}
		int id = stoi(s);
		level[id] = l;
		int p = st.top();
		if (l > level[p]) {
			st.push(id);
			f[id] = p;
		} else {
			while (l <= level[p]) {
				st.pop();
				p = st.top();
			}
			st.push(id);
			f[id] = p;
		}
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		if (f[id] == -1) {
			cout << "Error: " << setfill('0') << setw(4) << id << " is not found." << "\n";
			continue;
		}
		vector<int> ans;
		dfs(id, ans);
		for (int i = 0; i < ans.size(); i++) {
			cout << setfill('0') << setw(4) << ans[i];
			if (i < ans.size() - 1) {
				cout << "->";
			} else {
				cout << "\n";
			}
		}
	}
	return 0;
}