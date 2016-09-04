# SearchWords

The Problem:

Consider that you have been provided with two files.

keywords.txt : new line separated keywords

searchWords.txt : words that need to be checked against the keywords.


What we need to do is search for the words present in searchWords.txt and check if they are from the set of valid keywords (given in keywords.txt)

How this needs to be done:

1. Read the file keywords.txt and create a binary search tree out of it with every node of the tree containing a valid keyword.

2. Spawn 100 threads that will split up the file searchWords.txt into separate sections and take care of the words they are responsible for.

3. Generate the result which is a map of every word in searchWords.txt to a TRUE/FALSE value based on whether it was found or not.


Example:

If the file keywords.txt contained the following words:

Judy

Bill

Mary

Fred

Alice

Dave

Jane

Tom

Joe


and the searchWords.txt contains 1000 words. Each thread would be responsible for processing 10 words each.


If the file searchWords.txt contained the following text:

Alice

Dave

Drake

Mary

Jude

Bill

Francis

Jane

Tom


The expected output would be as following:

Alice : TRUE

Dave : TRUE

Drake : FALSE

Mary : TRUE

Jude : FALSE

Bill : TRUE

Francis : FALSE

Jane : TRUE

Tom : TRUE

