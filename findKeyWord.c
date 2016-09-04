#include <pthread.h>
#include <string.h>
#include "bst.h"

#define NUM_THREADS 100
#define MAX_SEARCHWORDS 10000

char searchWords[MAX_SEARCHWORDS][KEYWORD_SIZE];
bool result[MAX_SEARCHWORDS];
int searchWordCount = 0;

FILE * keywordsFile = NULL;
FILE * searchWordsFile = NULL;

pthread_mutex_t search_mutex;

bool readKeyWordsNBuildBST()
{
	char word[KEYWORD_SIZE];

    while (fgets(word, sizeof(word), keywordsFile)) 
	{
		if(!insert(word))
			return false;
    }

	return true;
}

void * readNSearch(void *arg)
{
			pthread_mutex_lock(&search_mutex);
    int steps = searchWordCount / NUM_THREADS ;
	int offset = *(int *)arg;
	int loc = 0;
	int loopCtr = 0;

	
	for(loopCtr = 0; loopCtr <= steps; loopCtr++)
	{
		loc = NUM_THREADS * loopCtr + offset;
		if(loc < searchWordCount)
		{
			if(find(searchWords[loc]))
			{
				result[loc] = true;
			}
			else
			{
				result[loc] = false;
			}
		}
	}

			pthread_mutex_unlock(&search_mutex);
	return NULL;
}

bool searchForWords()
{
	pthread_t threads[NUM_THREADS];
	int count = 0;

	char word[KEYWORD_SIZE];
	while (fgets(word, sizeof(word), searchWordsFile))
    {
		strcpy(searchWords[searchWordCount], word);
		searchWordCount++;
	}

	for(count = 0; count < NUM_THREADS; count++)
	{
		pthread_create( &threads[count], NULL, readNSearch, (void*) &count);
		
	}	

	for(count = 0; count < NUM_THREADS; count++)
    {
		pthread_join(threads[count], NULL);
	}

	for (count = 0; count < searchWordCount; count++)
	{
		printf("%s : %d\n", searchWords[count], result[count]);
	}

	return true;
}


int main()
{
	keywordsFile = fopen("keywords.txt", "r"); /* assuming the file is kept in the current directory */
	if(NULL == keywordsFile)
	{
		printf("Unable to open the keyword file ..... exiting\n");
		return -1;
	}

	searchWordsFile = fopen("searchWords.txt", "r"); /* assuming the file is kept in the current directory */
	if(NULL == searchWordsFile)
	{
		printf("Unable to open the searchWords file ..... exiting\n");
		fclose(keywordsFile);
		return -1;
	}

	if(!readKeyWordsNBuildBST())
	{
		fclose(keywordsFile);
    	fclose(searchWordsFile);
		return -1;
	}

	if(!searchForWords())
	{
        fclose(keywordsFile);
        fclose(searchWordsFile);
        return -1;
    }


	fclose(keywordsFile);
	fclose(searchWordsFile);

	return 0;
}




