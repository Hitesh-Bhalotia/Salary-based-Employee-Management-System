#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
          char name[20];
          char gender[20];
	  char empid[20];
          int age;
          char des[20];
          int wdays;
          int ohrs;
          float osal;
          float bsal;
          float da;
          float hra;
          float ca;
          float pf;
          float total;
          int recp;
};
void details(int n);
void display();
void search(char name[]);
void main()
{
    int n,ch;
    char name[30];
    while(1)
    {
     printf("---MENU---\n1.Add employee record\n2.Print employee payslip\n3.Print all payslips\n4.Exit\n");
     printf("Enter choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:printf("Enter the number of employees: ");
               scanf("%d", &n) ;
               details(n);
               break;
      case 2:printf("Enter name: ");
             scanf(" %[^\n]",name);
             search(name);
             break;
      case 3:display();
               break;
      case 4:exit(0);
               break;
      //case '\n':break;
      default:printf("Invalid choice entered\n");

     }
    }
}
void details(int n)
{
    struct employee emp;
    FILE *fptr;
    fptr = fopen("emp.txt", "a+") ;
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter name: ");
        scanf("%s",emp.name);
 	printf("Enter gender: ");
 	scanf("%s",emp.gender);
        printf("Enter employee id: ");
 	scanf("%s",emp.empid);
 	printf("Enter designation: ");
 	scanf("%s",emp.des);
 	printf("Enter age: ");
 	scanf("%d",&emp.age);
 	printf("Enter basic salary: ");
 	scanf("%f",&emp.bsal);
 	printf("Enter no. of working days: ");
 	scanf("%d",&emp.wdays);
 	printf("Enter overtime in hours: ");
 	scanf("%d",&emp.ohrs);
 	printf("Enter conveyance allowance: ");
 	scanf("%f",&emp.ca);
 	emp.da=0.1*emp.bsal;
 	emp.hra=0.12*emp.bsal;
 	emp.pf=0.05*emp.bsal;
 	emp.osal=0.004*emp.ohrs*emp.bsal;
 	emp.total=emp.bsal+emp.da+emp.hra+emp.pf+emp.osal;
        fprintf(fptr,"-----------------------------------------------------------------------------------------\n");
	fprintf(fptr,"Recp_num: %d   Emp id: %s   Name: %s   Age: %d   Gender: %s   Designation: %s\nNo. of days worked: %d        No.of overtime hours: %d\n",rand(),emp.empid,emp.name,emp.age,emp.gender,emp.des,emp.wdays,emp.ohrs);
 	//fprintf(fptr,"-----------------------------------------------------------------------------------------\n");
 	fprintf(fptr,"Basic Pay: Rs.%f      		DA: Rs.%f\nHRA: %f		      Overtime: %f\nTotal salary: %f\n",emp.bsal,emp.da,emp.hra,emp.osal,emp.total);
    fprintf(fptr,"-----------------------------------------------------------------------------------------\n");
    }
    fclose(fptr);
}
void display()
{
    char c;
    FILE *fptr;
    fptr = fopen("emp.txt", "r") ;
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}
void search(char name[])
{
    char temp[512],ch[1024],buffer[512],tempo[100];
    char stri = '-';
    int line_num=1,num_lines =4,linecount = 0 ,flag=0;
    FILE *fptr;
    fptr = fopen("emp.txt", "r+");
    while(fgets(temp, 512, fptr) != NULL)
    {

        if((strstr(temp, name)) != NULL)
        {
            flag =10;
            printf("A match found on line: %d\n%s", line_num-2,temp);
            char c = fgetc(fptr);
             while ( c != stri)
                {
                    printf ("%c", c);
                    c = fgetc(fptr);

                }
                break;
                fclose(fptr);
        }
        line_num++;
    }
    if(flag!=10){
        printf("Name not found\n");
        fclose(fptr);
        }
}
































