/*
Copyright (c) Sam Roberts <vieuxtech@gmail.com>, see COPYING

Utility to print the sizes of various system types.
*/

#include<complex.h>
#include<inttypes.h>
#include<limits.h>
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

#include<netinet/in.h>

#include<sys/socket.h>
#include<sys/un.h>

#define SZ(x) printf("%3zd bytes " #x "%s\n", sizeof(x), ((x) 0 > (x) -1) ? "" : " (unsigned)")
#define SZ2(x) printf("%3zd bytes " #x "\n", sizeof(x))

typedef void function(void);
typedef enum { spe = 0xFF } small_positive_enum;
typedef enum { mpe = 0xFFFF } medium_positive_enum;
typedef enum { bpe = 0xFFFFFFFF } big_positive_enum;
typedef enum { sne = -0x80 } small_negative_enum;
typedef enum { mne = -0x8000 } medium_negative_enum;
typedef enum { bne = -0x80000000 } big_negative_enum;
typedef struct {} empty_struct;
typedef struct { char c; int s; double i; } sparse_struct;

#ifdef __cplusplus
class empty_abstract_class { virtual int member(); };
typedef void (empty_struct::*member_function)();
#endif

const char* endian()
{
    unsigned endian = 1;
    const char* first = (char*) &endian;
    const char* last = first + sizeof(endian) - 1;
    if (*first == 1)
        return "little";
    else if (*last == 1)
        return "big";
    else
        return "unknown";
}

int main()
{
    printf("   endian %s\n", endian());
    
    SZ(void*);
    SZ(function*);
    SZ(char);
    SZ(short);
    SZ(int);
    SZ(long);
    SZ(long long);
    SZ(float);
    SZ(double);
    SZ(long double);
    SZ(quad_t);
    SZ(time_t);
    SZ(suseconds_t);
    SZ(pid_t);
    SZ(wchar_t);
    SZ(size_t);
    SZ(ptrdiff_t);
    SZ(ssize_t);
    SZ(intmax_t);
    SZ(uintmax_t);
    /* SZ(complex); */

    SZ(small_positive_enum);
    SZ(medium_positive_enum);
    SZ(big_positive_enum);
    SZ(small_negative_enum);
    SZ(medium_negative_enum);
    SZ(big_negative_enum);
    SZ2(empty_struct);
    SZ2(sparse_struct);

    SZ2(struct sockaddr);
    SZ2(struct sockaddr_in);
    SZ2(struct sockaddr_in6);
    SZ2(struct sockaddr_un);

#ifdef __cplusplus
    SZ(bool);
    SZ2(empty_abstract_class);
    SZ2(member_function);
#endif

    return 0;
}

