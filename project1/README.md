

### Usage

To compile the file:

~~~

> make

~~~

Or:


~~~

> g++ main.cpp bst.cpp hashTable.cpp -o main

~~~

To test the program:

~~~

> ./main

~~~

Press 1 for search; 2 for insert; 3 for delete; 4 for sort; 5 for range sort 

### FILE CONFIGURATION:

main.cpp: main file
bst.h and hashTable.h: head files
bst.cpp: implementation of BST
hashTable.cpp: implementation of HashTable
Makefile: the Makefile
stopWords.txt: the list of stop words we are using in this project
words.txt: a list of words we use for testing the runtime of insertion, search, and deletion
sort.txt: words sorted by BST and hashTable
report.pdf: report of runtime analysis

runtime.cpp: program to test runtime of insertion, search, and deletion, to complile runtime.cpp, please type the following command into command line
~~~
> g++ runtime.cpp bst.cpp hashTable.cpp -o runtime
~~~



### Citation and Reference:

Kavita Ganesan and ChengXiang Zhai, "Opinion-Based Entity Ranking", Information Retrieval, 2011. 

~~~
@article {opinrank, 
title = {Opinion-Based Entity Ranking}, 
journal = {Information Retrieval}, 
year = {2011}, 
keywords = {adhoc multifaceted search, entity oriented search, entity ranking, entity retrieval, product search}, 
doi = {10.1007/s10791-011-9174-8}, 
attachments = {[Web Link]}, 
author = {Kavita Ganesan and ChengXiang Zhai} 
}
~~~