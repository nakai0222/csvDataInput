#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream file("TrackingData_2016-02-05.csv");
	vector<vector<string>> values;
	string str;
	int p;

	if (file.fail()) {
		cerr << "failed." << endl;
		exit(0);
	}

	while (getline(file, str)) {
		//�R�����g�ӏ��͏���
		if ((p = str.find("comment")) != str.npos) continue;
		vector<string> inner;

		//�R���}�����邩��T���A�����܂ł�values�Ɋi�[
		while ((p = str.find(",")) != str.npos) {
			inner.push_back(str.substr(0, p));
			//str�̒��g��","��1������܂Ŕ�΂�
			str = str.substr(p + 1);
		}
		inner.push_back(str);
		values.push_back(inner);
	}

	for (unsigned int i = 0; i < values.size(); ++i) {
		for (unsigned int j = 0; j < values[i].size(); ++j) {
			cout << values[i][j] << ",";
		}
		cout << endl;
		getchar();
	}

	return 0;
}