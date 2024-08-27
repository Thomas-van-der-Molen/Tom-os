//#include <stdlib.h>
//#include <unistd.h>
#include <stdint.h>


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
	int vga_width = 80;
	int vga_height = 25;
	uint16_t terminalBuffer[vga_width*vga_height]; 
	
	//need to add test to make sure value is uint_16
	if(sizeof(value) != 2){
		return 0;
	}
	terminalBuffer[index] = value;
	return 1;
}
