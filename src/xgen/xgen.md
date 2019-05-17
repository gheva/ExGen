## xgen - The exercise generator library
This module consists of 4 classes, which can be used to construct an exercise generator library and application.

## Terms
* `Topic` - A `Topic` is a container of different levels of exercises. Conceptually one can think of an exercise generator which will have several topics from which to generate exercises, each topic is expected to produce exercises indifferent levels. (xgen::Topic)
* `Level` - A `Level` is responsible to generate exercises suitable for that given level. (xgen::Level)
* `Exercise` - An `Exercise` is a container of data that can be used to display an exercise. (xgen::Exercise)
* `Display` - A `Display` is responsible of showing a single `Exercise`. (xgen::Display)

## Creating an exercise library
To create an exercise library, one will have to implement at least one `Topic`. Since the topic is a simple container, one could get away with just instantiating a `Topic` with the desired name for that `Topic` instance to be passed to the constructor, then add `Level`s to this `Topic` instance, though it would be easier to subclass the `Topic` class and have this subclass add `Level`s in the constructor.

### Creating a `Level`
A level implementation needs to implement the xgen::Level::generate method, to return a type of `Exercise` defined by this new exercise library.

### The `Exercise` implementation
The `Exercise` subclass suitable for your specific library is allowed to contain any type of data you see fit, however, you need to ensure that the clients of your library can display this `Exercise`.

## Displaying `Exercise`s
There is some coupling between the `Display` and the `Exercise` as the `Display` needs to know what to do with the information stored in the `Exercise`.
