#pragma once

#include<iostream>
#include<fstream>
#include<string>
class IDCARD {
public:
	std::string number;
	std::string Place;
	IDCARD(std::string s) {
		number = s;
	}
	void setitems();
	bool IDcardtrue();
	bool checknum();
	void XingZuo(int, int, int);
	void brithday(std::string, std::string, std::string);
	bool truthage();
	void iffalse();
	void get_sx();
	void get_sex();
	bool RN();
	void get_age();
	void dis_brith();
	void end() {
		std::ofstream fout("C:\\BDT\\out.txt", std::ios::app);
		if (!fout)
		{
			std::cerr << "�ļ���ʧ�ܣ�\n";
			exit(1);
		}//�ж��ļ����Ƿ�ɹ�
		fout << "********************************************" << std::endl;
	}
	bool GSD();
	void get_GSD();
	void luner(int, int, int);
	void num();
	void suliaodai();
};
