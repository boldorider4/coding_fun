Code Review Test
================


What am I supposed to do?
-------------------------

Code review is an important part in our effort to control and improve
the quality of our code. Therefore we do code reviews with every piece
of software that is going to be merged.


* Comment any line that you think:
   - has wrongly named, typed, declared code
   - should be improved
   - is dubious
   - malpractice 
   - is plain wrong
   
* Don't write stories; be short and concise using english language.

* Very important: the code is already correctly formatted using clang-format.
  Please do do not comment on formatting. The team has agreed on formatting
  rules and we ensure that they are applied. If you don't like the formatting,
  this can be discussed with the team, but not as part of a code review.

* Look at every file, not only the C++ source code.

Examples:
<pre>
// use unsigned, this value will never be negative
// i.e. unsigned index = 5U;
int index = 5;

// use auto: (auto &item:table) 
for (unsigned int i=0; i < table.size(); ++i)
</pre>


Project Titles
--------------
A small class to handle pairs of keys and values used for managing titles
in a list of songs.

There is a unit-test included.


Project FluxCapacitor
---------------------

The FluxCapacitor Class

Just a fun idea, nothing real...

You can set timepoints and then search the optimum power value for the
flux capacitor feed.

