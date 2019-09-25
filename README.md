# Memory-Database

### Jackson Huettl

## What is it?
Memory-Database is a psuedo-database for storing records such as books or albums. It is written in the C programming language because I decided it would be and the orginial version was also written in C. 

>NOTE: This is not an actual database, its just a bunch of structs in a block of memory but that doesn't sound as nice. 

## Purpose
The purpose of Memory-Database is to showcase my knowledge of the C programming language and to get used to using git/github. It also serves as a way to catalog my books and vinyl records as I add functionality to the program. 

>DISCLAIMER: This is probably the worst way to do this ever, but the basis of this was an assignment and I thought it would be an interesting project to continue. 

## How It Works
The program works via a command line interface comprised of a menu and other basic user input. Operations can be selected when the menu appears by inputting the corresponding number. In terms of actual functionality, the basis of the database is looped calls of memcpy. There are also calloc calls that get allocate the proper amount of memory for each copy of the database. 

### The Basics

##### Add (add)
The add function creates a copy of the database with a size of counter + 1, and then copies the old database into the new one with memcpy. There is a final memcpy which copies the newly created record to the copied database (aka copybase), the copied database is then returned. 

##### Delete (del)
The delete function operates much like the add function but in reverse. It allocates a copy of the database with size of counter - 1 and the copies over the contents of the old database. This simply removes the last entry in the database by not copying it over and the overwriting the database pointer. While it has been replaced (by the selective delete function), it will remain in the program for testing purposes and possible later use. 

>~~NOTE: As of 02/18/19, the delete function is only able to remove the last record but, in the future there will be a selective delete function.~~

##### Printing (printAll)
As of right now the only way to view the contents of the database is via the printAll function, which simply does pointer arithmetic to move through the database, and print out the data held by each record. 

### Additional Functions

##### Selective Delete (selDelete) (added 02/19/19)
The selective delete function replaces the old delete function allowing the user to select which record to delete. The function works by simply skipping over the record selected when it reaches it, and copying the rest of the records to the new database (aka copybase). The user is prompt to enter an integer which corresponds to the index at which the record resides in the block of memory. To make it simpler, in this case the indeces start at 1 so that more people will understand which record they need to choose. 

##### Saving (saveToFile)
To save the database in its current state, the user can call the saveToFile function. This function steps through the database and writes the data of each record to a buffer and then to a file called "db.txt". Each field is separated by commas and each record has its own line in the file. The header of the file is the number of records in the database and the size of the database. 

### Functions in Testing

##### Multiple files / Saving to Named File
To allow for the use of multiple databases and allow for some level of portability (POSIX systems only), it is necessary to allow the user to name the file and thus the database. When saving the database, users will be prompted to enter a name and then a filename will be created and database will be saved to that file. 

>   The filename will be formatted as such:
>       db_"filename".txt

This allows program to find which database is present easier and reduces clutter within the save file. In many ways, this simplifies the program and allows users to directly see which databases are present and share databases if they desire. 



### Necessary Files
- db.h (header file)
- main.c (main file)
- functions.c (functions file)
- README.md (this file)
- makefile (makefile)

###  Notes
- Use the makefile to compile and clean up


### Planned Additions / To Do's
[x] Selective delete (added 02/19/2019)

[x] Save to formatted file (added 02/20/2019)

[ ] Read from formatted file

[ ] Support for multiple databases

    [x] naming convention of database files
    
    [ ] reading from file given database name


[ ] Sorting by various fields