#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// please compile me with gcc this.cpp -lcrypto

char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

void try2Find_p1(){
	char input[]="ojvtpuvg";
	char Answer[9] = {0};
	char md5This[15];
    int add = 0;
	char *md5res;
	for (int i = 0; i < 8; ++i)
	{
		
		while (strncmp(md5res,"00000",5)) {
			sprintf(md5This, "%s%d", input,add);
			md5res = str2md5(md5This, strlen(md5This));
			//printf("%s = %s\n", md5This, md5res);
			add++;
		}
		Answer[i]=md5res[5];
		printf("The next [%d] = %c\n", i,md5res[5]);
		printf("%s = %s\n", md5This, md5res);
		md5res = str2md5("hello", strlen("hello"));
	}
	printf("Answer = %s\n", Answer);
	free(md5res);
}

void try2Find_p2(){
	char input[]="ojvtpuvg";
	char Answer[] = "________";
	char md5This[15];
    int add = 0;
	char *md5res;
	for (int i = 0; i < 8; ++i)
	while(strchr(Answer,'_'))
	{
		
		while (strncmp(md5res,"00000",5)) {
			sprintf(md5This, "%s%d", input,add);
			md5res = str2md5(md5This, strlen(md5This));
			add++;
		}
		if ((md5res[5]-48 < 8) && (Answer[md5res[5]-48]=='_'))
			Answer[md5res[5]-48]=md5res[6];
		printf("Found md5(%s) = %s\n", md5This, md5res);
		printf("Now Answer = \"%s\" \n", Answer);
		md5res = str2md5("hello", strlen("hello"));
	}
	printf("Answer = %s\n", Answer);
	free(md5res);
}

int main(int argc, char **argv) {
	try2Find_p2();
    return 0;
}
