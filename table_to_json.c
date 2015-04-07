#include <cstdio>
#include <cstring>
#include <string>

#define ROW_BUFFER_LEN 200

int main(int argc, char *argv[]) {
    if (!argc) return 0;
    FILE *source_table = fopen(strcat(argv[1], ".tbl"), "r");
    FILE *aim_json = fopen(strcat(strtok(argv[1], "."), ".json"), "w+");
    char row_buffer[ROW_BUFFER_LEN], *key;
    static char BUFFER[BUFSIZ];
    std::string key_container[16] = {"ORDERKEY", "PARTKEY", "SUPPERKEY", "LINENUMBER", "QUANTITY", "EXTENDEDPRICE", "DISCOUNT", "TAX", "RETURNFLAG", "LINESTATUS", "SHIPDATE", "COMMITDATE", "RECEIPTDATE", "SHIPINSTRUCT", "SHIPMODE", "COMMENT"};
    unsigned short i;
    unsigned long long id = 1;
    setbuf(aim_json, BUFFER);
    while (fgets(row_buffer, ROW_BUFFER_LEN, source_table)) {
        i = 0;
        key = strtok(row_buffer, "|");
        fprintf(aim_json, "%lld\t{", id++);
        while (key != NULL && *key != '\n') {
            fprintf(aim_json, "\"%s\": \"%s\"", key_container[i++].c_str(), key);
            key = strtok(NULL, "|");
            (*key == '\n') ? 0: fputs(",", aim_json);
        }
        fputs("}\n", aim_json);
    }
    fclose(source_table);
    fclose(aim_json);
    return 0;
}

