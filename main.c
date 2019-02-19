// main code for memory-database
// jackson huettl || 2019

#include "db.h"

int counter = 0;
int sel, seldelint;

int main() {

  fprintf(stdout, "memory database ... \n\n");

  
  while (1) {
    fprintf(stdout, "MENU\n=======\n");
  
    fprintf(stdout, "1. add record.\n");
    fprintf(stdout, "2. delete record\n");
    fprintf(stdout, "3. print all records\n");
    fprintf(stdout, "4. exit\n");

    fprintf(stdout, "selection: ");

    fscanf(stdin, "%d", &sel);
    getchar();

    switch (sel) {
      case 1 : // add
        rn = createNew();
        database = add(database, rn);
        break;
      case 2 : // del
        fprintf(stdout, "enter record number: ");
	      fscanf(stdin, "%d", &seldelint);
	      database = selDel(database, seldelint);
        break;
      case 3 : // printAll
        printAll(database);
        break;
      case 4 : // exit
        return 0;

      // new features / testing

      default :
        fprintf(stdout, "error: invalid choice.\n");
        break;
    }
  }

  return 1; // if 1, something weird has happened

} // main
