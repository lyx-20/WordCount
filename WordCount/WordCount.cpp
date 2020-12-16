#include<stdio.h>
#include<string.h>
#include<string>
int zifushu (char * argv);
int dancishu (char * argv);
int main (int argc, char* argv[])
{	
	if (strcmp(argv[1],"-w")==0)
	{
		dancishu(argv [2]);		
	}
	else if (strcmp(argv[1],"-c")==0)
	{
		zifushu(argv [2]);
	}
	else
	{
		printf("检查输入\n");
	}
	return 0;
}
int zifushu (char* argv)
{
	FILE * fp;
	char ch;
	int count = 0;
	if ((fp = fopen(argv, "r") )== NULL)
	{
        printf("Cannot open file\n");
    }
    else
	{
        ch = fgetc(fp);
        while (ch != EOF)
		{
            
            ch = fgetc(fp);
			count++;
        }
		printf("\n字符数：%d\n",count);
    }
    fclose(fp);
	return 0;
}
int dancishu (char * argv)
{
	FILE * fp;
	char ch;
	int word;
	word = 1;
	if ((fp = fopen(argv, "r") )== NULL)
	{
        printf("Cannot open file\n");
    }
    else
	{

		ch = fgetc(fp);
		while (ch != EOF)
		{
			
			ch = fgetc(fp);
            if(ch == ' ')
			{
				word++;
			}
			if(ch == ',')
			{
				word++;
			}
			if(ch == '\n')
			{
				word++;
			}
        }
		printf("\n单词数：%d\n",word);
    }
	fclose(fp);
	return 0;
}
