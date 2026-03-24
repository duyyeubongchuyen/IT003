#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PRODUCT {
	string name;
	unsigned int price;
};

vector<string> flashSaleFinder(vector<PRODUCT> products, unsigned int budget) {
	vector<string> res;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].price < budget) res.push_back(products[i].name);
	}
	return res;
}

void printProducts(vector<string> products) {
	if (products.empty()) cout << "No items found";
	else {
		for (int i = 0; i < products.size(); i++) {
			cout << products[i] << endl;
		}
	}
}

int main() {
	unsigned int n;
	cin >> n;
	
	vector<PRODUCT> products(n);
	for (int i = 0; i < n; i++) {
		cin >> products[i].name >> products[i].price;
	}

	unsigned int budget;
	cin >> budget;
	printProducts(flashSaleFinder(products, budget));
	return 0;
}