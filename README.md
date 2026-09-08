# Inverted Search Engine

An Inverted Search Engine implemented in C using hash tables and linked lists. The project indexes words from multiple text files and enables efficient searching and retrieval of word information.

## Features

- Create an inverted index database from text files
- Display the complete database
- Search for a word in the database
- Update the database with additional files
- Save the database to a file
- Track word occurrences across files
- Validate input files and avoid duplicate files

## Concepts Used

- C Programming
- Data Structures
- Hash Tables
- Linked Lists
- File Handling
- Dynamic Memory Allocation
- String Handling

## Project Files

- main.c - Main program and menu handling
- create_database.c - Creates the inverted database
- display.c - Displays database contents
  search.c - Searches for a word
- update_database.c - Updates the existing database
- save.c - Saves the database to a file
- file_validation.c - Validates input files
- insert.c - Handles insertion operations
- inverted_search.h - Structure definitions and function declarations

## Compilation

```bash
cd invertedsearch_src
gcc *.c
./a.oout
