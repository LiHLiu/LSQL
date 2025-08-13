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
	//string filepath = "E:\\QQ\\文件\\大学\\大三下\\编译原理\\上机\\实验二\\实验2语法分析\\LLHSQLFile";
	filesystem::path rootpath = "E:\\QQ\\文件\\大学\\大三下\\编译原理\\上机\\实验二\\实验2语法分析\\LLHSQLFile";
	cout << rootpath << '\n';
	return rootpath;
}

void CreateDatabase(const string& name)
{
    filesystem::path rootpath = RootPath();
	fs::path db = rootpath / name;
    if (!fs::exists(db)) {
        // 如果不存在，则创建子目录  
        try {
            fs::create_directories(db);
            std::cout << "Database " << db << " 创建成功！" << std::endl;
        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "创建失败！ " << e.what() << std::endl;
        }
    }
    else {
        // 如果存在，则打开（在这里只是打印消息，因为“打开”一个目录在文件系统中没有特定操作）  
        std::cout << "Database " << db << " 已经存在！" << std::endl;
    }
}
void test()
{	
	const string db = "A";
	CreateDatabase(db);
}
