#include "TCB.h"

TCB_t*  head;
TCB_t*  newQueue();
void    AddQueue(TCB_t* q,TCB_t* ele);
TCB_t*  DelQueue(TCB_t* q);
TCB_t*  newItem();

TCB_t* newQueue(){
  head = newItem();
  return head;
}

TCB_t* newItem(){
  TCB_t* q = (TCB_t*) malloc(sizeof(TCB_t));
  q->prev = q;
  q->next = q;
  return q;
}

void AddQueue(TCB_t* q,TCB_t* ele)
{
  TCB_t* temp = q->prev;
  if(q==NULL)
    {
    q = ele;
    }
    else
    {
    if(temp==NULL)
      {
      q->next = ele;
      q->prev = ele;
      ele->next = q;
      ele->prev = q;
      }
    else
      {
      temp->next = ele;
      ele->prev = temp;
      ele->next = q;
      q->prev = ele;
      }
    }
}

TCB_t* DelQueue(TCB_t* q)
{
  TCB_t *temp = q->next;
  if(q == NULL)
    {
    return NULL;
    }
  else
    {
      q->next = temp->next;
      temp->next->prev = q;
    }
  return temp;
}

int sizeOfQ(TCB_t* head){
  int counter = 1;
  TCB_t* temp=head->next;
  while(temp!=head){
    temp = temp->next;
    counter++;
  }
  return counter;
}
