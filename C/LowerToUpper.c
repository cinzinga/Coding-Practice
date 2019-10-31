#include <stdio.h>
#include <string.h>

//This programs takes 3 strings and makes them all uppercase

char *upper(char *);

int main(int argc, char *argv[]) 
{

	char s[3][256];
	for(int i = 0; i < 3; i++)
	{
		printf("Type string %d: ", i+1);
		scanf("%[^\n]%*c", s[i]);

	}

	for(int i = 0; i < 3; i++)
	{
		printf("input %d: %s\n", i+1, s[i]);
		printf("output %d: %s\n", i+1, upper(s[i]));
	}

	return 0;
}

char *upper(char *input) {
	char *output = input;
	int i = 0;
	while(output[i] != '\0') 
		{
			char c = output[i];
			if(c >= 97 && c <= 122) 
			{
            	c = c - 32;
            	output[i] = c;
        	}
        	i++;
		}
	return output;
}
