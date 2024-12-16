/*****************************************************************************
 * Smallest Bare Metal Program for the Raspberry Pi Pico2
 *
 * Copyright (c) 2025 Douglas H. Summerville, Binghamton University
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ****************************************************************************/

//Order is important since the linker will place sections consecttively into flash

//Declare the first function, needed to refer to it in the vector table
void entry_point( void ); 

//Minimum vector table.  Contains initial SP and entry point.
//This is assigned to the .text section to force the linker to 
//treat it as code instead of data
void * const  __attribute__((section(".startup"))) vector_table[] =  
{
	(void *)0x20082000, // Initial stack pointer
	&entry_point	    // Reset handler
};

//RP2 uses boot blocks to identify valid bootable code in flash. 
//The zero pointer allows us to skip the end block to keep things
//simple.a See Pico SDK for detail.
unsigned const __attribute__((section(".startup"))) bootblock[] =  
{
	0xFFFFDED3, //magic number
	0x10210142, //flags
	0x000001FF, 
	0x00000000, //Zero
	0xAB123579  //magic number
};
void entry_point( void )
{
	//Release IO_BANK and PADS resets
	*(unsigned volatile *)0x40020000 &= ((1<<6) | (1<<9));
	while((*(unsigned volatile *)0x40020008 & ((1<<6) | (1<<9)) ) != ((1<<6) | (1<<9)) )
		continue;
	//Configure PAD25 and PIN25
	*(unsigned volatile *)0x40038068 = 0;
	*(unsigned volatile *)0x400280CC = 5;
	//Enable GPIO25 and Set to 1
	*(unsigned volatile *)0xd0000030 |= (1<<25);
	*(unsigned volatile *)0xd0000010 |= (1<<25);
	//Hange out here forever
	while(1);
}
