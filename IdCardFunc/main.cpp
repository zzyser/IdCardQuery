#include<iostream>
#include<string>
#include<fstream>

#include"IdCard.h"

using namespace std;

int main() {

	string IDnum;
	ifstream fin123("C:\\BDT\\in.txt");
	ofstream fout123("C:\\BDT\\out.txt");
	if (!fin123 || !fout123) {
		cout << "文件打开失败\n";
		exit(1);
	}
	while (getline(fin123, IDnum)) {
		IDCARD id(IDnum);
		id.num();
		id.setitems();
		if (id.IDcardtrue()) {
			id.suliaodai();
		}
		id.end();
	}

	return 0;
}