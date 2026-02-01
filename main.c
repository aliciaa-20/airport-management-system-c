#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nop=-1,th=0,temp;
char S[5]="yes"; 
float T=0,GT=0,aged=0,cardd=0,weightd=0;
struct Airway
{
  char name[100];
  int id;
  char gender[5];
  int age;
  float weight;
  char source[10];
  char destination[10];
  char card[5];
  float distance;
  float fare;
  float tfare;
  
  int d,m,y;
}p[100];

int date1(int a)
{
	printf("Enter date dd mm yyyy seperately\n");
	scanf("%d%d%d",&p[a].d,&p[a].m,&p[a].y);
}
int date2(int a)
{
	printf("\nDate            :      %d-%d-%d\n",p[a].d,p[a].m,p[a].y);
}

int menu()
{
  printf("\n1. Add Passenger \n");
  printf("2. Show Passenger Profile \n");
  printf("3. Calculate Airfare \n");
  printf("4. Generate E-ticket \n");
  //printf("5. Select profile \n");
  printf("5. All passenger \n");
  printf("6. Total Fees collected \n");
  printf("7. Exit \n");
}
int addp()
{
   nop=nop+1;
   printf("\n\nPROFILE NO.: %d",nop);
   printf("\n\nName            ");scanf("%s",&p[nop].name);
   printf("Id              ");scanf("%d",&p[nop].id);
   printf("Gender          ");scanf("%s",&p[nop].gender);
   printf("Age             ");scanf("%d",&p[nop].age);
   printf("Baggage Weight  ");scanf("%f",&p[nop].weight);
   printf("Source          ");scanf("%s",&p[nop].source);
   printf("Destination     ");scanf("%s",&p[nop].destination);
   printf("Distance        ");scanf("%f",&p[nop].distance);
   date1(nop);
   printf("Membership Card ");scanf("%s",&p[nop].card);
   system("cls");
   
}

int show(int a)
{
   printf("------------------------------------\n");
   printf("        PASSENGER PROFILE  %d       \n",a);
   printf("------------------------------------\n");
	
   printf("\nName            :      %s",p[a].name);
   printf("\nId              :      %d",p[a].id);
   printf("\nGender          :      %s",p[a].gender);
   printf("\nAge             :      %d",p[a].age);
   printf("\nBaggege weight  :      %f",p[a].weight);
   printf("\nSource          :      %s",p[a].source);
   printf("\nDestination     :      %s",p[a].destination);
   printf("\nDistance        :      %f",p[a].distance);
   date2(a);
   printf("\nMembership Card :      %s",p[a].card);
   
   printf("\n------------------------------------\n");
   
   printf("\n\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");
}

int show2(int a)
{
   printf("------------------------------------\n");
   printf("        PASSENGER PROFILE %d        \n",a);
   printf("------------------------------------\n");
	
   printf("\nName            :      %s",p[a].name);
   printf("\nPassenger Id    :      %d",p[a].id);
   printf("\nAge             :      %d",p[a].age);
   printf("\nGender          :      %s",p[a].gender);
   printf("\nBaggage weight  :      %f",p[a].weight);
   printf("\nSource          :      %s",p[a].source);
   printf("\nDestination     :      %s",p[a].destination);
   date2(a);
   printf("\nDistance        :      %f",p[a].distance);
   printf("\nMembership Card :      %s",p[a].card);
   
   printf("\n------------------------------------\n\n");
   
}

int airfare()
{
   printf("Enter profile no. \n");
   scanf("%d",&th);
   
   printf("------------------------------------\n");
   printf("        AIRFARE FEE STRUCTURE       \n");
   printf("------------------------------------\n");
   
   printf("DISTANCE              : %f\n",p[th].distance);
   printf("AGE                   : %d\n",p[th].age);
   printf("CARD                  : %s\n",p[th].card);
   printf("WEIGHT                : %f\n\n",p[th].weight);
   
   T=p[th].distance*150;
   printf("BASE FARE             : %f\n",T);
   
   if(p[th].age>=60)
    aged =  T*0.4;
   printf("AGE DISCOUNT          : %f\n",aged); 
    
   if(strcmp(p[th].card,S)==0)
    cardd = T*0.05; 
   printf("CARD DISCOUNT         : %f\n",cardd); 
   
   if(p[th].weight>15)
    weightd = (p[th].weight -15)*20;
   printf("EXTRA WEIGHT CHARGE   : %f\n\n",weightd);   

   T=T-aged-cardd+weightd;
    printf("------------------------------------\n\n");
    printf("TOTAL                 : %f\n",T);
    printf("GST of 10 perc.       : %f\n",T*0.1);
   T=T- T*0.1;
    
   printf("G. Total              : %f\n",T);
   printf("------------------------------------\n");
   
   printf("\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");
}

int tfee()
{
   int i; 
   
   for(i=0;i<=nop;i++)
   {
   		T=p[i].distance*150;
   if(p[i].age>=60)
      aged =  T*0.4 ;
   if(strcmp(p[i].card,S)==0)
      cardd = T*0.05; 
   if(p[i].weight>15)
      weightd = (p[i].weight -15)*20;
   T=T-aged-cardd+weightd;
   T=T- T*0.1;
   p[i].fare=T;
   	 printf("passenger id : %d    Total Fee :%f\n",p[i].id,p[i].fare);
   	 GT=GT+p[i].fare;
   }
   float *ptr;
   ptr = &GT;
   
	printf("Total Fee Collected : %f\n",*ptr);
	*ptr=0;
	printf("\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");	
}

int BP()
{
	int a;
   printf("Enter profile no. \n");
   scanf("%d",&a);
   
   printf("------------------------------------\n");
   printf("            BOARDING PASS           \n");
   printf("------------------------------------\n");
   
   printf("\nPassenger Id    :      %d",p[a].id);
   printf("\nAge             :      %d",p[a].age);
   printf("\nGender          :      %s",p[a].gender);
   printf("\nBaggage weight  :      %f",p[a].weight);
   printf("\nSource          :      %s",p[a].source);
   printf("\nDestination     :      %s",p[a].destination);
   printf("\nDistance        :      %f",p[a].distance);
   date2(a);
   printf("\nMembership Card :      %s",p[a].card);
   
      T=p[a].distance*150;
   if(p[a].age>=60)
      aged =  T*0.4 ;
   if(strcmp(p[a].card,S)==0)
      cardd = T*0.05; 
   if(p[a].weight>15)
      weightd = (p[a].weight -15)*20;
   T=T-aged-cardd+weightd;
   T=T- T*0.1;
   printf("\nAirFare         :      %f\n",T); 
   printf("------------------------------------\n");
    
   printf("\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");
}
/*
int select()
{ 
   if(nop==-1)
    printf("No Profiles Created");
   else
   {
     printf("Nth");
     scanf("%d",&th);
   }
   
   printf("\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");
}
*/
int allp()
{
   int i;
   if(nop==-1)
    printf("No Profiles Created\n");
  else{  
    for(i=0;i<=nop;i++)
    {
      show2(i);
      printf("\n");
    }
   }
   
   printf("\nENTER 0 TO RETURN TO MENU");
   scanf("%d",&temp);
   system("cls");
}
int main()
{
   
   int a;
   
   again:
   
   menu();
   scanf("%d",&a);
   system("cls");
   
   switch(a)
   {
    case 1:addp(); goto again; break;
    case 2:printf("Enter profile no. \n");
           scanf("%d",&th);
           show(th);
           goto again;
           break;
    case 3:airfare();goto again; break;
    case 4:BP();goto again; break;
    //case 5:select();goto again; break;
    case 5:allp();goto again;
    case 6:tfee();goto again;
    case 7:break;
   
   default: printf("ENTER CORRECT CHOICE \n");
   			printf("\nENTER 0 TO RETURN TO MENU");
   			scanf("%d",&temp);
   			system("cls");
   			goto again;
   
   }
}