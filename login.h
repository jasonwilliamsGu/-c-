int Login(int r_n);
int Create_Paccount(int N);
int modification(int N);   //���ܣ�3�����޸��û���Ϣ
int Destoruction(int N);
void start1(int r_n);
int gamecontrol(int N,int r_n);

int FlashFile(int r_n);
void ResetRecord(int idpass);
void CheckRank(int r_n); 

void picture1()
{
	printf("\n\n\n\n");
	
	printf("\t\t   * * * * * * * * �� * ʼ * �� * �� * * * * * * * * *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
	printf("\t\t   *    ��������������Ϸ        ��ӭ�����ҵ�����     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *      1.�û�ע��                2.�û���½       *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *      3.�ÿ�����   4.�鿴����   5.��������       *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     ��д�ߣ���׿��  20����1��  202014210104     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("���������֣� ");
 } 


void start1(int r_n)      //��Ϸ��ʼ���� 
{  
	int choice;         
	char ch;  
	
	picture1();
	
	scanf("%d",&choice); 
	
	
	          
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) 
	{
		printf("�Ƿ����룬���������룺"); 
		scanf("%d",&choice);
	}  
	if(choice == 1)
	{
		if(Create_Paccount(r_n)==ERROR)
		{
			system("PAUSE");
			system("cls");
			start1(r_n);
		}
		else
		start1(r_n+1);
	}
	
	 else if(choice == 2)
	 {
	  system("cls");
	  Login(r_n);
	 }
	 else if (choice == 3)
	 {
	 	system("cls");
        gamecontrol(98,r_n);
	 }
	 else if (choice == 4)
	 {
	 	CheckRank(r_n) ;
	 	system("PAUSE");
	 	system("cls");
	 	start1(r_n);
	 }
	 
	  else if (choice == 5)
	 {
	 	FlashFile(r_n);
	 }
	 
}

int
Login(int r_n)    //�û���¼ 
{
	int id,N,choice;
	char p[20];
	printf("�������˻���");  scanf("%d",&id);   getchar();
	N = id-32300;
	printf("���������룺");  
	scanf("%s",p);
	if(!strcmp(user[N].password,p)){
		
	Changeinformation(N,r_n);
}
	else{
	 	 printf("��½ʧ�ܣ�"); return ERROR;
	 }
	
	 return OK; 
}

int Create_Paccount(int N){
	char p1[20],p2[20];
    if(N>=MAX){
    	printf("�û����������������");
		return 0; 
	}
	user[N].ID=32300+N;
	printf("�����˺ţ�%d\n",user[N].ID);
	printf("�������û���(���ֽ��������֡���ĸ���»������)��");  getchar();   gets(user[N].name);   //(���ֽ��������֡���ĸ���»������) 
	/*if(user[N].name)*/printf("\n����������(����С��20λ�������пո�)��");       scanf("%s",p1);
	system("cls"); 
	if(strlen(p1)>=6){
		printf("���ٴ��������룺");  getchar();  scanf("%s",p2);
	}
	else{
		printf("������̣��û�ע��ʧ��");
		return ERROR;
	}
	system("cls"); 
	if(!strcmp(p1,p2)){                               
		printf("\n\n\n\t\t   * * * * * * * * %s:����ע��ɹ��� * * * * * * * * *",user[N].name);
		strcpy(user[N].password,p1);
		user[N].wins = 0;  
		FILE *fp=fopen(FILE_NAME,"a+");
		fprintf(fp,"%d %s %s %d %d %d\n",user[N].ID,user[N].name,user[N].password,user[N].wins,user[N].rank,user[N].x);
		fclose(fp);
	}
	else{
		printf("�û�ע��ʧ��"); 
		return ERROR;
	}
	return N++;
}

int modification(int N)
{
	printf("�����û�������Ϣ�޸Ľ��棡\n");
	int choice; 
	printf("�޸����̴�С�밴1���鿴���̴�С�밴2\n");
	scanf("%d",&choice);
	while(choice!=1&&choice!=2)
		{ 
			printf("�������,����������.\n");
			scanf("%d",&choice);
		}  
	if(choice == 1){
		int x;
	printf("���������̴�С\n");
	scanf("%d",&x);
	user[N].x = x;
	printf("���̴�СΪ��%2d * %2d",user[N].x,user[N].x);
	}
	else
	printf("���̴�СΪ��%2d * %2d",user[N].x,user[N].x);
	return OK;
 } 
 
 int gamecontrol(int N,int r_n)
 {
 	char k;  
	do{
		int random = user[N].x;
		if(random == 0)
		random = 15;
		startgame(N,random,r_n);   
		printf("��Ҫ����һ����?����y��n��"); 
		getchar(); 
		scanf("%c",&k);   
	  while(k!='y'&&k!='n')
		{ 
			printf("�������,����������.\n");
			scanf("%c",&k);
		}   
		system("cls"); 
	}
	while(k=='y');  
	printf("ллʹ��!\n");
	system("PAUSE");
	start1(r_n);
	return 0;
	
 }//������Ϸ��
 
void Changeinformation(int idpass,int r_n)   //�޸��û�������Ϣ 
 {
 	system("cls");
 	printf("\n\n\n\n");
	
	printf("\t\t   * * * * * * * * �û���Ϣ�޸Ľ���  * * * * * * * * *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
	printf("\t\t   *      �û���%10s        ���̴�С��%2d       *\n",user[idpass].name,user[idpass].x);
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     1.�޸����̴�С          2.�û��ǳ��޸�      *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *       3.���ݸ���              4.������Ϸ        *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *       5.����ս��          6.���ؿ�ʼ�˵�����    *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     ��д�ߣ���׿��  20����1��  202014210104     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("���������֣� ");
    
    int choice;
    scanf("%d",&choice);           
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6) 
	{
		printf("�Ƿ����룬���������룺"); 
		scanf("%d",&choice);
	}  
	
	if(choice==1){
			modification(idpass);//�鿴���̴�С��ս������Ϣ���ṩ�޸����̴�Сѡ�
			printf("\n");
	        system("PAUSE");
			Changeinformation(idpass,r_n);
		}
		else if(choice==2)
		{
				printf("�������µ��û�����");  
				getchar();   
				gets(user[idpass].name); //�޸��û��� 
				printf("%s,�޸��û����ɹ���\n",user[idpass].name); 
				system("PAUSE");
				Changeinformation(idpass,r_n); 
		}
		else if(choice==3)
		{
			FlashFile(r_n);//���ݸ��� 
			system("cls");
			Changeinformation(idpass,r_n);
		}
		else if(choice==5)
		{
		   ResetRecord(idpass);
	    }
		else if(choice==4)
		{
			system("cls");
			gamecontrol(idpass,r_n);
	    }
	    else if(choice==6)
	    {
	    	system("cls");
	    	start1(r_n);
		}
	    getchar();
	    printf("\n��Enter��������Ϸ��");
	    char Enter;
	    Enter = getchar();
	    while(Enter!=10)
	    {
	     Enter = getchar();
		}
		if(Enter==10)
	     {
	      system("cls");
          gamecontrol(idpass,r_n);}
 }
 
int
 FlashFile(int r_n)
 {
 	FILE *fp=fopen(FILE_NAME,"w");//w,��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ��� 
	//���ļ� 
	if (fp == NULL)
	{
		printf("Cannot open file!\n");
		return 1;
	}
	rewind(fp);
	int N = 1;
	for (N = 1;N<r_n;N++)
	{
		fprintf(fp,"%d %s %s %d %d %d\n",user[N].ID,user[N].name,user[N].password,user[N].wins,user[N].rank,user[N].x);
	}
	fclose(fp);                                   //һ��Ҫд�������ı��޷����� 
	printf("�������ݳɹ���");
	printf("\n");
	system("PAUSE");
	system("cls");
	start1(r_n); 
 }
 
 void
 ResetRecord(int idpass)
 {
 	user[idpass].wins = 0;
 }
 
 void 
 CheckRank(int r_n)                   //���ݽṹ���򷽷� 
 {
 	system("cls");
 	printf("\n\n\t      * * * * * * * * * * ���а� * * * * * * * * * * * * * *\n");
 	struct RankQueue
 	{
 		char name[10000];
 		int wins;
 		int ranks;
	 }rankson[r_n];
	 
	 int r = 1;
	 for(r = 1;r<=r_n;r++)
	 {
	 	strcpy(rankson[r].name,user[r].name);
	 	rankson[r].wins = user[r].wins;
	 	rankson[r].ranks = 0;
	 }
	 
	 int b,u,temp;
	 char name[10000];
	 for(b = 0;b < r_n;b++)
	 {
	 	for (u = 0; u < r_n-b-1; u++)
	 	{
	 		if(rankson[u].wins>rankson[u+1].wins)
	 		{
	 			temp = rankson[u].wins;
	 			rankson[u].wins=rankson[u+1].wins;
	 			rankson[u+1].wins=temp;
	 			strcpy(name,rankson[u].name);
	 			strcpy(rankson[u].name,rankson[u+1].name);
	 			strcpy(rankson[u+1].name,name);
			 }
		 }
	 }	 
 	int i,z=1;
 	for(i = r_n-1;i >0;i--)
 	{
 		printf("\t\t  %2d*  %20s              ʤ����%d\n\n\n",z,rankson[i].name,rankson[i].wins);
 		z++;
	 }
 }
 
