// header for database


// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
typedef struct record {
  char title[128];
  char author[128];
  char genre[128];
  char year[5];
} record;

#define SIZE sizeof(record)

// variables
record * database;  // main database
record * copybase;  // copy of database (used in add and del)
record * copymovr;  // mover for copybase
record * datamovr;  // mover for database

int counter;        // how many records are in database
record * rn;        // new record

// basic functions
record * add(record * rp, record * rn); // adds new record (rn) to database (rp)
record * del(record * rp);              // deletes last record in database (rp)
record * createNew();                   // creates new record 
void getInfo();                         // prints out basic information about database
void printAll(record * rp);             // prints all records out

// search functions
record * searchTitle(record * rp);  // searches database for record w/ title
record * searchAuthor(record * rp); // searches database for record w/ author *1*
record * searchGenre(record * rp);  // searches database for record a/ genre  *1*

// structs for testing
/*
record t = {.title = "t", .author = "t1", .genre = "t2", .year = "1"};
record tt = {.title = "tt", .author = "tt1", .genre = "tt2", .year = "2"};
record * tptr = &t;
record * ttptr = &tt;
*/