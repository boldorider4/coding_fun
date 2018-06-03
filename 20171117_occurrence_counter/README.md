Hi Jack,

Here's the first C++ exercise.
Please implement it on your own pace but focusing on code quality.
Further exercises will build upon this one, so it's imperative that you write portable code.

In order to deliver an iteration of this exercise, please reply to this e-mail with a .zip or a .tar.gz package.

I want to implement a program called occ (occurrence counter).

This program receives two command-line arguments:
-w, specifying a word to search for
-f, specifying the path to a file
-h, if this switch appears, ignore the remaining ones and just print usage
-i, if this switch appears, do case-insensitive comparison when searching for the word

The program must do the following:
If no command-line arguments are provided, print the usage of the program and return EXIT_SUCCESS
Validate the command-line arguments and if there's an error, return EXIT_FAILURE with a message on std::cerr
Open the file for reading, parse the text into words and count how many times the word we specified with -w appears in that file, outputting that number on std::cout and returning EXIT_SUCCESS

So here's an example, image we have the following file:

my_text.txt
-----------
This is a nice text file that I just made up now. But what should I write? I don't know.


If I run the following commands, I expect the output below.

$ ./occ
usage: occ [option value?]*
  Options:
    w: specifies the word to search for
    f: path to a file
    h: print this usage text
    i: perform case-insensitive comparison

$ ./occ -f my_text.txt -w "i" -i
3

$ ./occ -w "This" -f my_text.txt
1

If you have any questions, please let me know.
Fair warning: things will only get more complicated from now on 😝

Regards,
