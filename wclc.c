#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wclc(int flag, char* file) {
	int *alls;
        int n = 20;
        alls = (int *)malloc(n * sizeof(int));

	if(alls == NULL) {
		fprintf(stderr,"Not enought memory!");
		return 1;
	}

        if (flag == 0) {
                FILE *f = fopen(file, "r");
                if(f == NULL){
                        fprintf(stderr, "File doesn't found!\n");
                        return 1;
                }
                int i = 0;

                int g = fgetc(f);

                while(g != EOF) {
                        fseek(f, i, SEEK_SET);
                        alls[i] = fgetc(f);
                        g = fgetc(f);
                        i++;
                        if(i == n) {
                                n++;
				int *erralls = alls;
                                alls = realloc(alls, (n)*sizeof(int));
				if(alls == NULL) {
					alls = erralls;
					free(erralls);
					fprintf(stderr,"Not enought memory!\n");
					return 1;
				}
                        }
                }
                fclose(f);
                int c = -1;

                int probel = ' ';
                int tab = '\t';
                int str = '\n';

                for(int z = 0; z < n + 1; z++) {
                        if(alls[z] == probel && alls[z+1] != probel && alls[z+1] != tab && alls[z+1] != str){
                                c++;
                        }
                        else if(alls[z] == tab && alls[z+1] != probel && alls[z+1] != tab && alls[z+1] != str){
                                c++;
                        }
                        else if(alls[z] == str && alls[z+1] != probel && alls[z+1] != tab && alls[z+1] != str){
                                c++;
                        }
                }
                free(alls);
                if(c != 0) {
                                c++;
                }
                printf("Quantity of words: %d\n", c);
        }
        else if (flag == 1) {
                FILE *f = fopen(file, "r");
                if(f == NULL){
                        fprintf(stderr, "File doesn't found!\n");
                        return 1;
                }
                int i = 0;

                int g = fgetc(f);

                while(g != EOF) {
                        fseek(f, i, SEEK_SET);
                        alls[i] = fgetc(f);
                        g = fgetc(f);
                        i++;
                        if(i == n) {
                                n++;
				int *erralls = alls;
                                alls = realloc(alls, (n)*sizeof(int));
                        	if(alls == NULL) {
					alls = erralls;
					free(erralls);
					fprintf(stderr,"Not enought memory!\n");
					return 1;
				}
			}
                }
                fclose(f);
                int c = -1;

                int str = '\n';

                for(int z = 0; z < n + 1; z++) {
                        if(alls[z] == str){
                                c++;
                        }
                }
                free(alls);
                if(c != 0) {
                                c++;
                }
                printf("Quantity of lines: %d\n", c);

        }
	return 0;
}

int main (int argc, char *argv[]) {
	char* file = argv[1];
	
	char* name = argv[0];
	char *p = name;

	while(*p) {
		if(*p == '/') name = p + 1;
		p++;
	}

	int flag = 2;
	if(strcmp(name,"wc") == 0) flag = 0;
	else if(strcmp(name,"lc") == 0) flag = 1;
	else fprintf(stderr,"Invalid programm's name! Valid names: 'wc' - to count words, 'lc' - to count lines.\n");

	wclc(flag, file);
	return 0;
}
