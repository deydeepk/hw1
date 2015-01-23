#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>

struct Item {
 // Item(int v, Item* n) { val = v; next = n; }
  int val;
  Item* next;
};

//Item* readlist(string line); //reads in string and creates a linked list

Item* concatenate(Item* head1, Item* head2);  // returns head pointer to new list

void removeEvens(Item*& head);

double findAverage(Item* head);
