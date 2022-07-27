#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int max_rect(vector<int>& height, int& size) {
	vector<int> nsl, nsr;
	stack<pair<int, int>> s;
	for (int i = 0; i < size; ++i) {
		while (!s.empty() && s.top().first >= height[i])
			s.pop();
		if (s.empty())
			nsl.push_back(-1);
		else
			nsl.push_back(s.top().second);
		
		s.push({height[i], i});
	}

	while (!s.empty())
		s.pop();

	for (int i = size - 1; i >= 0; --i) {
		while (!s.empty() && s.top().first >= height[i])
			s.pop();
		if (s.empty())
			nsr.push_back(size);
		else
			nsr.push_back(s.top().second);

		s.push({height[i], i});
	}
	reverse(nsr.begin(), nsr.end());

	vector<int> width(size);
        for (int i = 0; i < size; ++i)
                width[i] = nsr[i] - nsl[i] - 1;

        int max_area = 0;
        for (int i = 0; i < size; ++i)
                max_area = max(max_area, height[i] * width[i]);

	return max_area;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m);
	for (int i = 0; i < m; ++i) {
		vector<int> row(n);
		for (int j = 0; j < n; ++j)
			cin >> row[j];
		matrix[i] = row;
	}

	vector<int> cumsum = matrix[0];
	int max_area = max_rect(cumsum, n);
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j])
				cumsum[j] += matrix[i][j];
			else
				cumsum[j] = 0;
		}
		max_area = max(max_area, max_rect(cumsum, n));
	}
	cout << max_area << endl;
}
