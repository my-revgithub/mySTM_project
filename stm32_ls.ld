ENTRY(Reset_function)

MEMORY
{
	FLASH(rx): ORIGIN =0x08000000, LENGTH =1024K
	SRAM(rwx): ORIGIN =0x20000000, LENGTH =128K
}

SECTIONS
{
	.text :
	{
		*(.vect_table)
		*(.text)
		*(.rodata)
		_end_fl = .;
	}>FLASH
	
	_start_data_addr = LOADADDR(.data);
	.data :
	{
		_str_sram = .;
		*(.data)
		. = ALIGN(4);
		_end_sram = .;
	}>SRAM AT>FLASH

	.bss :
	{
		_str_bss = .;
		*(.bss)
		. = ALIGN(4);
		_end_bss = .;
	}>SRAM
	_stack_ptr = _str_sram + 128K - 1;
}
