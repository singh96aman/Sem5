//Write a program for the simulation of ls command.
#include<stdio.h>
#include<dirent.h> //for directory commands
#include<stdlib.h> //for exit
int main()
{
char dirname[10];
DIR*p;
// pointer to directory
struct dirent *d; // pointer to directory entry structure
