// functions for memory-database
// jackson huettl || 2019

#include "db.h"


// helper functions
void printRecord(record * rp) {
  // prints info from record (rp)

  fprintf(stdout, "  title: %s", rp->title);
  fprintf(stdout, "  by:    %s", rp->by);
  fprintf(stdout, "  genre: %s", rp->genre);
  fprintf(stdout, "  year:  %s\n\n", rp->year);
} // printRecord

record * createNew() {
  // uses user input to create new record structs
  // calls fgets, cn is the returned record

  record * cn = (record *) calloc(1, SIZE);

  fprintf(stdout, "\ncreating new record ...\n");

  // error check all fgets statements

  fprintf(stdout, "  title: ");
  if (fgets(cn->title, 128, stdin) == NULL) {
    perror("fgets error: ");
  }

  fprintf(stdout, "  by:    ");
  if (fgets(cn->by, 128, stdin) == NULL) {
    perror("fgets error: ");
  }

  fprintf(stdout, "  genre: ");
  if (fgets(cn->genre, 128, stdin) == NULL) {
    perror("fgets error: ");
  }

  fprintf(stdout, "  year:  ");
  if (fgets(cn->year, 5, stdin) == NULL) {
    perror("fgets error: ");
  }

  return cn;
} // createNew

// basic functions
record * del(record * rp) {
  // deletes last record in the database
  // copies to new database with size counter - 1
  // will be replaced by selective delete

  copybase = (record *) calloc(counter - 1, SIZE);
  copymovr = copybase;

  for (int i = 0; i < counter - 1; i++) {
    memcpy(copymovr, rp, SIZE);
    copymovr++;
    rp++;
  }
  
  counter--;
  return copybase;
} // del

record * add(record * rp, record * rn) {
  // adds new record to database with memcpy
  // calls createNew to actually creating new record

  fprintf(stdout, "\n");

  copybase = (record *) calloc(counter + 1, SIZE);
  copymovr = copybase;

  if (counter > 0) {
    for (int i = 0; i < counter; i++) {
      memcpy(copymovr, rp, SIZE);
      copymovr++;
      rp++;
    }
  }

  memcpy(copymovr, rn, SIZE);
  counter++; 

  fprintf(stdout, "\n");
  return copybase;
} // add

void printAll(record * rp) {
  // prints out all records stored in rp
  // calls printRecord on each record in database

  datamovr = rp;

  fprintf(stdout, "\nprinting ... \n");

  for (int i = 0; i < counter; i++) {
    fprintf(stdout, "record: %d\n", i + 1);
    printRecord(datamovr);
    datamovr++;
  }

} // printAll


// selective delete function 

record * selDel(record * rp, int s) {
  // deletes record s in database rp
  // user selects a number which then will be deleted

  copybase = (record *) calloc(counter - 1, SIZE);
  copymovr = copybase;

  for (int i = 0; i < counter; i++) {
    if ((i + 1) == s) {
      // record found skipping to delete
      rp++; 
    } 
    else {
      memcpy(copymovr, rp, SIZE);
      copymovr++;
      rp++;
    }
  }

  counter--;
  return copybase;
} // selDel
