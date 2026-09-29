#include<stdio.h>

int main (int argc, char* argv[]) {
        if(argc != 2) {
                fprintf(stderr, "Error! Must entered file's name without space or another separators\n");
                return 1;
        }

        FILE *f = fopen(argv[1], "a");
        if(f == NULL) {
                FILE *f = fopen(argv[1], "r");
                if (f == NULL) {
                        printf("Don't have enough permisions!");
                        return 2;
                }
                else {
                        int seek = fseek(f, 0, SEEK_END);
                        if (seek != 0) {
                                fprintf(stderr, "Fseek error!");
                        }
                }
        }

        long fsize = ftell(f);
        fclose(f);
        printf("Size of file: %ld bytes\n", fsize);

        return 0;
}
