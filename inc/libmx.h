#pragma once

#include <wchar.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

// Utils pack
char *mx_itoa(int number);
char *mx_nbr_to_hex(unsigned long nbr);

int mx_sqrt(int x);
int mx_bubble_sort(char **arr, int size);
double mx_pow(double n, unsigned int pow);
unsigned long mx_hex_to_nbr(const char *hex);
int mx_quicksort(char **arr, int left, int right);
int mx_binary_search(char **arr, int size, const char *s, int *count);

void mx_printint(int n);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_print_unicode(wchar_t c);
void mx_print_strarr(char **arr, const char *delim);
void mx_foreach(const int *arr, int size, void (*f)(int));

// String pack
void mx_strdel(char **str);
void mx_str_reverse(char *s);
void mx_del_strarr(char ***arr);
void mx_swap_char(char *s1, char *s2);

int mx_strlen(const char *str);
int mx_strcmp(const char *s1, const char *s2);
int mx_get_char_index(const char *str, char c);
int mx_count_words(const char *str, char delimiter);
int mx_count_substr(const char *str, const char *sub);
int mx_get_substr_index(const char *str, const char *sub);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);

char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strtrim(const char *str);
char *mx_file_to_str(const char *file);
char **mx_strsplit(char const *s, char c);
char *mx_strndup(const char *s1, size_t n);
char *mx_del_extra_spaces(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strstr(const char *haystack, const char *needle);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

// Memory pack
int mx_memcmp(const void *s1, const void *s2, size_t n);

void *mx_realloc(void *ptr, size_t size);
void *mx_memset(void *b, int c, size_t len);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);

// List pack
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

int mx_list_size(t_list *list);

t_list *mx_create_node(void *data);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

void mx_pop_back(t_list **head);
void mx_pop_front(t_list **head);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);

// else
bool mx_isdigit(int c);
bool mx_isspace(char c);
bool mx_islower_hex(int c);
bool mx_isupper_hex(int c);
void mx_printerr(const char *s);
void *mx_calloc(size_t count, size_t size);

char *mx_strchr(const char *s, int c);

void mx_swap_str(char **str1, char **str2);

int mx_atoi(const char *str);
int mx_file_content_len(int fd);
int mx_strncmp(const char *s1, const char *s2, int n);
