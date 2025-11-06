#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
/*
    * Trying to remake the parser since the last one pretty much failed
    * similar motive, just tokenise a char array into an char pointer array
	* 
	* DAMN AN ACTUALLY FUNCTIONAL TOKENIZER THAT WAS RELATIVELY UNDERSTANDABLE?????
	* HELL YEAH, okay its probably confusing af and im too lazy to document it
	* but what it does is basically
	* iterate a sentence, when the last character is a space, and the current one isnt,
	* then just add a new index to our char array
	* and add our word to the array
	* keep doing this untill a NULL terminator
	* then NULL terminate our new array or pointers
	* thats about it, the iterating function was just for testing the functionality
	

*/


char *getWord(const char *string)
{
	//takes a sentence not starting with a space
    //Returns the first word
    size_t size = 16;
	size_t len = 0;
	char *word = malloc(sizeof(char) * size);
	if (word == NULL)
	{
		fprintf(stderr,"Mallocation failure");
		return NULL;
	}
	
	for (int i = 0;!isspace((unsigned char)string[i]) && ((string[i] != 0));i++)
	{
		word[len] = string[i];
		len++;

		if (len >= size)
		{
			size *= 2;
			char *temp = realloc(word,sizeof(char) * size);
			if (temp == NULL)
			{
				free(word);
				fprintf(stderr,"Mallocation failure");
				return NULL;
			}
			word = temp;
		}
	}
	word[len] = 0;
	return word;
    
}
char **Tokenize(const char *string)
{
	int tokenCount = 0;
	char **tokens = NULL;
	char last = ' ';

	for (int i = 0;string[i] != 0;i++)
	{
		if ((last == ' ') && (string[i] != ' '))
		{
			tokenCount++;
			char **temp = realloc(tokens,sizeof(char *) * tokenCount);
			if (temp == NULL)
			{
				fprintf(stderr,"Mallocation failure");
				return NULL;
			}	
			tokens = temp;		
			tokens[tokenCount - 1] = getWord(string + i);
		}
		last = string[i];
	}
	char **temp = realloc(tokens,sizeof(char *) * tokenCount);
	if (temp == NULL)
	{
		fprintf(stderr,"Mallocation failure");
		return NULL;
	}
	tokens = temp;
	tokens[tokenCount] = NULL;

	return tokens;

}

void IterateCharr(char **array)
{
	for (int i = 0; array[i] != NULL;i++)
	{
		printf("%d. %s\n",i,array[i]);
	}
	return;
}

int main(void)
{
	char **tokens = Tokenize("Hello i am a friendly string");
	IterateCharr(tokens);	
}