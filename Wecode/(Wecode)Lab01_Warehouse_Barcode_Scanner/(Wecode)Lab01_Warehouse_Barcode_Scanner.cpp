#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long ul;

long long warehouseBarcodeScanner(vector<ul> barcodes, ul query_barcode) {
	for (long long i = 0; i < barcodes.size(); i++) {
		if (barcodes[i] == query_barcode) return i + 1;
	}
	return -1;
}

int main() {
	ul n;
	cin >> n;

	vector<ul> barcodes(n);
	for (ul i = 0; i < n; i++) {
		cin >> barcodes[i];
	}

	ul query_barcode;
	cin >> query_barcode;

	cout << warehouseBarcodeScanner(barcodes, query_barcode);
	return 0;
}