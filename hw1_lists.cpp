#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include "hw1_lists.h"

using namespace std;

Item* readStringAslist(string line){
  stringstream stream(line);
  Item* list;
  Item* prevItem ;
  int n;
  while(stream >> n){
    //cout<<n<<endl;
  	Item* tmp = new Item();
 	tmp->val = n;
 	tmp->next = NULL;
  	if(list == NULL){
		list = tmp;
	 	prevItem = list;
	 	//cout<< "creating to list" << endl;
	} 
	else {
		prevItem->next = tmp;
		prevItem = tmp;
		//cout << "adding list" << endl;
	}
  }
  return list;
}

/*
void DisplayList(Item* list) {
	Item* tmp = list; 
	// No nodes 
	if ( tmp == NULL ) { cout << "EMPTY" << endl; return; } 
	// One node in the list 
	if ( tmp->next == NULL ) 	{ 
		cout << tmp->val; cout << " --> "; 
		cout << "NULL" << endl; 
	} 
	else { // Parse and print the list 
		int count =0;
		do {
			cout << tmp->val; 
			cout << " --> "; 
			//if(tmp->next == NULL || count++ > 5)  break;
			tmp = tmp->next; 
		} 
		while ( tmp != NULL ); 
		cout << "NULL" << endl;
	 } 
} 
*/


Item* concatenate(Item* head1, Item* head2){
  //new merged list, starts empty 	
  Item* merged = NULL;
  //if the first list is empty, return second list
  if (head1 == NULL) 
     return(head2);
 //if the second list is empty, return first list
  else if (head2==NULL) 
     return(head1);
  //assigned first value of first list to first value of merged list
  merged = head1;
  //do the same for all remaining items in list, until the head2 is null
  merged->next = concatenate(head1->next, head2);
  return(merged);
}


void removeEvens(Item*& head) {
  //remove nothing if list is empty
  if(head == NULL) {
  	return;
  }
  //as long as the next value exists    
  if(head->next!= NULL){    	
  	//and it is even
    if(head->val % 2 == 0) {
    	//set the value of it to the next one
    	head = head->next;
    	//repeat for all until list reaches its end
    	removeEvens(head);   
	}  
	//move on to the next one 
	else  {
		removeEvens(head->next); 	 
	}
  }
}

//helper function for findAverage
//parameters item, number of items, and sum of values
void findAveragehelper (Item* head, double &numitems, double &sum){
	//return on empty list
	if (head == NULL)
		return;  
	//otherwise, increment the number of items 
	//Also, add the current value to the current sum
	numitems++;
	sum+=(head->val);
	//repeat for next item until done 
	findAveragehelper (head->next, numitems, sum);
}

//finds average
double findAverage(Item* head){
	double numberofitems;
	double total;
	findAveragehelper(head, numberofitems, total);
	return total/numberofitems;
}


void printList(std::ostream& ofile, Item* head)
{
  if(head == NULL)
    ofile << std::endl;
  else {
    ofile << head->val << " ";
    printList(ofile, head->next);    
  }
}


int main(int argc, char* argv[])
{
  if (argc!=3){
	cout << "Usage: ./hw1_lists input.txt output.txt" << endl;
	return 1;	
  }	

  ifstream inf(argv[1]);
  
  if(!inf){
	cout << "Could not open file: " << argv[1] << endl;
	return 1;
  }

  ofstream myfile;
  myfile.open (argv[2]);
 
  
  	
  string line1, line2;
  	
  getline(inf, line1);
  getline(inf, line2);

  Item* head1 = readStringAslist(line1);
  Item* head2 = readStringAslist(line2);

  //DisplayList(head1);
  //DisplayList(head2);

  Item* head3 = concatenate(head1, head2);
  printList(myfile, head3);
  removeEvens(head3);
  printList(myfile, head3);
  //DisplayList(head3);
  double average = findAverage(head3);
  printList(myfile, head3);
  myfile << average;

 //myfile << "Writing this to a file.\n";
  myfile.close();
 
  //printList();
  //removeEvens(head3);
  //cout << findAverage(head3) << endl;
}


