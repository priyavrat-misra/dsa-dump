class MinStack {
public:
	stack<int> s;
	stack<int> ss;

	void push(int val) {
		s.push(val);
		if (ss.empty() || ss.top() >= val)
			ss.push(val);
	}

	void pop() {
		if (s.empty())
			return;
		if (s.top() == ss.top())
			ss.pop();
		s.pop();
	}
	
	int top() {
		if (s.empty())
			return -1;
		return s.top();
	}

	int getMin() {
		if (ss.empty())
			return -1;
		return ss.top();
	}
};
