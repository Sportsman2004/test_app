#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


void print() {
    setlocale(LC_ALL,"Rus");
    printf("Use:\n");
    printf("  test_app.exe [-g] <File_Name.csv>\n");
    printf("  test_app.exe -?\n");
    printf("\nPparameters:\n");
    printf("  -g          Enable option g\n");
    printf("  <File.csv>  File name with permission .csv\n");
    printf("  -?          Show help\n");
}


int has_csv_extension(const char *filename) {
    const char *a = strrchr(filename, '.');
    if (!a || a == filename) return 0;
    return strcmp(a, ".csv") == 0;
}

int main(int argc, char *argv[]) {
    int g_option = 0;
    char *filename = NULL;

    if (argc == 1) {
        print();
        return 0;
    }

    if (argc == 2) {
        if (strcmp(argv[1], "-?") == 0) {
            print();
            return 0;
        }
        if (argv[1][0] == '-') {
            printf("Invalid parameter '%s'\n\n", argv[1]);
            print();
            return 1;
        }
        if (!has_csv_extension(argv[1])) {
            printf("The file name must have the extension .csv\n\n");
            print();
            return 1;
        }
        filename = argv[1];
        printf("Option not specified\n");
        printf("File name: %s\n", filename);
        return 0;
    }

    if (argc == 3) {
        if (strcmp(argv[1], "-g") == 0) {
            if (!has_csv_extension(argv[2])) {
                printf("The file name must have the extension .csv\n\n");
                print();
                return 1;
            }
            g_option = 1;
            filename = argv[2];
            printf("Option specified\n");
            printf("File name: %s\n", filename);
            return 0;
        } else {
            if (strcmp(argv[1], "-?") == 0) {
                print();
                return 0;
            }
            printf("Error, invalid parameter '%s'\n\n", argv[1]);
            print();
            return 1;
        }
    }
    printf("Error, incorrect number of parameters\n\n");
    print();
    return 1;

}

