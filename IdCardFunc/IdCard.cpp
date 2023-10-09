#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<Windows.h>

#include"IdCard.h"

using namespace std;

static int cishu = 0;
int stand1 = 0, stand2 = 0, stand3 = 0;
string N, Y, R, Sex;
int n, y, r, sex;

void IDCARD::suliaodai() {
	get_GSD();
	get_sex();
	brithday(N, Y, R);
	luner(n, y, r);
	get_age();
	dis_brith();
	XingZuo(n, y, r);
	get_sx();
}

void IDCARD::num() {
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "���֤���룺 " << number << endl;
	fout.close();
}
void IDCARD::dis_brith() {
	//�ȼ�������������ǰ������,�ټ���������������������,��������.����������
	int DAYS = 0, days = 0;
	int CHA = 0, BRI = 0;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	if (RN()) {//����ʱ
		switch (sys.wMonth) {
		case 1:DAYS = sys.wDay; break;
		case 2:DAYS = 31 + sys.wDay; break;
		case 3:DAYS = 60 + sys.wDay; break;
		case 4:DAYS = 91 + sys.wDay; break;
		case 5:DAYS = 121 + sys.wDay; break;
		case 6:DAYS = 152 + sys.wDay; break;
		case 7:DAYS = 182 + sys.wDay; break;
		case 8:DAYS = 213 + sys.wDay; break;
		case 9:DAYS = 244 + sys.wDay; break;
		case 10:DAYS = 274 + sys.wDay; break;
		case 11:DAYS = 305 + sys.wDay; break;
		case 12:DAYS = 335 + sys.wDay; break;

		}
		switch (y) {
		case 1:days = r; break;
		case 2:days = 31 + r; break;
		case 3:days = 60 + r; break;
		case 4:days = 91 + r; break;
		case 5:days = 121 + r; break;
		case 6:days = 152 + r; break;
		case 7:days = 182 + r; break;
		case 8:days = 213 + r; break;
		case 9:days = 244 + r; break;
		case 10:days = 274 + r; break;
		case 11:days = 305 + r; break;
		case 12:days = 335 + r; break;
		}
		CHA = DAYS - days;
	}
	else {//ƽ��ʱ
		switch (sys.wMonth) {
		case 1:DAYS = sys.wDay; break;
		case 2:DAYS = 31 + sys.wDay; break;
		case 3:DAYS = 59 + sys.wDay; break;
		case 4:DAYS = 90 + sys.wDay; break;
		case 5:DAYS = 120 + sys.wDay; break;
		case 6:DAYS = 151 + sys.wDay; break;
		case 7:DAYS = 181 + sys.wDay; break;
		case 8:DAYS = 212 + sys.wDay; break;
		case 9:DAYS = 243 + sys.wDay; break;
		case 10:DAYS = 273 + sys.wDay; break;
		case 11:DAYS = 304 + sys.wDay; break;
		case 12:DAYS = 334 + sys.wDay; break;
		}
		switch (y) {
		case 1:days = r; break;
		case 2:days = 31 + r; break;
		case 3:days = 69 + r; break;
		case 4:days = 90 + r; break;
		case 5:days = 120 + r; break;
		case 6:days = 151 + r; break;
		case 7:days = 181 + r; break;
		case 8:days = 212 + r; break;
		case 9:days = 243 + r; break;
		case 10:days = 273 + r; break;
		case 11:days = 304 + r; break;
		case 12:days = 334 + r; break;
		}
		CHA = DAYS - days;
	}
	if (CHA < 0) {
		BRI = -CHA;
	}
	else {
		if (RN()) {
			BRI = 366 - DAYS + days;
		}
		else {
			BRI = 365 - DAYS + days;
		}
	}
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "�����´����ջ��У� " << BRI << "��\n";
	fout.close();
}
void IDCARD::setitems() {
	N = number.substr(6, 4);
	Y = number.substr(10, 2);
	R = number.substr(12, 2);
	Sex = number.substr(16, 1);
	stringstream sss1, sss2, sss3, sss4;
	sss1 << N;
	sss2 << Y;
	sss3 << R;
	sss1 >> n;
	sss2 >> y;
	sss3 >> r;//��string���� �ꡢ�¡��� ת���� ����
	sss4 << Sex;
	sss4 >> sex;
}
bool IDCARD::IDcardtrue() {
	bool A, B, C;
	A = checknum();
	B = truthage();
	C = GSD();
	if (A) {
		if (B) {
			if (C) {
				return true;
			}
		}

	}
	iffalse();

	return false;
}
void IDCARD::brithday(string N, string Y, string R) {
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "�������ڣ� " << N << "��" << Y << "��" << R << "��\n";
	fout.close();
}
void IDCARD::XingZuo(int year, int month, int day)
{
	string xingzuo;
	if ((month == 12 && day >= 21) || (month == 1 && day <= 19))
		xingzuo = "Ħ����";
	else if ((month == 1 && day >= 19) || (month == 2 && day <= 18))
		xingzuo = "ˮƿ��";
	else if ((month == 2 && day >= 18) || (month == 3 && day <= 20))
		xingzuo = "˫����";
	else if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
		xingzuo = "������";
	else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
		xingzuo = "��ţ��";
	else if ((month == 5 && day >= 21) || (month == 6 && day <= 21))
		xingzuo = "˫����";
	else if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
		xingzuo = "��з��";
	else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
		xingzuo = "ʨ����";
	else if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
		xingzuo = "��Ů��";
	else if ((month == 9 && day >= 23) || (month == 10 && day <= 23))
		xingzuo = "�����";
	else if ((month == 10 && day >= 24) || (month == 11 && day <= 22))
		xingzuo = "��Ы��";
	else
		xingzuo = "������";
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "������ " << xingzuo << endl;
	fout.close();
}
bool IDCARD::checknum()//���֤У��λ
{
	int weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char validate[] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int sum = 0;
	int mode = 0;
	int i = 0;
	if (number.length() == 18)
	{
		for (i = 0; i < number.length() - 1; i++)
			sum = sum + (number[i] - '0') * weight[i];
		mode = sum % 11;
		if (validate[mode] == number[17])
		{
			return true;
		}
	}
	stand3 = 1;
	return false;
}
bool IDCARD::truthage() {//�����Ƿ����130��
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	if (sys.wYear - n >= 130 || sys.wYear - n < 0) {
		stand2 = 1;
		return false;
	}
	return true;
}
bool IDCARD::RN() {
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0)) {
		return true;
	}
	else
		return false;
}
void IDCARD::iffalse() {
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	if (stand1 == 1 || stand2 == 1 || stand3 == 1) {//�ж����֤����ԭ��
		fout << "���֤���벻��ȷ";
	}
	if (stand1 == 1) {
		if (stand2 == 1) {
			if (stand3 == 1) {
				fout << "�����ڵǼǵش��󡢳������ڴ���У��λ����\n";
			}
			else {
				fout << "�����ڵǼǵش��󡢳������ڴ���\n";
			}
		}
		else if (stand3 == 1) {
			fout << "�����ڵǼǵش��󡢼���λ����\n";
		}
		else {
			fout << "�����ڵǼǵش���\n";
		}
	}
	else if (stand2 == 1) {
		if (stand3 == 1) {
			fout << "���������ڴ���У��λ����\n";
		}
		else {
			fout << "���������ڴ���\n";
		}

	}
	else if (stand3 == 1) {
		fout << "��У��λ����\n";
	}
	fout.close();
}
void IDCARD::get_sx() {
	string sx;
	int yy = n - 1900;
	int year = yy % 12;
	if (year == 0)
		sx = "��";
	if (year == 1)
		sx = "ţ";
	if (year == 2)
		sx = "��";
	if (year == 3)
		sx = "��";
	if (year == 4)
		sx = "��";
	if (year == 5)
		sx = "��";
	if (year == 6)
		sx = "��";
	if (year == 7)
		sx = "��";
	if (year == 8)
		sx = "��";
	if (year == 9)
		sx = "��";
	if (year == 10)
		sx = "��";
	if (year == 11)
		sx = "��";
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "��Ф��" << sx << endl;
	fout.close();
}
void IDCARD::get_sex() {
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	if (sex % 2 == 1) {
		fout << "�Ա���\n";
	}
	else {
		fout << "�Ա�Ů\n";
	}
	fout.close();
}
void IDCARD::get_age() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int age = sys.wYear - n;
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "���䣺" << age << "��\n";
	fout.close();
}
bool IDCARD::GSD() {
	string place;
	ifstream  fin("C:\\BDT\\���֤���������ݿ�.txt");
	if (!fin) {
		cout << "�ļ��򿪴���\n";
		exit(1);
	}
	while (!fin.eof())
	{
		getline(fin, place);
		if (number.substr(0, 6) == place.substr(0, 6))
		{
			Place = place.substr(6);
			return true;
		}
	}
	stand1 = 1;
	return false;
	fin.close();
}
void IDCARD::get_GSD() {
	ofstream fout("C:\\BDT\\out.txt", ios::app);
	if (!fout)
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		exit(1);
	}//�ж��ļ����Ƿ�ɹ�
	fout << "���ڵǼǵأ� " << Place << endl;
	fout.close();
}


string Date[155] = { "04AE53","0A5748","5526BD","0D2650","0D9544","46AAB9","056A4D","09AD42",
				  "24AEB6","04AE4A","6A4DBE","0A4D52","0D2546","5D52BA","0B544E","0D6A43",
				  "296D37","095B4B","749BC1","049754","0A4B48","5B25BC","06A550","06D445",
				  "4ADAB8","02B64D","095742","2497B7","04974A","664B3E","0D4A51","0EA546",
				  "56D4BA","05AD4E","02B644","393738","092E4B","7C96BF","0C9553","0D4A48",
				  "6DA53B","0B554F","056A45","4AADB9","025D4D","092D42","2C95B6","0A954A",
				  "7B4ABD","06CA51","0B5546","555ABB","04DA4E","0A5B43","352BB8","052B4C",
				  "8A953F","0E9552","06AA48","7AD53C","0AB54F","04B645","4A5739","0A574D",
				  "052642","3E9335","0D9549","75AABE","056A51","096D46","54AEBB","04AD4F",
				  "0A4D43","4D26B7","0D254B","8D52BF","0B5452","0B6A47","696D3C","095B50",
				  "049B45","4A4BB9","0A4B4D","AB25C2","06A554","06D449","6ADA3D","0AB651",
				  "093746","5497BB","04974F","064B44","36A537","0EA54A","86B2BF","05AC53",
				  "0AB647","5936BC","092E50","0C9645","4D4AB8","0D4A4C","0DA541","25AAB6",
				  "056A49","7AADBD","025D52","092D47","5C95BA","0A954E","0B4A43","4B5537",
				  "0AD54A","955ABF","04BA53","0A5B48","652BBC","052B50","0A9345","474AB9","06AA4C" };
string sta[20] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
				"1010","1011","1100","1101","1110","1111" };
int run[2500][15];
string get(string s)
{
	string c;
	//F(i,0,5)
	for (int i = 0; i < 5; i++)
	{
		char e = s[i];
		//int a = e >= 'A' && e <= 'F' ? e - 'A' + 10 : e - '0';
		int a;
		if (e >= 'A' && e <= 'F')
		{
			a = e - 'A' + 10;
		}
		else
		{
			a = e - '0';
		}
		c += sta[a];
	}
	return c;
}
string old_m[13] = { "","��","��","��","��","��","��","��","��","��","ʮ","ʮһ","��" };
string old_d[31] = { "","��һ","����","����","����","����","����","����","����","����","��ʮ",
					"ʮһ","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
					"إһ","إ��","إ��","إ��","إ��","إ��","إ��","إ��","إ��","��ʮ" };
string Old[10] = { "��","һ","��","��","��","��","��","��","��","��" };
void IDCARD::luner(int year, int mon, int day)
{
	{

		int y = 1901;//��1901�꿪ʼ
		for (int i = 0; i <= 120; ++i)
		{
			string s = get(Date[i]);//get������16����ת��Ϊ2���Ʒ������
			for (int j = 1; j <= 13; ++j)
			{
				run[y][j] = s[3 + j] == '0' ? 29 : 30;
			}
			int x = (s[3] - '0') * 1 + (s[2] - '0') * 2 + (s[1] - '0') * 4 + (s[0] - '0') * 8;//��0~3λת��Ϊ10����
			run[y][14] = x;
			if (x != 0)
			{
				run[y][13] = s[16] == '0' ? 29 : 30;
			}
			else
				run[y][13] = 0;
			y++;
		}
		int sum = 0;
		for (int i = 1901; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				sum++;
		}
		int allday;
		int yuday;
		int r = 0;
		int lyear, lmon, birthday = 0;
		int d[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		int f[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (!(mon * 100 + day == 229))
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				for (int i = 0; i < (mon - 1); i++)
				{
					birthday = birthday + d[i];
				}
				birthday = birthday + day - 1;
			}
			else
			{
				birthday = 0;
				for (int i = 0; i < (mon - 1); i++)
				{
					birthday = birthday + f[i];
				}
				birthday = birthday + day - 1;
			}
		}
		else
			birthday = 60;
		allday = (year - 1901 - 1) * 365 + 315 + birthday + sum + 1;
		yuday = allday + 1;
		for (int j = 1901; j < 2100; j++)
		{
			for (int k = 1; k < 14; k++)
			{
				yuday = yuday - run[j][k];
				if (yuday <= 30)
				{
					lyear = j; lmon = k + 1;

					break;
				}
			}
			if (yuday <= 30)

				break;

		}
		if ((run[lyear][14] == (lmon - 1)) && (run[lyear][14] != 0))
		{
			r = 1;
		}
		if ((run[lyear][14]) < (lmon) && (run[lyear][14] != 0))
		{
			lmon = lmon - 1;
		}
		if ((yuday == 30) && (run[lyear][lmon] == 29))
		{
			if ((run[lyear][14] == 0))
			{
				if (lmon == 12)
				{
					lyear = lyear + 1;
					lmon = 1; yuday = 1;
				}
				else
					lmon = lmon + 1; yuday = 1;
			}
			if ((run[lyear][14] != 0))
			{
				if (lmon == 13)
				{
					lyear = lyear + 1;
					lmon = 1; yuday = 1;
				}
				else if (run[lyear][14] == (lmon))
				{
					r = 1; lmon += 1; yuday = 1;
				}
				else if (run[lyear][14] >= (1 + lmon))
				{
					lmon = lmon; yuday = 1;
				}
				else if (run[lyear][14] < (1 + lmon))
				{
					lmon = lmon + 1;
					yuday = 1;
				}
			}
		}
		ofstream fout("C:\\BDT\\out.txt", ios::app);
		if (!fout)
		{
			cerr << "�ļ���ʧ�ܣ�\n";
			exit(1);
		}//�ж��ļ����Ƿ�ɹ�
		string Old_year = Old[lyear / 1000] + Old[lyear % 1000 / 100] + Old[lyear % 100 / 10] + Old[lyear % 10 / 1];
		string Old_month = old_m[lmon];
		string Old_day = old_d[yuday];
		if (r == 1)
		{
			fout << "ũ������:" << Old_year << "����" << Old_month << "��" << Old_day << endl;
		}
		else
		{
			fout << "ũ������:" << Old_year << "��" << Old_month << "��" << Old_day << endl;
		}
		fout.close();
	}
}


