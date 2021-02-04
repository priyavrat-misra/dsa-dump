#include <iostream>

int main(){
	int n, no, ans = 0;
	std::cout << "Enter count: ";
	std::cin >> n;
	std::cout << "Enter " << n << " number(s):" << std::endl;
	std::cout << "(doesn't support multiple unique numbers btw)" << std::endl;

	for(int i=0; i<n; i++){
		std::cin >> no;
		ans ^= no;
	}

	if(ans){
		std::cout << ans << " is unique." << std::endl;
	}
	else{
		std::cout << "No unique numbers found." << std::endl;
	}
}
