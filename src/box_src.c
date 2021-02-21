#include "box.h"

void read_box(box *p)
{
    printf("\nEnter box details: unique ID,length,breadth,height,colour and weight respectively\n");
    scanf("%d%s%d%d%s%lf",&p->unique_id,&p->length,&p->breadth,&p->height,p->colour,&p->weight);
}

void display_box(box p)
{
    printf("\n Unique ID = %d \t Length = %d \t Breadth = %d \t Height = %d \n colour = %s \t Weight = %lf",p.unique_id,p.length,p.breadth,p.height,p.colour,p.weight);
}

struct Node *getNode()
{
    return(malloc(sizeof(struct Node)));
}

void freenode(struct Node *p)
{
    free(p);
}

struct Node *createlist()
{
  struct   Node *first,*neww,*previous;
    int ch;
    first=neww=NULL;
    do
    {   previous=neww;
        neww=getNode();
        read_box(&neww->data);
        if(first==NULL)
            first=neww;
        else
            previous->next=neww;
        printf("\n1->continue for other record \n2->exit");
        scanf("%d",&ch);
    }while(ch==1);
  neww->next=NULL;
    return(first);

}

struct Node *insert_last(struct Node *first)
{
    struct Node *nww,*prev;
     nww= getNode();
     read_box(&nww->data);
     nww->next=NULL ;
    if(first==NULL)
        first=nww;
    else
    {
        for(prev=first;prev->next!=NULL;prev=prev->next);
            prev->next=nww;
    }
    //display_list(first);
     return first;
}

struct Node*deleteAnyPos(struct Node*first)
{
    struct Node *prev,*cur;
    int uid;
    printf("\nenter unique id to delete\n");
    scanf("%d",&uid);
    if(first==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        for(prev=NULL,cur=first;cur!=NULL&&uid!=cur->data.unique_id;prev=cur,cur=cur->next);
        if(cur==NULL)
        {
            printf("\n node not found");
        }
        else
        {
            if(first ==cur)
                first=first->next;
            else
                prev->next=cur->next;
            printf("\n Deleted data is:");
            display_box(cur->data);
            freenode(cur);
        }

    }
     return first;
}

void display_list(struct Node *first)
{
 struct Node *cuu;
    if(first==NULL)
        printf("\nlink is empty");
    else
    {
        for(cuu=first;cuu!=NULL;cuu=cuu->next)

            display_box(cuu->data);
    }
}
void max_height(struct Node *first)
{
    struct Node *cuu;
    if(first==NULL)
        printf("\nlink is empty");
    else
    {
        int maxH=0;
        box result;
        for(cuu=first;cuu!=NULL;cuu=cuu->next)
            {
                box temp=cuu->data;
                if(maxH < temp.height)
                {
                    maxH = temp.height;
                    result = cuu->data;
                }
            }
            printf("Maximum height of box is : %d\n",maxH);
            display_box(result);
    }

}
struct Node *update_weight(struct Node *curr)
{
	int uid;
	int new;
	printf("\nEnter unique ID to change its weight: ");
	scanf("%d", &uid);
	printf("Searching for %d\n", uid);
	while(curr!=NULL)
	{
		// printf("ID: %d", curr->data.unique_id);
		if(curr->data.unique_id == uid)
		{
			printf("Box found\n");
			printf("\nEnter new weight to update the old weight : ");
			scanf("%d",&new);
			printf("\nUpdating weight....");
			curr->data.weight = new;
			display_box(curr->data);
			return (curr);
		}

		else
		{
			 printf("\nBox not found");
		}
		curr = curr->next;  
	}
}
struct Node*deleteAnyPos(struct Node*first)
{
	struct Node *prev,*cur;
	int uid;
	printf("\nenter unique id to delete\n");
	scanf("%d",&uid);
	if(first==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		for(prev=NULL,cur=first;cur!=NULL&&uid!=cur->data.unique_id;prev=cur,cur=cur->next);
		if(cur==NULL)
		{
			printf("\n node not found");
		}
		else
		{
			if(first ==cur)
				first=first->next;
			else
				prev->next=cur->next;
			printf("\n Deleted data is:");
			display_box(cur->data);
			freenode(cur);
		}

	}
	 return first;
}

void *count_colur(struct Node *first)
{
    char name[20];
    int count=0;
    struct Node *curr;
    printf("\nEnter the colour of the box to count");
    scanf("%s",name);
    for(curr= first; curr!=NULL; curr=curr->next)
    {
        if((strcmp(curr->data.colour,name)==0))
        {
            printf("\n Data found");
            count++;
            display_box(curr->data);
        }
        else
        printf("\n data not found:");
    }
    printf("\n Number of boxes with %s colour= %d",name,count);   
}


void average_vol(struct Node *first)
{
    int sum=0;
    struct Node *curr;
    double avg;
    int i;
    for(curr = first;curr!=NULL;curr=curr->next)
    {
        sum += ((curr->data.length)*(curr->data.breadth)*(curr->data.height));
        i++;
    }
    avg = sum/i;
    printf("\n Average of all the boxes = %lf",avg);
}


