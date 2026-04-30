# StringLib (C)

A lightweight string utility library for the C programming language that provides safer and more convenient string handling compared to raw `char*`.

---

## Features

* Dynamic string allocation
* Safe string assignment
* String concatenation
* Length calculation
* Character manipulation
* Case conversion (upper/lower)
* String comparison
* Memory-safe cleanup

---

## compile test

```bash
make test
```

## to install it on your system run
```c
make install
```

and after that you can use the library on your projects by simple putting on your source code this at the top
```c
#include <stringlib.h>
```

you should compile your project with 
```c
gcc project.c -o project -lstringlib
```
---

## remove the library
```bash
make remove
```
---

# USAGE OF LIBRARY

```c
//intiliaze the string
char *str = string_initialize();

//if you want to put a value safely just say
string_put_value(&str, "hello");

//to find the length of a string
int len = string_len(&str);

//this function adds 2 strings together
string_join(&str, " world");

//you can also pass an existing string 
strign_join(&str, str2);

//this functions make the string either full upper case or full lower case
string_upper(&str);
string_lower(&str);

//and this has bounds checks so you put characters on indexes safely
string_change_char(&str, 0, 'H');

//here we have 2 string and we check if they are equal
char *a = string_initialize();
char *b = string_initialize();

string_put_value(&a, "test");
string_put_value(&b, "test");

if(string_equal(&a, b)) {
    //do some code if they are equal
}

if(string_equal(&a, "some text")) {
    //do some code if they are equal
}

//this function adds a character at the end of the string so you dont have to realloc manually
string_push_char(&a, 'H');

//always put that at the end otherwise you will have memory leaks
string_destroy(&str);
```

---

## Notes

* All functions expect a pointer to the string (`char**`) when modification or reallocation is required.
* Strings must be initialized using `string_initialize()` before use.
* Always call `string_destroy()` to prevent memory leaks.
* The library internally uses dynamic memory allocation (`malloc`, `strdup`, `free`).

---

## Limitations

* No bounds-safe APIs for all operations
* No support for UTF-8 / multibyte characters
* No internal capacity tracking (unlike `std::string`)
* Some functions rely on standard C string behavior (`'\0'` termination)

---

## Design Philosophy

This library aims to:

* Simplify string handling in C
* Reduce common memory errors
* Provide a minimal abstraction layer over `char*`

---

## Program Example

```c
#include <stdio.h>
#include "stringlib.h"

int main() {
    char *str = string_initialize();

    string_put_value(&str, "hello");
    string_join(&str, " world");
    string_upper(&str);

    printf("%s\n", str); 

    string_destroy(&str);
    return 0;
}
```
# string-lib
