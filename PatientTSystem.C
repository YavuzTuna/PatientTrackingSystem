#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addPatient();
void patientRecord();
void searchPatient();
void deletePatient();
void payBills();

#define COUGH 100;
#define HEADACHE 200;
#define FEVER 300;
#define FLU 400;
#define SURGERY 500;
      
struct patient{
	int id;
	char first_Name[50];
	char last_Name[50];
	char illness[50];
	int bill;
}p;

int currentId = 0;

int main(){
	int choice;
	while(choice!=5){
		printf("\n\t\t    **** CANKAYA UNIVERSITY PATIENT TRACKING SYSTEM ****");
		printf("\n\n\n\t\t\t\t 1.Add New Patient Record\n");
		printf("\t\t\t\t 2.Review Patients\n");
		printf("\t\t\t\t 3.Search a Patient\n");
		printf("\t\t\t\t 4.Delete a Record\n");
		printf("\t\t\t\t 5.Exit\n");
		printf("\t\t\t\t 6.Pay The Bill \n\t\t\t\t ");
		scanf("%d", &choice);
		
		switch(choice){
				
			case 1:
				system("cls");
				addPatient();
				system("cls");
				break;
				
			case 2: 
				system("cls");
				patientRecord();
				getch();
				system("cls");
				break;
				
			case 3:
				system("cls");
				searchPatient();
				getch();
				system("cls");
				break;
			
			case 4:
				system("cls");
				deletePatient();
				getch();
				system("cls");
				break;
				
			case 5:
				system("cls");
				printf("\n\t\t\t\tThanks for using this software.\n\n");
				exit(0);
				break;
				
			case 6:
				system("cls");
				payBills();			
				break;
				
			default:
				system("cls");
				getch();
				printf("\n\t\t\t\tEnter a valid number.");
				printf("\n\t\t\t\tPress any key to continue...\t\t\t\t\t\t\t\t\t\n");
				getch();
		}
	}
}

FILE *fp;

void addPatient(){
	
		char another;
		
		do{
			
			fp=fopen("patients.txt","r"); 
	    
	        int tempId = 0;
	        while(fread(&p,sizeof(p),1,fp))
			{
				currentId = p.id;
	        }
	        currentId = currentId + 1;
	        
	        
	        fclose(fp);
	
			printf("\n\n\n\t\t\t\t** Add Patient Information **\n\n\n");
			fp=fopen("patients.txt","ab"); 
			p.id = currentId;
			
			printf("\n\t\t\t\t  Enter your first name : ");
			fflush(stdin);
   			gets(p.first_Name);
   			
   			printf("\n\t\t\t\t  Enter your last name : ");
			fflush(stdin);
   			gets(p.last_Name);
   			

    		
    		bool condIllness = false;
			do
			{
				printf("\n\t\t\t\t  Enter your illness (ID) : ");
	   			printf("\n\t\t\t\t  1-COUGH");
	   			printf("\n\t\t\t\t  2-HEADACHE ");
	   			printf("\n\t\t\t\t  3-FEVER ");
	   			printf("\n\t\t\t\t  4-FLU ");
	   			printf("\n\t\t\t\t  5-SURGERY \n\t\t\t\t  ");
				fflush(stdin);
	    		gets(p.illness);
			
	      	if(strcmp(p.illness, "1" ) == 0)
	      	{
	      		p.bill = COUGH;
	      		condIllness = false;
			}
			else if(strcmp(p.illness, "2" ) == 0)
			{
				p.bill = HEADACHE;
				condIllness = false;
			}
			else if(strcmp(p.illness, "3" ) == 0)
			{
				p.bill = FEVER;
				condIllness = false;
			} 
			else if(strcmp(p.illness, "4" ) == 0)
			{
				p.bill = FLU;
				condIllness = false;
			} 
			else if(strcmp(p.illness, "5" ) == 0)
			{
				p.bill = SURGERY;
				condIllness = false;
			} 
			else
			{
				printf("\n\t\t\t\t  Invalid Illness.Enter your illness    : ");
				condIllness = true;
			} 
 		}while(condIllness);
    		
    		
			if(fp==NULL){
				fprintf(stderr,"\n\t\t\tCan't open the file!!\n");
			}else{
				printf("\n\t\t\t         The record stored successfully!\n");
			}
			
			fwrite(&p, sizeof(p), 1, fp);
			fclose(fp);
			
			printf("\n\t\t\t         Do you want to add another record?(y/n): \n\t\t\t\t ");
			scanf("%s", &another);
			system("cls");
		}while(another=='y'||another=='Y');
}

void patientRecord(){
	
       
        fp=fopen("patients.txt","r"); 
        printf("\n\n\n\t\t\t\t       Patient Records \n");
        if(fp==NULL){
                fprintf(stderr,"\n\t\t\tCan't open the file!!\n");
            }else{
                
                printf("\n\t\t\t\t_______________________________\n");
            }
        while(fread(&p,sizeof(p),1,fp))
		{
            printf("\n\t\t\t\tId       : %d",p.id);
            printf("\n\t\t\t\tPatient Name  : %s %s",p.first_Name, p.last_Name);
            printf("\n\t\t\t\tIllness       : %s",p.illness);
            printf("\n\t\t\t\tBill          : %d",p.bill);
            printf("\n\t\t\t\t-------------------------------");
        }
        fclose(fp);
        getch();
}


void searchPatient(){
	
		fp=fopen("patients.txt","r"); 
		int id,found=0;
		
		printf("\n\n\n\t\t\t\t    ** Search a Patient **\n\n\n");
		printf("\t\t\t\t     Enter an id number : ");
		scanf("%d",&id);
		
		while(fread(&p,sizeof(p),1,fp))
		{
			if(p.id==id)
			{
				found=1;
				printf("\n\t\t\t\tPatient name  : %s %s",p.first_Name, p.last_Name);
				printf("\n\t\t\t\tIllness       : %s",p.illness);
				printf("\n\t\t\t\tBill          : %d",p.bill);
				printf("\n\t\t\t\t-------------------------------");		
			}
		}
		
		if(!found){
			printf("\n\t\t\tRecord does not exist.");
			
		}
		fclose(fp);
		getch();	
}
void deletePatient(){
    int id, f=0;
    system("cls");
    printf("\n\n\t\t\t\t  Enter a Patient Id To Delete: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patients.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\n\t\t\t\t  Patient Deleted Successfully.");
    }else{
        printf("\n\n\t\t\t\t  Record Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

}

void payBills()
{
	system("cls");
	int id, f=0;
	
	printf("\n\t\t\t\t Enter patient ID:\n\t\t\t\t ");
	scanf("%d", &id);
	
	int choice2;
	printf("\t\t\t\t Enter amount of bill:\n\t\t\t\t ");
	scanf("%d", &choice2);
	system("cls");
    FILE *ft;

    fp = fopen("patients.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1)
	{

        if(id == p.id)
		{
        	p.bill = p.bill-choice2;
        	
        	if(p.bill>0)
        	{
        		fwrite(&p, sizeof(p), 1, ft);
			}
        	else
        	{
        	
			}
            
        }else
		{
            fwrite(&p, sizeof(p), 1, ft);
        }
    } 


    fclose(fp);
    fclose(ft);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");
	
}

// Assume You are writing a program for a hospital.
// You should be able to add new patients, display the previous patients, delete patients
// Every patient will have a unique ID in integer form. When you add a new patient you should give him/her a new id. (if previous was 25, give 26)
// And also patients have illnesses, According to their illnesses, generate a bill. For example, if the patient has a surgery,
// he/she should pay 500 , but if patient has headache he/she should pay 100. Similar to that example for 5 different illness generate a bill.
// Use switch case to generate the bills. You should have a function named pay_bill() where you input the patient name and the amount to pay.
// if patient has the bill 0, delete the patient. Use .txt file, read the previous patients from .txt file and also write the updated patients to .txt file.
