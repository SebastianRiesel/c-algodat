#ifndef _COMPARE_H__
#define _COMPARE_H__

typedef int (*ald_compare_function_t)(void*, void*);

int ald_compare_pointer_cmp(void* data1, void* data2);
int ald_compare_int8_cmp(void* data1, void* data2);
int ald_compare_int16_cmp(void* data1, void* data2);
int ald_compare_int32_cmp(void* data1, void* data2);
int ald_compare_int64_cmp(void* data1, void* data2);
int ald_compare_float_cmp(void* data1, void* data2);
int ald_compare_double_cmp(void* data1, void* data2);
int ald_compare_str_cmp(void* data1, void* data2);

#endif
