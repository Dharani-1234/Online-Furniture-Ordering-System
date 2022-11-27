
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

extern cu *start1,*new1,*ptr1,*prev1,*last1;
extern pr *start2, *new2, *ptr2, *prev2,*last2;
extern tr *start3, *new3, *ptr3, *prev3,*last3;
int register_customer()
{
        if((new1=(cu *)calloc(1,sizeof(cu)))==NULL)
        {
                printf("\n Memory allocation failed\n");
                return EXIT_FAILURE;
        }
        while(1)
        {
                while(1)
                {
                        printf("Enter Customer Id");
                        scanf("%d",&new1->customer_id);
                        if(validate_id(new1->customer_id))
                                continue;
                        break;
                }
                if(start1)
                {
                        for(ptr1=start1;(ptr1) && ptr1->customer_id!=new1->customer_id;ptr1=ptr1->next1);
                        if(ptr1)
                        {
                                printf("\n customer id %d is duplicate\n",new1->customer_id);
                                return EXIT_FAILURE;
                        }
                        else
                                break;
                }
                break;
        }
        while(1)
        {
                printf("Enter the name-");
                scanf("%s",new1->customer_name);
                if(validate_name(new1->customer_name))
                        continue;
                break;
        }
        while(1)
        {
                printf("Enter phone number-");
                scanf("%lld",&new1->cmobile_no);
                if(validate_phoneno(new1->cmobile_no))
                        continue;
                break;
        }
        printf("Enter the address-");
        scanf("%s",new1->customer_address);
        if(!start1)
        {
                start1=new1;
                new1->next1=NULL;
        }
        else if(new1->customer_id<start1->customer_id)
        {
                new1->next1=start1;
                start1=new1;
        }
        else
        {
                for(ptr1=start1;(ptr1) && ptr1->customer_id<new1->customer_id;prev1=ptr1,ptr1=ptr1->next1);
                prev1->next1=new1;
                new1->next1=ptr1;
        }
        return EXIT_SUCCESS;
}

int  remove_customer()
{
        if(!start1)
        {
                printf("\nEmpty List\n");
                return EXIT_FAILURE;
        }
        int customerid;
        while(1)
        {
                printf("\nEnter the customer id for deleting-");
                scanf("%d",&customerid);
                if(validate_id(customerid))
                        continue;
                break;

        }
        if(customerid==start1->customer_id)
        {
                ptr1=start1;
                start1=start1->next1;
                free(ptr1);
        }
        else
        {
                for(ptr1=start1;(ptr1) && ptr1->customer_id!=customerid;prev1=ptr1,ptr1=ptr1->next1);
                if(!ptr1)
                {
                        printf("\ncustomer id  %d is not found\n",customerid);
                        return EXIT_FAILURE;
                }
                prev1->next1=ptr1->next1;
                free(ptr1);
        }
        return EXIT_SUCCESS;
}



int edit_customer()
{
        if(!start1)
        {
                printf("\n Empty List\n");
                return EXIT_FAILURE;
        }
        int cusid;
        while(1)
        {
                printf("\nEnter customer id for editing-");
                scanf("%d",&cusid);
                if(validate_id(cusid))
                        continue;
                break;
        }
        for(ptr1=start1;(ptr1) && ptr1->customer_id!=cusid;ptr1=ptr1->next1);
        if(!ptr1)
        {
                printf("\n Adhar num %lld not found\n",cusid);
                return EXIT_FAILURE;
        }
        printf("Old name is %s and phonenum is %lld\n",ptr1->customer_name,ptr1->cmobile_no);
        printf("Enter new name and new phone number-");
        scanf("%s %lld",&ptr1->customer_name,&ptr1->cmobile_no);
        return EXIT_SUCCESS;
}

int view_customer()
{
        if(!start1)
        {
                printf("\nEmpty List\n");
                return EXIT_FAILURE;
        }
        printf("\n CUSTOMER ID           NAME          PHONENUM         ADDRESS   \n");
        for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
        {
                printf("\n%d     %2s      %3lld       %3s   ",ptr1->customer_id,ptr1->customer_name,ptr1->cmobile_no,ptr1->customer_address);

        }
        return EXIT_SUCCESS;
}

int order_items()
{                    
	int mid;
	printf("Enter customer id : ");
	scanf("%d",&mid);
	if(!start2)
	{
		printf("\nThere are no available products\n");
		system("read a");
		return EXIT_FAILURE;
	}
	printf("\n------------List of Furnitures  available ------------\n");
	printf("\nSerial NO    Product ID     Product NAME    Product QUANTITY \n");
	int count=1;
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		printf("\n%3d",count);
		printf(" %15d  %10s  %20d\n ",ptr2->id,ptr2->name,ptr2->quantity);
		count++;
	}
	int n=0,a;
	int s;
	int x;
	while(n!=3)
	{
		printf("\nEnter product ID to add products or press 2 to exit -\n");
		scanf("%d",&s);
		if(validate_id(s))
		{
			continue;
		}
		if(s==2)
		{
			break;
		}
		for(ptr2=start2;(ptr2) && ptr2->id!=s;ptr2=ptr2->next2);
		if(!ptr2)
		{
			printf("\nProduct ID not found\n");
			continue;
		}
		for(ptr1=start1;(ptr1) && ptr1->customer_id!=mid;ptr1=ptr1->next1);
		ptr1->items_ordered[n]=a;
		while(1)
		{
			printf("\nEnter product quantity -\n");
			scanf("%d",&x);
			if(validate_id(x))
			{
				continue;
			}
			break;
		}
		int temp=ptr2->quantity-x;
		if(temp<0)
		{
			printf("Cannot order due to less quantity\n");
			continue;
		}
		ptr2->quantity=temp;
		if((new3=(tr*)calloc(1,sizeof(tr)))==NULL)
		{
			printf("\nMemory Allocation Failed\n");
			return EXIT_FAILURE;
		}
		new3->customer_id=mid;
		new3->product_id=a;
		new3->product_quantity=x;
	        strcpy(new3->product_name,ptr2->name);
	        strcpy(new3->customer_name,ptr1->customer_name);
		if(!start3)
		{
			start3=new3;
			start3->next3=NULL;
		}
		else
		{
			for(ptr3=start3;(ptr3);prev3=ptr3,ptr3=ptr3->next3);
			prev3->next3=new3;
			new3->next3=ptr3;
		}
		n++;
	}
		return EXIT_SUCCESS;
}

int view_stock()
{                                         
	if(!start2)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\nS.no    Product ID      NAME      Quantity\n");
	int count2=1;
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		printf("\n%3d",count2);
		printf("\n%15d  %10s %15d  %20d\n",ptr2->id,ptr2->name,ptr2->rol,ptr2->quantity);
		count2++;
	}
	printf("\n");

}

int customer_file_to_list()
{

        FILE *cp;
        tmp c1;
        if((cp=fopen("Customer.data","rb"))==NULL)
        {
                printf("\nFile is not present to read from\n");
                return EXIT_FAILURE;
        }
        system("clear");
        fread(&c1,sizeof(tmp),1,cp);
        while(!feof(cp))
        {
                if((new1=(cu *)calloc(1,sizeof(cu)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
                new1->customer_id=c1.customer_id;
                strcpy(new1->customer_name, c1.customer_name);
                new1->cmobile_no=c1.cmobile_no;
                strcpy(new1->customer_address,c1.customer_address);
                if(!start1)
                {
                        start1 = last1 = new1;
                        new1->next1=NULL;
                }
                else
                {
                        last1->next1=new1;
                        last1=new1;
                        new1->next1=NULL;
                }
                fread(&c1,sizeof(tmp),1,cp);
        }
        fclose(cp);
        return EXIT_SUCCESS;
}

int customer_list_to_file()
{
        tmp c2;
        if(!start1)
        {
                printf("\nThe List is Empty.\n");
                return EXIT_FAILURE;
        }
        FILE *cp1;
        if((cp1=fopen("Customer.data","wb"))==NULL)
        {
                printf("\nFile is not present to read \n");
                return EXIT_FAILURE;
        }
        for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
        {
                c2.customer_id=ptr1->customer_id;
                strcpy(c2.customer_name,ptr1->customer_name);
                c2.cmobile_no=ptr1->cmobile_no;
                strcpy(c2.customer_address,ptr1->customer_address);
                fwrite(&c2,sizeof(tmp),1,cp1);
        }
        fclose(cp1);
        return EXIT_SUCCESS;
}


