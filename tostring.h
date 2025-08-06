#ifndef _TOSTRING_H__
#define _TOSTRING_H__

#include <stddef.h>
/*
 * Writes a string representation of the data into the buffer, but at most n bytes.
 * Returns count of bytes written.
 */
typedef size_t (*ald_tostring_function_t)(void* data, char* buffer, size_t n);

size_t ald_tostring_pointer(void* data, char* buffer, size_t n);
size_t ald_tostring_int8(void* data, char* buffer, size_t n);
size_t ald_tostring_int16(void* data, char* buffer, size_t n);
size_t ald_tostring_int32(void* data, char* buffer, size_t n);
size_t ald_tostring_int64(void* data, char* buffer, size_t n);
size_t ald_tostring_float(void* data, char* buffer, size_t n);
size_t ald_tostring_double(void* data, char* buffer, size_t n);
size_t ald_tostring_str(void* data, char* buffer, size_t n);

#endif
