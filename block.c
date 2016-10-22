#include "disk.h"






void read_block(int disk_id, char *buf) {
	fseek(fp, BLOCK_SIZE * disk_id , SEEK_SET);
	fread(buf, BLOCK_SIZE, 1, fp);
}


void write_block(int disk_id, char *buf) {
	fseek(fp, BLOCK_SIZE * disk_id, SEEK_SET);
	fwrite(buf, BLOCK_SIZE, 1, fp);
}


void read_inode(int num){
	/*  char *buf;
	 fp = fopen("disk.txt", "r+");
	 buf = (char*)malloc(2* 1024 * 1024);
	 fseek(fp, INODE_BLOCKS*BLOCK_SIZE * num, SEEK_SET);
	 fread(buf, sizeof(struct inode), 1, fp);
	 printf("%s\n", buf);
	 free(buf);
	 fclose(fp); */
}

void write_inode(int num){
	
	
	
	

}
