#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

/**
 * @file box.h
 * @author A H Aruna name (a.aruna@ltts.com.com)
 * @brief
 * @version 0.1
 * @date 2021-02-20
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int unique_id;
    int length;
    int breadth;
    int height;
    char colour[20];
    double weight;
}box;
// struture of box that has all the parameters 

struct Node
{
    box data;
   struct Node *next;
};
// structure for linked list that holds the address of next box

void read_box(box *); // read the box parameters

void display_box(box ); // display the box paramters

struct Node *getNode(); // creates the memory for the box

void freenode(struct Node *);// frees the memory of th ebox

struct Node *createlist(); // creates the list of all the boxes calling getnode function and holds the address of first box

struct Node *insert_last(struct Node *); // Inserts the box at last of the list

void display_list(struct Node *);// display the list calling display function holds first box address


#endif // BOX_H_INCLUDED