# Memory-Database

### Jackson Huettl

## What is it?
Memory-Database is a psuedo-database for storing records such as books or albums. It is written in the C programming language because I decided it would be and the orginial version was also written in C. 

>NOTE: This is not an actual database, its just a bunch of structs in a block of memory but that doesn't sound as nice. 

## Purpose
The purpose of Memory-Database is to showcase my knowledge of the C programming language and to get used to using git/github. It also serves as a way to catalog my books and vinyl records as I add functionality to the program. 

## How It Works
The program works via a command line interface comprised of a menu and other basic user input. Operations can be selected when the menu appears by inputting the corresponding number. In terms of actual functionality, the basis of the database is looped calls of memcpy. There are also calloc calls that get allocate the proper amount of memory for each copy of the database. 

### The Basics

##### Add (add)
The add function creates a copy of the database with a size of counter + 1, and then copies the old database into the new one with memcpy. There is a final memcpy which copies the newly created record to the copied database (aka copybase), the copied database is then returned. 

##### Delete (del)
The delete function operates much like the add function but in reverse. It allocates a copy of the database with size of counter - 1 and the copies over the contents of the old database. This simply removes the last entry in the database by not copying it over and the overwriting the database pointer. 

>NOTE: As of 02/18/19, the delete function is only able to remove the last record but, in the future there will be a selective delete function.

##### Printing (printAll)
As of right now the only way to view the contents of the database is via the printAll function, which simply does pointer arithmetic to move through the database, and print out the data held by each record. 

### Necessary Files
- db.h (header file)
- main.c (main file)
- functions.c (functions file)
- README.md (this file)

### Compliation Notes

1. Compile by running "gcc main.c functions.c -o db"


### Planned Additions / To Do's
[] Selective delete

[] Save to formatted file

[] Read from formatted file

[] Support for multiple databases