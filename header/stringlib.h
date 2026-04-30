#ifndef STRING_LIB_H
#define STRING_LIB_H

char *string_initialize(void);
int string_put_value(char **string,char *content);
int string_join(char **str1,char *str2);
int string_len(char **string);
int string_upper(char **string);
int string_lower(char **string);
int string_change_char(char **string,int index,char ch);
int string_equal(char **str1,char *str2);
int string_push_char(char **string, char ch);
void string_destroy(char **string);

#endif
