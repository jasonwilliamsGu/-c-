# include<stdio.h> 
# include<string.h> 
# include<stdlib.h>
# include<windows.h>

# include<istream>
# include <conio.h>
# include <cstdlib>
# include <cstdio>
# include <ctime>
# include <cmath>
using namespace std;
# define ERROR 0
# define OK 1 
# define ElemType int
# define MAX 99

# define FILE_NAME "accountbook.txt"

int game_height = 20;
int game_width  = 20;

/*typedef */struct PersonalAccount      //�����˻� 
{
 int ID;
 char name[100000];
 char password[10000];
 int wins;                   //ʤ�� 
 int rank;                   //���� 
 int x;                    //����x�� 
} user[MAX];

# include"fromme.h" 
# include"login.h"

void writeFILE_NAME()
{
	printf("��������Ϣ�����ַ��");
	 
}
int main() 
{
	
	FILE *fp=fopen(FILE_NAME,"a+");
	//���ļ� 
	if (fp == NULL)
	{
		printf("Cannot open file!\n");
		return 1;
	}
	int r_n = 1;
	rewind(fp);
	/*while(!feof(fp))
	{
		c = fgetc(fp);
		if (c == '\n')
		r_n++;        //�����ļ������ݵ����� 
	}*/
	rewind(fp);//��ָ�������ڵ�һ�� 
	int i=1;
	while(fscanf(fp,"%d %s %s %d %d %d",&user[i].ID,&user[i].name,&user[i].password,&user[i].wins,&user[i].rank,&user[i].x)==6)//��ȡ�ļ��е�ֵ 
	{
	//	fgets(buf,BUFSIZE,fp);  //һ�ζ�ȡһ��
		r_n++;
		i++;
	//	fscanf(fp,"%d %s %s %d %d %d",&user[i].ID,&user[i].name,&user[i].password,&user[i].wins,&user[i].rank,user[i].x);
	}
	fclose(fp);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE  | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("cls"); 
	
	start1(r_n);
	return 0;	
}




