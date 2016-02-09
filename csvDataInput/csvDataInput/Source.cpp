#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

void csvDataInput(vector<vector<double>> &csv_data);
bool csvDataInputTest(vector<vector<double>> &csv_data);

int main() {

	vector<vector<double>> csv_data;
	csvDataInputTest(csv_data);

	return 0;
}

//void csvDataInput(�f�B���N�g�����Avector<vector<double>> &csv_data)�ɂ������ˁB
void csvDataInput(vector<vector<double>> &csv_data) {

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
	//string->double vector�Ƃ��Ď��B
	vector<double> inner_d;
	for (unsigned int i = 0; i < values.size(); ++i) {
		inner_d.clear();
		for (unsigned int j = 0; j < values[i].size(); ++j) {
			if (std::all_of(values[i][j].cbegin(), values[i][j].cbegin() + 1, isdigit))
			{
				// string �̍\�������񂪑S�Đ����̏ꍇ�� true �ɂȂ�܂��B
				inner_d.push_back(stof(values[i][j]));
			}
		}
		if (inner_d.size() > 0)
			csv_data.push_back(inner_d);
	}
}

bool csvDataInputTest(vector<vector<double>> &csv_data) {

	csvDataInput(csv_data);

	for (int i = 0; i < csv_data.size(); ++i) {
		cout << "size : " << csv_data[i].size() << endl;
		for (int j = 0; j < csv_data[i].size(); ++j) {
			std::cout << csv_data[i][j] << std::endl;
		}
		cout << endl;
	}
	cout << "Test Finished!" << endl;
	return true;
}
