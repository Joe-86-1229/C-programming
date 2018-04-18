// implement a hash table using C

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "string_set.h"

using namespace std;

string_set::string_set() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
		hash_table[i] = NULL;
}

void string_set::add(const char *s) {
	if(contains(s) == 1)
		throw duplicate_exception();
	iterator_index = hash_function(s);
	node *p = new node;
	p->s = new char[strlen(s)+1];
	strcpy(p->s,s);
	p->next = hash_table[iterator_index];
	hash_table[iterator_index] = p;
	reset();
	
}

void string_set::remove(const char *s) {
	//if s is null, throw exception
	if(*s == 0)							
		throw exception();
	//if s is not found, throw not found exception
	if (contains(s) == 0)				
		throw not_found_exception();
	else
	iterator_index = hash_function(s);
	node *pre_node = new node;
	iterator_node = hash_table[iterator_index];
	
	//if the first one is the target, delete the head pointer
	if(strcmp(s,iterator_node->s) == 0 ) {		
		hash_table[iterator_index] = iterator_node->next;	
		delete pre_node;	 
		delete iterator_node; 
		reset();
	}
	//if not,try to find the target value
	else{
		while(strcmp(iterator_node->s,s) != 0 ){
		pre_node = iterator_node;
		iterator_node = iterator_node->next;
		}
		//once find it, delete current node 
		pre_node->next = iterator_node->next;
		delete iterator_node;
		delete pre_node;
		reset();
		}
	
	
}

int string_set::contains(const char *s) { 
	iterator_index = hash_function(s);
	iterator_node = hash_table[iterator_index];
	while( iterator_node != NULL){ 
		if(strcmp(s,iterator_node->s) == 0)
			return 1;
		else
			iterator_node = iterator_node->next;
		}
		return 0; 
			
	}

void string_set::reset() {
	// iterator_node point to the beginnig of hash_table,and keep moving till the first unNULL element
	iterator_index = 0;
	iterator_node = hash_table[iterator_index];
	while(iterator_node == NULL){
		iterator_node = hash_table[++iterator_index];
	

	}
	
}

const char *string_set::next() {
	//if iterator_node point to any NULL,move down to next hash value;
	if(iterator_node == NULL){
		++iterator_index;
		iterator_node = hash_table[iterator_index];
		//if the next hash value still point null,return null;
		if(iterator_node == NULL)
			return NULL;
		else{
		//if not, return this element and move to next position of linklist 
			char *tmp;
			tmp = iterator_node->s;
			iterator_node = iterator_node->next;
			return tmp;
		}
			
	}
	// if not, keep iterator_node iterate the whole list till end
	else{
		char *tmp;
		tmp = iterator_node->s;
	 	iterator_node = iterator_node->next;
		return tmp;
		
	} 
}

string_set::~string_set() {
	cout << "Object is being deleted" << endl;
	//delete []hash_table; 
}

int string_set::hash_function(const char *s) {
	int h,i;
	h = i = 0;
	while( s[i] != 0) { 
		h = h + (int)s[i];
		i++; 
	} 
	h = h % HASH_TABLE_SIZE;
	return h;
}
