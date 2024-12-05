#include <stdlib.h>
#include <string>
#include <stdio.h>

// ���� sql-parser ��
#include "SQLParser.h"

// ������ӡ����
#include "util/sqlhelper.h"

int main() {
    // ����һ��Ӳ����� SQL ��ѯ
    std::string query = "INSERT INTO test_table VALUES (1, 2, 'test')";

    // ���������Ĳ�ѯ
    hsql::SQLParserResult result;
    hsql::SQLParser::parse(query, &result);

    // �������Ƿ�ɹ�
    if (result.isValid()) {
        printf("Parsed successfully!\n");
        printf("Number of statements: %lu\n", result.size());

        // ��ӡÿ������������Ϣ
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
