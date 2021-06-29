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

int** slice(int** points, int start, int end) {
	int** sl = new int*[end-start];
	for (int i = start; i < end; ++i) {
		sl[i-start] = new int[2];
		sl[i-start][0] = points[i][0];
		sl[i-start][1] = points[i][1];
	}
	return sl;
}

// merge sort - start
void merge(int** p, int** l, int** r, int ls, int rs, bool sort_y) {
	int i = 0, j = 0;
	while (i < ls && j < rs) {
		if (l[i][sort_y] > r[j][sort_y]) {
			p[i+j][0] = r[j][0];
			p[i+j][1] = r[j][1];
			++j;
		} else {
			p[i+j][0] = l[i][0];
			p[i+j][1] = l[i][1];
			++i;
		}
	}
	while (i < ls) {
		p[i+j][0] = l[i][0];
		p[i+j][1] = l[i][1];
		++i;
	}
	while (j < rs) {
		p[i+j][0] = r[j][0];
		p[i+j][1] = r[j][1];
		++j;
	}

	// deallocate arrays from heap
	delete2d(l, ls);
	delete2d(r, rs);
}

void msort(int** points, int n, bool sort_y) {
	if (n > 1) {
		int mid = n / 2;
		int** left = slice(points, 0, mid);
		int** right = slice(points, mid, n);

		msort(left, mid, sort_y);
		msort(right, n - mid, sort_y);
		merge(points, left, right, mid, n - mid, sort_y);
	}
}
// merge sort - end

inline float distance(int* p, int* q) {
	return std::sqrt((q[0]-p[0])*(q[0]-p[0])
			+ (q[1]-p[1])*(q[1]-p[1]));
}

float closest_pair(int** sorted_x, int** sorted_y, int n) {
	if (n == 2) { // base case
		return distance(sorted_x[0], sorted_x[1]);
	} else if (n == 3) { // base case
		float a = distance(sorted_x[0], sorted_x[1]);
		float b = distance(sorted_x[1], sorted_x[2]);
		float c = distance(sorted_x[2], sorted_x[0]);
		b = a > b ? b : a;
		return c > b ? b : c; // min (a, b, c)
	} else {
		// divide
		int mid = n / 2;
		int** left = slice(sorted_x, 0, mid);
		int** right = slice(sorted_x, mid, n);
		float dl = closest_pair(left, sorted_y, mid);
		float dr = closest_pair(right, sorted_y, n - mid);
		float d = dl < dr ? dl : dr; // d = min (dl, dr)
		
		// create an array of elements whose x co-ordinates
		// are in range: [mid - d, mid + d)
		int** temp_strip = new int*[n];
		int k = 0, s = 0;
		dl = sorted_x[mid][0] - d;
		dr = sorted_x[mid][0] + d;
		while (k < n) {
			temp_strip[k] = new int[2];
			if (sorted_y[k][0] >= dl && sorted_y[k][0] < dr) {
				temp_strip[s][0] = sorted_y[k][0];
				temp_strip[s][1] = sorted_y[k][1];
				++s;
				++k;
			} else {
				++k;
			}
		}
		int** strip = new int*[s];
		for (int i = 0; i < s; ++i) {
			strip[i] = new int[2];
			strip[i][0] = temp_strip[i][0];
			strip[i][1] = temp_strip[i][1];
		}

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
		
		// deallocate arrays from heap
		delete2d(left, mid);
		delete2d(right, n - mid);
		delete2d(temp_strip, n);
		delete2d(strip, s);

		return d;
	}	
}

int main() {
	int n;
	std::cout << "Enter number of points: ";
	if (std::cin >> n && n > 1) {
		int** sort_x = new int*[n];
		int** sort_y = new int*[n];
		/* Two arrays because one will contain points
		 * sorted w.r.t x co-ordinates and the other
		 * sorted w.r.t y co-ordinates. This is because it'll
		 * save computation later on in the recursion steps,
		 * where there is a need of sorting w.r.t y co-ordinates.
		 */
		
		// get and store the inputs in the two 2d arrays
		std::cout << "Enter the co-ordinates:" << std::endl;
		for (int i = 0; i < n; ++i) {
			sort_x[i] = new int[2];
			sort_y[i] = new int[2];
			std::cout << "x y: ";
			std::cin >> sort_x[i][0] >> sort_x[i][1];
			sort_y[i][0] = sort_x[i][0];
			sort_y[i][1] = sort_x[i][1];
		}

		// sort the points inplace
		msort(sort_x, n, false);
		msort(sort_y, n, true);

		std::cout << "The distance between the closest pair is: "
			<< closest_pair(sort_x, sort_y, n) << std::endl;

		// deallocate arrays from heap
		delete2d(sort_x, n);
		delete2d(sort_y, n);
	} else {
		std::cerr << "There must be at least 2 points." << std::endl;
	}
}
