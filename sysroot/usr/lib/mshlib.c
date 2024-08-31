//#include <stdlib.h>
//#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/*
int m_chdir(char path[]){
	return chdir(path);		
}
*/

int use_video_memory(uint32_t index, uint16_t value){
	//video memory starts at 0xb8000
	
	//uint16_t* terminalBuffer = (uint16_t*) 0xb8000;
	//need to change the above line later
	//uint16_t temp = 0;
	//uint16_t* terminalBuffer = &temp;

	//
	//this will prevent a segfault in matlab, but needs to be changed to point to 0xb8000 before compiling/creating the iso
	//conceptually, this is how it works anyway
	//
	//int vga_width = 80;
	//int vga_height = 25;
	//uint16_t terminalBuffer[vga_width*vga_height]; 
	
	//need to add test to make sure value is uint_16
	//terminalBuffer[0] = (uint16_t)1864;
	//return 1;
	//the nature of this challenge demands that this function simply do nothing, and that it is edited later to do something after compiling 
	
	uint16_t* terminalBuffer = (uint16_t*)0xb8000;
	terminalBuffer[index] = value;

	//yeah I was going to do error checking but not anymore so just return 1 every time :)
	return 1;
}
