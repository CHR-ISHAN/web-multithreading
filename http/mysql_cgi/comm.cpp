#include "comm.h"

MYSQL* initMysql()
{
	MYSQL* myfd = mysql_init(NULL);
	return myfd;
}

int connectMysql(MYSQL *myfd)
{
	int ret = 0;
	if(mysql_real_connect(myfd, "127.0.0.1",\
				"root", "", "rocket_bj", 3306, NULL, 0)){
		std::cout << "connect success!" <<std::endl;
	}
	else{
		std::cerr << "connect failed" << std::endl;
		ret = -1;
	}
	return -1;
}

int insertMysql(MYSQL *myfd, const std::string &name, const std::string &school, const std::string &hobby)
{
	//INSERT INTO students (name,school,hobby) VALUES ("ZS","QINGHUA","sleep");
	std::string sql = "INSERT INTO students (name,school,hobby) VALUES (\"";
	sql += name;
	sql += "\",\"";
	sql += school;
	sql += "\",\"";
	sql += hobby;
	sql += "\")";
	std::cout << sql << std::endl;
	return mysql_query(myfd, sql.c_str());
}

void selectMysql(MYSQL *myfd)
{
	std::string sql = "SELECT * FROM students";
	mysql_query(myfd, sql.c_str());

	MYSQL_RES *result = mysql_store_result(myfd);
	int rows = mysql_num_rows(result);
	int cols = mysql_num_fields(result);
	std::cout << "<table border=\"1\">"<<std::endl;
	int i = 0;
	for(; i < rows; i++){
		std::cout << "<tr>" << std::endl;
		int j = 0;
		MYSQL_ROW row = mysql_fetch_row(result);
		for(; j < cols; j++){
			std::cout << "<td>" <<row[j] <<"</td>";
		}
		std::cout << "</tr>" << std::endl;
	}
	std::cout << "</table>"<<std::endl;
}

void connectClose(MYSQL *myfd)
{
	mysql_close(myfd);
}



















