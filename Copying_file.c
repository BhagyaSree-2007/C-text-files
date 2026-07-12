/*Write a C program to copy the content from one file to another file*/
#include<stdio.h>
int main()
{
   FILE *fp1,*fp2;
   char ch;
   fp1=fopen("source.txt","r");
   if(fp1==NULL)
   {
      printf("Source File cannot be opened.\n");
      return 1;
   }
   fp2=fopen("destination.txt","w");
   if(fp2==NULL)
   {
      printf("Destination File cannot be opened.\n");
      return 1;
   }
   while((ch=fgetc(fp1))!=EOF)
   {
      fputc(ch,fp2);
   }
   printf("File copied successfully.\n");
   fclose(fp1);
   fclose(fp2);
   return 0;
}
