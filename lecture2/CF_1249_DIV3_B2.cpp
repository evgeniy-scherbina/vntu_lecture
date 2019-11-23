#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int a, b;
    // cin >> a >> b;
    // cout << a + b;
    int q, n;
    cin >> q;

	for (int t = 0; t < q; t++) {
    	cin >> n;
        vector<int> p(n + 1);
    	for (int i = 1; i <= n; i++) {
    		cin >> p[i];
    	}

        vector<int> answer(n + 1);
        vector<bool> visited(n + 1, false);
    	for (int i = 1; i <= n; i++) {
    		if (visited[i]) {
    			continue;
    		}

    		int nxt = i;
    		visited[nxt] = true;
            vector<int> cycle;
            cycle.push_back(nxt);
    		while (true) {
    			nxt = p[nxt];
    			if (visited[nxt]) {
    				break;
    			}
    			visited[nxt] = true;
    			cycle.push_back(nxt);
    		}

            for (int j = 0; j < cycle.size(); j++) {
                int vertex = cycle[j];
                answer[vertex] = cycle.size();
            }
        }

        for (int i = 1; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
	}
	return 0;
}