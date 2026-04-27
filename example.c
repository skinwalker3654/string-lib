#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header/stringlib.h"

int main(void) {
    char *string = string_initialize();

    printf("Putting the value hi\n");
    string_put_value(&string,"hi");
    printf("%s\n",string);

    printf("Puting the value hello\n");
    string_put_value(&string,"hello");
    printf("%s\n",string);

    printf("Making the string upper case\n");
    string_upper(&string);
    printf("%s\n",string);

    printf("Making the string lower case\n");
    string_lower(&string);
    printf("%s\n",string);

    printf("Finding the length of the string\n");
    int len = string_len(&string);
    printf("%d\n",len);

    printf("Adding the word hi at the end of the string\n");
    string_join(&string," hi");
    printf("%s\n",string);

    printf("Accessing an invalid index to see if the function checks OUT OF BOUNDS\n");
    if(string_change_char(&string,8,'f')==-1) {
        printf("Out of bounds\n");
    }

    printf("Accesing a normal index to see if it changes the character there\n");
    string_change_char(&string,2,'m');
    printf("%s\n",string);

    
    printf("Creating a new string and comparing it with our string THEY ARE THE SAME\n");
    char *new_string = strdup(string);
    if(string_equal(&string,&new_string)) {
        printf("Strings are equal\n");
    }

    printf("Realishing memory back to the system\n");
    string_destroy(&string);
    free(new_string);

    return 0;
}
