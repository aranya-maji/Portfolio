#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stdbool.h>
using namespace std;
struct Process {
    int id;
    char name[100];
    int age;
    char gender[100];
    int Arrival_time;
    char Location[100];
    int Area_Size;
    char Severity_of_injuries[100];
    char Disaster_Type[100];
    int Burst_time_fcfs_ps;
    int Burst_Time_rr;
    int Burst_Time_sjf;
    int Burst_time_mq;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int remaining_time;
    int priority;
};
int compareArrivalTime(const void* a, const void* b) {
    return ((struct Process*)a)->Arrival_time - ((struct Process*)b)->Arrival_time;
}
void fcfs()
{
int a;
cout<<"Enter 1 for Flood,2 for Earthquake and 3 for Volcano: "<<endl;
cin>>a;
FILE *the_file=fopen("pp.csv","r");
    if(the_file==NULL)
    {
        perror("Unable to open the file.");
        exit(1);
    }

    int max_processes = 531;  // Maximum number of processes (adjust as needed)
    struct Process processes[max_processes];
    int num_processes = 0;

    char line[2048];
    while (feof(the_file) != true && num_processes<max_processes) {
        fgets(line,2048,the_file);
        char str[100];
        for(int l=0;l<100;l++)
        {
            str[l] = '\0';
        }
        int v = 0;
        int y = 0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i] != '\n' && line[i] != ',')
            {
                str[y] = line[i];
                y++;
            }
            else if(line[i] == ',')
            {
                str[y] = '\0';
                y = 0;
                if(v == 0)
                {
                    processes[num_processes].id = atoi(str);
                }
                else if(v == 1)
                {
                    strcpy(processes[num_processes].name,str);
                }
                else if(v == 2)
                {
                    processes[num_processes].age = atoi(str);
                }
                else if(v == 3)
                {
                    strcpy(processes[num_processes].gender,str);
                }
                else if(v == 4)
                {
                    processes[num_processes].Arrival_time = atoi(str);
                }
                else if(v == 5)
                {
                    strcpy(processes[num_processes].Location,str);
                }
                else if(v == 6)
                {
                    processes[num_processes].Area_Size = atoi(str);
                }
                else if(v == 7)
                {
                    strcpy(processes[num_processes].Severity_of_injuries,str);
                }
                else if(v == 8)
                {
                    strcpy(processes[num_processes].Disaster_Type,str);
                }
                else if(v == 9)
                {
                    processes[num_processes].Burst_time_fcfs_ps = atoi(str);
                }
                else if(v == 10)
                {
                    processes[num_processes].Burst_Time_rr = atoi(str);
                }
                else if(v == 11)
                {
                    processes[num_processes].Burst_Time_sjf = atoi(str);
                }
                else if(v == 12)
                {
                    processes[num_processes].Burst_time_mq = atoi(str);
                }
                v++;
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
            }
            else if(line[i] == '\n')
            {
                if(v == 13)
                {
                    processes[num_processes].priority = atoi(str);
                }
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
                break;
            }
        }
        num_processes++;
    }
    //Close the input file
   fclose(the_file);

if(a==1)
{
    // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
                 if (strcmp(processes[j].Disaster_Type, "Flood") == 0)
                 {


             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }



   for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Flood") == 0)
            {

        if (i == 0) {
            processes[i].completion_time = processes[i].Arrival_time + processes[i].Burst_time_fcfs_ps;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].Burst_time_fcfs_ps;
        }

        if (processes[i].completion_time < processes[i].Arrival_time) {
            processes[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
processes[0].waiting_time = 0;
processes[0].turnaround_time = processes[0].Burst_time_fcfs_ps;

for (int i = 1; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Flood") == 0)
            {

processes[i].waiting_time = processes[i - 1].turnaround_time;
processes[i].turnaround_time = processes[i].waiting_time +processes[i].Burst_time_fcfs_ps;
}
}    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_fcfs.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].Disaster_Type, "Flood") == 0)
                {


            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_time_fcfs_ps,processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
}
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);
     printf("FCFS scheduling results written to output_fcfs.csv\n");
}
else if(a==2)
{
    // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
                 if (strcmp(processes[j].Disaster_Type, "Earthquake") == 0)
                 {


             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }



   for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
            {

        if (i == 0) {
            processes[i].completion_time = processes[i].Arrival_time + processes[i].Burst_time_fcfs_ps;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].Burst_time_fcfs_ps;
        }

        if (processes[i].completion_time < processes[i].Arrival_time) {
            processes[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
processes[0].waiting_time = 0;
processes[0].turnaround_time = processes[0].Burst_time_fcfs_ps;

for (int i = 1; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
            {

processes[i].waiting_time = processes[i - 1].turnaround_time;
processes[i].turnaround_time = processes[i].waiting_time +processes[i].Burst_time_fcfs_ps;
}
}    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_fcfs.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
                {


            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_time_fcfs_ps,processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);
     printf("FCFS scheduling results written to output_fcfs.csv\n");
}
else if(a==3)
{
    // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
                 if (strcmp(processes[j].Disaster_Type, "Volcano") == 0)
                 {


             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }



   for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Volcano") == 0)
            {

        if (i == 0) {
            processes[i].completion_time = processes[i].Arrival_time + processes[i].Burst_time_fcfs_ps;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].Burst_time_fcfs_ps;
        }

        if (processes[i].completion_time < processes[i].Arrival_time) {
            processes[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
processes[0].waiting_time = 0;
processes[0].turnaround_time = processes[0].Burst_time_fcfs_ps;

for (int i = 1; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Volcano") == 0)
            {

processes[i].waiting_time = processes[i - 1].turnaround_time;
processes[i].turnaround_time = processes[i].waiting_time +processes[i].Burst_time_fcfs_ps;
}
}    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_fcfs.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,Distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].Disaster_Type, "Volcano") == 0)
                {


            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_time_fcfs_ps, processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
    }
    ;
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }
 printf("FCFS scheduling results written to output_fcfs.csv\n");
    // Close the output file
    fclose(output_file);
}
else
{
    cout<<"Invalid input";
}
}

void sjf()
{
int a;
cout<<"Enter 1 for Flood,2 for Earthquake and 3 for Volcano: "<<endl;
cin>>a;
   FILE *the_file=fopen("pp.csv","r");
    if(the_file==NULL)
    {
        perror("Unable to open the file.");
        exit(1);
    }

    int max_processes = 531;  // Maximum number of processes (adjust as needed)
    struct Process processes[max_processes];
    int num_processes = 0;

    char line[2048];
    while (feof(the_file) != true && num_processes<max_processes) {
        fgets(line,2048,the_file);
        char str[100];
        for(int l=0;l<100;l++)
        {
            str[l] = '\0';
        }
        int v = 0;
        int y = 0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i] != '\n' && line[i] != ',')
            {
                str[y] = line[i];
                y++;
            }
            else if(line[i] == ',')
            {
                str[y] = '\0';
                y = 0;
                if(v == 0)
                {
                    processes[num_processes].id = atoi(str);
                }
                else if(v == 1)
                {
                    strcpy(processes[num_processes].name,str);
                }
                else if(v == 2)
                {
                    processes[num_processes].age = atoi(str);
                }
                else if(v == 3)
                {
                    strcpy(processes[num_processes].gender,str);
                }
                else if(v == 4)
                {
                    processes[num_processes].Arrival_time = atoi(str);
                }
                else if(v == 5)
                {
                    strcpy(processes[num_processes].Location,str);
                }
                else if(v == 6)
                {
                    processes[num_processes].Area_Size = atoi(str);
                }
                else if(v == 7)
                {
                    strcpy(processes[num_processes].Severity_of_injuries,str);
                }
                else if(v == 8)
                {
                    strcpy(processes[num_processes].Disaster_Type,str);
                }
                else if(v == 9)
                {
                    processes[num_processes].Burst_time_fcfs_ps = atoi(str);
                }
                else if(v == 10)
                {
                    processes[num_processes].Burst_Time_rr = atoi(str);
                }
                else if(v == 11)
                {
                    processes[num_processes].Burst_Time_sjf = atoi(str);
                }
                else if(v == 12)
                {
                    processes[num_processes].Burst_time_mq = atoi(str);
                }
                v++;
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
            }
            else if(line[i] == '\n')
            {
                if(v == 13)
                {
                    processes[num_processes].priority = atoi(str);
                }
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
                break;
            }
        }
        num_processes++;
    }
    //Close the input file
   fclose(the_file);
if(a==1){
        int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Flood") == 0){
             if(processes[j-1].Burst_Time_sjf>processes[j].Burst_Time_sjf)
             {
                 struct Process temp1=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp1;
             }
         }
     }
     }
     int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Flood") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Flood") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_sjf.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);


   printf("SJF scheduling results written to output_sjf.csv\n");
}
else if(a==2){
    int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Earthquake") == 0){
             if(processes[j-1].Burst_Time_sjf>processes[j].Burst_Time_sjf)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }
int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_sjf.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);


   printf("SJF scheduling results written to output_sjf.csv\n");
}
else if(a==3){
    int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Volcano") == 0){
             if(processes[j-1].Burst_Time_sjf>processes[j].Burst_Time_sjf)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }
     int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Volcano") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Volcano") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_sjf.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);


   printf("SJF scheduling results written to output_sjf.csv\n");
}
else{
    cout<<"Invalid input";
}
}

int rr()
{
int a;
cout<<"Enter 1 for Flood,2 for Earthquake and 3 for Volcano: "<<endl;
cin>>a;
    int tq;
    printf("Enter tq: ");
    scanf("%d",&tq);

FILE *the_file=fopen("pp.csv","r");
    if(the_file==NULL)
    {
        perror("Unable to open the file.");
        exit(1);
    }

    int max_processes = 531;  // Maximum number of processes (adjust as needed)
    struct Process processes[max_processes];
    int num_processes = 0;

    char line[2048];
    while (feof(the_file) != true && num_processes<max_processes) {
        fgets(line,2048,the_file);
        char str[100];
        for(int l=0;l<100;l++)
        {
            str[l] = '\0';
        }
        int v = 0;
        int y = 0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i] != '\n' && line[i] != ',')
            {
                str[y] = line[i];
                y++;
            }
            else if(line[i] == ',')
            {
                str[y] = '\0';
                y = 0;
                if(v == 0)
                {
                    processes[num_processes].id = atoi(str);
                }
                else if(v == 1)
                {
                    strcpy(processes[num_processes].name,str);
                }
                else if(v == 2)
                {
                    processes[num_processes].age = atoi(str);
                }
                else if(v == 3)
                {
                    strcpy(processes[num_processes].gender,str);
                }
                else if(v == 4)
                {
                    processes[num_processes].Arrival_time = atoi(str);
                }
                else if(v == 5)
                {
                    strcpy(processes[num_processes].Location,str);
                }
                else if(v == 6)
                {
                    processes[num_processes].Area_Size = atoi(str);
                }
                else if(v == 7)
                {
                    strcpy(processes[num_processes].Severity_of_injuries,str);
                }
                else if(v == 8)
                {
                    strcpy(processes[num_processes].Disaster_Type,str);
                }
                else if(v == 9)
                {
                    processes[num_processes].Burst_time_fcfs_ps = atoi(str);
                }
                else if(v == 10)
                {
                    processes[num_processes].Burst_Time_rr = atoi(str);
                }
                else if(v == 11)
                {
                    processes[num_processes].Burst_Time_sjf = atoi(str);
                }
                else if(v == 12)
                {
                    processes[num_processes].Burst_time_mq = atoi(str);
                }
                v++;
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
            }
            else if(line[i] == '\n')
            {
                if(v == 13)
                {
                    processes[num_processes].priority = atoi(str);
                }
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
                break;
            }
        }
        num_processes++;
    }
    //Close the input file
   fclose(the_file);
   if(a==1){
     int completed = 0;
    int current_time = 0;
    int time=0;
    int n=531;

         // Sort the array of processes by arrival time
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Flood") == 0){
             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }
     for(int i=0;i<n;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Flood") == 0){
         processes[i].remaining_time = processes[i].Burst_Time_rr;
     }
     }

        while(completed<n)
        {
            for(int i=0;i<n;i++)
            {
                if (strcmp(processes[i].Disaster_Type, "Flood") == 0){
                if (processes[i].remaining_time <= tq) {
                        time += processes[i].remaining_time;
                        processes[i].remaining_time = 0;
                        processes[i].completion_time = time;
                        completed++;
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_rr;
                } else {
                        time += tq;
                        processes[i].remaining_time -= tq;
            }
            }
        }
}

    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_rr.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Flood") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_Time_rr,processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("RR scheduling results written to output_rr.csv\n");
}
else if(a==2){
     int completed = 0;
    int current_time = 0;
    int time=0;
    int n=531;

         // Sort the array of processes by arrival time
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Earthquake") == 0){
             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }
     for(int i=0;i<n;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0){
         processes[i].remaining_time = processes[i].Burst_Time_rr;
     }
     }
 while(completed<n)
        {
            for(int i=0;i<n;i++)
            {
                if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0){
                if (processes[i].remaining_time <= tq) {
                        time += processes[i].remaining_time;
                        processes[i].remaining_time = 0;
                        processes[i].completion_time = time;
                        completed++;
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_rr;
                } else {
                        time += tq;
                        processes[i].remaining_time -= tq;
            }
            }
        }
}
for (int i = 0; i < num_processes; i++) {
        if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0){
    if (current_time < processes[i].Arrival_time) {
        current_time = processes[i].Arrival_time; // If the process arrives later, update the current time
    }
}
}


    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_rr.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_Time_rr,processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("RR scheduling results written to output_rr.csv\n");
}
else if(a==3){
     int completed = 0;
    int current_time = 0;
    int time=0;
    int n=531;

         // Sort the array of processes by arrival time
     for(int i=0;i<531;i++)
     {
         for(int j=1;j<531;j++)
         {
             if (strcmp(processes[j].Disaster_Type, "Volcano") == 0){
             if(processes[j-1].Arrival_time>processes[j].Arrival_time)
             {
                 struct Process temp=processes[j-1];
                 processes[j-1]=processes[j];
                 processes[j]=temp;
             }
         }
     }
     }
     for(int i=0;i<n;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Volcano") == 0){
         processes[i].remaining_time = processes[i].Burst_Time_rr;
     }
     }

         while(completed<n)
        {
            for(int i=0;i<n;i++)
            {
                if (strcmp(processes[i].Disaster_Type, "Volcano") == 0){
                if (processes[i].remaining_time <= tq) {
                        time += processes[i].remaining_time;
                        processes[i].remaining_time = 0;
                        processes[i].completion_time = time;
                        completed++;
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_rr;
                } else {
                        time += tq;
                        processes[i].remaining_time -= tq;
            }
            }
        }
}


    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_rr.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < num_processes; i++) {
            if (strcmp(processes[i].Disaster_Type, "Volcano") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", processes[i].id, processes[i].name,processes[i].age, processes[i].gender,processes[i].Arrival_time, processes[i].Location,processes[i].Area_Size, processes[i].Severity_of_injuries, processes[i].Disaster_Type,processes[i].Burst_Time_rr,processes[i].waiting_time,processes[i].turnaround_time,processes[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("RR scheduling results written to output_rr.csv\n");
}
else{
    cout<<"Invalid input";
}
}


void ps()
{
    int a;
    cout<<"Enter 1 for Flood,2 for Earthquake and 3 for Volcano: "<<endl;
    cin>>a;
    FILE *the_file=fopen("pp.csv","r");

    if(the_file==NULL)
    {
        perror("Unable to open the file.");
        exit(1);
    }

    int max_processes = 531;  // Maximum number of processes (adjust as needed)
    struct Process processes[max_processes];
    int num_processes = 0;

    char line[2048];
    while (feof(the_file) != true && num_processes<max_processes) {
        fgets(line,2048,the_file);
        char str[100];
        for(int l=0;l<100;l++)
        {
            str[l] = '\0';
        }
        int v = 0;
        int y = 0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i] != '\n' && line[i] != ',')
            {
                str[y] = line[i];
                y++;
            }
            else if(line[i] == ',')
            {
                str[y] = '\0';
                y = 0;
                if(v == 0)
                {
                    processes[num_processes].id = atoi(str);
                }
                else if(v == 1)
                {
                    strcpy(processes[num_processes].name,str);
                }
                else if(v == 2)
                {
                    processes[num_processes].age = atoi(str);
                }
                else if(v == 3)
                {
                    strcpy(processes[num_processes].gender,str);
                }
                else if(v == 4)
                {
                    processes[num_processes].Arrival_time = atoi(str);
                }
                else if(v == 5)
                {
                    strcpy(processes[num_processes].Location,str);
                }
                else if(v == 6)
                {
                    processes[num_processes].Area_Size = atoi(str);
                }
                else if(v == 7)
                {
                    strcpy(processes[num_processes].Severity_of_injuries,str);
                }
                else if(v == 8)
                {
                    strcpy(processes[num_processes].Disaster_Type,str);
                }
                else if(v == 9)
                {
                    processes[num_processes].Burst_time_fcfs_ps = atoi(str);
                }
                else if(v == 10)
                {
                    processes[num_processes].Burst_Time_rr = atoi(str);
                }
                else if(v == 11)
                {
                    processes[num_processes].Burst_Time_sjf = atoi(str);
                }
                else if(v == 12)
                {
                    processes[num_processes].Burst_time_mq = atoi(str);
                }
                v++;
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
            }
            else if(line[i] == '\n')
            {
                if(v == 13)
                {
                    processes[num_processes].priority = atoi(str);
                }
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
                break;
            }
        }
        num_processes++;
    }

    //Close the input file
   fclose(the_file);
   if(a==1){
        for(int i=0;i<531;i++)
        {
            if(strcmp(processes[i].Severity_of_injuries, "Severe") == 0)
            {
                processes[i].priority = 3;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Moderate") == 0)
            {
                processes[i].priority = 2;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Minor") == 0)
            {
                processes[i].priority = 1;
            }
        }
    for (int i = 0; i < 531; i++) {
        for (int j = 0; j < 530; j++) {
                if (strcmp(processes[j].Disaster_Type, "Flood") == 0){
            if (processes[j].priority >processes[j + 1].priority) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    }
    int m=0;
    int arrt=INT_MAX;
int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Flood") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Flood") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_ps.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("PS scheduling results written to output_ps.csv\n");
}
else if(a==2){
        for(int i=0;i<531;i++)
        {
            if(strcmp(processes[i].Severity_of_injuries, "Severe") == 0)
            {
                processes[i].priority = 3;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Moderate") == 0)
            {
                processes[i].priority = 2;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Minor") == 0)
            {
                processes[i].priority = 1;
            }
        }
    for (int i = 0; i < 531; i++) {
        for (int j = 0; j < 530; j++) {
                if (strcmp(processes[j].Disaster_Type, "Earthquake") == 0){
            if (processes[j].priority >processes[j + 1].priority) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    }
    int m=0;
    int arrt=INT_MAX;
int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Earthquake") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_ps.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("PS scheduling results written to output_ps.csv\n");
}
else if(a==3){
        for(int i=0;i<531;i++)
        {
            if(strcmp(processes[i].Severity_of_injuries, "Severe") == 0)
            {
                processes[i].priority = 3;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Moderate") == 0)
            {
                processes[i].priority = 2;
            }
            else if(strcmp(processes[i].Severity_of_injuries, "Minor") == 0)
            {
                processes[i].priority = 1;
            }
        }
    for (int i = 0; i < 531; i++) {
        for (int j = 0; j < 530; j++) {
                if (strcmp(processes[j].Disaster_Type, "Volcano") == 0){
            if (processes[j].priority >processes[j + 1].priority) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    }
    int m=0;
    int arrt=INT_MAX;
int k = 0;
     for (int i = 0 ;i<531 ;i++)
     {
         if (strcmp(processes[i].Disaster_Type, "Volcano") == 0)
         {
             if(processes[i].Arrival_time <= arrt)
             {
                 arrt = processes[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <531 ; i++)
         {
             if (processes[i].Arrival_time <= arrt && strcmp(processes[i].Disaster_Type, "Volcano") == 0)
             {
                 m++;
                 arrt = arrt+processes[i].Burst_Time_sjf;
                 processes[i].completion_time = arrt;
                 processes[i].turnaround_time = processes[i].completion_time - processes[i].Arrival_time;
                 processes[i].waiting_time = processes[i].turnaround_time - processes[i].Burst_Time_sjf;
                 temp[counter] = processes[i];
                 processes[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_ps.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

   printf("PS scheduling results written to output_ps.csv\n");
}
else{
    cout<<"Invalid input";
}
}

void mq()
{
    int a;
    cout<<"Enter 1 for Flood,2 for Earthquake and 3 for Volcano: "<<endl;
    cin>>a;
    FILE *the_file=fopen("pp.csv","r");
    if(the_file==NULL)
    {
        perror("Unable to open the file.");
        exit(1);
    }

    int max_processes = 531;  // Maximum number of processes (adjust as needed)
    struct Process processes[max_processes];
    int num_processes = 0;

    char line[2048];
    while (feof(the_file) != true && num_processes<max_processes) {
        fgets(line,2048,the_file);
        char str[100];
        for(int l=0;l<100;l++)
        {
            str[l] = '\0';
        }
        int v = 0;
        int y = 0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i] != '\n' && line[i] != ',')
            {
                str[y] = line[i];
                y++;
            }
            else if(line[i] == ',')
            {
                str[y] = '\0';
                y = 0;
                if(v == 0)
                {
                    processes[num_processes].id = atoi(str);
                }
                else if(v == 1)
                {
                    strcpy(processes[num_processes].name,str);
                }
                else if(v == 2)
                {
                    processes[num_processes].age = atoi(str);
                }
                else if(v == 3)
                {
                    strcpy(processes[num_processes].gender,str);
                }
                else if(v == 4)
                {
                    processes[num_processes].Arrival_time = atoi(str);
                }
                else if(v == 5)
                {
                    strcpy(processes[num_processes].Location,str);
                }
                else if(v == 6)
                {
                    processes[num_processes].Area_Size = atoi(str);
                }
                else if(v == 7)
                {
                    strcpy(processes[num_processes].Severity_of_injuries,str);
                }
                else if(v == 8)
                {
                    strcpy(processes[num_processes].Disaster_Type,str);
                }
                else if(v == 9)
                {
                    processes[num_processes].Burst_time_fcfs_ps = atoi(str);
                }
                else if(v == 10)
                {
                    processes[num_processes].Burst_Time_rr = atoi(str);
                }
                else if(v == 11)
                {
                    processes[num_processes].Burst_Time_sjf = atoi(str);
                }
                else if(v == 12)
                {
                    processes[num_processes].Burst_time_mq = atoi(str);
                }
                v++;
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
            }
            else if(line[i] == '\n')
            {
                if(v == 13)
                {
                    processes[num_processes].priority = atoi(str);
                }
                for(int l=0;l<100;l++)
                {
                    str[l] = '\0';
                }
                break;
            }
        }
        num_processes++;
    }



    // Close the input file
   fclose(the_file);
   if(a==1){
     // Separate processes into two queues based on priority
    struct Process highPriorityQueue[531];
    struct Process lowPriorityQueue[531];
    int highPriorityCount = 0;
    int lowPriorityCount = 0;

    // Divide processes into queues
    for (int i = 0; i < 531; i++) {
            if (strcmp(processes[i].Disaster_Type, "Flood") == 0){
        if (processes[i].priority >= 10) {
            highPriorityQueue[highPriorityCount++] = processes[i];
        } else {
            lowPriorityQueue[lowPriorityCount++] = processes[i];
        }
    }
    }


    int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<highPriorityCount;i++)
     {
         for(int j=1;j<highPriorityCount;j++)
         {
             if (strcmp(highPriorityQueue[j].Disaster_Type, "Flood") == 0){
             if(highPriorityQueue[j-1].Burst_Time_sjf>highPriorityQueue[j].Burst_Time_sjf)
             {
                 struct Process temp1=highPriorityQueue[j-1];
                 highPriorityQueue[j-1]=highPriorityQueue[j];
                 highPriorityQueue[j]=temp1;
             }
         }
     }
     }
     int k = 0;
     for (int i = 0 ;i<highPriorityCount ;i++)
     {
         if (strcmp(highPriorityQueue[i].Disaster_Type, "Flood") == 0)
         {
             if(highPriorityQueue[i].Arrival_time <= arrt)
             {
                 arrt = highPriorityQueue[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <highPriorityCount ; i++)
         {
             if (highPriorityQueue[i].Arrival_time <= arrt && strcmp(highPriorityQueue[i].Disaster_Type, "Flood") == 0)
             {
                 m++;
                 arrt = arrt+highPriorityQueue[i].Burst_Time_sjf;
                 highPriorityQueue[i].completion_time = arrt;
                 highPriorityQueue[i].turnaround_time = highPriorityQueue[i].completion_time - highPriorityQueue[i].Arrival_time;
                 highPriorityQueue[i].waiting_time = highPriorityQueue[i].turnaround_time - highPriorityQueue[i].Burst_Time_sjf;
                 temp[counter] = highPriorityQueue[i];
                 highPriorityQueue[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_high.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    for (int i = 0; i < lowPriorityCount; i++) {

        // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<lowPriorityCount;i++)
     {
         for(int j=1;j<lowPriorityCount;j++)
         {
             if (strcmp(lowPriorityQueue[j].Disaster_Type, "Flood") == 0){
             if(lowPriorityQueue[j-1].Arrival_time>lowPriorityQueue[j].Arrival_time)
             {
                 struct Process temp=lowPriorityQueue[j-1];
                 lowPriorityQueue[j-1]=lowPriorityQueue[j];
                 lowPriorityQueue[j]=temp;
             }
         }
     }
     }


   for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Flood") == 0){
        if (i == 0) {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i].Arrival_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        } else {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i - 1].completion_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        }

        if (lowPriorityQueue[i].completion_time < lowPriorityQueue[i].Arrival_time) {
            lowPriorityQueue[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
lowPriorityQueue[0].waiting_time = 0;
lowPriorityQueue[0].turnaround_time = lowPriorityQueue[0].Burst_time_fcfs_ps;

for (int i = 1; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Flood") == 0){
lowPriorityQueue[i].waiting_time = lowPriorityQueue[i - 1].turnaround_time;
lowPriorityQueue[i].turnaround_time = lowPriorityQueue[i].waiting_time +lowPriorityQueue[i].Burst_time_fcfs_ps;
}
}
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_low.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,Distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Flood") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", lowPriorityQueue[i].id, lowPriorityQueue[i].name,lowPriorityQueue[i].age, lowPriorityQueue[i].gender,lowPriorityQueue[i].Arrival_time, lowPriorityQueue[i].Location,lowPriorityQueue[i].Area_Size, lowPriorityQueue[i].Severity_of_injuries, lowPriorityQueue[i].Disaster_Type,lowPriorityQueue[i].Burst_time_fcfs_ps,lowPriorityQueue[i].waiting_time,lowPriorityQueue[i].turnaround_time,lowPriorityQueue[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    }
     printf("MQ scheduling results written to output_low.csv and output_high.csv\n");

   }
 else if(a==2){
     // Separate processes into two queues based on priority
    struct Process highPriorityQueue[531];
    struct Process lowPriorityQueue[531];
    int highPriorityCount = 0;
    int lowPriorityCount = 0;

    // Divide processes into queues
    for (int i = 0; i < 531; i++) {
            if (strcmp(processes[i].Disaster_Type, "Earthquake") == 0){
        if (processes[i].priority >= 10) {
            highPriorityQueue[highPriorityCount++] = processes[i];
        } else {
            lowPriorityQueue[lowPriorityCount++] = processes[i];
        }
    }
    }


    int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<highPriorityCount;i++)
     {
         for(int j=1;j<highPriorityCount;j++)
         {
             if (strcmp(highPriorityQueue[j].Disaster_Type, "Earthquake") == 0){
             if(highPriorityQueue[j-1].Burst_Time_sjf>highPriorityQueue[j].Burst_Time_sjf)
             {
                 struct Process temp1=highPriorityQueue[j-1];
                 highPriorityQueue[j-1]=highPriorityQueue[j];
                 highPriorityQueue[j]=temp1;
             }
         }
     }
     }
     int k = 0;
     for (int i = 0 ;i<highPriorityCount ;i++)
     {
         if (strcmp(highPriorityQueue[i].Disaster_Type, "Earthquake") == 0)
         {
             if(highPriorityQueue[i].Arrival_time <= arrt)
             {
                 arrt = highPriorityQueue[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <highPriorityCount ; i++)
         {
             if (highPriorityQueue[i].Arrival_time <= arrt && strcmp(highPriorityQueue[i].Disaster_Type, "Earthquake") == 0)
             {
                 m++;
                 arrt = arrt+highPriorityQueue[i].Burst_Time_sjf;
                 highPriorityQueue[i].completion_time = arrt;
                 highPriorityQueue[i].turnaround_time = highPriorityQueue[i].completion_time - highPriorityQueue[i].Arrival_time;
                 highPriorityQueue[i].waiting_time = highPriorityQueue[i].turnaround_time - highPriorityQueue[i].Burst_Time_sjf;
                 temp[counter] = highPriorityQueue[i];
                 highPriorityQueue[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_high.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    for (int i = 0; i < lowPriorityCount; i++) {

        // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<lowPriorityCount;i++)
     {
         for(int j=1;j<lowPriorityCount;j++)
         {
             if (strcmp(lowPriorityQueue[j].Disaster_Type, "Earthquake") == 0){
             if(lowPriorityQueue[j-1].Arrival_time>lowPriorityQueue[j].Arrival_time)
             {
                 struct Process temp=lowPriorityQueue[j-1];
                 lowPriorityQueue[j-1]=lowPriorityQueue[j];
                 lowPriorityQueue[j]=temp;
             }
         }
     }
     }


   for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Earthquake") == 0){
        if (i == 0) {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i].Arrival_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        } else {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i - 1].completion_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        }

        if (lowPriorityQueue[i].completion_time < lowPriorityQueue[i].Arrival_time) {
            lowPriorityQueue[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
lowPriorityQueue[0].waiting_time = 0;
lowPriorityQueue[0].turnaround_time = lowPriorityQueue[0].Burst_time_fcfs_ps;

for (int i = 1; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Earthquake") == 0){
lowPriorityQueue[i].waiting_time = lowPriorityQueue[i - 1].turnaround_time;
lowPriorityQueue[i].turnaround_time = lowPriorityQueue[i].waiting_time +lowPriorityQueue[i].Burst_time_fcfs_ps;
}
}
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_low.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,Distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Earthquake") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", lowPriorityQueue[i].id, lowPriorityQueue[i].name,lowPriorityQueue[i].age, lowPriorityQueue[i].gender,lowPriorityQueue[i].Arrival_time, lowPriorityQueue[i].Location,lowPriorityQueue[i].Area_Size, lowPriorityQueue[i].Severity_of_injuries, lowPriorityQueue[i].Disaster_Type,lowPriorityQueue[i].Burst_time_fcfs_ps,lowPriorityQueue[i].waiting_time,lowPriorityQueue[i].turnaround_time,lowPriorityQueue[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    }
     printf("MQ scheduling results written to output_low.csv and output_high.csv\n");

   }
 else if(a==3){
     // Separate processes into two queues based on priority
    struct Process highPriorityQueue[531];
    struct Process lowPriorityQueue[531];
    int highPriorityCount = 0;
    int lowPriorityCount = 0;

    // Divide processes into queues
    for (int i = 0; i < 531; i++) {
            if (strcmp(processes[i].Disaster_Type, "Volcano") == 0){
        if (processes[i].priority >= 10) {
            highPriorityQueue[highPriorityCount++] = processes[i];
        } else {
            lowPriorityQueue[lowPriorityCount++] = processes[i];
        }
    }
    }


    int m = 0;
   int arrt=INT_MAX;
     // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<highPriorityCount;i++)
     {
         for(int j=1;j<highPriorityCount;j++)
         {
             if (strcmp(highPriorityQueue[j].Disaster_Type, "Volcano") == 0){
             if(highPriorityQueue[j-1].Burst_Time_sjf>highPriorityQueue[j].Burst_Time_sjf)
             {
                 struct Process temp1=highPriorityQueue[j-1];
                 highPriorityQueue[j-1]=highPriorityQueue[j];
                 highPriorityQueue[j]=temp1;
             }
         }
     }
     }
     int k = 0;
     for (int i = 0 ;i<highPriorityCount ;i++)
     {
         if (strcmp(highPriorityQueue[i].Disaster_Type, "Volcano") == 0)
         {
             if(highPriorityQueue[i].Arrival_time <= arrt)
             {
                 arrt = highPriorityQueue[i].Arrival_time;
             }
             k++;
         }

     }
        printf("%d\n",k);
     struct Process temp[k];
     int counter = 0;
     while (m<k)
     {
         for (int i = 0;i <highPriorityCount ; i++)
         {
             if (highPriorityQueue[i].Arrival_time <= arrt && strcmp(highPriorityQueue[i].Disaster_Type, "Volcano") == 0)
             {
                 m++;
                 arrt = arrt+highPriorityQueue[i].Burst_Time_sjf;
                 highPriorityQueue[i].completion_time = arrt;
                 highPriorityQueue[i].turnaround_time = highPriorityQueue[i].completion_time - highPriorityQueue[i].Arrival_time;
                 highPriorityQueue[i].waiting_time = highPriorityQueue[i].turnaround_time - highPriorityQueue[i].Burst_Time_sjf;
                 temp[counter] = highPriorityQueue[i];
                 highPriorityQueue[i].Arrival_time = INT_MAX;
                 counter++;
                 break;
             }
         }
     }
// Calculate waiting time and turnaround time and completion_time
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_high.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
    // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");
    // Write the results to the output CSV file
    for (int i = 0; i < k; i++) {
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", temp[i].id, temp[i].name,temp[i].age, temp[i].gender,temp[i].Arrival_time, temp[i].Location,temp[i].Area_Size, temp[i].Severity_of_injuries, temp[i].Disaster_Type,temp[i].Burst_Time_sjf,temp[i].waiting_time,temp[i].turnaround_time,temp[i].priority);
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    for (int i = 0; i < lowPriorityCount; i++) {

        // Sort the array of processes by arrival time (FCFS)
     for(int i=0;i<lowPriorityCount;i++)
     {
         for(int j=1;j<lowPriorityCount;j++)
         {
             if (strcmp(lowPriorityQueue[j].Disaster_Type, "Volcano") == 0){
             if(lowPriorityQueue[j-1].Arrival_time>lowPriorityQueue[j].Arrival_time)
             {
                 struct Process temp=lowPriorityQueue[j-1];
                 lowPriorityQueue[j-1]=lowPriorityQueue[j];
                 lowPriorityQueue[j]=temp;
             }
         }
     }
     }


   for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Volcano") == 0){
        if (i == 0) {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i].Arrival_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        } else {
            lowPriorityQueue[i].completion_time = lowPriorityQueue[i - 1].completion_time + lowPriorityQueue[i].Burst_time_fcfs_ps;
        }

        if (lowPriorityQueue[i].completion_time < lowPriorityQueue[i].Arrival_time) {
            lowPriorityQueue[i].completion_time = 999999999; // Completion time is infinity
        }
    }
   }
// Calculate waiting time and turnaround time and completion_time
int current_time = 0;  // Initialize the current time
lowPriorityQueue[0].waiting_time = 0;
lowPriorityQueue[0].turnaround_time = lowPriorityQueue[0].Burst_time_fcfs_ps;

for (int i = 1; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Volcano") == 0){
lowPriorityQueue[i].waiting_time = lowPriorityQueue[i - 1].turnaround_time;
lowPriorityQueue[i].turnaround_time = lowPriorityQueue[i].waiting_time +lowPriorityQueue[i].Burst_time_fcfs_ps;
}
}
    // Open the output CSV file for writing
    FILE* output_file;
    output_file=fopen("output_low.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output.csv");
    }
     // Write the header to the output CSV file
    fprintf(output_file, "Process ID,Name,Age,Gender,Arrival Time,Location,Area_size,Severe,Distype,Burst Time,Waiting_time,Turnaround_time,Priority\n");

    // Write the results to the output CSV file
    for (int i = 0; i < lowPriorityCount; i++) {
        if (strcmp(lowPriorityQueue[i].Disaster_Type, "Volcano") == 0){
            fprintf(output_file, "%d,%s,%d,%s,%d,%s,%d,%s,%s,%d,%d,%d,%d\n", lowPriorityQueue[i].id, lowPriorityQueue[i].name,lowPriorityQueue[i].age, lowPriorityQueue[i].gender,lowPriorityQueue[i].Arrival_time, lowPriorityQueue[i].Location,lowPriorityQueue[i].Area_Size, lowPriorityQueue[i].Severity_of_injuries, lowPriorityQueue[i].Disaster_Type,lowPriorityQueue[i].Burst_time_fcfs_ps,lowPriorityQueue[i].waiting_time,lowPriorityQueue[i].turnaround_time,lowPriorityQueue[i].priority);
    }
    }
    if(ferror(output_file))
    {
        printf("Error writing to file");
    }

    // Close the output file
    fclose(output_file);

    }
     printf("MQ scheduling results written to output_low.csv and output_high.csv\n");

   }
    else{
        cout<<"Invalid input";
    }
   }





int main()
{
int n;

    cout<<"Enter 1 for evacuation of disaster stricken areas"<<endl;
    cout<<"Enter 2 for dispatching search and rescue teams"<<endl;
    cout<<"Enter 3 for allocation of relief supplies to affected areas"<<endl;
    cout<<"Enter 4 for emergency medical treatment at a disaster site"<<endl;
    cout<<"Enter 5 for disaster management teams with specialized functions"<<endl;
    cout<<"Enter your choice:";
    cin>>n;
    switch(n)
        {
    case 1:
        fcfs();
        break;
    case 2:
        sjf();
        break;
    case 3:
        rr();
        break;
    case 4:
        ps();
        break;
    case 5:
        mq();
        break;
    case 6:
         exit(1);
        break;
        }
}

