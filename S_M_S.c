#include<stdio.h>
#include<string.h>

int i = 0,j;

struct sch_mana_sys
{
    int roll_no;
    char fname[50],lname[50],course[5][50];
    float cgpa;
} stin[55];//struct variable

//function to add students details
void add_studdetails()
{
    printf("!!Students Information!!");
    printf("\n_________________________\n");

    printf("\nEnter Student's first name:");
    scanf("%s",stin[i].fname);

    printf("Enter Student's last name:");
    scanf("%s",stin[i].lname);

    printf("Enter Student's Roll Number:");
    scanf("%d",&stin[i].roll_no);

    printf("Enter Student's cgpa:");
    scanf("%f",&stin[i].cgpa);

    printf("Enter course name enrolled by the student:");
    for(j = 0; j < 5; j++){
    printf("\n Course %d:" ,j + 1);
    scanf("%s",stin[i].course[j]);
    }
    i++;
}

//function containing all details
void details(int index)
{
    printf("\nStudent's name:%s %s",stin[index].fname,stin[index].lname);
    printf("\nStudent's Roll no:%d",stin[index].roll_no);
    printf("\nStudent's CGPA:%2f",stin[index].cgpa);
    printf("\nStudent's Course enrolled:");
    for(j = 0; j < 5; j++){
    printf("Course %d:%s",j + 1,stin[index].course[j]);
    }
}

//Function to find the student by the given roll number
void find_rollno()
{
    int n;
    printf("\nEnter a valid Roll No you want to find:");
    scanf("%d",&n);

    for (int j = 0; j < i; j++)
    {
        if (stin[j].roll_no == n)
        {
            printf("\nPrinting Students Detail::");
            details(j);    
            return;  
        }
    }
    printf("Roll number not found.");
}

//function to find the student by the given first name
void find_fname()
{
    char name[50];

    printf("Enter first name:");
    scanf("%s",name);

    for(j = 0; j < i; i++)
    {
    if (strcmp(stin[j].fname,name) == 0)
    {
        details(j);
        return;
    }
    }
    printf("Name not found.");
}

//function to find the students registered in a course
void find_course()
{
    char cname[50];

    printf("Enter the course name:");
    scanf("%s", cname);

    for(j = 0; j < i; j++)
    {
        for(int k = 0; k < 5; k++)
    if (strcmp(stin[j].course[k],cname) == 0)
    {
        details(j);
        return;
    }
    }
    printf("Course not found.");
}

//function to find total number of students
void find_totstud()
{
    printf("The total number of Student is %d\n",i);
    printf("\n you can have a max of 50 students\n");
    printf("you can have %d more students\n",50 - i);
}

//function to delete the Students Details by Roll Number
void del_stud()
{
    int del;

    printf("Enter the roll number you want to delete:");
    scanf("%d",&del);

    for ( j = 0; j < i; j++)
    {
        if (stin[j].roll_no == del)
        {
            for (int k = 0; k < i - 1; k++)
            {
                stin[k] = stin[k + 1];    
            }   
            i--;
            printf("Details of the roll no %d has been deleted successfully.",del);
            return;
        }
    }
}

//function to update the details
void up_stud()
{
    int update;

    printf("Enter the roll number to update the details:");
    scanf("%d",&update);

    for ( j = 0; j < i; j++)
    {
      if(stin[j].roll_no == update)
      {
        printf("1. First name");
        printf("2. Last name");
        printf("3. Roll Number");
        printf("4. CGPA");
        printf("5. Courses Enrolled");

    int choice;

    printf("Enter the number to update the corresponding detail:");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1 : printf("Enter the new first name: ");
             scanf("%s",stin[j].fname);
        break;
    
    case 2 : printf("Enter the new last name: ");
             scanf("%s",stin[j].lname);
        break;
    
    case 3 : printf("Enter the new roll number: ");
             scanf("%d",&stin[j].roll_no);
        break;
    
    case 4 : printf("Enter the new CGPA: ");
             scanf("%f",&stin[j].cgpa);
        break;
    
    case 5 : printf("Enter the new courses enrolled: ");
            for(int k = 0; k < 5; k++){
            printf("\n Course %d:" ,k + 1);
            scanf("%s",stin[j].course[k]);
            }
            i++;
        break;

    default: printf("Entered invalid details");
        break;
    }
    printf("Details of the roll no %d has been updated successfully.",update);
    return;
    }
    }
    printf("No student found with Roll No %d.\n", update);
}

int main()
{
    printf("\n !! SCHOOL MANAGEMENT SYSTEM !!\n");

    int choice;

    while(1) {
        printf("\n\nThe Task that you "
               "want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student "
               "Details by Roll Number\n");
        printf("3. Find the Student "
               "Details by First Name\n");
        printf("4. Find the Student "
               "Details by Course Id\n");
        printf("5. Find the Total number"
               " of Students\n");
        printf("6. Delete the Students Details"
               " by Roll Number\n");
        printf("7. Update the Students Details"
               " by Roll Number\n");
        printf("8. To Exit\n");
        printf("Enter your choice to "
               "find the task\n");
        scanf("%d", &choice); 

        switch (choice)
        {
        case 1 : add_studdetails();
            break;
        
        case 2 : find_rollno();
            break;

        case 3 : find_fname();
            break;

        case 4 : find_course();
            break;

        case 5 : find_totstud();
            break;

        case 6 : del_stud();
            break;

        case 7 : up_stud();
            break;

        case 8 : return 0;

        default: printf("Invalid option");
            break;
        }
}
return 0;
}
