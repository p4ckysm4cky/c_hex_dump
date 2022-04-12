#ifndef CHD_H
#define CHD_H
int handle_read_file(FILE **fp, char *path);
void read_binary(FILE *fp);
void print_byte_ascii(unsigned char line[], int length);

#endif