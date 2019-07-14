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
	int id;//��Ʒ���š�
	string name;//��Ʒ����
	int price;//��Ʒ�۸�
	int num;//��Ʒ������
};

class InfoFile
{
public:
	InfoFile();
	~InfoFile();
	void readLogin(CString &name, CString &paw);//��ȡ��¼��Ϣ��
	void changePaw(char *name, char *paw);//�޸����롣
	void readDocline();//��ȡ��Ʒ���ݡ�
	void writeDocline();//д����Ʒ���ݡ�
	void addLine(CString name, int num, int price);//������Ʒ��

	list<msg> _ls;
	int _num;
};

