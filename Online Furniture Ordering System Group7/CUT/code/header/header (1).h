#ifndef HEADER_H
#define HEADER_H
#define MAX 50

typedef struct customer
{
        int customer_id;
        char customer_name[50];
        long long int cmobile_no;
        char customer_address[50];
	int items_ordered[3];
        struct customer *next1;
}cu;

typedef struct temp
{
        int customer_id;
        char customer_name[50];
        long long int cmobile_no;
        char customer_address[50];
	int items_ordered[3];
}tmp;

typedef struct supplier
{
        int supplier_id;
        char supplier_name[50];
        char supplier_address[50];
        long int mobile_no;
	int items_supplied[3];
        struct supplier *next;
}su;

typedef struct temp1
{
        int supplier_id;
        char supplier_name[100];
        char supplier_address[50];
        int items_supplied[3];
        long int mobile_no;
}tmp1;

typedef struct transaction
{
        int customer_id;
	int product_id;
        int product_quantity;
        char product_name[20];
	char customer_name[20];
        struct transaction *next3;
}tr;

typedef struct temp4
{
        int customer_id;
	int product_id;
	int product_quantity;
	char product_name[20];
	char customer_name[20];
}tmp3;

typedef struct product
{
                int id;
                char name[50];
		int rol;
                int quantity;
                double unit_price;
		char status_indicator;
                struct product *next2;

}pr;

typedef struct temp3
{
                int id;
                char name[50];
		int rol;
		int quantity;
		double unit_price;
		int status_indicator;
}tmp2;



//customer functionalities
int register_customer();
int view_customer();
int edit_customer();
int remove_customer();
int order_items();
int view_stock();

//supplier functionalities

int register_supplier();
int edit_supplier();
int view_supplier();
int remove_supplier();
int supplier_add_product();
int view_selected_products();

//product functionalities

int view_product();
int edit_product_details();
int add_product();
int delete_product();

int display_report();
int display_report_customer();
int display_report_item();

int supplier_corner();
int customer_corner();
int admin_corner();
int supplier_list_to_file();
int supplier_file_to_list();
int customer_list_to_file();
int customer_file_to_list();
int product_list_to_file();
int product_file_to_list();
int transaction_list_to_file();
int transaction_file_to_list();

int validate_name(char *);
int validate_id(int);
int validate_phoneno(long long int);
int validate_address(char *);
int validate_password(char *);



#endif

