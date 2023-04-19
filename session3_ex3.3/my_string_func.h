/*Using #pragma allows the compiler to use its internal caches which is of course faster
 than using the pre-processor which will always include the contents of your file just
  to later stumble on your guards and dismiss the whole thing.
  
#pragma once is a non-standard but widely supported preprocessor directive designed to cause the current source file to
 be included only once in a single compilation. */

#pragma once
/* read_line: read a line into s, return length */
int read_line(char s[]);
/* my_to_upper: Makes an upper-case converted version of str_in in str_out */
void my_to_upper(char* str_in, char* str_out);
int my_length(char* text);

//used to find the length of character string
int my_strlen(const char* str);
//used to compare two character strings
int my_strcmp(const char* str1, const char* str2);
//used to copy a character variable
char* my_strcpy(char* dest, const char* src);
//used to duplicate the string
char* my_strdup(const char* str);
