//   mystring.c
//   David Gregg
//   December 2022

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"


// (a) create a new empty list string
struct mystring * new_empty_mystring() {

  struct mystring * result;
  result = malloc(sizeof(struct mystring));
  result -> head = NULL;
  return result;
 
}

// (b) create a new list string with the same contents as a normal
// NULL-terminated C string
struct mystring * new_array2mystring(char * text) {

  struct mystring * this = new_empty_mystring();
  int length = strlen(text);
  for(int i=0; i< length;i++){
    //fprintf(stderr, "1 %d,%s,  %c\n",length,text,text[i]);
    struct ls_node * new_node;
    new_node =  malloc(sizeof(struct ls_node));
    new_node->c = text[i];
    if (this->head == NULL){
       new_node->next = NULL;
       // fprintf(stderr, "2\n");
    }
     else {
      new_node->next = this->head;
      // fprintf(stderr, "3\n");
    }
    this->head = new_node;
    // fprintf(stderr, "4\n");
  }
  // fprintf(stderr, "9\n");
  return this;
}

// (c) create a new mystring that is a copy of str
struct mystring * mystring_copy(struct mystring * str) {

   struct mystring * this = new_empty_mystring();
   struct ls_node * old_node;
   old_node =  malloc(sizeof(struct ls_node));
   old_node = str->head;
   // fprintf(stderr, "9\n")
   while(old_node != NULL){

     struct ls_node * new_node;
     new_node =  malloc(sizeof(struct ls_node));
     new_node->c = old_node->c;
     if (this->head == NULL){
       new_node->next = NULL;
    }
     else {
      new_node->next = this->head;
    }
    this->head = new_node;   
    old_node = old_node->next;
   }
   //fprintf(stderr, "9\n");
   return this;
}

// (d) create a new mystring that is the concatenation of two
// mystrings
struct mystring * mystring_concatenate(struct mystring * str1,
				       struct mystring * str2) {

   struct mystring * this = new_empty_mystring();
   struct ls_node * old_node;
   old_node =  malloc(sizeof(struct ls_node));
   old_node = str1->head;
   while(old_node != NULL){

     struct ls_node * new_node;
     new_node =  malloc(sizeof(struct ls_node));
     new_node->c = old_node->c;
     if (this->head == NULL){
       new_node->next = NULL;
    }
     else {
      new_node->next = this->head;
    }
    this->head = new_node;   
    old_node = old_node->next;
   }

   old_node = str2->head;
   while(old_node != NULL){

     struct ls_node * new_node;
     new_node =  malloc(sizeof(struct ls_node));
     new_node->c = old_node->c;
     if (this->head == NULL){
       new_node->next = NULL;
    }
     else {
      new_node->next = this->head;
    }
    this->head = new_node;   
    old_node = old_node->next;
   }
   //  fprintf(stderr, "9\n");
   return this;
  
}

// (e) create a new mystring containing the same characters as str,
// but in reverse order
struct mystring * mystring_reverse(struct mystring * str) {

   struct mystring * this = new_empty_mystring();
   this =  mystring_copy(str);
   struct ls_node * current_node;
   struct ls_node * next_node;
   struct ls_node * prev_node;
   current_node =  malloc(sizeof(struct ls_node));
   prev_node =  malloc(sizeof(struct ls_node));
   next_node =  malloc(sizeof(struct ls_node));
   prev_node = NULL;

   current_node = str->head;

   while(current_node != NULL){

     next_node = current_node->next;
     current_node->next = prev_node;
     prev_node = current_node;
     current_node = next_node;
   }
   // fprintf(stderr, "9\n");
   return this;
}

// is there a match starting at this point in the text
int match_substring(struct ls_node * text, struct ls_node * str) {

}

// (f) return 1 if str is a substring of text; 0 otherwise
int mystring_substring(struct mystring * text, struct mystring * str) {

}


// (g) free the memory used by the mystring
void mystring_free(struct mystring * str) {

   struct ls_node * temp;
   temp = str->head;
   while(temp!=NULL){
     temp = temp->next;
     free(temp);
   }
   free(temp);
   // fprintf(stderr, "9\n");
}
