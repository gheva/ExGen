This project produces a few executables, here is some information about what each one of them does.

# cursive_wrksheet
This application produces a worksheet with cursive letters, letter combinations, words and sentences. It requires the use of the font `5th_grade_cursive` which can be found in the `assets` directory.
The words are selected from the file `word_list.txt` in the `assets` directory. The sentences are taken from the `proverbs.txt` file in the same directory. These files are included (`#include "proverbs.txt"`) in the source code, so modifying them should take into account that they should be valid header files. [The cursive worksheet generator](group__cursive__worksheet.html)


# lined_page
This application produces an svg page with lines suitable for cursive writing. [The lined page generator](group__lined__page.html)

# unittests
Because we strive for good test coverage as practice. [The unittests application](group__unittests.html)

# exgen
This is the application that produces exercises. Currently only math exercises are implemented, but more subjects and more levels in math are to be added with time. [ExGen](group__exgen.html)

