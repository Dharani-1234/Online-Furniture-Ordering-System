#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
extern cu *start1, *new1, *ptr1, *prev1, *last1;
extern pr *start2, *new2, *ptr2, *prev2,*last2;
tr *start3, *new3, *ptr3, *prev3, *last3;
int display_report()
{
	if(!start3)
	{
		printf("Transaction file is empty\n");
		return EXIT_FAILURE;
	}
	printf("Transactions file\n");
	printf("PRODUCT ID     STOCKIST ID    PRODUCT NAME    STOCKIST NAME     PRODUCT QUANTITY\n");
	for(ptr3=start3;(ptr3);ptr3=ptr3->next3)
	{
        printf("%d------------    %d-----------  %s--------------  %s-----------------   %d\n",ptr3->product_id, ptr3->customer_id, ptr3->product_name, ptr3->customer_name, ptr3->product_quantity);
	}
	return EXIT_SUCCESS;
}

int display_report_item()
{
	if(!start3 || !start2)
	{
		printf("Product/Transaction file is empty\n");
		return EXIT_FAILURE;
	}
	int count;
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		count=0;
		for(ptr3=start3;(ptr3);ptr3=ptr3->next3)
		{
			if(ptr2->id==ptr3->product_id)
			{
				count++;
			}
		}
		if(count>=5)
		{
			printf("%s is in high demand\n",ptr2->name);
		}
	}
	return EXIT_SUCCESS;
}

int display_report_customer()
{
	if(!ptr3)
	{
		printf("Transaction file s empty\n");
		return EXIT_FAILURE;
	}
	int count;
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		count=0;
		for(ptr3=start3;(ptr3);ptr3=ptr3->next3)
		{
			if(ptr1->customer_id == ptr3->customer_id)
			{
				count++;
			}
		}
		if(count>=5)
		{
			printf("%s (%d) has made frequent transactions\n",ptr1->customer_name,ptr1->customer_id);
		}
	}
	return EXIT_SUCCESS;
}

int transaction_file_to_list()
{
	FILE *fp;
	tmp3 t1;
	if((fp=fopen("Transaction.data","rb"))==NULL)
	{
		printf("\nTransaction File is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&t1,sizeof(tmp3),1,fp);
	while(!feof(fp))
	{
		if((new3=(tr *)calloc(1,sizeof(tr)))==NULL)
		{
			printf("\n Memory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new3->customer_id=t1.customer_id;
		new3->product_id=t1.product_id;
		new3->product_quantity=t1.product_quantity;
		strcpy(new3->product_name,t1.product_name);
                strcpy(new3->customer_name,t1.customer_name);
		if(!start3)
		{
			start3=last3=new3;
			new3->next3=NULL;
		}
		else
		{
			last3->next3=new3;
			last3=new3;
			new3->next3=NULL;
		}
		fread(&t1,sizeof(tmp3),1,fp);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}

int transaction_list_to_file()
{
	tmp3 t2;
	if(!start3)
	{
		printf("\nTransaction List is Empty \n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("Transaction.data","wb"))==NULL)
	{
		printf("\nTransaction File is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr3=start3;(ptr3);prev3=ptr3,ptr3=ptr3->next3)
	{
		t2.customer_id=ptr3->customer_id;
		t2.product_id=ptr3->product_id;
		t2.product_quantity=ptr3->product_quantity;
		strcpy(t2.product_name,ptr3->product_name);
                strcpy(t2.customer_name,ptr3->customer_name);
		fwrite(&t2,sizeof(tmp3),1,p1);
//		free(prev3);
	}
	fclose(p1);
//	free(prev3);
	return EXIT_SUCCESS;
}
