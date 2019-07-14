#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"
#define _F_STOCK "./stock.txt"
using namespace std;

struct msg
{
	int id;//商品代号。
	string name;//商品名。
	int price;//商品价格。
	int num;//商品数量。
};

class InfoFile
{
public:
	InfoFile();
	~InfoFile();
	void readLogin(CString &name, CString &paw);//读取登录信息。
	void changePaw(char *name, char *paw);//修改密码。
	void readDocline();//读取商品数据。
	void writeDocline();//写入商品数据。
	void addLine(CString name, int num, int price);//新增商品。

	list<msg> _ls;
	int _num;
};

