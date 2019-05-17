# Exercise generator
This program is designed to generate exercises to different types of displays. We currently only support a text display and an svg display, which uses an in house written svg library to display exercises.

## Building
Our build system uses GNU make. We tested this on mac, linux and cygwin. best of luck ;-). It should be as simple as running `make`.

## documentation
The best way to understand this is to clone the code and run 
\code
make docs
\endcode
and read the generated documentation.

## Applications
While our intention was to generate both cursive writing exercises and math exercises, however we were not able to achieve this yet. However, additional applications are provided to generate cursive writing worksheets. (see also [Applications](md_src_apps_apps.html))

## The exercise generator library
This library (it is statically linked, feel free to change if this ever makes sense) can create exercises in different topics and levels. This can be extended easily to add topics and levels (see the documentation for the [xgen](group__education.html)
