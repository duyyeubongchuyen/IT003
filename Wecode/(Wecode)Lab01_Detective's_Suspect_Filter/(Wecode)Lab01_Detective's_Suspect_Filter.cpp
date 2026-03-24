#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SUSPECT {
	string name;
	unsigned int height;
	string hair_color;
};

struct FEATURES{
	unsigned int max_height;
	unsigned int min_height;
	string hair_color;
};

vector<SUSPECT> suspectFilter(vector<SUSPECT> suspects,FEATURES features ) {
	vector<SUSPECT> res;
	for (int i = 0; i < suspects.size(); i++) {
		if (suspects[i].hair_color == features.hair_color && (suspects[i].height >= features.min_height && suspects[i].height <= features.max_height)){
			res.push_back(suspects[i]);
		}
	}
	return res;
}

void printSuspectNames(vector<SUSPECT> suspects) {
	if (suspects.empty()) {
		cout << "No suspects found";
	}
	else {
		for (int i = 0; i < suspects.size(); i++) {
			cout << suspects[i].name << endl;
		}
	}
}

void insertSuspects(vector<SUSPECT>& suspects) {
	for (int i = 0; i < suspects.size(); i++) {
		cin >> suspects[i].name >> suspects[i].height >> suspects[i].hair_color;
	}
}

void insertFeatures(FEATURES& features) {
	cin >> features.min_height >> features.max_height >> features.hair_color;
}


int main() {
	int n;
	cin >> n;

	vector<SUSPECT>suspects (n);
	insertSuspects(suspects);

	FEATURES features;
	insertFeatures(features);

	printSuspectNames(suspectFilter(suspects, features));
	return 0;
}