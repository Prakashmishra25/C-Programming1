#include <cstdio>
#include <cstdlib>
#define HASHSIZE 101

using namespace std;

struct Node {
  int key;
  Node *prev,*next;
};

Node *nil;

void init()
{
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key)
{
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node* listSearch(int key)
{
  Node *cur = nil->next;
  while(cur != nil && cur->key != key){
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t)
{
  if (t == nil)  return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}
void deleteFirst()
{
  deleteNode(nil->next);
}
void deleteLast()
{
  deleteNode(nil->prev);
}
void deleteKey(int key)
{
  deleteNode(listSearch(key));
}
int main()
{
  int key,n,i;
  int size = 0;
  char com[20];
  int np = 0,nd = 0;
  scanf("%d",&n);
  init();
  for(i=0;i<n,i++){
    scanf("%s%d",com,&key);
    if(com[0] == 'i'){insert(key);np++;size++}
    else if(com[0])
  }
}
