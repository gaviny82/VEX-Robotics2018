#include <stdio.h>

/* PROS did not implement some necessary stub functions 
 * for libc(newlib in this case) */

void __sync_synchronize() {
    /* Perform a memory barrier to workaround malfunctional lock */
     asm volatile("dmb" : : : "memory");
}

//FIXME: Shoud we also implement atomic operations? Zynq is a SMP SoC.
