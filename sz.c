#include<complex.h>
#include<inttypes.h>
#include<limits.h>
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

#define SZ(x) printf("%2zd bytes " #x "%s\n", sizeof(x), ((x) 0 > (x) -1) ? "" : " (unsigned)")
#define SZ2(x) printf("%2zd bytes " #x "\n", sizeof(x))

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

int main()
{
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
#ifdef __cplusplus
    SZ(bool);
    SZ2(empty_abstract_class);
    SZ2(member_function);
#endif
    return 0;
}

