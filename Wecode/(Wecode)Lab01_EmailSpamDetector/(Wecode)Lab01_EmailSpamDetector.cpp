#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void emailSpamDetector(unordered_set<string> black_list, vector<string> email_subjects) {
	int res = 0;
	bool found_any_spam = false;
	for (int i = 0; i < email_subjects.size(); i++) {
		string temp = "";
		bool is_current_email_spam = false;
		for(int j = 0;j<=email_subjects[i].length();j++) {
			if (j<email_subjects[i].length() && email_subjects[i][j] != ' ') {
				temp += email_subjects[i][j];
			}
			else {
				if (!temp.empty()) {
					if (black_list.count(temp)) {
						is_current_email_spam = true;
						break;
					}
					temp.clear();
				}
			}
		}
		if (is_current_email_spam) {
			cout << i + 1 << endl;
			found_any_spam = true;
		}
	}
	if (!found_any_spam) cout << "No spam found";
}

int main() {
	int M;
	cin >> M;
	cin.ignore(1000, '\n');

	unordered_set<string> black_list;
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		black_list.insert(temp);
	}

	int N;
	cin >> N;
	cin.ignore(1000, '\n');

	vector<string> email_subjects;
	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		email_subjects.push_back(temp);
	}

	emailSpamDetector(black_list, email_subjects);
	return 0;
}