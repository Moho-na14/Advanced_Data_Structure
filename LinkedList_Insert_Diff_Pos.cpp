#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

 void insertAtBeginning(node *header, int data);
 void insertAtFirst(node *header, int data);
 void insertAtLast(node*header, int data);
 void insertAfter(node*header,int pos, int data);
 void deletefromFirst(node*header);
 void deletefromLast(node*header);

int main()
{
    node *header;
    header = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

    if(header == NULL)
    {
        cout << "Memory not Available!" << endl;
        return 0;
    }

    header->data = INT_MAX;
    header->link = NULL;

    int n,d;
    cout<< "Insert Node Length : "; cin >> n;

    for(int i=0; i<n; i++)
    {
        cout<<"Insert Integer data No. "; cin >> d;
        insertAtBeginning(header, d);
    }

    node *ptr = header->link;
     while(ptr != NULL)
    {
            cout << ptr ->data<<" ";
            ptr = ptr->link;
    }
    cout << endl;

    cout<<"Insert Integer data to insert at last. "; cin >> d;
    insertAtLast(header, d);

    node *ptr1 = header->link;
     while(ptr1 != NULL)
    {
            cout << ptr1 ->data<<" ";
            ptr1 = ptr1->link;
    }
    cout << endl;

    cout<<"Insert Position "; cin >> n;
    cout << endl;
    cout<<"Insert Data "; cin >> d;
    insertAfter(header, n, d);

    node *ptr2 = header->link;
     while(ptr2 != NULL)
    {
            cout << ptr2 ->data<<" ";
            ptr2 = ptr2->link;
    }
    cout << endl;

    cout<<"Insert data at First. "; cin >> d;
    insertAtFirst(header, d);

     node *ptr3 = header->link;
     while(ptr3 != NULL)
    {
            cout << ptr3 ->data<<" ";
            ptr3 = ptr3->link;
    }
    cout << endl;


    //

    cout<<"Delete data last. ";
    deletefromLast(header);

    cout<<"Delete data First. ";
    deletefromFirst(header);

}

/*header - newnode - n1 - n2*/

void insertAtBeginning(node *header, int data)
{
    node *newNode;
    newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

    if(newNode == NULL)
    {
        cout << "Insert at Beginning not working due to Memory not available" << endl;
        //return 0;
    }
   else
    {
         newNode->data = data;
         /*upgrade Pointer*/
         newNode->link = header->link;
         header->link = newNode;
    }
}

void insertAtFirst(node *header, int data)
{
    //create a new node
     node *newNode;
     newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

      newNode->data = data;

      newNode->link = header->link;

      header->link = newNode;
}
void insertAtLast(node*header, int data)
{
     node *ptr = header;

     while(ptr->link != NULL)
     {
        ptr = ptr->link;
     }
    node *newNode;
    newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

    if(newNode == NULL)
    {
        cout << "Insert at Ending not working due to Memory not available" << endl;
        //return 0;
    }
    else
    {
         newNode->data = data;
         /*upgrade Pointer*/
         newNode->link = ptr->link;
         ptr->link = newNode;
    }
}

// Insert a node after a node
void insertAfter(node *header, int n, int data)
{
     node *ptr = header;
     int chk = -1;
     while (chk < n-1 && ptr->link != NULL)
    {
        chk++;
        ptr = ptr->link;
    }
    if(chk +1 != n)
    {
        cout<<"Out of Boundary";

    }
else
    {
        node *newNode;
    newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

    if(newNode == NULL)
    {
        cout << "the given previous node cannot be NULL" << endl;
        //return 0;
    }
    else
    {
         newNode->data = data;
         /*upgrade Pointer*/
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
}

}

void deletefromFirst(node *header)
{
    //create a new node
     node *temp = new node;
     if(header == NULL){return;}
     //newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/
     else
        {
        temp = header;
      header = header->link;

      delete temp;

      cout << " After Deleting Node ";
      node *ptr4 = header->link;
     while(ptr4 != NULL)
    {
            cout << ptr4 ->data<<" ";
            ptr4 = ptr4->link;
    }
    cout << endl;
     }

}

void deletefromLast(node *header)
{
    //create a new node
     node *current = new node;
     node *previous = new node;

     if(header == NULL){return;}
     //newNode = (node *) malloc(sizeof(node)); /*Here Check that memory is allocated or not*/

      current = header;
      previous = NULL;

      while(current ->link != NULL)
      {
        previous = current;
        current = current->link;
      }
    previous->link= NULL;
 delete current;
      cout << " After Deleting Last Node ";
      node *ptr5 = header->link;

         while(ptr5 != NULL)
         {
            cout << ptr5 ->data<<" ";
            ptr5 = ptr5->link;
         }
            cout << endl;

}


