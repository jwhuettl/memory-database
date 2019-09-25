// functions for memory-database
// jackson huettl || 2019

#include "db.h"


// helper functions
void printRecord(record * rp) {
  // prints info from record (rp)

  fprintf(stdout, "  title: %s\n", rp->title);
  fprintf(stdout, "  by:    %s\n", rp->by);
  fprintf(stdout, "  genre: %s\n", rp->genre);
  fprintf(stdout, "  year:  %s\n\n", rp->year);
} // printRecord

record * createNew() {
  // uses user input to create new record structs
  // calls fgets, cn is the returned record

  record * cn = (record *) calloc(1, SIZE);
  char t[128], b[128], g[128], y[5];

  fprintf(stdout, "\ncreating new record ...\n");

  // 
  
  fprintf(stdout, "  title: ");
  fgets(cn->title, 128, stdin);
  strtok(cn->title, "\n");       // removing \n at end 

  fprintf(stdout, "  by:    ");
  fgets(cn->by, 128, stdin);
  strtok(cn->by, "\n");          // removing \n at end 

  fprintf(stdout, "  genre: ");
  fgets(cn->genre, 128, stdin);
  strtok(cn->genre, "\n");       // removing \n at end 

  fprintf(stdout, "  year:  ");
  fgets(cn->year, 5, stdin);
  strtok(cn->year, "\n");        // removing \n at end 
  
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

// saving to file

int saveToFile(record * rp) {
  // saves to formatted .txt file

  FILE * fp = fopen("db.txt", "w");

  datamovr = rp;
  char data[389];
  

  fprintf(fp, "%d %d\n", counter, (SIZE * counter));
  fprintf(fp, "tile, by, genre, year\n");

  for (int i = 0; i < counter; i++) {
    sprintf(data, "%s,%s,%s,%s", datamovr->title, datamovr->by, datamovr->genre, datamovr->year);
    fprintf(fp, "%s\n", data);
    datamovr++;
  }

  fclose(fp);
  return 0;
  
} // saveToFile

int saveToNamedFile(record * rp) {
  // saves to named file to eventually allow for multiple databases
  
  char[128] usrfn; // user file name

  fprintf(stdout, "database name: ");
  fgets(usrfn, 120, stdin);


  // creating naming convention for saved files
  char[128] filename = "db_";
  strcat(filename, userfn);
  strcat(filename, '.txt');

  fprintf(stdout, '%s', filename);

  FILE * fp = fopen(filename, "w");

  datamovr = rp;
  char data[389];
  

  fprintf(fp, "%d %d\n", counter, (SIZE * counter));
  fprintf(fp, "tile, by, genre, year\n");

  for (int i = 0; i < counter; i++) {
    sprintf(data, "%s,%s,%s,%s", datamovr->title, datamovr->by, datamovr->genre, datamovr->year);
    fprintf(fp, "%s\n", data);
    datamovr++;
  }

  fclose(fp);
  return 0;
  
}