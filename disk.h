#ifndef _DISK_H
#define _DISK_H

#define BLOCK_SIZE	512
#define NUM_BLOCKS 4096
#define INODE_BLOCKS 128	
#define INODE_SIZE	32
#define DENTRY_MAX	16			//max dir numbers is 16
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


FILE *fp;



struct super_block
{
	int magic_number;
	int block_num;          	//total block number
	int inode_num;				//total inode number
	int free_blk;				//free block number
	int free_inode;				//free inode number
	/* int	s_ifree[127];
	int	s_dfree[4095];				 */
				
};



struct inode {
	int size;							/* file size */
	int flags;							/* file type */
	int type;                       	/* 1 for file, 2 for dir */
	short int num;                      /* inode number */
	int blocks[10];                 	/* direct blocks(5 KB) one indirect block*/
	int count ;
	short int sin_in_block;
	short int dou_in_block;       
	

	//2-level indirect blocks
};

struct dirEntry
{
	unsigned char inode_indicator;	// 1 or 0, 0 means no entry
	int inode;          			// dir entry inode
	int type;           			// dir entry type: file or sub dir
	int length;         			// file name's length: 32 or 64
	int count ;
	char name[20];      			// file or sub dir name, max is 20 bytes
};


// directory block struct, has 16 dir entries space
struct dir
{
	struct dirEntry dentry[DENTRY_MAX];   
};



void system_start(); 
int format();
void mkdis();
void read_inode(int);
void write_inode(int );
void read_block(int, char *);
void write_block(int, char *);

#endif //_QUEUE_H