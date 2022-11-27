#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"


pr *start2, *new2, *ptr2, *prev2,*last2;
int add_product()
{
	if((new2=(pr*)calloc(1,sizeof(pr)))==NULL)
	{
		printf("\nMemory Allocation Failed...\n");
		return EXIT_FAILURE;
	}
	char name[MAX];
	while(1)
	{
		printf("\nEnter product Name -\n");
		scanf("%s",name);
		if(validate_name(name))
			continue;
		break;
	}
	strcpy(new2->name,name);
	new2->quantity=0;
	new2->unit_price=0;
//	new2->status_indicator='N';
	if(!start2)
	{
		start2=new2;
		new2->id=300;
		new2->next2=NULL;
	}
	else
	{
		for(ptr2=start2;(ptr2);prev2=ptr2,ptr2=ptr2->next2);
		new2->id=prev2->id+1;
		prev2->next2=new2;
		new2->next2=ptr2;
	}
	return EXIT_SUCCESS;
}

int edit_product_details()
{
	if(!start2)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}
	int edit;
	while(1)
	{
		printf("\nEnter the Product ID for editing -\n");
		scanf("%d",&edit);
		if(validate_id(edit))
			continue;
		break;
	}
	for(ptr2=start2;(ptr2)&& ptr2->id!=edit;prev2=ptr2,ptr2=ptr2->next2);
	if(!ptr2)
	{
		printf("\nProduct id %d not found for editing\n",edit);
		return EXIT_FAILURE;
	}
	printf("\nOld name is - %s\nOld quantity is - %d\nOld unit_price is - %lf\n",ptr2->name,ptr2->quantity,ptr2->unit_price);
	char name[MAX];
	int quantity;
	while(1)
	{
		printf("\nEnter new name -\n");
		scanf("%s",name);
		if(validate_name(name))
			continue;
		break;
	}
	strcpy(ptr2->name,name);
	while(1)
	{
		printf("\nEnter new quantity -\n");
		scanf("%d",&quantity);
		if(validate_id(quantity))
			continue;
		break;
	}
	ptr2->quantity=quantity;
	printf("\nEnter new unit price -\n");
	scanf("%lf",&ptr2->unit_price);
	printf("Product ID %d edited successfully\n",edit);
	return EXIT_SUCCESS;

}


int delete_product()
{
	if(!start2)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int x;
	while(1)
	{
		printf("\nEnter Product Id to delete -\n");
		scanf("%d",&x);
		if(validate_id(x))
			continue;
		break;
	}
	if(x==start2->id)
	{
		ptr2=start2;
		start2=start2->next2;
		free(ptr2);
	}
	else
	{
		for(ptr2=start2;(ptr2)&& ptr2->id!=x;prev2=ptr2,ptr2=ptr2->next2);
		if(!ptr2)
		{
			printf("\nProduct id %d not found for deletion\n",x);
			return EXIT_FAILURE;
		}
		prev2->next2=ptr2->next2;
		free(ptr2);
	}
	printf("Product ID %d deleted successfully\n",x);
	return EXIT_SUCCESS;

}

int view_product()
{
	if(!start2)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\nProduct ID       Product NAME    QUANTITY   UNIT_PRICE \n");
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		printf("\n%d--%s --%d --%lf",ptr2->id,ptr2->name,ptr2->quantity,ptr2->unit_price);
	}
	printf("\n");
	return EXIT_SUCCESS;
}


int product_file_to_list()
{
	FILE *fp;
	tmp2 t1;
	if((fp=fopen("Product.data","rb"))==NULL)
	{
		printf("\nProduct File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&t1,sizeof(tmp2),1,fp);
	while(!feof(fp))
	{
		if((new2=(pr*)calloc(1,sizeof(pr)))==NULL)
		{
			printf("\nMemory Allocation Failed\n");
			return EXIT_FAILURE;
		}
		new2->id=t1.id;
		strcpy(new2->name,t1.name);
		new2->rol=t1.rol;
		new2->quantity=t1.quantity;
		new2->unit_price=t1.unit_price;
		new2->status_indicator=t1.status_indicator;
		if(!start2)
		{
			start2=last2=new2;
			new2->next2=NULL;
		}
		else
		{
			last2->next2=new2;
			last2=new2;
			new2->next2=NULL;
		}
		fread(&t1,sizeof(tmp2),1,fp);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}
int product_list_to_file()
{
	tmp2 t2;
	pr *p;
	if(!start2)
	{
		printf("\nProduct List is empty\n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("Product.data","wb"))==NULL)
	{
		printf("\nProduct File is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);prev2=ptr2,ptr2=ptr2->next2)
	{
		t2.id=ptr2->id;
		strcpy(t2.name,ptr2->name);
		t2.rol=ptr2->rol;
		t2.quantity=ptr2->quantity;
		t2.unit_price=ptr2->unit_price;
		t2.status_indicator=ptr2->status_indicator;
		fwrite(&t2,sizeof(tmp2),1,p1);
	}
	fclose(p1);
	return EXIT_SUCCESS;
}



