#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>

MYSQL* initMysql();
int connectMysql(MYSQL *myfd);
int insertMysql(MYSQL *myfd, const std::string &name, const std::string &school, const std::string &hobby);
void selectMysql(MYSQL *myfd);
////void deleteMysql();
////void modifyMysql();
void connectClose(MYSQL *myfd);
