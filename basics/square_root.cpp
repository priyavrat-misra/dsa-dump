#include <iostream>

int main(){
	int n, p;
	float r = 0, inc = 1;

	std::cout << "Enter a number: ";
	std::cin >> n;
	std::cout << "Enter the precision count: ";
	std::cin >> p;

	for(int i=0; i<=p; i++){
		while(r*r<=n){
			r += inc;
		}
		r -= inc;
		inc /= 10;
	}

	std::cout << "The square root is: " << r << std::endl;
}
