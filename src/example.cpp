#include <stdlib.h>
#include <string>
#include <stdio.h>

// 包含 sql-parser 库
#include "SQLParser.h"

// 包含打印工具
#include "util/sqlhelper.h"

int main() {
    // 定义一个硬编码的 SQL 查询
    std::string query = "INSERT INTO test_table VALUES (1, 2, 'test')";

    // 解析给定的查询
    hsql::SQLParserResult result;
    hsql::SQLParser::parse(query, &result);

    // 检查解析是否成功
    if (result.isValid()) {
        printf("Parsed successfully!\n");
        printf("Number of statements: %lu\n", result.size());

        // 打印每个解析语句的信息
        for (auto i = 0u; i < result.size(); ++i) {
            hsql::printStatementInfo(result.getStatement(i));
        }
        return 0;
    } else {
        fprintf(stderr, "Given string is not a valid SQL query.\n");
        fprintf(stderr, "%s (L%d:%d)\n",
                result.errorMsg(),
                result.errorLine(),
                result.errorColumn());
        return -1;
    }
}
