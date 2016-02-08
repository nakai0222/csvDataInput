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
		//コメント箇所は除く
		if ((p = str.find("comment")) != str.npos) continue;
		vector<string> inner;

		//コンマがあるかを探し、そこまでをvaluesに格納
		while ((p = str.find(",")) != str.npos) {
			inner.push_back(str.substr(0, p));
			//strの中身を","の1文字後まで飛ばす
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