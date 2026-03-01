#include <iostream>

using namespace std;

#define MAX 1000

int findMax(int a[], int size) {
	int max = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] > max) max = a[i];
	return max;
}

void countingSort(int a[], int size) {
	int max = findMax(a, size);
	if (max > MAX) return;
	int count[MAX+1] = { 0 };
	for (int i = 0; i < size; i++) count[a[i]]++;
	int idx = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i]--) {
			a[idx++] = i;
		}
	}
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) cout << a[i] << " ";
}

int main() {
	int a[7] = { 2,1,0,9,10,0,2 };
	printArray(a, 7);
	cout << endl;
	countingSort(a, 7);
	printArray(a, 7);
	return 0;
}