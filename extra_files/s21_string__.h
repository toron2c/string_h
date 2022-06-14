#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <wchar.h>
#include <math.h>
#define LEN 255
#define s21_NULL (void*)0
typedef unsigned long s21_size_t;
//  0 - флаг не установлен, 1 - если флаг установлен
typedef struct {
    char fminus;   //  '-'
    char fplus;    //  '+'
    char fspace;   //  ' '
    char fgrid;    //  '#'
    char fzero;    //  '0'
} struct_flags;

typedef struct {
    struct_flags* flags;
    int width;
    int accuracy;
    char length;
    char specifier;
} struct_sprintf_format;

typedef struct {
    char star;
    int width;
    char length;
    char specifier;
} struct_sscanf_format;

void *s21_memchr(const void *str, int c, s21_size_t n);  //  1
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);  //  2
void *s21_memcpy(void *dest, const void *src, s21_size_t n);  //  3
void *s21_memmove(void *dest, const void *src, s21_size_t n);  //  4
void *s21_memset(void *str, int c, s21_size_t n);  //  5
char *s21_strcat(char *dest, const char *src);  //  6
char *s21_strncat(char *dest, const char *src, s21_size_t n);  //  7
char *s21_strchr(const char *str, int c);  //  8
int s21_strcmp(const char *str1, const char *str2);  //  9
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);  //  10
char *s21_strcpy(char *dest, const char *src);  //  11
char *s21_strncpy(char *dest, const char *src, s21_size_t n);  //  12
s21_size_t s21_strcspn(const char *str1, const char *str2);  //  13
char *s21_strerror(int errnum);  //  14
s21_size_t s21_strlen(const char *str);  //  15
char *s21_strpbrk(const char *str1, const char *str2);  //  16
char *s21_strrchr(const char *str, int c);  //  17
s21_size_t s21_strspn(const char *str1, const char *str2);  //  18
char *s21_strstr(const char *haystack, const char *needle);  //  19
char *s21_strtok(char *str, const char *delim);  //  20
int check_s21_strtok(const char *str, const char *delim);  //  20.1
void *s21_to_upper(const char *str);  //  21
void *s21_to_lower(const char *str);  //  22
void *s21_insert(const char *src, const char *str, s21_size_t start_index);  //  23
void *s21_trim(const char *src, const char *trim_chars);  //  24
int* pos_trim_chars(const char *src, const char *trim_chars);  //  24.1

//--------------------------------/_function_sprintf_/--------------------------------//
int s21_sprintf(char *str, const char *format, ...);  //  25
const char* search_specifier(char *str, const char *format);  //  25.1
const char* parse_format(const char *format, struct_sprintf_format* Format);  //  25.2
char* get_flags(char* format, struct_flags* flags);  //  25.2.1
int get_width(const char *format);  //  25.2.2
int get_accuracy(const char* format);  //  25.2.3
char get_length(const char* format);  //  25.2.4
char get_specifier(char symbol);  //  25.2.54
int s21_atoi(const char *format);  //  26
int get_class_number(int number);  //  27
char* end_str(char* str);  // 28
void c_to_str(char* output, char symbol);  //  30
void wc_to_str(char *output, wchar_t symbol);
void wcs_to_str(char *output, wchar_t *wstr);  

void correct_accuracy_for_int(char* output, int accuracy);  //  ...40
void correct_accuracy_for_float(char* output, int accuracy);  //  ...41
void correct_g(char* output);
void correct_accuracy_for_str(char* output, char* str, int accuracy);  //  ...42
void init_pos(char* output, int* pos_point, int* len_remains, int* pos_e, int* len_e);  //
void s21_round(char* output, int accuracy, int pos_point);  //  ...44  
void correct_round(char* output, int index);  //  ...43
void correct_exp(char* output, int pos_e, int len_e);
//int type_specifier(char specifier);  //  ...42

//------------------------------////------------------------------//
void d_to_str(char *output, long long int num, s21_size_t size, char length);  // длина w, h, l, W
void i_to_str(char *output, long long int num, s21_size_t size, char length);  // длина w, h, l, W
void u_to_str(char *output, unsigned long long int num, s21_size_t size, char length);  // длина w, h, l, W
void f_to_str(char *output, long double num, s21_size_t size, char length);  // длина L
void e_to_str(char *output, long double num, s21_size_t size, char length);  // длина L
void E_to_str(char *output, long double num, s21_size_t size, char length);  // длина L
void g_to_str(char *output, long double num, s21_size_t size, char length, int *accuracy);  // длина L
void G_to_str(char *output, long double num, s21_size_t size, char length, int *accuracy);  // длина L
//----------------------------Ф-Л-А-Г-И----------------------------//
void flag_space_str(char *output);
void flag_minus_str(char *output);
void flag_plus_str(char *output);
void flag_zero_str(char *output);
void flag_grid_str(char *output, char length, int accuracy);
void set_width_str(char *output, s21_size_t width);
void correct_flags(struct_sprintf_format *format);
//------------------------------////------------------------------//
void str_to_str(char *output, char *str);
void p_to_str(char *output, unsigned long long int mem);
void x_to_str(char *output, unsigned long long num, s21_size_t size, char length);
void X_to_str(char *output, unsigned long long num, s21_size_t size, char length);
void o_to_str(char *output, unsigned long long num, s21_size_t size, char length);  //  длина w, h, l, W
void reverse(char *s);
void to_the_16(char *output, unsigned long long number, char c);
void to_the_8(char *output, unsigned long long number);

//--------------------------------/_function_sscanf_/--------------------------------//
int s21_sscanf(const char *str, const char *format, ...);
const char* sscanf_search_specifier(const char *str, const char *format);
int separator_character(char symbol);
const char* current_format(const char *format);
const char* sscanf_parse_format(const char *format, struct_sscanf_format* Format);
const char* sscanf_get_star(const char* format, char* star);
const char* sscanf_get_width(const char* format, int* width);
const char* sscanf_get_length(const char* format, char* length);
const char* sscanf_get_specifier(const char* format, char* specifier);

const char* str_to_d(const char* str, struct_sscanf_format Format, long long int* result);
void str_to_i(const char* str, struct_sscanf_format* Format);
const char* str_to_u(const char* str, struct_sscanf_format Format, unsigned long long int* result);
const char* str_to_o(const char* str, struct_sscanf_format Format, unsigned long long int* result);
const char* str_to_float(const char* str, struct_sscanf_format Format, long double* result);
const char* str_to_x(const char* str, struct_sscanf_format Format, unsigned long long int* result);
const char* str_to_s(const char* str, struct_sscanf_format Format, char* arg_str);
const char* wstr_to_ws(const char* str, struct_sscanf_format Format, wchar_t* arg_str);
const char* chech_sign(const char* str, int* flag_minus);
const char* check_inf_nan(const char* str, struct_sscanf_format Format, long double* result, int flag_minus);
int error(const char* str, struct_sscanf_format Format);
//void int_to_o(unsigned long long int num_10, unsigned long long int* num_8);  //  перевод числа из 10ричной в 8ричную систему

#define LINUX {"Success", "Operation not permitted", "No such file or directory", "No such process", \
"Interrupted system call", "Input/output error", "No such device or address", \
"Argument list too long", "Exec format error", "Bad file descriptor", "No child processes", \
"Resource temporarily unavailable", "Cannot allocate memory", "Permission denied", "Bad address", \
"Block device required", "Device or resource busy", "File exists", "Invalid cross-device link", \
"No such device", "Not a directory", "Is a directory", "Invalid argument", \
"Too many open files in system", "Too many open files", "Inappropriate ioctl for device", \
"Text file busy", "File too large", "No space left on device", "Illegal seek", \
"Read-only file system", "Too many links", "Broken pipe", "Numerical argument out of domain", \
"Numerical result out of range", "Resource deadlock avoided", "File name too long", \
"No locks available", "Function not implemented", "Directory not empty", \
"Too many levels of symbolic links", "Unknown error 41", "No message of desired type", \
"Identifier removed", "Channel number out of range", "Level 2 not synchronized", "Level 3 halted", \
"Level 3 reset", "Link number out of range", "Protocol driver not attached", \
"No CSI structure available", "Level 2 halted", "Invalid exchange", "Invalid request descriptor", \
"Exchange full", "No anode", "Invalid request code", "Invalid slot", "Unknown error 58", \
"Bad font file format", "Device not a stream", "No data available", "Timer expired", \
"Out of streams resources", "Machine is not on the network", "Package not installed", \
"Object is remote", "Link has been severed", "Advertise error", "Srmount error", \
"Communication error on send", "Protocol error", "Multihop attempted", "RFS specific error", \
"Bad message", "Value too large for defined data type", "Name not unique on network", \
"File descriptor in bad state", "Remote address changed", "Can not access a needed shared library", \
"Accessing a corrupted shared library", ".lib section in a.out corrupted", \
"Attempting to link in too many shared libraries", "Cannot exec a shared library directly", \
"Invalid or incomplete multibyte or wide character", "Interrupted system call should be restarted", \
"Streams pipe error", "Too many users", "Socket operation on non-socket", \
"Destination address required", "Message too long", "Protocol wrong type for socket", \
"Protocol not available", "Protocol not supported", "Socket type not supported", \
"Operation not supported", "Protocol family not supported", \
"Address family not supported by protocol", "Address already in use", \
"Cannot assign requested address", "Network is down", "Network is unreachable", \
"Network dropped connection on reset", "Software caused connection abort", \
"Connection reset by peer", "No buffer space available", "Transport endpoint is already connected", \
"Transport endpoint is not connected", "Cannot send after transport endpoint shutdown", \
"Too many references: cannot splice", "Connection timed out", "Connection refused", "Host is down", \
"No route to host", "Operation already in progress", "Operation now in progress", \
"Stale file handle", "Structure needs cleaning", "Not a XENIX named type file", \
"No XENIX semaphores available", "Is a named type file", "Remote I/O error", "Disk quota exceeded", \
"No medium found", "Wrong medium type", "Operation canceled", "Required key not available", \
"Key has expired", "Key has been revoked", "Key was rejected by service", "Owner died", \
"State not recoverable", "Operation not possible due to RF-kill", "Memory page has hardware error"}

#define MAC {"Undefined error: 0", "Operation not permitted", "No such file or directory", \
"No such process", "Interrupted system call", "Input/output error", "Device not configured", \
"Argument list too long", "Exec format error", "Bad file descriptor", "No child processes", \
"Resource deadlock avoided", "Cannot allocate memory", "Permission denied", "Bad address", \
"Block device required", "Resource busy", "File exists", "Cross-device link", \
"Operation not supported by device", "Not a directory", "Is a directory", "Invalid argument", \
"Too many open files in system", "Too many open files", "Inappropriate ioctl for device", \
"Text file busy", "File too large", "No space left on device", "Illegal seek", \
"Read-only file system", "Too many links", "Broken pipe", "Numerical argument out of domain", \
"Result too large", "Resource temporarily unavailable", "Operation now in progress", \
"Operation already in progress", "Socket operation on non-socket", "Destination address required", \
"Message too long", "Protocol wrong type for socket", "Protocol not available", \
"Protocol not supported", "Socket type not supported", "Operation not supported", \
"Protocol family not supported", "Address family not supported by protocol family", \
"Address already in use", "Can't assign requested address", "Network is down", \
"Network is unreachable", "Network dropped connection on reset", "Software caused connection abort", \
"Connection reset by peer", "No buffer space available", "Socket is already connected", \
"Socket is not connected", "Can't send after socket shutdown", "Too many references: can't splice", \
"Operation timed out", "Connection refused", "Too many levels of symbolic links", \
"File name too long", "Host is down", "No route to host", "Directory not empty", \
"Too many processes", "Too many users", "Disc quota exceeded", "Stale NFS file handle", \
"Too many levels of remote in path", "RPC struct is bad", "RPC version wrong", \
"RPC prog. not avail", "Program version wrong", "Bad procedure for program", "No locks available", \
"Function not implemented", "Inappropriate file type or format", "Authentication error", \
"Need authenticator", "Device power is off", "Device error", \
"Value too large to be stored in data type", "Bad executable (or shared library)", \
"Bad CPU type in executable", "Shared library version mismatch", "Malformed Mach-o file", \
"Operation canceled", "Identifier removed", "No message of desired type", "Illegal byte sequence", \
"Attribute not found", "Bad message", "EMULTIHOP (Reserved)", "No message available on STREAM", \
"ENOLINK (Reserved)", "No STREAM resources", "Not a STREAM", "Protocol error", \
"STREAM ioctl timeout", "Operation not supported on socket", "Policy not found", \
"State not recoverable", "Previous owner died", "Interface output queue is full"}

#endif  //  SRC_S21_STRING_H_
