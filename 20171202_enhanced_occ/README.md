Excuse my role playing.

The client is very satisfied with the occurrence counter you've developed on Exercise 1, although
he feels like it takes too long to search for different words on the same file, as such, he 
requested that an interactive version of the occurrence counter be built. Additionally, he requested
that it should be possible to search for the same word on multiple files at the same time.

The program will be named occi and it will not accept any command-line arguments.

When a user runs the program he enters in an interactive menu, such as the one below.
The help page is shown when the program runs for the first time as a reminder.
After this, the program must enter a loop waiting for input from the user.

$ ./occi
welcome to the interactive occurrence counter
f: open/read from a new file
s: search for a word
h: show this help
q: quit
option> 

The user may specify an option and some options have arguments.

Option f:
  This option opens and reads from a new file.
  Internally, the program must store the file so that it can perform a search on it.
  
  Example usage:
  option> f /path/to/file
  OK
  
  option> f /path/to/invalid/file
  ERROR
  
  
Option s:
  This option searches for a word in all the files that are open.
  The program must present a report with the combination of file-word counts.
  
  
  Example usage:
  option> s Jack
  In /path/to/file: 5 occurrences
  In /path/to/other/file: 0 occurrences
  Search took 5s
  
  option> s i CaSeInSeNSITiVe
  No files open
  

Option h:
  Show program help.
  
Option q:
  Quit program, releasing all the resources.
  

This exercise should be developed in two iterations.

Iteration 1
========

Every time the user uses the f option, keep file name in memory only.
When the user performs a search, open each file sequentially, search for the word and print result.

Iteration 2
========

Use a cache to speed up the searches, for example, using the hash-table developed on Exercise 2.
Every time the user uses the f option, open the file, parse each word and do a pre-count of 
occurrences, closing the file after that. Note that if the user uses the f option more than once
on the same file, the cache should be updated.
When the user performs a search, search this cache instead of each file individually.

Compare to iteration 1 in terms of memory footprint and speed.
You can use profiling tools for this.
Also, perform a simple analysis of the distribution of keys on the hash-table and, if necessary,
tune the hash-table size and/or function.

Good luck!

Best regards,
