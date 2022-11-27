#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
int maintain_product()
{

        int ch=0;
        while(ch!=5)
        {
               // system("read a");
                //system("clear");
                printf("\n1.Add product\n 2.Edit product\n 3.Remove product\n 4.View list of products\n 5.Back");
                printf("enter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                         case 1: add_product();
                                 break;
                         case 2:edit_product_details();
                                 break;
                         case 3:delete_product();
                                 break;
                         case 4: view_product();
                                 break;
                         case 5:
                                 break;
                         default:
                                 printf("\n Invalid choice\n");
                                 continue;
                }

        }
        return EXIT_SUCCESS;
}
int maintain_supplier()
{
        int ch1=0;
        while(ch1!=6)
        {
               // system("read a");
               // system("clear");
                printf("\n1.Edit Supplier\n 2.Remove Supplier\n 3.View Supplier List\n 4.supplier_add_product\n 5.view selected products\n 6.Exit\n");
                printf("\nenter choice-");
                scanf("%d",&ch1);
                switch(ch1)
                {
                        case 1:edit_supplier();
                               break;
                        case 2:remove_supplier();
                               break;
                        case 3:view_supplier();
                               break;
                        case 4:supplier_add_product();
                               break;
			case 5:view_selected_products();
			       break;
			case 6:
			       break;
                        default:
                               printf("\n Invalid choice\n");
                               continue;
                }

        }
        return EXIT_SUCCESS;
}
int maintain_customer()
{
        int ch2=0;
        while(ch2!=4)
        {
                //system("read a");
                //system("clear");
                printf("\n1.Edit Customer\n 2.Remove Customer\n 3.View list\n 4.Back");
                printf("\nenter choice-");
                scanf("%d",&ch2);
                switch(ch2)
                {
                     case 1: edit_customer();
                              break;
                     case 2: remove_customer();
                              break;
                     case 3: view_customer();
                              break;
                     case 4:
                              break;
                     default:
                            printf("\n Invalid choice\n");
                            continue;
                }

        }
        return EXIT_SUCCESS;
}
int admin_corner()
{
        int ch3=0;
        while(ch3!=7)
        {
               // system("read a");
                //system("clear");
                printf("\n1.Maintain Supplier\n 2.Maintain Customer\n 3.Maintain Product\n 4.Display report\n 5.display report items\n 6.display report customer\n 7.exit\n");
                printf("enter choice-");
                scanf("%d",&ch3);
                switch(ch3)
                {
                        case 1: maintain_supplier();
                                 break;
                        case 2: maintain_customer();
                                 break;
                        case 3: maintain_product();
                                 break;
			case 4: display_report();
				break;
			case 5: display_report_item();
				break;
			case 6: display_report_customer();
				break;
			case 7: break;
                        default:
                                printf("\nInvalid Choice\n");
                                continue;
                 }

        }
        return EXIT_SUCCESS;
}
int supplier_corner()
{
        int ch4=0;
        while(ch4!=3)
        {
               // system("read a");
                //system("clear");
                printf("\n1.Supplier Registration\n 2.maintain supplier\n 3.Back\n");
                printf("Enter choice-");
                scanf("%d",&ch4);
                switch(ch4)
                {
                        case 1: register_supplier();
                                 break;
                        case 2: maintain_supplier();
                                 break;
                        case 3:
                                 break;
                        default:
                               printf("\nInvalid choice\n");
                               continue;
                }

        }
        return EXIT_SUCCESS;
}
int customer_corner()
{
        int ch5=0;
        while(ch5!=5)
        {
                //system("read a");
                //system("clear");
                printf("\n1.Customer Registration\n 2.maintain customer\n 3.order item\n 4.view stock\n 5.View added products\n 6. Exit\n");
                printf("\nEnter choice-");
                scanf("%d",&ch5);
                {
                        switch(ch5)
                        {
				case 1 : register_customer();
					 break;
				case 2 : maintain_customer();
					 break;
				case 3 : order_items();
					 break;
				case 4 : view_stock();
					 break;
				case 5 : 
					 break;
				default :
					 printf("\n Invalid choice");
					 continue;
                        }
                        return EXIT_SUCCESS;
                }
        }
}

