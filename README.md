[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/xVSnZM4b)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=20192725&assignment_repo_type=AssignmentRepo)
# Week 2 Wed Lab

## Directions

You will be implementing the List ADT as an array-based class. The `List` abstract class is already given to you, along with the header file for the `ArrayList` class, and a skeleton of its implementation file. A driver program is also provided that tests the various operations for the class.

A few notes as your work through this:

- If you need to access the `length` attribute in your `ArrayList` class, you need to write it as `this->length`
- The `buffer` attribute is meant to be a fixed-size, dynamic array
- There are a number of operations that need to consider if it's invalid for it to be called: in those scenarios, make sure to `throw` a `string` exception explaining the error, like this
```C++
throw string("message goes here");
```
- The tests provided are not exhaustive, consider writing your own additional tests

## Sample Run

The following is a sample run of my solution. You can use this as a model to aim for with your program.

```
replace: error, position out of bounds
insert: error, position out of bounds
May Your Heart
Element 2: Heart
May Your Drums Beat
remove: error, position out of bounds
List is empty, no elements to display.
thirdList length: 3
thirdList maximum size: 5
getElement: error, position out of bounds
append: error, list is full
insert: error, list is full
May Your Heart Be A Yellow
myList is empty!
```

