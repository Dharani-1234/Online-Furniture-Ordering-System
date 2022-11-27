#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"


su *start, *new, *ptr, *prev,*last;
cu *start1,*new1,*ptr1,*prev1,*last1;
extern pr *start2, *new2,*ptr2, *prev2, *last2;
int register_supplier()
{
        if((new=(su*)calloc(1,sizeof(su)))==NULL)
        {
                printf("\nMemory Allocation failed\n");
                return EXIT_FAILURE;
        }

        while(1)
        {
                printf("Enter Supplier Name:  ");
                scanf("%s",new->supplier_name);
                if(validate_name(new->supplier_name))
                        continue;
                break;
        }
        while(1)
        {
                printf("Enter phoneno:  ");
                scanf("%lld", &new->mobile_no);
                if(validate_phoneno(new->mobile_no))
                        continue;
                break;
        }
        while(1)
        {
                printf("Enter Address: ");
                scanf("%s",new->supplier_address);
                if(validate_address(new->supplier_address))
                        continue;
                break;
        }

        while(1)
        {
                printf("Enter supplier id:  ");
                scanf("%d", &new->supplier_id);
                if(validate_id(new->supplier_id))
                        continue;
                break;
        }
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->supplier_id<start->supplier_id)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && new->supplier_id<ptr->supplier_id;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}


        return EXIT_SUCCESS;
}

int view_supplier()
{
        if(!start)
        {
                printf("\n Empty List\n");
                return EXIT_FAILURE;
        }

        printf("\nSUPPLIER ID.            NAME        PHONE NO.        ADDRESS  \n");
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                        printf("\n%d    %4s    %4lld  %3s  \n",ptr->supplier_id,ptr->supplier_name,ptr->mobile_no,ptr->supplier_address);

        }
        return EXIT_SUCCESS;
}
int  remove_supplier()
{
        if(!start)
        {
                printf("\nEmpty List\n");
                return EXIT_FAILURE;
        }
        int supplierid;
        while(1)
        {
                printf("\nEnter the supplier id for deleting-");
                scanf("%d",&supplierid);
                if(validate_id(supplierid))
                        continue;
                break;

        }
        if(supplierid==start->supplier_id)
        {
                ptr=start;
                start=start->next;
                free(ptr);
        }
        else
        {
                for(ptr=start;(ptr) && ptr->supplier_id!=supplierid;prev=ptr,ptr=ptr->next);
                if(!ptr)
                {
                        printf("\nsupplier id  %d is not found\n",supplierid);
                        return EXIT_FAILURE;
                }
                prev->next=ptr->next;
                free(ptr);
        }
        return EXIT_SUCCESS;
}

int edit_supplier()
{
        if(!start)
        {
                printf("\n Empty List\n");
                return EXIT_FAILURE;
        }
        int supplier_id;
        while(1)
        {
                printf("\nEnter supplier_id for editing: ");
                scanf("%d",&supplier_id);
                if(validate_id(supplier_id))
                        continue;
                break;
        }

        for(ptr=start;(ptr) && ptr->supplier_id!=supplier_id;ptr=ptr->next);
        if(!ptr)
        {
                printf("\nsupplier_id %d not found\n",supplier_id);
                return EXIT_FAILURE;
        }
        printf("Enter new name, new mobile_no and supplier_id \n");
        scanf("%s %lld %s",&ptr->supplier_name,&ptr->mobile_no,&ptr->supplier_address);

        return EXIT_SUCCESS;
}

int supplier_add_product()
{   
	int mid;
	printf("Enter the supplier id :\n ");
	scanf("%d",&mid);

	if(!start2)
	{
		printf("There are no available products\n");
		return EXIT_FAILURE;
	}
	printf("\nThe available products are -\n");
	view_product();
	int n=0,a;
	int s;
	int i;
	int x;
	while(n!=3)            
	{
		printf("Enter product ID to add products \nPress 2 to exit \n");
		scanf("%d",&s);
		if(validate_id(s))
		{
			continue;
		}		
		a=s;
		if(a==2)
		{
			break;
		}
		for(ptr2=start2;(ptr2) && ptr2->id!=a;ptr2=ptr2->next2);
		if(!ptr2)
		{
			printf("\nProduct ID not found\n");
			continue;
		}
		for(ptr=start;(ptr) && ptr->supplier_id!=mid;ptr=ptr->next);
		if(!ptr)
		{
			printf("\nSupplier ID %d not found\n",mid);
			return EXIT_FAILURE;
		}
		ptr->items_supplied[n]=a;
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
		ptr2->quantity=x+ptr2->quantity;
		if(ptr2->quantity > ptr2->rol)
		{
			ptr2->status_indicator='N';
		}
		printf("\nEnter product unit price -\n");
		scanf("%lf",&ptr2->unit_price);
		n++;
	}
}

int view_selected_products()
{            
	int mid;
	printf("Enter supplier id : ");
	scanf("%d",&mid);
	if(!start2)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr) && ptr->supplier_id!=mid;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nSupplier ID %d not found for viewing products\n",mid);
		return EXIT_FAILURE;
	}
	printf("\nPRODUCT ID   PRODUCT NAME    QUANTITY    UNIT PRICE\n");
	int f=0;
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		for(int i=0;i<3;i++)
		{
			if(ptr2->id==ptr->items_supplied[i])
			{
				printf("\n%3d-------%10s---------%3d---------%5.2lf\n",ptr2->id,ptr2->name,ptr2->quantity,ptr2->unit_price);
				f=1;
			}
		}
	}
	if(f==0)
	{
		printf("\nYou have not supplied any products\n");
	}
	printf("\n");
	return EXIT_SUCCESS;
}                                            

int supplier_file_to_list()
{

        FILE *sp;
        tmp1 s1;
        if((sp=fopen("supplier.data","rb"))==NULL)
        {
                printf("\nFile is not present to read from\n");
                return EXIT_FAILURE;
        }
        system("clear");
        fread(&s1,sizeof(tmp1),1,sp);
        while(!feof(sp))
        {
                if((new=(su *)calloc(1,sizeof(su)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
                new->supplier_id=s1.supplier_id;
                strcpy(new->supplier_name, s1.supplier_name);
                new->mobile_no=s1.mobile_no;
		strcpy(new->supplier_address,s1.supplier_address);
                if(!start)
                {
                        start = last = new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&s1,sizeof(tmp1),1,sp);
        }
        fclose(sp);
        return EXIT_SUCCESS;
}

int supplier_list_to_file()
{
        tmp1 s2;
        if(!start)
        {
                printf("\nThe List is Empty.\n");
                return EXIT_FAILURE;
        }
        FILE *sp1;
        if((sp1=fopen("supplier.data","wb"))==NULL)
        {
                printf("\nFile is not present to read \n");
                return EXIT_FAILURE;
        }
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                s2.supplier_id=ptr->supplier_id;
                strcpy(s2.supplier_name,ptr->supplier_name);
                s2.mobile_no=ptr->mobile_no;
                strcpy(s2.supplier_address,ptr->supplier_address);
                fwrite(&s2,sizeof(s2),1,sp1);
        }
        fclose(sp1);
        return EXIT_SUCCESS;
}


