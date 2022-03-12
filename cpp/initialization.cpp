int main() {
	int i = 0;
	int i(0);
	// list initialization
	int i = {0};
	int i{0};

	long double ld = 3.1415926536;
	// compiler will not let us do the following
	// since it leads to loss of information
	int a{ld}, b = {ld};
	// whereas it allows the following
	int c(ld); d = ld;
}
