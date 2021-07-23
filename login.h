int Login(int r_n);
int Create_Paccount(int N);
int modification(int N);   //功能（3）：修改用户信息
int Destoruction(int N);
void start1(int r_n);
int gamecontrol(int N,int r_n);

int FlashFile(int r_n);
void ResetRecord(int idpass);
void CheckRank(int r_n); 

void picture1()
{
	printf("\n\n\n\n");
	
	printf("\t\t   * * * * * * * * 开 * 始 * 菜 * 单 * * * * * * * * *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
	printf("\t\t   *    这里是五子棋游戏        欢迎来到我的世界     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *      1.用户注册                2.用户登陆       *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *      3.访客试玩   4.查看排名   5.更新数据       *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     编写者：古卓恒  20网工1班  202014210104     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("请输入数字： ");
 } 


void start1(int r_n)      //游戏初始界面 
{  
	int choice;         
	char ch;  
	
	picture1();
	
	scanf("%d",&choice); 
	
	
	          
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) 
	{
		printf("非法输入，请重新输入："); 
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
Login(int r_n)    //用户登录 
{
	int id,N,choice;
	char p[20];
	printf("请输入账户：");  scanf("%d",&id);   getchar();
	N = id-32300;
	printf("请输入密码：");  
	scanf("%s",p);
	if(!strcmp(user[N].password,p)){
		
	Changeinformation(N,r_n);
}
	else{
	 	 printf("登陆失败！"); return ERROR;
	 }
	
	 return OK; 
}

int Create_Paccount(int N){
	char p1[20],p2[20];
    if(N>=MAX){
    	printf("用户数已满，敬请见谅");
		return 0; 
	}
	user[N].ID=32300+N;
	printf("您的账号：%d\n",user[N].ID);
	printf("请输入用户名(名字仅能由数字、字母、下划线组成)：");  getchar();   gets(user[N].name);   //(名字仅能由数字、字母、下划线组成) 
	/*if(user[N].name)*/printf("\n请输入密码(密码小于20位，不能有空格)：");       scanf("%s",p1);
	system("cls"); 
	if(strlen(p1)>=6){
		printf("请再次输入密码：");  getchar();  scanf("%s",p2);
	}
	else{
		printf("密码过短，用户注册失败");
		return ERROR;
	}
	system("cls"); 
	if(!strcmp(p1,p2)){                               
		printf("\n\n\n\t\t   * * * * * * * * %s:您已注册成功！ * * * * * * * * *",user[N].name);
		strcpy(user[N].password,p1);
		user[N].wins = 0;  
		FILE *fp=fopen(FILE_NAME,"a+");
		fprintf(fp,"%d %s %s %d %d %d\n",user[N].ID,user[N].name,user[N].password,user[N].wins,user[N].rank,user[N].x);
		fclose(fp);
	}
	else{
		printf("用户注册失败"); 
		return ERROR;
	}
	return N++;
}

int modification(int N)
{
	printf("进入用户棋盘信息修改界面！\n");
	int choice; 
	printf("修改棋盘大小请按1，查看棋盘大小请按2\n");
	scanf("%d",&choice);
	while(choice!=1&&choice!=2)
		{ 
			printf("输入错误,请重新输入.\n");
			scanf("%d",&choice);
		}  
	if(choice == 1){
		int x;
	printf("请输入棋盘大小\n");
	scanf("%d",&x);
	user[N].x = x;
	printf("棋盘大小为：%2d * %2d",user[N].x,user[N].x);
	}
	else
	printf("棋盘大小为：%2d * %2d",user[N].x,user[N].x);
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
		printf("还要再来一局吗?输入y或n："); 
		getchar(); 
		scanf("%c",&k);   
	  while(k!='y'&&k!='n')
		{ 
			printf("输入错误,请重新输入.\n");
			scanf("%c",&k);
		}   
		system("cls"); 
	}
	while(k=='y');  
	printf("谢谢使用!\n");
	system("PAUSE");
	start1(r_n);
	return 0;
	
 }//进入游戏。
 
void Changeinformation(int idpass,int r_n)   //修改用户个人信息 
 {
 	system("cls");
 	printf("\n\n\n\n");
	
	printf("\t\t   * * * * * * * * 用户信息修改界面  * * * * * * * * *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
	printf("\t\t   *      用户：%10s        棋盘大小：%2d       *\n",user[idpass].name,user[idpass].x);
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     1.修改棋盘大小          2.用户昵称修改      *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *       3.数据更新              4.进入游戏        *\n"); 
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *       5.重置战绩          6.返回开始菜单界面    *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *     编写者：古卓恒  20网工1班  202014210104     *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   *                                                 *\n");
    printf("\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("请输入数字： ");
    
    int choice;
    scanf("%d",&choice);           
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6) 
	{
		printf("非法输入，请重新输入："); 
		scanf("%d",&choice);
	}  
	
	if(choice==1){
			modification(idpass);//查看棋盘大小、战绩等信息。提供修改棋盘大小选项。
			printf("\n");
	        system("PAUSE");
			Changeinformation(idpass,r_n);
		}
		else if(choice==2)
		{
				printf("请输入新的用户名：");  
				getchar();   
				gets(user[idpass].name); //修改用户名 
				printf("%s,修改用户名成功！\n",user[idpass].name); 
				system("PAUSE");
				Changeinformation(idpass,r_n); 
		}
		else if(choice==3)
		{
			FlashFile(r_n);//数据更新 
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
	    printf("\n按Enter键进入游戏！");
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
 	FILE *fp=fopen(FILE_NAME,"w");//w,打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。 
	//打开文件 
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
	fclose(fp);                                   //一定要写，否则文本无法保存 
	printf("更新数据成功！");
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
 CheckRank(int r_n)                   //数据结构排序方法 
 {
 	system("cls");
 	printf("\n\n\t      * * * * * * * * * * 排行榜 * * * * * * * * * * * * * *\n");
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
 		printf("\t\t  %2d*  %20s              胜场：%d\n\n\n",z,rankson[i].name,rankson[i].wins);
 		z++;
	 }
 }
 
