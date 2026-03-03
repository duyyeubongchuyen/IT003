#include <iostream>
#include <vector>

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

void countSort(int arr[], int n, int exp)
{
	int output[MAX+1];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


void radixSort(int a[], int size) {
	int max = findMax(a, size);
	for (int exp = 1; max / exp > 0; exp*=10) 
		countSort(a, size, exp);
}

void merge(vector<int>& arr, int left,
    int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
	int a[7] = { 2,1,0,9,10,0,2 };
	printArray(a, 7);
	cout << endl;
	radixSort(a, 7);
	printArray(a, 7);
	return 0;
}