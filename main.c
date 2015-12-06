#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>

static const char *HEADER = "iwrupvqb";

void generateHash(int input, unsigned char *output, unsigned char *clearOutput)
{
	unsigned char buffer[128] = { 0 };
	sprintf(buffer, "%s%d", HEADER, input);
	MD5(buffer, strlen(buffer), output);
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		
		sprintf(clearOutput+i*2, "%02X", output[i]);
	}
//	printf("OUTPUT: %s\n", clearOutput);
}

int main(int argc, char **argv)
{
	int input = 0;
	unsigned char outputBuffer[MD5_DIGEST_LENGTH] = { 0 };
	unsigned char clearOutput[MD5_DIGEST_LENGTH*2 + 1] = { 0 };
	for(;;input++)
	{
		generateHash(input, outputBuffer, clearOutput);
		if (strncmp("000000", clearOutput, 6) == 0)
		{
			printf("HIT! %d", input);
			break;
		}
	}
	return 0;
}
