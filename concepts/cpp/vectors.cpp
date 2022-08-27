#include <iostream>
#include <vector>

void printsc(std::vector<int> &v) {
	// prints the size and the capacity
	std::cout << v.size() << "\t"
		<< v.capacity() << std::endl;
}

void printvec(std::vector<int> &v) {
	// prints the elements
	for (int el: v)  // for-each
		std::cout << el << " ";
	/* is same as
	* for (int i = 0; i < v.size(); ++i)
	* 	std::cout << v[i] << " ";
	*//* is same as
	* for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	* 	std::cout << *i << " ";
	*//* is same as
	* for (auto i = v.begin(); i != v.end(); ++i)
	* 	std::cout << *i << " ";
	*/
	// `auto` sets the type of the variable (`i`) same as
	// whatever it's initializer (`v.begin()`) is returning
	
	std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
	std::vector<int> v;
	printsc(v);
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		printsc(v);
	}
	std::cout << std::endl;

	// will allocate a vector of capacity 10 with garbage values
	std::vector<int> v1(10);
	printvec(v1);
	printsc(v1);
	std::cout << std::endl;

	// will allocate a vector of capacity 10 with all -1
	std::vector<int> v2(10, -1);
	printvec(v2);
	printsc(v2);
	std::cout << std::endl;

	std::vector<int> v3 = {1, 2, 3};  // or v3{1, 2, 3};
	printvec(v3);
	printsc(v3);
	v3.push_back(4);
	v3[1] = 0;
	printvec(v3);
	printsc(v3);
	std::cout << std::endl;

	std::vector<int> v4 = {v3.begin(), v3.end() - 2};  // note the -2
	printvec(v4);
	printsc(v4);
	std::cout << std::endl;

	// can be initialized from an array
	int arr[] = {5, 4, 3, 2, 1};
	std::vector<int> v5 = {arr, arr + 4};
	printvec(v5);
	printsc(v5);
	std::cout << std::endl;

	// will have 1 at non-zero element positions
	std::vector<bool> v6 = {v3.begin(), v.end()};  // or v6(v3.begin(), v3.end());
	for (bool elm: v6)
		std::cout << elm << " ";
	
	// bool vectors are assigned a capacity of 64 after first push back
	std::cout  << "\n" << v6.size() << "\t"
		<< v6.capacity() << "\n" << std::endl;

	// comparing vectors element-wise
	std::cout << (v3 == v5 ? "true" : "false") << std::endl;

	// clearing vectors for reuse
	v.clear();
	printsc(v);  // note: allocated capacity wasn't deallocated
	std::cout << (v.empty() ? "true" : "false") << std::endl;

	return 0;
}
