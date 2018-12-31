.section .init
.globl hijack_entry

hijack_entry:


/* Load 0x00 to r3 */
	mov	r3,	#0x00
/* Load .bss start address to r1*/
	ldr	r1,	=__bss_start
/* Load .bss end address to r2 */
	ldr	r2,	=__bss_end
_clear_bss:
/* Compare r1 and r2 */
	cmp	r1,r2
/* Fill r3(0x0) into address in r1, r1+4 */
	strne 	r3,[r1],#+4
/* if compare result r1 != r2,  back to _clear_bss and clear next byte */
	bne 	_clear_bss

/* The same for .sbss */
	ldr	r1,	=__sbss_start
	ldr	r2,	=__sbss_end
_clear_sbss:
	cmp	r1,r2
	strne 	r3,[r1],#+4
	bne 	_clear_sbss

/* Branch to PROS entry */
    b vexStartup