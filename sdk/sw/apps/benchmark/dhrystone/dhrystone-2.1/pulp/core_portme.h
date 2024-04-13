#ifndef CORE_PORTME_H
#define CORE_PORTME_H

#include <stddef.h>
#include <rt/rt_api.h>

//for fpga
#include <pflib.h>


/************************/
/* Data types and settings */
/************************/
/* Data Types :
        To avoid compiler issues, define the data types that need ot be used for 8b, 16b and 32b in <core_portme.h>.
        
        *Imprtant* :
        ee_ptr_int needs to be the data type used to hold pointers, otherwise coremark may fail!!!
*/
typedef signed short ee_s16;
typedef unsigned short ee_u16;
typedef signed int ee_s32;
typedef double ee_f32;
typedef unsigned char ee_u8;
typedef unsigned int ee_u32;
typedef ee_u32 ee_ptr_int;
typedef size_t ee_size_t;


#ifndef TIME
#define TIME
#endif

#ifndef HAS_FLOAT
#define HAS_FLOAT 0
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 50000000
#endif

#ifndef CPU_MHz
#define CPU_MHz   CLOCKS_PER_SEC/1000000        
#endif

#define NSECS_PER_SEC        CLOCKS_PER_SEC
#define TIMER_RES_DIVIDER    1
#define EE_TICKS_PER_SEC     (NSECS_PER_SEC / TIMER_RES_DIVIDER)
#define EE_TICKS_PER_MIC_SEC (EE_TICKS_PER_SEC / 1000000)

/* Configuration : MEM_METHOD
	Defines method to get a block of memry.
	
	Valid values :
	MEM_MALLOC - for platforms that implement malloc and have malloc.h.
	MEM_STATIC - to use a static memory array.
	MEM_STACK - to allocate the data block on the stack (NYI).
*/
#define  MEM_MALLOC 0
#define  MEM_STATIC 1
#define  MEM_STACK  2

#ifndef MEM_METHOD
#define MEM_METHOD MEM_STATIC
#endif

typedef struct CORE_PORTABLE_S {
        ee_u8   portable_id;
} core_portable;

/* target specific init/fini */
void portable_init(void);
void portable_fini(void);

#define ee_printf printf

#endif /* CORE_PORTME_H */
