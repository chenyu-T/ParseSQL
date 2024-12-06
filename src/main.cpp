#include <stdlib.h>
#include <string>
#include <stdio.h>

// ���� sql-parser ��
#include "SQLParser.h"

// ������ӡ����
#include <iostream>

#include "util/sqlhelper.h"

int main() {
    // ����һ��Ӳ����� SQL ��ѯ
    std::string select_query = "SELECT a, SUM(b) FROM db.t2 GROUP BY a HAVING SUM(b) > 100";
    // std::string select_query = "SELECT * FROM a.x join a.y on a=b;";
    std::string update_query = "update BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO set SHIP_NAME = 'test No2' where SHIP_NAME = 'test No1'";
    std::string delete_query = "delete from BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO where SHIP_NAME = 'test No2'";
    //todo:insert �������values�������޷�����
    std::string insert_query = "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) values (7082002, 7082006, 'test No1')";

    // ���������Ĳ�ѯ
    hsql::SQLParserResult select_result;
    // hsql::SQLParserResult update_result;
    // hsql::SQLParserResult delete_result;
    // hsql::SQLParserResult insert_result;

    hsql::SQLParser::parse(select_query, &select_result);
    // hsql::SQLParser::parse(update_query, &update_result);
    // hsql::SQLParser::parse(delete_query, &delete_result);
    // hsql::SQLParser::parse(insert_query, &insert_result);
    //����0������

    hsql::SelectStatement* select_sel = (hsql::SelectStatement *) select_result.getStatement(0);
    // hsql::UpdateStatement* update_sel = (hsql::UpdateStatement *) update_result.getStatement(0);
    // hsql::DeleteStatement* delete_sel = (hsql::DeleteStatement *) delete_result.getStatement(0);
    // hsql::InsertStatement *insert_sel = (hsql::InsertStatement *) insert_result.getStatement(0);

    std::cout << "==========select==========" << std::endl;
    auto result = select_sel->fromTable->join;
    if(result) {
        std::cout << "Left DB name is: " << result->left->schema << std::endl;
        std::cout << "Table name is: " << result->left->name << std::endl;
        std::cout << "Right DB name is: " << result->right->schema << std::endl;
        std::cout << "Table name is: " << result->right->name << std::endl;
    }else {
        std::cout << "DB name is: " << select_sel->fromTable->schema << std::endl;
    }
    // std::cout << "Table name1 is: " << select_sel->fromTable->join->right->schema << std::endl;
    // std::cout << "==========update==========" << std::endl;
    // std::cout << "DB Name is: " << update_sel->table->schema << std::endl;
    // std::cout << "Table Name is: " << update_sel->table->name << std::endl;
    // std::cout << "==========delete==========" << std::endl;
    // std::cout << "DBname Name is: " << delete_sel->schema << std::endl;
    // std::cout << "Table name Name is: " << delete_sel->tableName << std::endl;
    // std::cout << "==========insert==========" << std::endl;
    // std::cout << "DB Name is: " << insert_sel->schema<< std::endl;
    // std::cout << "Table Name is: " << insert_sel->tableName << std::endl;

    return 0;
}
