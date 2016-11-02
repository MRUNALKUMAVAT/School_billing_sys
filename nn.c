#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include"SDL.h"
//#include"SDL/SDL_ttf.h"
void start();
void addrec(int j);
void searchrec(int j);
void modrec(int j);
void fee(int mm);
int chkdat(int mnt,int dnt);
int clscanf();
FILE *fs,*ft;//file declaration
int mm,dd;//mm=month, dd=day
struct date//for date(month and day
	{
    	int d,m;//d=day,m=month
	};
struct student
	{
   	 struct date dt;
    	float f,fine,tot,adv,due;//f=fee
    	char n[50];
    	int r,c;//roll and class
	} s;
struct teacher
	{
    	struct date dt;

    	char n[50];

    	float sal,adv,tot;

    	int id,no;
	} t;
void main()
{
    int i,j,k;
    for(i=0; i<80; i++)
    	{
       		 printf("\xdb");
    	}
    		printf("\n");
    for(i=0; i<80; i++)
    	{
       		 printf("\xdb");
        }
            system("color black");
	    printf(" \t_______________________________________________________\n");
	    printf("\t|                                                      |\n");
	    printf("\t** SCHOOL BILLING SYSTEM **\n");
	    printf("\n\t|                                                      |\n");
	    printf("\t ______________________________________________________\n");
	    printf(" \t________________________________________________________\n");
	    printf("\t|    *****************************************            |\n");
	    printf("\t|    *****************************************            |\n");
	    printf(" \t_______________________________________________________\n");
	    printf("\n\tPLEASE ENTER ANY KEY TO CONTINUE");
    for(i=0; i<5; i++)
   	 {
        	printf(".");
   	 }
    system("cls");//clears the screen
    printf("\n");
   	 for(i=0; i<80; i++)
    		{
       			 printf("\xdb");
    		}
   	 system("color yellow");
    	 printf("\n\n\t** SCHOOL BILLING SYSTEM  **\n\n\n");
   	 	for(i=0; i<80; i++)
   		 	{
        			printf("\xdb");
   		 	}
   			 printf("\nPLEASE ENTER ANY KEY TO START\n");
   	 		for(i=0; i<5; i++)
   		 		{
        				printf(".");
    			        }
	    	system("cls");
	    	system("color white");//1st is for back ground color and second is for text color
		printf("\n\t\tPLEASE ENTER CURRENT DATE\nmm dd\n ");
		scanf("%d%d",&mm,&dd);
		mm=chkdat(mm,dd);
		printf("%d",mm);
		start();
		addrec(j);
		searchrec(j);
		modrec(j); 
		fee(j);
		clscanf();
		return 0;
}
void start()
{
    int i,j;//j is for selection of account type
    system("cls");
	    printf("\n\t\tPLEASE ENTER ACCOUNT TYPE");
	    printf("\n\t\t1:: s");
	    printf("\n\t\t2:: ts and Staffs");
	    printf("\n\t\t3:: Exit");
	    printf("\n\t\tAccount type choice  ");
	    scanf("%d",&j);
       switch (j)
		{
	    	case 3:
	       		 printf("Invalid\n");
			 break;
		case 1:
	   	     {
			system("cls");
			printf("\n\t\tPLEASE ENTER THE CHOICE");
			printf("\n\t\t1:: Add record");
			printf("\n\t\t2:: Search record");
			printf("\n\t\t3:: Modify record");
			printf("\n\t\t4:: Calculate fee");
			printf("\n\t\t5:: Exit");
			printf("\n\n Enter choice  ");
			scanf("%d",&i);
        switch (i)
        {
        	case 1:
			addrec(j);//function call
			break;
        	case 2:
       			searchrec(j);
			break;
        	case 3:
        	    modrec(j);
        	      break;
        	case 4:
        	    fee(mm);
              		break;
		case 5:
		    printf("Invalid\n");
		    break;
		default :
		{
		    printf("\n\n\tInvalid entry!!");
		    printf("\n\nTo Account Type\n\n\t");
		    system("pause");
		}
       		 break;
	  }
    	   break;
    }
	  }   
               }
void addrec(int j)
{
    int dif,cdat,ddat,month=0;//cdat=month till which fee is cleared
    float ff;//used in calculation of fee of different class
    char c='y';
    system("cls");
    printf("\n\t******************************************************************");
    printf("\n\t                     ***************************                  ");
    printf("\n\t*********************          ADD RECORD       *******************");
    printf("\n\t                     ***************************                  ");
    printf("\n\t******************************************************************");
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nEnter the name of s: ");
            scanf("%[^\n]",s.n);
            printf("\nEnter the class: ");
            s.c=clscanf();
            printf("\nEnter the Roll No.:");
            scanf("%2d",&s.r);
            printf("\nEnter month and day till which fee is paid:");
            scanf("%2d%2d",&cdat,&ddat);
            cdat=chkdat(cdat,ddat);
            s.dt.m=cdat;
            ff=s.c/10.0;
            s.f=1000*(1+ff);//fee of different classes
            dif=mm-s.dt.m;//months of fee left to be paid
            s.fine=(dif*s.f)*1/100;
            s.due=(dif)*s.f;//fees left to be paid
            	if(dif==1)
		    {
		        s.tot=s.f;
		        s.fine=0;
		    }
		    else
		   	 {
		        	s.tot=s.fine+s.due;
		   	 }//for calculation of total fee
		    fs=fopen("s","ab+");//opening a binary file in apend mode
		    fwrite(&s,sizeof(s),1,fs);
		    fclose(fs);
           }
}
    if (j==2)
    {
        while(c=='y'||c=='Y')
       	{
            int a=1;
            printf("\n\nEnter name of t/staff:" );
            scanf("%[^\n]",t.n);
            printf("\nEnter t/staff id: ");
            scanf("%d",&t.id);
            printf("\nEnter number of class/shift per month:: ");
            scanf("%d",&t.no);
            printf("\nEnter month and day till which salary is paid::");
            scanf("%d %d",&t.dt.m,&t.dt.d);
            cdat=chkdat(cdat,ddat);
            t.dt.m=cdat;
            t.sal=t.no*500;
            t.adv=(t.dt.m-mm-1)*t.sal;
            if (t.adv<0) t.adv=0;
            t.tot=t.sal;
            ft=fopen("t","ab+");
            fwrite(&t,sizeof(t),1,ft);
            fclose(ft);
        }
       
        system("pause");
    }
}
void searchrec(int j)
{
    char name[50],namet[50];
    int a=1,choice;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            system("cls");
            printf("\n\t******************************************************************");
            printf("\n\t                    ***************************                  ");
            printf("\n\t*********************   SEARCH RECORD     *******************");
            printf("\n\t                     ***************************                  ");
            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
            printf("\n\n\t\t1::Search by name::");
            printf("\n\n\t\t2::Search by class::");
            printf("\n\n\t\t3::Search by rollno::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            scanf("%d",&choice);
            if (choice==1)
            {
                a=1;
                printf("\n\nEnter name of s to search: ");
                scanf("%[^\n]",name);
                fs=fopen("s","rb");
                while(fread(&s,sizeof(s),1,fs)==1)
               	{
                    	 if (strcmp(name,s.n)==0)
                      	 {
		                a=0;
		                printf("\nname = %s",s.n);
		                printf("\nclass = %d",s.c);
		                printf("\nroll no = %d",s.r);
		                printf("\nmonthy fee =%.2f",s.f);
		                printf("\nlast fee paid in month =%2d",s.dt.m);
		                printf("\n due=%.2f",s.due);
		                printf("\n fine=%.2f",s.fine);
		                printf("\n total=%.2f\n\n",s.tot);
		          }
                }
                if (a==1)
                   	 printf("\n\nRECORD NOT FOUND");
               		 printf("\n\n");
		       	 system("pause");      
		      	 fclose(fs);
            }
            else if (choice==2)
            {
		        int cl;
		        a=1;
		        printf("\n\nEnter class of s to search: ");
		        cl=clscanf();
		        fs=fopen("s","rb");
                while(fread(&s,sizeof(s),1,fs)==1)
                {
                    if (s.c==cl)
                    {
                        a=0;
                        printf("\nname = %s",s.n);
                        printf("\nclass = %d",s.c);
                        printf("\nroll no = %d",s.r);
                        printf("\nmonthy fee =%.2f",s.f);
                        printf("\nlast fee paid in month =%2d",s.dt.m);
                        printf("\n due=%.2f",s.due);
                        printf("\n fine=%.2f",s.fine);
                        printf("\n total=%.2f",s.tot);
                    }
                }
                if (a==1)
                        printf("\n\nRECORD NOT FOUND");
		        printf("\n\n");
		        system("pause");
		        fclose(fs);
            }
            else if (choice==3)
            {
                int roll;
                a=1;
                printf("\n\nEnter roll of s to search: ");
                roll=clscanf();
                fs=fopen("s","rb");
                while(fread(&s,sizeof(s),1,fs)==1)
                {
                    if (strcmp(name,s.n)==0)
                    {
                        a=0;
                        printf("\nname = %s",s.n);
                        printf("\nclass = %d",s.c);
                        printf("\nroll no = %d",s.r);
                        printf("\nmonthy fee =%.2f",s.f);
                        printf("\nlast fee paid in month =%d",s.dt.m);
                        printf("\n due=%.2f",s.due);
                        printf("\n fine=%.2f",s.fine);
                        printf("\n total=%.2f",s.tot);
                    }
                }
                if (a==1)
                        printf("\n\nRECORD NOT FOUND");
		        printf("\n\n");
		        system("pause");
		        fclose(fs);
                }
              	 else if(choice==4)
          	 {
               		 printf("Invalid\n");
           	 }
                else
           	 {
		        printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
		        system("pause");
		        searchrec(1);
                  }
            		printf("\n\nDo you want to continue with the process(press y or Y");
      }
}
    if (j==2)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nname of t/staff to search: ");
            scanf("%[^\n]",namet);
            ft=fopen("t","rb");
            while(fread(&t,sizeof(t),1,ft)==1)
            {
                if (strcmp(namet,t.n)==0)
                {
                    a=0;
                    printf("\nname = %s",t.n);
                    printf("\nt/staff id = %d",t.id);
                    printf("\nmonth till when salary is paid =%d",t.dt.m);
                    printf("\nmonthy salary = %.2f",t.sal);
                    printf("\nadvance paid = %.2f",t.adv);
                }
            }
            if (a==1)
                    printf("\n\nRECORD NOT FOUND");
		    printf("\n\n");
		    system("pause");
		    fclose(ft);
                    printf("\n\nDo you want to continue with the process(press y or Y");   
        }
    }
}
void modrec(int j)
{
    char name[50];
    int a=1,choice,cl,rolno;
    char c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            system("cls");
            printf("\n\t******************************************************************");
            printf("\n\t                    ***************************                  ");
            printf("\n\t*********************   MODIFY RECORD     *******************");
            printf("\n\t                     ***************************                  ");
            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
            printf("\n\n\t\t1::Modify by name::");
            printf("\n\n\t\t2::Modify by name &class::");
            printf("\n\n\t\t3::Modify by name,class & rollno::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your choice:: ");
            scanf("%d",&choice);
            if (choice==1)
            {
                int a=0;
                printf("\n\nenter name of s to modify: ");
                scanf("%[^\n]",name);
                fs=fopen("s","rb+");
                while(fread(&s,sizeof(s),1,fs)==1)
                {
                    a=1;
                    if (strcmp(name,s.n)==0)
                    {
                        a=0;
                        printf("\nenter new name of s: ");
                        scanf("%[^\n]",s.n);
                        printf("\nenter new class of s: "); 
                        s.c=clscanf();
                        printf("\nenter new roll of s: "); 
                        scanf("%d",&s.r);
                        fseek(fs,sizeof(s),SEEK_CUR);
                        fwrite(&s,sizeof(s),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    	printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
		        printf("\n\n");
		        system("pause");
		    }
            else if (choice==2)
            {
                int a=0;
                printf("\n\nenter name of s to modify: ");
                scanf("%[^\n]",name);
                printf("\n\nenter class of s to modify: ");
                cl=clscanf();
                fs=fopen("s","rb+");
                while(fread(&s,sizeof(s),1,fs)==1)
                {
                    a=1;
                    if (strcmp(name,s.n)==0 && cl==s.c)
                    {
                        a=0;
                        printf("\nenter new name of s: ");
                        scanf("%[^\n]",s.n);
                        printf("\nenter new class of s: ");
                        s.c=clscanf();
                        printf("\nenter new roll of s: ");
                        scanf("%d",&s.r);
                        fseek(fs,sizeof(s),SEEK_CUR);
                        fwrite(&s,sizeof(s),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
		        printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
		        printf("\n\n");
		        system("pause");
                }
                else if (choice==3)
                {
		        int a=0;
		        printf("\n\nenter name of s to modify: ");
		        scanf("%[^\n]",name);
		        printf("\n\nenter class of s to modify: ");
		        cl=clscanf();
		        printf("\n\nenter roll of s to modify: ");
		        scanf("%d",&rolno);
		        fs=fopen("s","rb+");
                while(fread(&s,sizeof(s),1,fs)==1)
                {
                    a=1;
                    if (strcmp(name,s.n)==0 && cl==s.c &&rolno==s.r)
                    {
                        a=0;
                        printf("\nenter new name of s: ");
                        scanf("%[^\n]",s.n);
                        printf("\nenter new class of s: ");
                        s.c=clscanf();
                        printf("\nenter new roll of s: ");
                        scanf("%d",&s.r);
                        fseek(fs,sizeof(s),SEEK_CUR);
                        fwrite(&s,sizeof(s),1,fs);
                        fclose(fs);
                    }
                }
                if (a==1)
                    printf("\n\n NO RECORD HERE ");
                else
		        printf("\n\n RECORDS SUCCESSFULLY  SAVED ");
		        printf("\n\n");
		        system("pause");
		 }
                else if (choice==4) exit(0);
                     else
                     {
				printf("\n\n\n\t\t RE-ENTER PLZ \n\n\t\t");
				system("pause");
				modrec(1);           
                     }
                                printf("\n\nDo you want to continue with the process ?(press y or Y");
           }
 }
	    if (j==2)
	    {
		while(c=='y'||c=='Y')
		{
		    int a=1;
		    printf("enter name of t to modify: ");             
		    scanf("%[^\n]",name);
		    ft=fopen("t","rb+");
		    while(fread(&t,sizeof(t),1,ft)==1)
		    {
		        if (strcmp(name,t.n)==0)
		        {
		            a=0;
		            printf("\nenter new name of t: ");                     
		            scanf("%[^\n]",t.n);
		            printf("\nenter new ID of t: ");
		            scanf("%d",&t.id);
		            fseek(ft,sizeof(t),SEEK_CUR);
		            fwrite(&t,sizeof(t),1,ft);
		            fclose(ft);
		        }
		    }
		    if (a==1)
		        printf("\n\n NO RECORD HERE");
		    else
		            printf("\n\nRECORD SUCCESSFULLY SAVED");
			    printf("\n\n");
			    system("pause");
			    printf("\n\nDo you want to continue with the process ?(press y or Y");
		}   
        }
}
void fee(int mm)
{
	    system("cls");
	    printf("\n\t******************************************************************");
	    printf("\n\t                     ***************************                  ");
	    printf("\n\t*********************          FEE     *******************");
	    printf("\n\t                     ***************************                  ");
	    printf("\n\t******************************************************************");
	    FILE *f,*t;
	    int a=0;
	    char name[50],c='y';
	    int clas, roll,month,dif;
	    while(c=='y'||c=='Y')
	    {
		int a=1,day=0;
		printf("\n\nEnter name:: ");
		scanf("%[^\n]",name);
		printf("\n\nEnter class:: ");
		clas=clscanf();
		printf("\n\nEnter roll:: ");
		scanf("%d",&roll);
		f=fopen("s","rb+");
		t=fopen("te","wb");
		while(fread(&s,sizeof(s),1,f)==1)
		{
		    if(strcmp(s.n,name)==0 && clas==s.c && roll==s.r)
		    {
		        a=0;
		        printf("\n\nEnter the month till which fee to be paid:: "); 
		        scanf("%d",&month);
		        month=chkdat(month,day);
		        dif=mm-s.dt.m;
		        s.fine=(dif*s.f)*0.01;
		        s.due=(dif)*s.f;
		        if (s.fine<0) s.fine=0;
		         	if (s.due<0) s.due=0;
						if (s.tot<0) s.tot=0;
			s.tot=s.fine+s.due+s.adv;
		        printf("\nfine :: %.2f",s.fine);
		        printf("\ndue :: %.2f",s.due);
		        printf("\ntotal :: %.2f",s.tot);
		        printf("\nadvance :: %.2f",s.adv);
		        s.dt.m=month;
		        s.tot=0;
		        s.fine=0;
		        s.due=0;
		        fwrite(&s,sizeof(s),1,t);
		    }
        }
        if (a==1)
                printf("\n\nRECORD NOT FOUND");
		printf("\n\n");
		system("pause");
		fclose(f);
		fclose(t);
		system("del s");
		printf("\n\nDo you want to continue with the process ?(press y or Y");     
        }
}

int chkdat(int mnt,int dnt)
{
    int mon,day;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>31)
    {
        printf("Invalid Date! \n Enter Again Error!");
        scanf("%d%d",&mon,&day);
        mon=chkdat(mon,day);
    }
    else
        return (mnt);
}
int clscanf()
{
    int mnt,mon;     
    scanf("%d",&mnt);
    if (mnt>12 ||mnt<1)
    {
        printf("Invalid Class! \n Enter Again Error!!");
        mon=clscanf();
    }
    else
        return mnt;
}



