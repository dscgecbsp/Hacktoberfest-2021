#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("file2.txt","r");
    if(fp==NULL)
    printf("file does not exist");
    else
    {
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fp);
    }
    }
    fclose(fp);
    return 0;
}


#include <stdio.h>
int main()
{
    FILE *fp1,*fp2;
    char ch;
    fp1=fopen("file1.txt","r");
    fp2=fopen("file2.txt","w");
    ch=fgetc(fp1);
    while(ch!=EOF)
    {
        fputc(ch,fp2);
        ch=fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
