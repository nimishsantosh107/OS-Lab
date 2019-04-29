#include<stdio.h>
#include<stdlib.h>

struct node
{
  int size;
  char id;
  int blockno;
  struct node *next;
  struct node *lnext;
};

typedef struct node node;


struct index
{
  char id;
  node iarray[20];
};

typedef struct index index;

index IndexBlock[10];
int x=0;

node *create(node *head,int n)
{
  node *new,*temp;
  temp = head;
  for(int i=0;i<n;i++)
    {
      new = (node *)malloc(sizeof(node));
      new->id='H';
      new->size=0;
      new->lnext=NULL;
      new->blockno=i+1;
      if(head==NULL)
	{
	  head=new;
	  temp=new;
	}
      else
	{
	  temp->next=new;
	  temp=new;
	}
    }
  return head;
}

node *contiguous(node *head,char p,int num)
{
  node *temp,*new,*prev,*temp2;
  int count=0,i=0,countp=0;
  for(temp=head,prev=head;temp!=NULL;temp=temp->next)
    {
      if(temp->id=='H' && prev->id=='H')
	{
	  for(temp2=temp;temp2!=NULL;temp2=temp2->next)
	    {
	      if(count<num)
		{
		  count++;
		}
	      if(count==num || temp2->next->id!='H')
		break;
	    }
	  if(count==num || temp2->next->id!='H')
	    break;
	}
      prev=temp;
    }
  if(count<num-1)
    {
      printf("Contiguous alloc not possible\n");
    }
  else
    {
      for(i=0;i<num;i++)
	{
	  prev->id=p;
	  prev=prev->next;
	}
    }
  return head;
}

void display(node *head)
{
  node* temp;
  for(temp=head;temp!=NULL;temp=temp->next)
    {
      if(temp->size!=0 && temp->id!='H')
	printf("BNO%d F%c | ",temp->blockno,temp->id);
      if(temp->size!=0 && temp->id=='H')
	printf("BNO%d %c | ",temp->blockno,temp->id);
    }
  printf("\n");
}

node *deallocate(node *head,char p)
{
  node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
    {
      if(temp->id==p)
	temp->id='H';
    }
  return head;
}

node* linked(node *head,char p,int num)
{
  node *temp=head,*prev,*temp2;
  int i;
  for(i=0;i<num;i++)
    {
      while(temp!=NULL)
	{
	  if(temp->id=='H')
	    {
	      temp->id=p;
	      temp=temp->next;
	      break;
	    }
	  else
	    temp=temp->next;
	}
    }
  for(temp=head;temp!=NULL;temp=temp->next)
    {
      if(temp->id==p)
	{
	  for(temp2=temp->next;temp2!=NULL;temp2=temp2->next)
	    {
	      if(temp2->id==p)
		{
		  temp->lnext=temp2;
		  break;
		}
	    }
	}
    }
  return head;
}

node *indexed(node *head,char p,int num)
{
  node *temp=head;
  index itemp;
  itemp.id=p;
  int i=0;
  for(i=0;i<num;i++)
    {
      while(temp!=NULL)
	{
	  if(temp->id=='H')
	    {
	      temp->id=p;
	      temp=temp->next;
	      break;
	    }
	  else
	    temp=temp->next;
	}
    }
  i=0;
  for(temp=head;temp!=NULL;temp=temp->next)
    {
      if(temp->id==p)
	{
	  itemp.iarray[i].next=temp;
	  i++;
	}
    }
  IndexBlock[x]=itemp;
  x++;
  return head;
}

void main()
{
  int num;
  node *mem=NULL,*temp;
  char pid; 
  int size_partition,size;
  printf("Enter number of partitions : ");
  scanf("%d",&num);
  mem=create(mem,num);
  for(temp=mem;temp!=NULL;temp=temp->next)
    {
      temp->size=8;
    }
  
  mem=contiguous(mem,'1',4);
  display(mem);
  mem=contiguous(mem,'2',4);
  mem=contiguous(mem,'3',4);
  display(mem);
  mem=deallocate(mem,'2');
  display(mem);
  mem=contiguous(mem,'4',6);
  display(mem);
  //mem=linked(mem,'4',5);
  //display(mem);
  /*char fname;
  printf("Enter file to find : ");
  scanf(" %c",&fname);
  printf("Found in : ");
  for(temp=mem;temp!=NULL;temp=temp->next)
    {
      if(temp->id==fname)
	{
	  printf("BNO%d ",temp->blockno);
	}
    }
    printf("\n\n");*/

  mem=indexed(mem,'4',5);
  display(mem);
  mem=indexed(mem,'5',6);
  display(mem);
  int j=0;

  printf("File %c : ",IndexBlock[1].id);
  int i=0;
  while(i<6)
    {
      printf("BNO%d ",IndexBlock[1].iarray[i].next->blockno);
      i++;
    }
  printf("\n");
}
      
  
