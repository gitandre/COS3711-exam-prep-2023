# COS3711 - Assignment 2 Question 1

Write a console application that can be run from the command line using the following forms:

1. count // run without any parameters
2. count file1.txt // pass one file name
3. count file1.txt fileTwo.txt // pass more than one file name
4. count –a –b file1.txt fileTwo.txt // pass flags to change behaviour
5. count –ab –c file1.txt // pass flags in an alternative way

If no arguments are provided, then print a message describing what arguments should be
included.

The application should, using regular expressions, count the number of occurrences of each of
the following in the text files given.

1. If the –a flag is set, count the number of words longer than 4 characters that start with a capital
letter. There may be further capital letters in the word.
2. If the –b flag is set, count the number of words that are hyphenated. This hyphen should not
be at the start or end of a word.
3. If the –c flag is set, count the number of words that start and end on the same character.
4. If the –d flag is set, count the number of words that do not start with a vowel. Note that these
words can start with any character, and do not just have to start with alphabetic characters.
5. If no flags are provided, it is assumed that all counts should be performed