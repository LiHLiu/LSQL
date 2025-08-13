#include<iostream>
#include<string>
#include <filesystem>
#include <direct.h>
#include "LLHSQL.h"
using namespace std;
namespace fs = filesystem;
class DB {
public:
	string name;
	string path;
};

filesystem::path RootPath()
{
	//string filepath = "E:\\QQ\\�ļ�\\��ѧ\\������\\����ԭ��\\�ϻ�\\ʵ���\\ʵ��2�﷨����\\LLHSQLFile";
	filesystem::path rootpath = "E:\\QQ\\�ļ�\\��ѧ\\������\\����ԭ��\\�ϻ�\\ʵ���\\ʵ��2�﷨����\\LLHSQLFile";
	cout << rootpath << '\n';
	return rootpath;
}

void CreateDatabase(const string& name)
{
    filesystem::path rootpath = RootPath();
	fs::path db = rootpath / name;
    if (!fs::exists(db)) {
        // ��������ڣ��򴴽���Ŀ¼  
        try {
            fs::create_directories(db);
            std::cout << "Database " << db << " �����ɹ���" << std::endl;
        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "����ʧ�ܣ� " << e.what() << std::endl;
        }
    }
    else {
        // ������ڣ���򿪣�������ֻ�Ǵ�ӡ��Ϣ����Ϊ���򿪡�һ��Ŀ¼���ļ�ϵͳ��û���ض�������  
        std::cout << "Database " << db << " �Ѿ����ڣ�" << std::endl;
    }
}
void test()
{	
	const string db = "A";
	CreateDatabase(db);
}
