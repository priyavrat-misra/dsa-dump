// given co-ordinates in a 2D plane,
// find the distance between the closest pair
#include <iostream>
#include <cmath>

void delete2d(int** a, int n) {
	// deletes a 2d array
	for (int i = 0; i < n; ++i)
		delete[] a[i];
	delete[] a;
	a = nullptr;
}

void swap(int* a, int* b) {
	// swaps two arrays
	int t[] = {a[0], a[1]};
	a[0] = b[0];
	a[1] = b[1];
	b[0] = t[0];
	b[1] = t[1];
}

void qsort(int** points, int n, bool sort_y) {
	// quick sort with 1st element as pivot
	if (n > 1) {
		int i = 0, j = 1;
		while (j < n) {
			if (points[0][sort_y] <= points[j][sort_y]) {
				++j;
			} else {
				swap(points[i+1], points[j]);
				++i;
				++j;
			}
		}
		swap(points[0], points[i]);

		qsort(points, i, sort_y);
		qsort(points + i + 1, n - i - 1, sort_y);
	}
}

inline float distance(int* p, int* q) {
	return std::sqrt((q[0]-p[0])*(q[0]-p[0])
			+ (q[1]-p[1])*(q[1]-p[1]));
}

float closest_pair(int** points, int n) {
	if (n == 2) { // base case
		return distance(points[0], points[1]);
	} else if (n == 3) { // base case
		float a = distance(points[0], points[1]);
		float b = distance(points[1], points[2]);
		float c = distance(points[2], points[0]);
		b = a > b ? b : a;
		return c > b ? b : c; // min (a, b, c)
	} else {
		// divide
		int mid = n / 2;
		float dl = closest_pair(points, mid);
		float dr = closest_pair(points + mid, n - mid);
		float d = dl < dr ? dl : dr; // d = min (dl, dr)
		
		/* create an array of elements whose x co-ordinates
		 * are in range: [mid - d, mid + d) */
		int** strip = new int*[n];
		int k = 0, s = 0;
		dl = points[mid][0] - d;
		dr = points[mid][0] + d;
		while (k < n) {
			strip[k] = new int[2];
			if (points[k][0] >= dl && points[k][0] < dr) {
				strip[s][0] = points[k][0];
				strip[s][1] = points[k][1];
				++s;
				++k;
			} else {
				++k;
			}
		}

		qsort(strip, s, true); // sort strip wrt y co-ordinates
		
		// combine
		float t;
		int i = 0;
		while (s - i > 7) {
			for (int j = i + 1; j < 8; ++j) {
				t = distance(strip[i], strip[j]);
				d = d > t ? t : d;		
			}
			++i;
		}
		while (i < s) {
			for (int j = i + 1; j < s; ++j) {
				t = distance(strip[i], strip[j]);
				d = d > t ? t : d;
			}
			++i;
		}
		delete2d(strip, n);

		return d;
	}
}

int main() {
	int n;
	std::cout << "Enter number of points: ";
	if (std::cin >> n && n > 1) {
		int** points = new int*[n];
		
		// get and store the inputs in a 2d array
		std::cout << "Enter the co-ordinates:" << std::endl;
		for (int i = 0; i < n; ++i) {
			points[i] = new int[2];
			std::cout << "x y: ";
			std::cin >> points[i][0] >> points[i][1];
		}

		// sort the points wrt x co-ordinates inplace
		qsort(points, n, false);

		std::cout << "The distance between the closest pair is: "
			<< closest_pair(points, n) << std::endl;

		// deallocate array from heap
		delete2d(points, n);
	} else {
		std::cerr << "There must be at least 2 points." << std::endl;
	}
}
