#include<stdio.h>
#include<stdlib.h>
#include "header.h"
int main()
{
        customer_file_to_list();
        supplier_file_to_list();
        product_file_to_list();
        //transaction_file_to_list();
        int ch=0;
        while(ch!=4)
        {
                printf("\n\t1.supplier corner\n\t2.customer corner\n\t3.admin corner\n\t4.Exit");
                printf("\nEnter your choice");
                scanf("%d",&ch);
                switch(ch)
                {
              
                        case 1:supplier_corner();
                               break;
                        case 2:customer_corner();
                               break;
			case 3:admin_corner();
			       break;
                        case 4: break;
                        default:
                               printf("\n Invalid choice\n");
                               continue;
                }
        }
        supplier_list_to_file();
        customer_list_to_file();
        product_list_to_file();
        //transaction_list_to_file();
        return EXIT_SUCCESS;
}

