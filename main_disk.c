
#include "disk.h"


void main() {
	
	
	char* buffer = "CSC370";
	
	system_start();
	fp = fopen("vdisk.txt", "r+");
	
	write_block(130, buffer);
	fclose(fp);
	 

}




