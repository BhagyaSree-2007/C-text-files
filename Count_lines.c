/*Write a C program to count number of lines and characters in a text file*/
#include<stdio.h>
int main()
{
   FILE *fp;
   char ch;
   int c=0,l=0;
   fp=fopen("ex10a.txt","r");
   if(fp==NULL)
   {
      printf("File cannot be opened.\n");
      return 1;
   }
   while((ch=fgetc(fp))!=EOF)
   {
      if(ch!='\n' && ch!='\r' && ch!='\t')
         c++;
      if(ch=='\n')
         l++;
   }
   fclose(fp);
   printf("Total Characters:%d\n",c);
   printf("Total lines:%d\n",l);
   return 0;
}
