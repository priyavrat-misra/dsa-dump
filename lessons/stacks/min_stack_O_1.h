class MinStack {
public:
	stack<int> s;
	int min = -1;

	void push(int val) {
		if (s.empty()) {
			s.push(val);
			min = val;
		} else {
			if (val >= min)
				s.push(val);
			else {
				s.push(2 * val - min);
				min = val;
			}
		}
	}

	void pop() {
		if (s.empty())
			return;
		if (s.top() >= min)
			s.pop();
		else {
			min = 2 * min - s.top();
			s.pop();
		}
	}

	int top() {
		if (s.empty())
			return -1;
		if (s.top() >= min)
			return s.top();
		else
			return min;
	}

	int getMin() {
		if (s.empty())
			return -1;
		return min;
	}
};
