#include "disk.h"
#include <string.h>


void system_start() {
	fp = fopen("vdisk.txt", "w+");
	printf("system are formatting...\n");
	if(!format())
		return;
	fclose(fp);
}

int format() {
	char *buf;
	
	/* allocate 2048 KB which is 2M memory space for buffer */
	buf = (char*)malloc(2* 1024 * 1024);
	
	// put the indicator at the front of file
	fseek(fp, 0, SEEK_SET);
	
	/* write data into fp */
	fwrite(buf, 1024 * 1024 * 2, 1, fp);
	free(buf);

	mkdis();  
	fclose(fp);
	return 0;
}


void mkdis () {
	int i;
	struct super_block *sb = (struct super_block *) malloc(sizeof(struct super_block));      // allowcate in heap
	struct inode *root = (struct inode *) malloc(sizeof(struct inode));
	struct dir *root_block = (struct dir *) malloc(sizeof(struct dir));

	sb->magic_number = 10;							// write the magic number
	sb->block_num = NUM_BLOCKS;						// total numbers of blocks
	sb->inode_num = INODE_BLOCKS;					// total numbers of inode in i-list
	sb->free_blk = NUM_BLOCKS - INODE_BLOCKS -1;    // numbers of free blocks 
	sb->free_inode = 127;   						// numbers of free inode		
	
	fseek(fp, 0, SEEK_SET);		// set file indicator at the front of file
	fwrite(&sb, sizeof(struct super_block), 1, fp);					// write the super_block into first block

	printf("-------------Super block initialized-----------\n");
	printf("Total number of blocks is %d\n", NUM_BLOCKS);
	printf("Size of each block is %d\n", BLOCK_SIZE);
	printf("Free block so far is %d\n", sb->free_blk);
	
	
	
	/* root inode initial */
	root->flags = 1;								/* 1 for file, 2 for dir */
	root->num = 1; 
	root->count++;	
	
	  		

	/* -1 means have not been used */
	for(i = 1; i < 10; i++)
		root->blocks[i] = -1; 
	root->sin_in_block = -1;
	root->dou_in_block = -1;
	
	/* root inode is located at 11th block becuase the first 10 is not available for data */
	fseek(fp, 10 * BLOCK_SIZE, SEEK_SET);		
	fwrite(&root, sizeof(struct inode), 1, fp);
	
	/* create root directory */
	root_block->dentry[0].inode_indicator = 1;
	root_block->dentry[0].inode = 1;				//this dir is pointed by inode number 1
	root_block->dentry[0].type = 2;					//2 is a directory
	root_block->dentry[0].length = 128;				//file length is 128 
	root_block->dentry[0].name = "root";			//dir's name
	

	fseek(fp, (INODE_BLOCKS + 1) * BLOCK_SIZE, SEEK_SET);		
	fwrite(&root_block, sizeof(struct dir), 1, fp);
	
	free(sb);
	free(root);
	free(root_block);
	
	printf("root inode is initialized\n");
	printf("disk is initialized\n");
}

