#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 30

#define MAX_DATABASE_SIZE 100

/* Struct for all users. */
typedef struct User
{
	int user_id;
	
	char user_name[MAX_STRING_LENGTH];
	char first_name[MAX_STRING_LENGTH];
	char last_name[MAX_STRING_LENGTH];

	char email_id[MAX_STRING_LENGTH];
	char account_pasword[MAX_STRING_LENGTH];
	
	int age;
	long long mobile_number;
}User;

struct Database
{
	int current_database_size;
	struct User users[MAX_DATABASE_SIZE];
};

struct sign_up
{
    char f_name[15];
    char l_name[15];
    char user_name[25];
    int age;
    char email_id[39];
    char paswrd1[24];
    char paswrd2[24];
    long long int mob_no;
};

struct sign_up account[MAX_DATABASE_SIZE];

int digits(long long int i);
int name_validity(char *s);
int U_name_validity(char *u);
int email_validity(char *q);
int paswrd_validity(char *r);


void sign_up(struct Database *database);
int login_user(struct Database *database);

int orderbyhotel();
int orderbyfood(int a);

void rating();

int main()
{
	puts("\n************************************************************");
	puts("\n\t Welcome to the Food Ordering System!");
	puts("\n************************************************************");

	struct Database database;
	database.current_database_size = 0;
	
	//setting up admin user for testing.
	database.users[0].user_id = 0;
	
	strcpy(database.users[0].user_name, "Admin");
	strcpy(database.users[0].first_name, "Admin");
	strcpy(database.users[0].last_name, "Null");

	strcpy(database.users[0].email_id, "admin@gmail.com");
	strcpy(database.users[0].account_pasword, "Admin123");

	database.users[0].age = 100;
	database.users[0].mobile_number = 1000;

	database.current_database_size = 1;

	//start menu driven program
	int option = 0;
	char repeat = 'y';
	
	do
	{
		puts("\nTo use this application, you need an account.\n");
		puts("Press '1' to create a new account.");
		puts("Press '2' to sign in to an existing account.");

		printf("Enter option : ");
		scanf("%d", &option);

		while (option != 1 && option != 2)
		{
			printf("\nPlease enter valid option (1 or 2). \n");
			printf("Enter option : ");
			scanf("%d", &option);
		}

		if (option == 1)
		{
			sign_up(&database);
			login_user(&database);
		}
		else if (option == 2)
		{
			int result = login_user(&database);
			if (result == -1)
			{
				printf("\nExceeded max login attempts. Please Try again later.");
				printf("\nGoing back to the main menu now....\n");
				continue;
			}
		}

		option = 0;
		printf("\nPress 1 to order by food.\n");
		printf("Press 2 to order by hotel.\n");

		printf("\nEnter option : ");
		scanf("%d", &option);

		while (option != 1 && option != 2)
		{
			printf("\nPlease enter valid option (1 or 2). \n");
			printf("Enter option : ");
			scanf("%d", &option);
		}

		//stores order value
		int cost_price = 0;
		if (option == 1)
		{
			cost_price = orderbyfood(1);
		}
		else if (option == 2)
		{
			cost_price = orderbyhotel();
		}

		char place[10];

		printf("Do you want to place your order? Enter Yes/No\n"); 
		scanf("%s",place);

		if(strcmp(place,"Yes")==0||strcmp(place,"yes")==0)
		{
			printf("Your order has been sucessfully placed\n");
			
		}
		else 
		{
			printf("Re-shop for a better experience\n"); 
			printf("Thanks for visiting\n");
		}
        rating();
		printf("Thank you for using our services. Press 'y' or 'Y' to continue.\n");
		getchar();
		scanf("%c", &repeat);
	}
	while(repeat == 'y' || repeat == 'Y');

	printf("\nQuitting Application...........");
	return 0;
}


void rating()
{
	int rating;
	printf("How many points out of 5 do you want to rate us?\n"); 
	scanf("%d",&rating);

	if (rating==5) 
	printf("Thank you very much\n");

	else if (rating==4)
	printf("Thank you for your rating\n");

	else if (rating==3) 
	printf("We will try to improve our services\n");
	
	else if (rating==2) 
	printf("Please excuse us\n");

	else
	printf("Sorry for your inconvenience!\n");

	printf("Thanks for visiting!!!\n");
}

void sign_up(struct Database *database)
{
	int a,acc_no=0;
    a = 1;

    while (a==1)
    {
        printf(".............SIGNUP.............\n");
        printf("Enter the following details : \n");


        printf("First name (ALPHABETS ONLY) : ");
        scanf("%s",account[acc_no].f_name);
        while (name_validity(account[acc_no].f_name)==1) //makes sure only alphabets are entered
        {
            printf("Invalid First Name.\nRe-enter the name\n");
            printf("First name (ALPHABETS ONLY) : ");
            scanf("%s",account[acc_no].f_name);
        }


        printf("Last name (ALPHABETS ONLY): ");
        scanf("%s",account[acc_no].l_name);
         while (name_validity(account[acc_no].l_name)==1) //makes sure only alphabets are entered
        {
            printf("Invalid Last Name.\nRe-enter the name\n");
            printf("Last name (ALPHABETS ONLY) : ");
            scanf("%s",account[acc_no].l_name);
        }


        printf("User name (without any spaces!!!): ");
        
        int flag_4=0;
        //different accounts cannot have same user name
        do
        {
            flag_4=0;
            scanf("%s",account[acc_no].user_name);
            while (U_name_validity(account[acc_no].user_name)==1)
        {
            printf("Invalid User Name.\nRe-enter the User-name\n");
            printf("User name (ALPHABETS and DIGITS and '@' or '_' with length greater than or equal to 8) : ");
            scanf("%s",account[acc_no].user_name);
        }
            for (int k = 0; k < acc_no; k++)
            {
                if (strcmp(account[acc_no].user_name,account[k].user_name)==0)
                {
                    flag_4=1;
                }
                
            }
            
            if (flag_4==1)
            {
                printf("User name already taken.Please re-enter : ");
            }

            
        } while (flag_4==1);
        

        printf("Age : ");
        scanf("%d",&account[acc_no].age);
        while (account[acc_no].age<10||account[acc_no].age>100)
        {
            printf("You are not eligible for creating account.\nRe-enter the age\n");
            printf("Age : ");
            scanf("%d",&account[acc_no].age);
        }


        printf("Email Id (xxxxxx@gmail.com) : ");
        scanf("%s",account[acc_no].email_id);
        while (email_validity(account[acc_no].email_id)==1)
        {
            printf("Invalid Email-Id.\nRe-enter the Email-Id\n");
            printf("Email Id ( \"xxxxxx@gmail.com\" and length >=15 ) : ");
            scanf("%s",account[acc_no].email_id);
        }
        

        printf("Enter a password (with length 8-13 characters) : ");
        scanf("%s",account[acc_no].paswrd1);
         while (paswrd_validity(account[acc_no].paswrd1)==1)
        {
            printf("Invalid password entry.\nEnter another password\n");
            printf("Pasword (length 8-13 with atleast one Uppercase and one Lowercase and a digit and a special character) : ");
            scanf("%s",account[acc_no].paswrd1);
        }

        printf("Confirm the password : ");
        scanf("%s",account[acc_no].paswrd2);
        while (strcmp(account[acc_no].paswrd2,account[acc_no].paswrd1)!=0)
        {
            printf("The first entered and second entered passwords doesnot match.\nRe-confirm the password : ");
            scanf("%s",account[acc_no].paswrd2);
        }
        


        printf("Enter your mobile number : ");
        scanf("%lld",&account[acc_no].mob_no);
        while (digits(account[acc_no].mob_no)!=10)
        {
            printf("Invalid Mobile number.\nRe-enter ypur mobile number\n");
            printf("Enter your mobile number : ");
            scanf("%lld",&account[acc_no].mob_no);
        }

        printf("\nAccount is created sucessfully:)\n\n");

		//copy details to database.

		int current_user_id = database->current_database_size;
		database->users[current_user_id].user_id = current_user_id;
		strcpy(database->users[current_user_id].user_name, account[acc_no].user_name);
		strcpy(database->users[current_user_id].first_name, account[acc_no].f_name);
		strcpy(database->users[current_user_id].last_name, account[acc_no].l_name);
		strcpy(database->users[current_user_id].email_id, account[acc_no].email_id);
		strcpy(database->users[current_user_id].account_pasword, account[acc_no].paswrd1);
		database->users[current_user_id].mobile_number = account[acc_no].mob_no;
		database->users[current_user_id].age = account[acc_no].age;

		database->current_database_size++;
        
		printf("Enter \"1\" to CREATE ANOTHE ACCOUNT and \"2\" to proceed to LOGIN : ");
        scanf("%d",&a);
        acc_no++;
    }
}

int name_validity(char *s){
    int i=0,flag=0;
        while (i<(strlen(s)))
        {
            if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
            {flag=1;}
            i++;
        }
        return flag;
}

int U_name_validity(char *u){
    int c=0,flag_1=0;
    while(c<strlen(u)){
        if(!((u[c]>='a'&&u[c]<='z')||(u[c]>='A'&&u[c]<='Z')||u[c]=='0'||u[c]=='1'||u[c]=='2'||u[c]=='3'||u[c]=='4'||u[c]=='5'||u[c]=='6'||u[c]=='7'||u[c]=='8'||u[c]=='9'||u[c]=='_'||u[c]=='@')){
            flag_1=1;
        }
        c++;
    }
    if(strlen(u)<8){
        flag_1=1;
    }
    return flag_1;
}

int email_validity(char *q){
    int flag_2=0;
    if(strlen(q)>=15){
    if (!(q[strlen(q)-10]=='@'&&q[strlen(q)-9]=='g'&&q[strlen(q)-8]=='m'&&q[strlen(q)-7]=='a'&&q[strlen(q)-6]=='i'&&q[strlen(q)-5]=='l'&&q[strlen(q)-4]=='.'&&q[strlen(q)-3]=='c'&&q[strlen(q)-2]=='o'&&q[strlen(q)-1]=='m'))
    {flag_2=1;}}
    else{
        flag_2=1;
    }
    return flag_2;
}

int paswrd_validity(char *r){
    int e,flag_3=1;
    if(strlen(r)<8){
        return 1;
    }
    for(e=0;e<strlen(r);e++){
        if(r[e]>='A'&&r[e]<='Z'){
            flag_3=0;break;
        }
    }
    if(flag_3==1){return flag_3;}
    flag_3=1;
    
    for(e=0;e<strlen(r);e++){
        if(r[e]>='a'&&r[e]<='z'){
            flag_3=0;break;
        }
    }
    if(flag_3==1){return flag_3;}
    flag_3=1;
    for(e=0;e<strlen(r);e++){
        if(r[e]=='0'||r[e]=='1'||r[e]=='2'||r[e]=='3'||r[e]=='4'||r[e]=='5'||r[e]=='6'||r[e]=='7'||r[e]=='8'||r[e]=='9'){
            flag_3=0;break;
        }
    }
    if(flag_3==1){return flag_3;}
    flag_3=1;
     for(e=0;e<strlen(r);e++){
        if(r[e]=='_'||r[e]=='@'||r[e]=='!'||r[e]=='&'||r[e]=='*'||r[e]=='.'){
            flag_3=0;break;
        }
    }
    if(flag_3==1){return flag_3;}
    
    return flag_3;
}

int digits(long long int i){
    int digit=0;
    while(i!=0){
        i=i/10;
        digit++;
    }
    return digit;
}

int login_user(struct Database *database)
{
	char user_name[MAX_STRING_LENGTH];
	char password[MAX_STRING_LENGTH];

	printf("\nEnter your user name : ");
	scanf("%s", user_name);

	const int MAX_LOGIN_ATTEMPTS = 5;
	int current_login_attempt = 0;

	int current_user_id = -1;
	
	do
	{
		//check if email is matching some user name in database.
		for (int i = 0; i < database->current_database_size; i++)
		{
			if (strcmp(database->users[i].user_name, user_name) == 0)
			{
				current_user_id = database->users[i].user_id;
			}
		}

		if (current_user_id == -1)
		{
			printf("\nCould not find any user with this user name. Try again.\n");
			printf("Enter your user name  id : ");
			scanf("%s", user_name);
		}

		current_login_attempt++;
		if (current_login_attempt > MAX_LOGIN_ATTEMPTS)
		{
			return -1;
		}
	}
	while (current_user_id == -1);

	current_login_attempt = 0;

	printf("\nEnter your password : ");
	scanf("%s", password);

	int password_match = 0;
	do
	{
		if (strcmp(database->users[current_user_id].account_pasword, password) == 0)
		{
			password_match = 1;
		}
		else
		{
			printf("\nYou entered an invalid password. Please try again.\n");
			printf("Enter your password : ");
			scanf("%s", password);
		}

		current_login_attempt++;
		if (current_login_attempt > MAX_LOGIN_ATTEMPTS)
		{
			return -1;
		}
	}	
	while(password_match == 0);

	printf("\nSuccessfully logged into the system.\n");
	
	return 1;
}


int orderbyhotel()
{
    int ch,innerch;
    int costprice=0;
    char cont[MAX_STRING_LENGTH];
    printf("\n");
    
    do{
        printf("Welcome to order by Hotel feature!\n");
        printf("Enter your choice of hotel and we will list out the different dishes that are served by the restaurant.\n"); 
        printf("Available Choices:\n");
        printf("1.Hotel Annapurna\n2.Hotel Niroopama\n3.That's Y Food\n4.McDonalds\n5.Crazy Burgers,Pizzas and more\n");
        printf("6.Pizza Hut\n7.Little Italy\n8.Hotel Sree Krishna Pure Veg\n9.Kimling Chinese\n10.Mainland China\n");
        printf("--------------------------------------------------------------------------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        printf("The different dishes served by this restauarant are:\n");
        if(ch==1)
        {
            printf("1.Paneer Malai Tikka");
            printf("\n2.Veg Biriyani");
            printf("\n3.Butter Chicken");
            printf("\n4.Gulab Jamun");
            printf("\n5.Masala Dosa");
            printf("\n6.Parotta Kurma");
            printf("\n7.Chocolate Cake");
            printf("\n8.Vanilla Ice Cream");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
            if(innerch==1)
            {
                printf("\nHotel Annapurna\n");
                printf("Paneer Malai Tikka\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==2)
            {
                printf("\nHotel Annapurna\n");
                printf("Veg Biriyani\n");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==3)
            {
                printf("\nHotel Annapurna\n");
                printf("Butter Chicken\n");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==4)
            {
                printf("\nHotel Annapurna\n");
                printf("Gulab Jamun\n");
                printf("Cost:Rs 40");
                costprice=costprice+40;
            }
            if(innerch==5)
            {
                printf("\nHotel Annapurna\n");
                printf("Masala Dosa\n");
                printf("Cost:Rs 90");
                costprice=costprice+90;
            }
            if(innerch==6)
            {
                printf("\nHotel Annapurna\n");
                printf("Parotta Kurma\n");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==7)
            {
                printf("\nHotel Annapurna\n");
                printf("Chocolate Cake\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==8)
            {
                printf("\nHotel Annapurna\n");
                printf("Vanilla Ice Cream\n");
                printf("Cost:Rs 70");
                costprice=costprice+70;
            }
        }
        else if(ch==2)
        {
            printf("1.Paneer Malai Tikka");
            printf("\n2.Veg Biriyani");
            printf("\n3.Butter Chicken");
            printf("\n4.Gulab Jamun");
            printf("\n5.Idly Sambar");
            printf("\n6.Jigarthanda");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
            if(innerch==1)
            {
                printf("\nHotel Niroopama\n");
                printf("Paneer Malai Tikka\n");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==2)
            {
                printf("\nHotel Niroopama\n");
                printf("Veg Biriyani\n");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
            if(innerch==3)
            {
                printf("\nHotel Niroopama\n");
                printf("Butter Chicken\n");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
            if(innerch==4)
            {
                printf("\nHotel Niroopama\n");
                printf("Gulab Jamun\n");
                printf("Cost:Rs 40");
                costprice=costprice+40;
            }
            if(innerch==5)
            {
                printf("\nHotel Niroopama\n");
                printf("Idly Sambar\n");
                printf("Cost:Rs 60");
                costprice=costprice+60;
            }
            if(innerch==6)
            {
                printf("\nHotel Niroopama\n");
                printf("Jigarthanda\n");
                printf("Cost:Rs 80");
                costprice=costprice+80;
            }
        }
        else if(ch==3)
        {
            printf("1.Paneer Malai Tikka");
            printf("\n2.Veg Biriyani");
            printf("\n3.Butter Chicken");
            printf("\n4.Gulab Jamun");
            printf("\n5.Chocolate Cake");
            printf("\n6.Vanilla Ice Cream");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
            if(innerch==1)
            {
                printf("\nThat's Y Food\n");
                printf("Paneer Malai Tikka\n");
                printf("Cost:Rs 150");
                costprice=costprice+150;
            }
            if(innerch==2)
            {
                printf("\nThat's Y Food\n");
                printf("Veg Biriyani\n");
                printf("Cost:Rs 220");
                costprice=costprice+220;
            }
            if(innerch==3)
            {
                printf("\nThat's Y Food\n");
                printf("Butter Chicken\n");
                printf("Cost:Rs 220");
                costprice=costprice+220;
            }
            if(innerch==4)
            {
                printf("\nThat's Y Food\n");
                printf("Gulab Jamun\n");
                printf("Cost:Rs 40");
                costprice=costprice+40;
            }
            if(innerch==5)
            {
                printf("\nThat's Y Food\n");
                printf("Chocolate Cake\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==6)
            {
                printf("\nThat's Y Food\n");
                printf("Vanilla Ice Cream\n");
                printf("Cost:Rs 70");
                costprice=costprice+70;
            }
        }
        else if(ch==4)
        {
            printf("1.Veg Burger Combo");
            printf("\n2.Chicken Burger Combo");
            printf("\n3.French Fries");
            printf("\n4.Coke");
            printf("\n5.Chicken Wrap");
            printf("\n6.Veg Wrap");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
            if(innerch==1)
            {
                printf("\nMcDonalds\n");
                printf("Veg Burger Combo\n");
                printf("Cost:Rs 160");
                costprice=costprice+160;
            }
            if(innerch==2)
            {
                printf("\nMcDonalds\n");
                printf("Chicken Burger Combo\n");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==3)
            {
                printf("\nMcDonalds\n");
                printf("French Fries\n");
                printf("Cost:Rs 90");
                costprice=costprice+90;
            }
            if(innerch==1)
            {
                printf("\nMcDonalds\n");
                printf("Coke\n");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==1)
            {
                printf("\nMcDonalds\n");
                printf("Chicken Wrap\n");
                printf("Cost:Rs 140");
                costprice=costprice+140;
            }
            if(innerch==1)
            {
                printf("\nMcDonalds\n");
                printf("Veg Wrap\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
        }
        else if(ch==5)
        {
            printf("1.Veg Burger Combo");
            printf("\n2.Chicken Burger Combo");
            printf("\n3.Veg Pizza");
            printf("\n4.Meat Lover's Pizza");
            printf("\n5.Chicken Pasta");
            printf("\n6.Veg Pasta");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
            if(innerch==1)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Veg Burger Combo\n");
                printf("Cost:Rs 140");
                costprice=costprice+140;
            }
            if(innerch==2)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Chicken Burger Combo\n");
                printf("Cost:Rs 170");
                costprice=costprice+170;
            }
            if(innerch==3)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Veg Pizza\n");
                printf("Cost:Rs 140");
                costprice=costprice+140;
            }
            if(innerch==4)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Meat Lover's Pizza\n");
                printf("Cost:Rs 170");
                costprice=costprice+170;
            }
            if(innerch==5)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Chicken Pasta\n");
                printf("Cost:Rs 160");
                costprice=costprice+160;
            }
            if(innerch==6)
            {
                printf("\nCrazy Burgers,Pizzas and more\n");
                printf("Veg Pasta\n");
                printf("Cost:Rs 140");
                costprice=costprice+140;
            }
        }
        else if(ch==6)
        {
            printf("1.Veg Pizza");
            printf("\n2.Meat Lover's Pizza");
            printf("\n3.Special Chicken Pizza");
            printf("\n4.Special Veg Pizza");
            printf("\n5.Garlic Bread");
            printf("\n6.Coke");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
             if(innerch==1)
            {
                printf("\nPizza Hut\n");
                printf("Veg Pizza\n");
                printf("Cost:Rs 160");
                costprice=costprice+160;
            }
            if(innerch==2)
            {
                printf("\nPizza Hut\n");
                printf("Meat Lover's Pizza\n");
                printf("Cost:Rs 190");
                costprice=costprice+190;
            }
             if(innerch==3)
            {
                printf("\nPizza Hut\n");
                printf("Special Chicken Pizza\n");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==4)
            {
                printf("\nPizza Hut\n");
                printf("Special Veg Pizza\n");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
             if(innerch==5)
            {
                printf("\nPizza Hut\n");
                printf("Garlic Bread\n");
                printf("Cost:Rs 60");
                costprice=costprice+60;
            }
            if(innerch==6)
            {
                printf("\nPizza Hut\n");
                printf("Coke\n");
                printf("Cost:Rs 90");
                costprice=costprice+90;
            }
        }
        else if(ch==7)
        {
            printf("1.Veg Pizza");
            printf("\n2.Meat Lover's Pizza");
            printf("\n3.Special Chicken Pizza");
            printf("\n4.Special Veg Pizza");
            printf("\n5.Veg Pasta");
            printf("\n6.Chicken Pasta");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
             if(innerch==1)
            {
                printf("\nLittle Italy\n");
                printf("Veg Pizza\n");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==2)
            {
                printf("\nLittle Italy\n");
                printf("Meat Lover's Pizza\n");
                printf("Cost:Rs 220");
                costprice=costprice+220;
            }
            if(innerch==3)
            {
                printf("\nLittle Italy\n");
                printf("Special Chicken Pizza\n");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
            if(innerch==4)
            {
                printf("\nLittle Italy\n");
                printf("Special Veg Pizza\n");
                printf("Cost:Rs 160");
                costprice=costprice+160;
            }
            if(innerch==5)
            {
                printf("\nLittle Italy\n");
                printf("Veg Pasta\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==6)
            {
                printf("\nLittle Italy\n");
                printf("Chicken Pasta\n");
                printf("Cost:Rs 140");
                costprice=costprice+140;
            }
        }
        else if(ch==8)
        {
            printf("1.Masala Dosa");
            printf("\n2.Parotta Kurma");
            printf("\n3.Chocolate Cake");
            printf("\n4.Vanilla Ice Cream");
            printf("\n5.Idly Sambar");
            printf("\n6.Filter Coffee");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
             if(innerch==1)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Masala Dosa\n");
                printf("Cost:Rs 70");
                costprice=costprice+70;
            }
            if(innerch==2)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Parotta Kurma\n");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==3)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Chocolate Cake\n");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==4)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Vanilla Ice Cream\n");
                printf("Cost:Rs 70");
                costprice=costprice+70;
            }
            if(innerch==5)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Idly Sambar\n");
                printf("Cost:Rs 50");
                costprice=costprice+50;
            }
            if(innerch==6)
            {
                printf("\nHotel Sree Krishna Pure Veg\n");
                printf("Filter Coffee\n");
                printf("Cost:Rs 40");
                costprice=costprice+40;
            }
        }
        else if(ch==9)
        {
            printf("1.Veg Manchurian Hakka Noodle Combo");
            printf("\n2.Chilli Chicken");
            printf("\n3.Dim Sum");
            printf("\n4.Chicken Manchurian Hakka Noodle Combo");
            printf("\n5.Veg fried rice");
            printf("\n6.Cheicken Fried rice");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
             if(innerch==1)
            {
                printf("\nKimling Chinese\n");
                printf("\nVeg Manchurian Hakka Noodle Combo");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
            if(innerch==2)
            {
                printf("\nKimling Chinese\n");
                printf("\nChilli Chicken");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
            if(innerch==3)
            {
                printf("\nKimling Chinese\n");
                printf("\nDim Sum");
                printf("Cost:Rs 90");
                costprice=costprice+90;
            }
            if(innerch==4)
            {
                printf("\nKimling Chinese\n");
                printf("\nChicken Manchurian Hakka Noodle Combo");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==5)
            {
                printf("\nKimling Chinese\n");
                printf("\nVeg Fried Rice");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==6)
            {
                printf("\nKimling Chinese\n");
                printf("\nChicken Fried Rice");
                printf("Cost:Rs 120");
                costprice=costprice+120;
            }
        }
        else if(ch==10)
        {
            printf("1.Veg Manchurian Hakka Noodle Combo");
            printf("\n2.Chilli Chicken");
            printf("\n3.Dim Sum");
            printf("\n4.Chicken Manchurian Hakka Noodle Combo");
            printf("\n5.Veg fried rice");
            printf("\n6.Cheicken Fried rice");
            printf("\nEnter a dish of your preference");
            scanf("%d",&innerch);
             if(innerch==1)
            {
                printf("\nMainland China\n");
                printf("\nVeg Manchurian Hakka Noodle Combo");
                printf("Cost:Rs 200");
                costprice=costprice+200;
            }
            if(innerch==2)
            {
                printf("\nMainland China\n");
                printf("\nChilli Chicken");
                printf("Cost:Rs 160");
                costprice=costprice+160;
            }
            if(innerch==3)
            {
                printf("\nKimling China\n");
                printf("\nDim Sum");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==4)
            {
                printf("\nmainaland China\n");
                printf("\nChicken Manchurian Hakka Noodle Combo");
                printf("Cost:Rs 180");
                costprice=costprice+180;
            }
            if(innerch==5)
            {
                printf("\nMainland China\n");
                printf("\nVeg Fried Rice");
                printf("Cost:Rs 100");
                costprice=costprice+100;
            }
            if(innerch==6)
            {
                printf("\nMainland China\n");
                printf("\nChicken Fried Rice");
                printf("Cost:Rs 110");
                costprice=costprice+110;
            }
        }
        else 
        {
            printf("\nWrong Choice\n");
        }

        printf("Do you want to change your order? Enter Yes/No\n"); 
		getchar();
		fgets(cont,sizeof(MAX_STRING_LENGTH),stdin); 
	} 
	while ((strcmp(cont, "Yes") == 0) || (strcmp(cont, "yes") == 0)); 
	return costprice;

}


int orderbyfood(int a)
{

	int choice, rest; 
	int costprice=0; 
	char cont[MAX_STRING_LENGTH]; 

	printf("\n");

	do 
	{ 	
		printf("Welcome to Order by Food feature!\n"); 
		printf("Enter a choice of food items and we will list out the restaurants that deliver the particular food item.\n"); 
		printf("Available choices:\n"); 
		printf("1. Paneer Malai Tikka\n"); 
		printf("2. Veg Pizza\n"); 
		printf("3. Veg Burger Combo\n"); 
		printf("4. Veg Manchurian Hakka Noodles Combo\n"); 
		printf("5. Masala Dosa\n"); 
		printf("6. Parotta Korma\n"); 
		printf("7. Veg Biryani\n"); 
		printf("8. Butter Chicken\n"); 
		printf("9. Meat Lovers Pizza\n"); 
		printf("10. Chicken Burger Combo\n"); 
		printf("11. Gulab Jamun\n"); 
		printf("12. Chocolate Cake\n"); 
		printf("13. Vanilla Ice Cream\n"); 
		printf("\nEnter option : ");
		scanf("%d",&choice); 
		printf("Here are the restaurants that deliver this food item:\n"); 
		printf("Choose from the following:\n"); 
		if (choice==1||choice==7||choice==8||choice==11) 
		{ 
		    printf("1. Hotel Annapurna\n"); 
		    printf("2. Hotel Niroopama\n"); 
		    printf("3. That’s Y Food\n"); 
		    scanf("%d",&rest); 
		    if(choice==1) 
		    { 
		        if (rest==1) 
		        { 
		        printf("Hotel Annapurna\n"); 
		        printf("Paneer Malai Tikka: Rs 120\n"); 
		        costprice=costprice+120; 
		        } 
		        else if (rest==2) 
		        { 
		        printf("Hotel Niroopama\n"); 
		        printf("Paneer Malai Tikka: Rs 100\n"); 
		        costprice=costprice+100; 
		        } 
		        else if (rest==3) 
		        { 
		        printf("That's Y Food\n"); 
		        printf("Paneer Malai Tikka: Rs 150\n"); 
		        costprice=costprice+150; 
		        } 
		    }

		    else if(choice==7) 
		    { 
		        if (rest==1) 
		        { 
		        printf("Hotel Annapurna\n"); 
		        printf("Veg Biryani: Rs 200\n"); 
		        costprice=costprice+200; 
		        } 
		        else if (rest==2) 
		        { 
		        printf("Hotel Niroopama\n"); 
		        printf("Veg Biryani: Rs 180\n"); 
		        costprice=costprice+180; 
		        } 
		        else if (rest==3) 
		        { 
		        printf("That's Y Food\n"); 
		        printf("Veg Biryani: Rs 220\n"); 
		        costprice=costprice+220; 
		        } 
		    } 

		    else if (choice==8) 
		    { 
		        if(rest==1) 
		        { 
		        printf("Hotel Annapurna\n"); 
		        printf("Butter Chicken: Rs 200\n"); 
		        costprice=costprice+200; 
		        } 
		        else if (rest==2) 
		        { 
		        printf("Hotel Niroopama\n"); 
		        printf("Butter Chicken: Rs 180\n"); 
		        costprice=costprice+180; 
		        } 
		        else if (rest==3) 
		        { 
		        printf("That's Y Food\n"); 
		        printf("Butter Chicken: Rs 220\n"); 
		        costprice=costprice+220; 
		        } 
		    } 
            
		    else if (choice==11) 
		    { 
		        if(rest==1) 
		        printf("Hotel Annapurna\n"); 
		        else if (rest==2) 
		        printf("Hotel Niroopama\n"); 
		        else if (rest==3) 
		        printf("That's Y Food\n"); 
		        printf("Gulab Jamun: Rs 40\n"); 
		        costprice=costprice+40; 
		    } 
		}

		else if (choice==3||choice==10) 
		{ 
		printf("1. Crazy Burgers, Pizzas and More\n"); 
		printf("2. McDonald's\n"); 
		scanf("%d",&rest); 
		if(choice==3) 
		{ 
		if (rest==1) 
		{ 
		printf("Crazy Burgers, Pizzas and More\n"); 
		printf("Veg Burger Combo: Rs 140\n"); 
		costprice=costprice+140; 
		} 
		else if (rest==2) 
		{ 
		printf("McDonald's\n"); 
		printf("Veg Burger Combo: Rs 160\n"); 
		costprice=costprice+160; 
		} 
		} 
		else if(choice==10) 
		{ 
		if (rest==1) 
		{ 
		printf("Crazy Burgers, Pizzas and More\n"); 
		printf("Chicken Burger Combo: Rs 170\n"); 
		costprice=costprice+170; 
		} 
		else if (rest==2) 
		{ 
		printf("McDonald's\n"); 
		printf("Chicken Burger Combo: Rs 200\n"); 
		costprice=costprice+200; 
		} 
		} 
		} 
		else if (choice==2||choice==9) 
		{ 
		printf("1. Crazy Burgers, Pizzas and More\n"); 
		printf("2. Pizza Hut\n"); 
		printf("3. Little Italy\n"); 
		scanf("%d",&rest); 
		if (choice==2) 
		{ 
		if (rest==1) 
		{ 
		printf("Crazy Burgers, Pizzas and More\n"); 
		printf("Veg Pizza: Rs 140\n"); 
		costprice=costprice+140; 
		} 
		else if (rest==2) 
		{ 
		printf("Pizza Hut\n"); 
		printf("Veg Pizza: Rs 160\n"); 
		costprice=costprice+160; 
		} 
		else if (rest==3) 
		{ 
		printf("Little Italy\n"); 
		printf("Veg Pizza: Rs 200\n"); 
		costprice=costprice+200; 
		} 
		} 
		else if (choice==9) 
		{ 
		if (rest==1) 
		{ 
		printf("Crazy Burgers, Pizzas and More\n"); 
		printf("Meat Lovers Pizza: Rs 170\n"); 
		costprice=costprice+170; 
		} 
		else if (rest==2) 
		{ 
		printf("Pizza Hut\n"); 
		printf("Meat Lovers Pizza: Rs 190\n"); 
		costprice=costprice+190; 
		} 
		else if (rest==3) 
		{ 
		printf("Little Italy\n"); 
		printf("Meat Lovers Pizza: Rs 220\n"); 
		costprice=costprice+220; 
		} 
		} 
		} 
		else if (choice==5||choice==6) 
		{ 
		printf("1. Hotel Annapurna\n"); 
		printf("2. Hotel Sree Krishna Pure Veg\n"); 
		scanf("%d",&rest); 
		if (choice==5) 
		{ 
		if (rest==1) 
		{ 
		printf("Hotel Annapurna\n"); 
		printf("Masala Dosa: Rs 90\n"); 
		costprice=costprice+90; 
		} 
		else if (rest==2) 
		{ 
		printf("Hotel Sree Krishna Pure Veg\n"); 
		printf("Masala Dosa: Rs 70\n"); 
		costprice=costprice+70; 
		} 
		} 
		else if (choice==6) 
		{ 
		if (rest==1) 
		{ 
		printf("Hotel Annapurna\n"); 
		printf("Parotta Korma: Rs 100\n"); 
		costprice=costprice+100; 
		} 
		else if (rest==2) 
		{ 
		printf("Hotel Sree Krishna Pure Veg\n"); 
		printf("Parotta Korma: Rs 120\n"); 
		costprice=costprice+120; 
		} 
		}
        }
        
        else if (choice==4) 
		{ 
		printf("1. Kimling Chinese\n"); 
		printf("2. Mainland China\n"); 
		scanf("%d",&rest); 
		if (rest==1) 
		{ 
		printf("Kimling Chinese\n"); 
		printf("Veg Manchurian Hakka Noodles Combo:Rs 150\n"); 
		costprice=costprice+150; 
		} 
		else if (rest==2) 
		{ 
		printf("Mainland China\n"); 
		printf("Veg Manchurian Hakka Noodles Combo:Rs 200\n"); 
		costprice=costprice+200; 
		} 
		} 
		
		else if (choice==12||choice==13) 
		{ 
		printf("1. Hotel Annapurna\n"); 
		printf("2. Hotel Sree Krishna Pure Veg\n"); 
		printf("3. That's Y Food\n"); 
		scanf("%d",&rest); 
		if (choice==12) 
		{ 
		if (rest==1) 
		{ 
		printf("Hotel Annapurna\n"); 
		printf("Chocolate Cake:Rs 120\n"); 
		costprice=costprice+120; 
		} 
		else if (rest==2) 
		{ 
		printf("Hotel Sree Krishna Pure Veg\n"); 
		printf("Chocolate Cake:Rs 100\n"); 
		costprice=costprice+100; 
		} 
		else if (rest==3) 
		{ 
		printf("That's Y Food\n"); 
		printf("Chocolate Cake:Rs 120\n"); 
		costprice=costprice+120; 
		} 
		} 
		else if (choice==13) 
		{ 
		if (rest==1) 
		{ 
		printf("Hotel Annapurna\n"); 
		printf("Vanilla Ice Cream:Rs 70\n"); 
		costprice=costprice+70; 
		} 
		else if (rest==2) 
		{ 
		printf("Hotel Sree Krishna Pure Veg\n"); 
		printf("Vanilla Ice Cream:Rs 70\n"); 
		costprice=costprice+70; 
		} 
		else if (rest==3) 
		{ 
		printf("That's Y Food\n"); 
		printf("Vanilla Ice Cream:Rs 90\n"); 
		costprice=costprice+70; 
		} 
		} 
		} 
		
		else 
        {
		    printf("Wrong Choice!\n"); 
        }
        printf("Do you want to change your order? Enter Yes/No\n"); 
		getchar();
		fgets(cont,sizeof(MAX_STRING_LENGTH),stdin); 
	} 
	while ((strcmp(cont, "Yes") == 0) || (strcmp(cont, "yes") == 0)); 
	return costprice;
}