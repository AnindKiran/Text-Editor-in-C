#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000
void deletion();
void capitalize();
void append();
void create();
void read_file();
void open();
void cprog();
void rename1();
void occurence();
void replace();
void cat();
void replaceAll(char *str, const char *oldWord, const char *newWord);


void replace()
{
    /* File pointer to hold reference of input file */
    FILE * fPtr; int myfile;
    FILE * fTemp;
    char path[100];    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];
    printf("Enter path of source file: ");fflush(stdin);
    scanf("%[^\n]s", path);fflush(stdin);
    printf("Enter word to replace: ");fflush(stdin);
    scanf("%s[^\n]", oldWord);fflush(stdin);
    printf("Replace %s with: ",oldWord);fflush(stdin);
    scanf("%s[^\n]", newWord);fflush(stdin);
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w"); 
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        replaceAll(buffer, oldWord, newWord);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);
    system("replace.txt");
}

void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;
    owlen = strlen(oldWord);
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0'; 
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}
void deletion()
{
	system( " dir *.txt");
	int myfile;
	char filename[50];
	printf("Enter the text file to be deleted:\n");
	fflush(stdin);
	gets(filename);
	fflush(stdin);
	myfile=remove(filename);
	if(myfile==0)
		printf("%s file successfully deleted.\n",filename);
	else
	{
		printf("Failed to delete file\n");
		perror("Following error occurred:");
	}
}

void capitalize()
{
	system( " dir *.txt");
	FILE *f,*f1;
	char filename[100];
	printf("Enter file-name:");fflush(stdin);
	scanf("%[^\n]s",filename);fflush(stdin);
	f=fopen(filename,"r");
	f1=fopen("cap.txt","w");
	char line[100];
	int fullstop=1;
	while(fgets(line,100,f)!=NULL)
		{ int i;
		for (i=0;line[i]!='\0';++i)
			{
			if(fullstop==1&&((int)line[i]>=65&&(int)line[i]<=90))
			{
				fullstop=0;
			}
			if(fullstop==1&&((int)line[i]>=97&&(int)line[i]<=122))
				{
				line[i]=(char)((int)(line[i])-32);
				fullstop=0;
				}
			if(line[i]=='.')
				fullstop=1;
			fprintf(f1,"%c",line[i]);
			}
		}
	fclose(f);
	fclose(f1);
	system("cap.txt");
}

void append()
{
	FILE *f1,*f2;
	char file[20];
	char c;
	printf("\nEnter the file name to append: ");
	scanf("%s",file);
	f2=fopen(file,"r");
	if(f2==NULL)
	{
		printf("\nFile not found!");
		fclose(f2);
		goto end;
	}
	while(!feof(f2))
	{
		c=getc(f2);
		printf("%c",c);
	}
	fclose(f2);//printf("\nType the text and press Ctrl+S to append.\n");
	f1=fopen(file,"a");
	while((c=getchar())!=19)//ASCII value for Ctrl+S
	{
		fputc(c,f1);
	}	
	fclose(f1);
	
	
	end: fclose(f2);
	system(file);
	
 	
}

void create()
{
	FILE *f1;
	char file[20];
	printf("\n\nEnter the file name to create:  ");fflush(stdin);
	scanf("%s",file);fflush(stdin);
	f1=fopen(file,"w"); 
	fclose(f1);

}

void read_file()
{
	char filename[100];
	printf("Enter file-name:");fflush(stdin);
	scanf("%[^\n]s",filename);fflush(stdin);
	char e;
    FILE *fp;
	fp = fopen(filename, "r");
    if(fp==NULL)
    {
    	printf("File not found");
    }
    else 
	{
		while (e!=EOF) 
		{
	        e = getc(fp);
	        putchar(e);
    	}
	}
	fclose(fp);
}

void open()
{
	char filename[100];
	system( " dir *.txt");
	printf("Enter file-name:");fflush(stdin);
	scanf("%[^\n]s",filename);fflush(stdin);
	system(filename);
}


void occurence()
{
system( " dir *.txt");
 FILE *f;
char ch,arr[100],arr1[100],filename[100];
int i,j,k,count;
char *token;
printf("Enter the filename:");
fflush(stdin);
scanf("%s",filename);
fflush(stdin);
f=fopen(filename,"r");
printf("Enter the word to be searched:");
scanf("%s",arr1);
ch=getc(f);
j=1;
count=0;
while(!feof(f))
	{
	i=0;
	while(ch!='\n')
		{
		if(ch=='.')
			{
				ch=getc(f);
				continue;
			}
		arr[i]=ch;
		i+=1;
		ch=getc(f);
		if(feof(f))
			break;
		}
	arr[i]='\0';
	token=strtok(arr," ");
	k=0;
	while(token!=NULL)
		{
		k+=1;
		if(strcmp(token,arr1)==0)
			{
				count+=1;
				printf("OCCURENCE %d:\n",count);
				printf("Line:%d",j);
				printf("\nWord:%d\n\n",k);
			}
		token=strtok(NULL," ");
		}
	ch=getc(f);
	j+=1;
	}

printf("\nTotal Number of occurences:%d",count);
fclose(f);

}
void cat()
{
FILE *f,*f1,*f2;
char ch;
char filename1[100],filename2[100],filename3[100];
printf("Enter file-name 1:");fflush(stdin);
scanf("%[^\n]s",filename1);fflush(stdin);
printf("Enter file-name 2:");fflush(stdin);
scanf("%[^\n]s",filename2);fflush(stdin);
printf("Enter file-name you want to concatenate in:");fflush(stdin);
scanf("%[^\n]s",filename3);fflush(stdin);
f=fopen(filename1,"r");
f1=fopen(filename2,"r");
f2=fopen(filename3,"w");
while(!feof(f))
	{
	ch=getc(f);
	if(ch!=EOF)
		fputc(ch,f2);
	}
fputc('\n',f2);
while(!feof(f1))
	{
	ch=getc(f1);
	if(ch!=EOF)
		fputc(ch,f2);
	}
fclose(f1);
fclose(f);
fclose(f2);
f=fopen("c.txt","r");
while(!feof(f))
	{
	ch=getc(f);
	printf("%c",ch);
	}
fclose(f);
system(filename3);
}


void cprog()
{

	char oldname[20];
	printf("Enter org file-name <enter in .txt format>:");fflush(stdin);
	scanf("%[^\n]s",oldname);fflush(stdin);
	char newname[20];
	printf("Enter new file-name: <enter a .c extension>");fflush(stdin); //enter .c extension. to make it automated later
	scanf("%[^\n]s",newname);fflush(stdin);
	int value = rename(oldname,newname); 
	printf("Return Status : %d\n",value);
	char str[30] = "gcc "; 
	strcat(str," -o test ");strcat(str,newname);
	printf(str);printf("\n\n");
	system(str);system("test");	
}

void rename1()
{
	char oldname[20];
	printf("Enter org file-name <enter in .txt format>:");fflush(stdin);
	scanf("%[^\n]s",oldname);fflush(stdin);
	char newname[20];
	printf("Enter new file-name: <enter a .c extension>");fflush(stdin); //enter .c extension. to make it automated later
	scanf("%[^\n]s",newname);fflush(stdin);
	int value = rename(oldname,newname); 
	printf("Return Status : %d",value);
}

int main() // add do while loop for choices
{
	char choice,ch;
	do 
	{   
		system("CLS");
		printf("\t\t\t\t\t EDITOR");
		printf("\nA)Create\nB)Add Content\nC)Read File\nD)Capitalize\nE)Delete a file\nF)Undo\nG)Rename\nH)Open\nI)Count of Words\nJ)Find and Replace\nK)C prog execution\nL)Concetenate two files\n\nEnter a Choice ");
		scanf("%c",&choice);	
		switch(choice)
		{
			case 'a':
			case 'A':
					create();break;
			case 'b':
			case 'B':	
					append();break;
			case 'c':
			case 'C':
					read_file();break;
			case 'd':
			case 'D': 
					capitalize();break;
			case 'e':
			case 'E':
					deletion();break;
			case 'f':
			case 'F': 
					//undo();
					break;
						
			case 'g':
			case 'G':
					rename1();
					break;
			case 'h':
			case'H': 
					open();break;
					break;
						
			case 'i':
			case 'I': 
					occurence();break;	
			case 'j':
			case 'J': 
					replace();break;
			case 'k':
			case 'K': 
					cprog();break;
			case 'l':
			case 'L': 
					cat();break;		
			
					
		}
		printf("\n Do u want to continue [Enter] : ");fflush(stdin);scanf("%c",&ch);fflush(stdin);
	}while(ch=='\n'|| ch=='\n');
} 
