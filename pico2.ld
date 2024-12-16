MEMORY
{
  ROM  (rx)    : ORIGIN = 0x10000000,  LENGTH = 4M 
}

/*Map sections to memory*/
SECTIONS
{
	.text : {
		*(.startup*)
		*(.text*)
	} > ROM
}
    
