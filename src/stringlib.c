#include "../header/stringlib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/* every string must be nulled at first so i made this clear function to prevent crushes */
char *string_initialize(void) {
    return NULL;
}

/* this uses the help of the strdup command so you dont have to resize the string every time */
int string_put_value(char **string,char *content) {
    char *value = strdup(content);
    if(!value) return -1;
    
    if(!*string) {
        *string = value;
        return 0;
    }

    free(*string);
    *string = value;

    return 0;
}

/* this counts the len of the string simply */
int string_len(char **string) {
    int counter = 0;
    while((*string)[counter] != '\0') counter++;
    return counter;
}

/* this joins 2 strings together */
int string_join(char **str1, char *str2) {
    if(!*str1 || !str2) return -1;

    int len1 = string_len(str1);
    int len2 = string_len(&str2);

    char *buffer = malloc(len1+len2+1);
    if(!buffer) return -1;

    strcpy(buffer,*str1);
    strcat(buffer,str2);
    buffer[len1+len2] = '\0';

    if(string_put_value(str1,buffer)==-1) {
        free(buffer);
        return -1;
    }

    free(buffer);
    return 0;
}

/* instead of manually doing the loop when you want your string to be upper use this */
int string_upper(char **string) {
    if(!*string) return -1;

    int counter = 0;
    while((*string)[counter] != '\0') {
        (*string)[counter] = toupper((*string)[counter]);
        counter++;
    }

    return 0;
}

/* instead of manually doing the loop when you want your string to be lower use this */
int string_lower(char **string) {
    if(!*string) return -1;

    int counter = 0;
    while((*string)[counter] != '\0') {
        (*string)[counter] = tolower((*string)[counter]);
        counter++;
    }

    return 0;
}

/* this is safely changes the character at a given index by preventing out of bounds crashes */
int string_change_char(char **string, int index, char ch) {
    if(!*string) return -1;

    if(index >= string_len(string) || index < 0) return -1;
    (*string)[index] = ch;

    return 0;
}

/* this is more clear then strcmp i guess */
int string_equal(char **str1, char *str2) {
    if(!*str1 || str2) return -1;
    if(strcmp(*str1,str2)==0) return 1;
    return 0;
}

/* this function adds a char at the end of the string */
int string_push_char(char **string, char ch) {
    if(!*string) {
        *string = malloc(2);
        if(!*string) return -1;

        (*string)[0] = ch;
        (*string)[1] = '\0';
        return 0;
    }

    int size = strlen(*string);
    char *temp =  realloc(*string,strlen(*string)+2);
    if(!temp) return -1;

    *string = temp;
    (*string)[size] = ch;
    (*string)[strlen(*string)] = '\0';

    return 0;
}

/* always destroy the string at the end. i made the life eisier with the simple functions but you dont get to have everything */
void string_destroy(char **string) {
    if(!*string) return;
    free(*string);
    *string = NULL;
}
