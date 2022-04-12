#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "chd.h"
#define LINE_SIZE 16

int handle_read_file(FILE **fp, char *path) 
{
    *fp = fopen(path, "rb");
    if (!fp) {
        return -1;
    } 
    else {
        return 0;
    }
}

void print_byte_ascii(unsigned char line[], int length)
{
    for (int i = 0; i < length; i++) {
        unsigned char temp_char = line[i];
        if (isprint(temp_char)){
            printf("%c", line[i]);
        }
        else {
            putchar('.');
        }
    }
}

void read_binary(FILE *fp)
{
    unsigned char buffer_byte;
    int i = 0;
    unsigned char line[LINE_SIZE];
    while (fread(&buffer_byte, sizeof(char), 1, fp) > 0) {
        line[i] = buffer_byte;
        printf("%02X ", buffer_byte);
        if (i == LINE_SIZE - 1) {
            printf(" | ");
            print_byte_ascii(line, i+1);
            putchar('\n');
            i = 0;
        } 
        else {
            ++i;
        }
    }
    // This part is just to print the remaining line in ascii
    while (i < LINE_SIZE) {
        printf("   ");
        ++i;
    }
    printf(" | ");
    print_byte_ascii(line, i+1);
}


int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc == 2) {
        char* path = argv[1];
        if (handle_read_file(&fp, path)) {
            printf("Cannot find file %s\n", path);
            exit(2);
        }
        read_binary(fp);
    }
    else {
        printf("Usage: \n");
        printf("chd [file] \n");
        exit(1);
    }
    return 0;
}