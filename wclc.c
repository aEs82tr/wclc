#include<stdio.h>
#include<string.h>
void registry(char s[])
{
        for(int i = 0; i < 5; i++)
        {
                if(s[i] >= 'A' && s[i] <= 'Z')
                        s[i] = (s[i] - 'A') + 'a';
        }
}

int main (int argc, char *argv[]) {

	registry(argv[0]);

	char v1[5] = "./wc";
	char v2[5] = "./lc";

	int dwc = strcmp(argv[0], v1);
	int dlc = strcmp(argv[0], v2);

	if (dwc == 0) {
		FILE *f = fopen(argv[1], "r");
		int g = fgetc(f);
		int i = 0;
		int alls[1000];

		while(g != EOF) {
			fseek(f, i, SEEK_SET);
			g = fgetc(f);
			alls[i] = g;
			i++;
		}
		fclose(f);
		int c = 0;
		for(int n; n < i - 1; n++) {
			if(alls[n] == ' ' || alls[n] == '	' || alls[n] == '\n') {
				c++;
			}
		}
		printf("Quantity of words is %d \n", c);
	}
	else if (dlc == 0) {
//		count lines;
	}
	else {
		fprintf(stderr, "Compiling file must to have name 'wc' or 'lc'!\n");
	}
	return 0;
}
