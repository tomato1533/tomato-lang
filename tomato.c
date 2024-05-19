#include <stdio.h>
#include <stdlib.h>

typedef struct token {
    char for_token;
    char if_token;
    char output_token;
    char output_data;
} TOKEN;

void test(int value) {
    printf("test%d", value);
}

void process(char content[]) {
    TOKEN T;
    char init = content[0];
    int i = 1;
    while (init == "{" && content[i] != "}") {
        if (content[i] == "write" && content[i+1] == ":") {
            i += 2;
            do {
                T.output_data += content[i];
                i ++;
                printf("%s", T.output_data);
            } while (content[i] != ";");
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line[24];
    int num = argv[1];
    char *content[num];
    int i = 0;
    int number = 2;
    printf("%d,%s", argv[1], argv[number]);
    file = fopen(argv[number], "r");
    if (file == NULL) {
        printf("file not open");
        return 1;
    } else {
        while (fgets(line, sizeof(line), file) != NULL) {
            content[i] = line;
            i ++;
            test(1);
        }
    }
    process(content);
    fclose(file);
    return 0;
}