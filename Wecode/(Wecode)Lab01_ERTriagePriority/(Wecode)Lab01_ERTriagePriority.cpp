#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct PATIENT {
	string name;
	int severityScore;  
	bool seen;    
	int entryOrder;  // Thứ tự trong hàng chờ (index)

	bool operator<(const PATIENT& patient)const {
		if (severityScore != patient.severityScore) {
			return severityScore < patient.severityScore;
		}
		return entryOrder > patient.entryOrder;
	}
};


int main() {
	long n;
	cin >> n;
	priority_queue<PATIENT> room;
	for (int i = 0; i < n; i++) {
		PATIENT temp;
		cin >> temp.name >> temp.severityScore >> temp.seen;
		temp.entryOrder = i;
		if (!temp.seen) room.push(temp);
	}
	if (room.empty()) cout << "All patients seen";
	else {
		PATIENT patientTop = room.top();
		cout << patientTop.name;
	}
	return 0;
}