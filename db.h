// header for database


// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// struct
typedef struct record {
  char title[128];
  char by[128];
  char genre[128];
  char year[5];
} record;

#define SIZE sizeof(record)

// variables
record * database;   // main database
record * copybase;   // copy of database (used in add and del)
record * copymovr;   // mover for copybase
record * datamovr;   // mover for database

int counter;         // how many records are in database
record * rn;         // new record
bool saved;          // saved flag
char db_name[128];   // name of database
char file_name[128]; // file name to save to 
FILE * fp;           // file to save to 

// basic functions
record * add(record * rp, record * rn); // adds new record (rn) to database (rp)
record * del(record * rp);              // deletes last record in database (rp)
record * createNew();                   // creates new record 
void printAll(record * rp);             // prints all records out
record * selDel(record * rp, int s);    // selective delete function

// beta functions
int saveToFile(record * rp);            // saves to file