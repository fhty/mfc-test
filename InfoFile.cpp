#include "stdafx.h"
#include "InfoFile.h"
#include <string.h>

InfoFile::InfoFile()
{
}


InfoFile::~InfoFile()
{
}

void InfoFile::readLogin(CString & name, CString & paw)
{
	ifstream ifs;
	ifs.open(_F_LOGIN);
	char buf[512] = { 0 };
	ifs.getline(buf, sizeof(buf));
	name = CString(buf);//char*תCString��
	ifs.getline(buf, sizeof(buf));
	paw = CString(buf);
	ifs.close();
}

void InfoFile::changePaw(char * name, char * paw)
{
	ofstream ofs;//�ļ����������
	ofs.open(_F_LOGIN);//���ļ���
	ofs << name << endl;
	ofs << paw << endl;
	ofs.close();
}

void InfoFile::readDocline()
{
	ifstream ifs;
	ifs.open(_F_STOCK);
	char buf[512] = { 0 };
	_num = 0;
	_ls.clear();
	ifs.getline(buf, sizeof(buf));
	while (!ifs.eof())
	{
		msg t;
		ifs.getline(buf, sizeof(buf));
		_num++;
		char *s = strtok(buf, "|");
		if (s == nullptr) break;
		t.id = atoi(s);
		s = strtok(NULL, "|");
		t.name = s;
		s = strtok(NULL, "|");
		t.price = atoi(s);
		s = strtok(NULL, "|");
		t.num = atoi(s);

		_ls.emplace_back(t);
	}
	ifs.close();
}

void InfoFile::writeDocline()
{
	ofstream ofs(_F_STOCK);
	if (_ls.size() != 0) {
		ofs << "��Ʒ����|��Ʒ����|��Ʒ�۸�|���" << endl;
		for (auto it = _ls.begin(); it != _ls.end(); ++it) {
			ofs << it->id << "|" << it->name << "|" << it->price << "|" << it->num << endl;
		}
	}
	ofs.close();
}

void InfoFile::addLine(CString name, int num, int price)
{
	msg add;
	add.name = (char *)name.GetBuffer(0);
	add.num += num;
	add.price = price;

	_ls.emplace_back(add);
}
