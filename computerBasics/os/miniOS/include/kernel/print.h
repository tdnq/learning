/**
 * 为print.S提供方便引用的头文件定义.
 */
#include "./stdint.h"
#ifndef _LIB_KERNEL_PRINT_H
#define _LIB_KERNEL_PRINT_H


void put_char(uint8_t char_asci);

/**
 *  字符串打印，必须以\0结尾.
 */ 
void put_str(char* message);

/**
 * 以16进制的形式打印数字.
 */ 
void put_int(uint32_t num);

#endif