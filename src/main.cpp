#include <stdlib.h>
#include <string>
#include <stdio.h>

// 包含 sql-parser 库
#include "SQLParser.h"

// 包含打印工具
#include <iostream>

#include "util/sqlhelper.h"

int main() {
    // 定义一个硬编码的 SQL 查询
    std::string select_query = "select * from BASIC_SHIP_INFORMATION_DB.SHIP_DATA_INFO where ship_type = '油船'";
    std::string update_query =
            "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No2' where SHIP_NAME = 'test No1'";
    std::string delete_query = "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No2'";
    //todo:insert 语句必须加values，否则无法解析
    std::string insert_query = "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) values (7082002, 7082006, 'test No1')";

    // 解析给定的查询
    hsql::SQLParserResult select_result;
    hsql::SQLParserResult update_result;
    hsql::SQLParserResult delete_result;
    hsql::SQLParserResult insert_result;

    hsql::SQLParser::parse(select_query, &select_result);
    hsql::SQLParser::parse(update_query, &update_result);
    hsql::SQLParser::parse(delete_query, &delete_result);
    hsql::SQLParser::parse(insert_query, &insert_result);
    //索引0：表名

    hsql::SelectStatement* select_sel = (hsql::SelectStatement *) select_result.getStatement(0);
    hsql::UpdateStatement* update_sel = (hsql::UpdateStatement *) update_result.getStatement(0);
    hsql::DeleteStatement* delete_sel = (hsql::DeleteStatement *) delete_result.getStatement(0);
    hsql::InsertStatement *insert_sel = (hsql::InsertStatement *) insert_result.getStatement(0);

    std::cout << "==========select==========" << std::endl;;
    std::cout << "DB name is: " << select_sel->fromTable->schema << std::endl;
    std::cout << "Table name is: " << select_sel->fromTable->name << std::endl;
    std::cout << "==========update==========" << std::endl;
    std::cout << "DB Name is: " << update_sel->table->schema << std::endl;
    std::cout << "Table Name is: " << update_sel->table->name << std::endl;
    std::cout << "==========delete==========" << std::endl;
    std::cout << "DBname Name is: " << delete_sel->schema << std::endl;
    std::cout << "Table name Name is: " << delete_sel->tableName << std::endl;
    std::cout << "==========insert==========" << std::endl;
    std::cout << "DB Name is: " << insert_sel->schema<< std::endl;
    std::cout << "Table Name is: " << insert_sel->tableName << std::endl;

    return 0;
}
