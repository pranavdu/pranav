#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
    int age;
    char name[20];
    char address[20];
    char email[20];
    char mobile[20];
    char bloodgrp[20];
    char gender[10];
}donor;

int main()
{
   int flag,choice,shift,found,continu,length;
   char name[20];
   char mobile[20]
   FILE *fp;
   printf("\n\tC BLOOD BANK APPLICATION");
   Label1:
      printf("\n1 -> Store a new record in database\n");
      printf("2 -> Search a donor record by blood group\n");
      printf("3 -> Search a donor record by m0obile no.\n");
      printf("4 -> Quit Donor record");
      printf("\n\n");
      printf("Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
       case  1:
       Label2:
       printf("\nEnter Donor Details:\n\nAGE (Integer): ");
       scanf("%d",&donor.age);
       printf("\nName:");
       scanf("%s",donor.name);
       printf("\nAddress:");
       scanf("%s",donor.address);
       printf("\nEmail iD : ");
       scanf("%d",&donor.email);
       fp=fopen("donorfile.txt","");
       fprintf(fp,"\n%d\t%s\t%s\t%s\t%s\t%s\t%s",donor.age,donor.name,donor.address,donor.email,donor.mobile,donor.bloodgrp,donor.gender);
       fclose(fp);
       printf("A student record has been added successfully...\n");
       printf("\n\n1 -> Wish to add another record to database");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label2;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("Exiting.........");
	break;
	}

       case 2:
       Label4:
       printf("\nEnter donor first name: ");
       scanf("%s",&name);
       printf("Searching record with donor name=%s.\n",name);
	   found=0;
	   if((fp=fopen("donorfile.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fscanf(fp,"\n%d\t%s\t%s\t%d\t",&donor.age,donor.name,donor.address,&donor.email,&donor.mobile,&donor.bloodgrp,&donor.gender);
		length = strlen(donor.name);
		if(donor.name[length]==name[length])
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 printf("\nAge: %d\nName: %s\nAddress: %s\nEmailID: %s\nMobile:%s\nBlood group:%s\nGender:",donor.age,donor.name,donor.address,donor.email,donor.mobile,donor.bloodgrp,donor.gender);
       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label5:
       printf("\n\n1 -> Wish to search another record");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label4;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label5;
	}
       case 3:
       Label6:
       printf("\nEnter the mobilenumber: ");
       scanf("%d",&mobile);
       printf("Searching record with mobilenumber=%d.\n",mobile);
	   found=0;
	   if((fp=fopen("donorfile.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t",&donor.age,donor.name,donor.address,&donor.email,donor.mobile,donor.bloodgrp,donor.gender);
		if(donor.mobile==mobile)
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 printf("\nAge: %d\nName: %s\nAddress: %s\nemail id: %s\nmobile:%s\nblood group:%s\ngender:%s",donor.age,donor.name,donor.address,donor.email,donor.bloodgrp,donor.gender);
       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label7:
       printf("\n\n1 -> Wish to search more..");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label6;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label7;
	}
       case 4: break;
       default :
	  printf(" Bad choice...Enter the choice again...\n");
	  goto Label1;
	}

      getch();
      return 0;
}
