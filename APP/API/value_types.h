#ifndef VALUE_TYPES_H__
#define VALUE_TYPES_H__


typedef   signed           char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

/* exact-width unsigned integer types */
typedef unsigned           char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef float               f32;
typedef unsigned char  		UCHAR8;                  /* defined for unsigned 8-bits integer variable 	    无符号8位整型变量  */
typedef signed   char  		SCHAR8;                  /* defined for signed 8-bits integer variable		    有符号8位整型变量  */
typedef unsigned short 		USHORT16;                /* defined for unsigned 16-bits integer variable 	  无符号16位整型变量 */
typedef signed   short 		SSHORT16;                /* defined for signed 16-bits integer variable 		  有符号16位整型变量 */
typedef unsigned int   		UINT32;                  /* defined for unsigned 32-bits integer variable 	  无符号32位整型变量 */
typedef int   				SINT32;                  /* defined for signed 32-bits integer variable 		  有符号32位整型变量 */
typedef float          		FP32;                    /* single precision floating point variable (32bits) 单精度浮点数（32位长度） */
typedef double         		DB64;                    /* double precision floating point variable (64bits) 双精度浮点数（64位长度） */
typedef uint8_t  u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef SSHORT16 s16;
typedef SINT32 s32;
typedef unsigned long ul32;
#define __NOP                             __nop

#endif

