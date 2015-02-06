// common.c -- Defines some global functions.
//             From JamesM's kernel development tutorials.

#include "common.h"

// Write a byte out to the specified port.
void outb(u16int port, u8int value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
    u8int ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inw(u16int port)
{
    u16int ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

// Copy len bytes from src to dest.
void memcpy(u8int *dest, const u8int *src, u32int len)
{
    while (len--)
        *dest++ = *src++;
}

// Write len copies of val into dest.
void memset(u8int *dest, u8int val, u32int len)
{
    while (len--)
        *dest++ = val;
}

// Return the length of a NULL-terminated string.
u32int strlen(char *str)
{
    char *p;
    for (p = str; *p; ++p);
    return p - str;
}

// Compare two strings. Should return -1 if 
// str1 < str2, 0 if they are equal or 1 otherwise.
int strcmp(char *str1, char *str2)
{
    char c1, c2;
    do
    {
        c1 = *str1++;
        c2 = *str2++;
        if (c1 == '\0' && c2 == '\0')
            return 0;
    } while (c1 == c2);
    return c1 < c2 ? -1 : 1;
}

// Copy the NULL-terminated string src into dest, and
// return dest.
char *strcpy(char *dest, const char *src)
{
    char *ret = dest;
    while ((*dest++ = *src++) != '\0');
    return ret;
}

// Concatenate the NULL-terminated string src onto
// the end of dest, and return dest.
char *strcat(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest++ != '\0');
    --dest;
    while ((*dest++ = *src++) != '\0');
    return ret;
}
