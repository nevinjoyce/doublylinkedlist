/* doubly linked list with append, display forward, display reverse, delete, traverse */
#include <stdio.h>
#include <stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	int ch, entry,count=-1;
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	while(1)
	{
		printf("\n1. Append\n2. Display Forward\n3. Display Reverse\n4. Delete\n5. Search\n6. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
					count++;

				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
					count++;
				}break;
			}
			case 2: 
			{
				pos=head;
				printf("\nElements in forward order are:");
				while (pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				} break;
			}
			case 3:
			{ 
				pos=tail;
				printf("\nElements in reverse order are:");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->prev;
				}break;
			}
			case 4:
			{	
				if(head==NULL)
				{ 
					printf("\nUnderflow\n");
					break;
				}
				int num;
				pos=head;
				printf("\nEnter Position to be Deleted: ");
				scanf("%d",&entry);
				if(entry>count)
				{
					printf("\nOut of Range\n");
					break;
				}
				else if(entry==0)
				{	
					struct node *temp=head;
					num=head->data;
					head=head->next;
					temp->next=NULL;
					head->prev=NULL;
					free(temp);
					count--;
				}
				else
				{
					for(int i=0;i<entry-1;i++)
					{	
						pos=pos->next;
					}
					if(pos->next->next==NULL)
					{
						num=tail->data;
						struct node *temp=tail;
						tail=tail->prev;
						temp->prev=NULL;
						tail->next=NULL;
						free(temp);
						count--;	
					}
					else
					{	
						num=pos->next->data;
						struct node*temp=pos->next;
						pos->next=pos->next->next;
						pos->next->next->prev=pos;
						temp->next=NULL;
						temp->prev=NULL;
						free(temp);
						count--;
					}
				}
					printf("\nElement Deleted is: %d\n",num);
					break;
			}
			case 5:
			{	
				int num,flag=0,position=-1;
				printf("\nEnter Which Element to Search for: ");
				scanf("%d", &num);			
				pos=head;
				while(pos!=NULL)
				{
					position++;
					if(pos->data==num)
					{
						printf("\nElement is present at position %d\n",position);
						flag=1;
					}
					pos=pos->next;

				} 
				if(flag==0)
				{
					printf("\nElement not found in linked list\n");
				} break;
			}
			case 6:
			{
				printf("\nGood Bye\n");
				exit(0);
			}
			case 7:
			{
				printf("\ncount value is: %d\n",count);
				break;
			}
		}
	}
}			
