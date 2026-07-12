/*Write a C program to store details of n students in a file student.txt using fprintf().
Then read the data usinf fscanf(),calculate each student grade and display Roll, name, marks, 
grade along with total and average*/
#include<stdio.h>
int main()
{
   FILE *fp;
   char name[20],grade;
   int j,i,roll,n;
   float marks[5];
   float average,sum=0;
   printf("Enter number of students:");
   scanf("%d",&n);
   getchar();
   fp=fopen("ex10c.txt","w");
   if(fp==NULL)
   {
      printf("Cannot open file for writing.\n");
      return 1;
   }
   printf("Enter details of %d students(Roll,Name,5marks):\n",n);
   for(i=0;i<n;i++)
   {
      printf("Student %d:\n",i+1);
      printf("Enter roll number:");
      scanf("%d",&roll);
      printf("Enter name:");
      scanf("%s",name);
      getchar();
      printf("Enter 5 marks:");
      for(j=0;j<5;j++)
         scanf("%f",&marks[j]);
      fprintf(fp,"%d %s %.2f %.2f %.2f %.2f %.2f\n",roll,name,marks[0],marks[1],marks[2],marks[3],marks[4]);
   }
   fclose(fp);
   fp=fopen("ex10c.txt","r");
   if(fp==NULL)
   {
      printf("Cannot open file for reading.\n");
      return 1;
   }
   printf("\nRoll\tName\tTotal\tAverage\tGrade\n");
   for(i=0;i<n;i++)
   {
      if(fscanf(fp,"%d %s %f %f %f %f %f",&roll,name,&marks[0],&marks[1],&marks[2],&marks[3],&marks[4])!=7)
      {
         break;
      }
      sum=0;
      for(j=0;j<5;j++)
         sum+=marks[j];
      average=sum/5;
      if(average>=90)
         grade='A';
      else if (average>=80)
         grade='B';
      else if (average>=70)
         grade='C';
      else if (average>=60)
         grade='D';
      else
         grade='F';
      printf("%d     %s     %.2f     %.2f     %c\n",roll,name,sum,average,grade);
   }
   fclose(fp);
   return 0;
}
