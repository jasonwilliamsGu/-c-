void Changeinformation(int idpass,int r_n);
# define SPA 0 
# define MAN 1 
# define COM 2    /* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为2 */ 
//const int x = 15;
# define MAXBOARD 65
int board[MAXBOARD][MAXBOARD];    /* 15*15的棋盘 */ 
void startgame(int N,int x,int r_n);
void draw(int x);   /* 画棋盘 */ 
void AI(int *p,int *q,int x);     /* 电脑下子 p q返回下子坐标 */ 
int value(int p,int q,int x);     /* 计算空点p q的价值 */ 
int win(int p,int q,int x);  /* 判断胜利 p q为判断点坐标 */ 
int qixing(int n,int p,int q,int x);    /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */ 
void yiwei(int n,int *i,int *j);   /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数  */

int a,b,c,d;  /* a b为玩家下子坐标 ，c d为电脑下子坐标 x为剩余空位置*/ 

void startgame(int N,int x,int r_n)   //登录成功后,传入棋盘长度 
{
		int W,Z;         //定义电脑下子坐标
		int X,Y;         //定义玩家下子坐标 
	int i,j,a1,b1,c1,d1,choice,max = x*x;        /* a1 b1储存玩家上手坐标 c1 d1储存电脑上手坐标 */  
	char ch;  
	printf("\n\n\n\n");
	printf("\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
	printf("\t\t\t   *  用户：%10s            祝您玩的愉快       *\n",user[N].name);
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *      1.人机对战                 2.人人对战      *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("请选择： ");
	scanf("%d",&choice);           /* 选择模式:人机或人人 */  
	while(choice!=1&&choice!=2) 
	{
		printf("非法输入，请重新输入："); 
		scanf("%d",&choice);
	}  
	if(choice==1)
	{    /* 人机模式 */   
		system("cls");    
		printf("\n\t\t\t尊敬的%s,欢迎进入人机模式！",user[N].name); 
		for(j=0;j<x;j++)    
			for(i=0;i<x;i++)     
			board[j][i]=SPA;  /* 置棋盘全为空 */ 
		draw(x);
		printf("\n\t\t\t先手请按1，后手请按2：");   
		int z;     //先下后下选择
		scanf("%d",&z); 
	while(z!=1&&z!=2)  
	{
		printf("输入错误，请重新输入："); 
		scanf("%d",&z);
	}   
	if(z == 1)                   //先手 
	{
		printf("请下子:");
		
		scanf("%d%d",&X,&Y);
	 while((X<0||X>x-1)||(Y<0||Y>x-1)){
		    printf("坐标非法!请重新输入："); 
			scanf("%d%d",&X,&Y); 
		}
	 a1=X;b1=Y;max--;
	 board[b1][a1] = MAN;        //棋盘 
	 system("cls");
	 
	 draw(x);
	}
    while(max!=0)
    {
    	if(max == x*x)
    	{
    	        W=x/2; Z=x/2; 
				board[Z][W]=COM; max--; 
				system("cls"); 
				draw(x);
			}  /* 电脑先下就下在7 7 */  
		else
			{ 
				AI(&W,&Z,x);           //电脑下棋算法 
				board[Z][W]=COM; max--; 
				system("cls"); 
				
				draw(x);//画下电脑下棋的操作 
			} /* 电脑下子 */ 
			
				 printf("玩家下在%d %d\n",X,Y); 
		c1=W; d1=Z;                 /* 储存电脑上手棋型 */    
			if(win(W,Z,x))/* 电脑赢 */ 
			{                   
				printf("要悔棋吗？请输入y或n："); 
				getchar(); 
				scanf("%c",&ch);     
				while(ch!='y'&&ch!='n') 
				{ 
					printf("输入错误，请重新输入："); 
					scanf("%c",&ch); 
				}     
				if(ch=='n') 
				{ 
				    
					printf("电脑赢! 下次继续努力！\n"); 
					return; 
				}     
				else 
				{
					max+=2;
					board[Z][W]=SPA; 
					board[b1][a1]=SPA; 
					system("cls");
					
					 draw(x); 
				} /* 悔棋 */    
			}    
			printf("电脑下在%d %d\n请输入：",W,Z); 
			scanf("%d%d",&X,&Y);   /* 玩家下子 */    
			if(Y==66&&X==66) /* 悔棋 */ 
			{
			 	max+=2; 
				board[Z][W]=SPA; 
				board[b1][a1]=SPA; 
				system("cls");
				
				draw(x); 
				printf("请输入："); 
				scanf("%d%d",&X,&Y); 
			}    
			if(Y==77&&X==77)
			{
				printf("确定退出游戏吗？请输入y或n："); 
				getchar(); 
				scanf("%c",&ch);     
				while(ch!='y'&&ch!='n') 
				{ 
					printf("输入错误，请重新输入："); 
					scanf("%c",&ch); 
				}     
				if(ch=='n') 
				{ 
				    
					printf("游戏继续\n"); 
					printf("电脑下在%d %d\n请输入：",W,Z); 
					scanf("%d%d",&X,&Y);   /* 玩家下子 */
				}  
				else 
				{
					Changeinformation(N,r_n); 
				}     
			}
			while((X<0||Y>x-1)||(Y<0||Y>x-1)||board[Y][X]!=SPA) 
			{ 
				printf("坐标错误或该位置已有子!请重新输入："); 
				scanf("%d%d",&X,&Y); 
			}    
			a1=X; b1=Y; max--; 
			board[Y][X]=MAN; 
			system("cls"); 
			
			draw(x);    
			if(win(X,Y,x))
			{ 
				printf("你真棒！电脑输!!!\n"); 
				user[N].wins++;
				printf("胜场为：%d",user[N].wins);
				return ;
			}    /* 玩家赢 */   
		}  
		printf("和局\n"); 
	}
		if(choice==2)    /*人人对战*/ 
	{   
		system("cls");    
		printf("欢迎使用五子棋人人对战！下子请输入坐标(如13 6)。悔棋请输入15 15。 \n\n\n");    
		for(j=0;j<x;j++)    
			for(i=0;i<x;i++)     
			board[j][i]=SPA; /* 置棋盘全为空 */   
		draw(x);   
		while(x!=0)
		{    
			printf("1P请输入："); 
			scanf("%d%d",&a,&b);    
			if(a==66&&b==66) /*悔棋*/ 
			{ 
				x+=2; 
				board[d][c]=SPA; 
				board[b1][a1]=SPA; 
				system("cls"); 
				draw(x); 
				printf("1P请输入："); 
				scanf("%d%d",&a,&b); 
			}     
			while((a<0||a>x-1)||(b<0||b>x-1)||board[b][a]!=SPA) 
			{ 
				printf("坐标错误或该位置已有子!请重新输入："); 
				scanf("%d%d",&a,&b); 
			}    
			a1=a; b1=b; max--; 
			board[b][a]=MAN; 
			system("cls"); 
			draw(x);   
			printf("1P下在%d %d。\n",a,b);    
			if(win(a,b,x))
			{
				printf("你真棒!!!\n"); 
				return; 
			}    /* 玩家1赢 */    
			printf("2P请输入：");
			scanf("%d%d",&c,&d);    
			if(c==66&&d==66) 
			{ 
				x+=2; 
				board[b][a]=SPA; 
				board[d1][c1]=SPA; 
				system("cls"); 
				draw(x); 
				printf("2P请输入："); 
				scanf("%d%d",&c,&d); 
			}    
 			while((c<0||c>x-1)||(d<0||d>x-1)||board[d][c]!=SPA) 
			{ 
				printf("坐标错误或该位置已有子!请重新输入："); 
				scanf("%d%d",&c,&d); 
			}    
			c1=c; d1=d; max--; 
			board[d][c]=COM; 
			system("cls");
			draw(x);    
			printf("2P下在%d %d。\n",c,d);    
			if(win(c,d,x))
			{ 
				printf("你真棒!!!\n"); 
				return; 
			}    /* 玩家2赢 */   
		}  
		 printf("和局\n");  
	} 
	
} /* 程序的主要控制函数 */ 

void draw(int x)
{
	int i,j,k,q;
	int a, b, c;
	char*** p = new char** [x];        //动态分配内存构造三维数组，用于存储该位置图像(即平面上的二维像素点和RGB通道) 
	for (a = 0; a < x; a++)
	{
		p[a] = new char* [x];
		for (b = 0; b < x; b++)
		{
			p[a][b] = new char[x];
		}
	}
	for (a = 0; a < x; a++)
	{
		for (b = 0; b < 4; b++)
		{
			for (c = 0; c < 4; c++)
			{
				p[a][b][c] = 1;
			}
		}
	}
for(j=0;j<x;j++)   
		for(i=0;i<x;i++)
		{    
			if(board[j][i]==SPA) 
			strcpy(p[j][i],"  \0");    //若为空，则记录空 
			if(board[j][i]==MAN) 
			strcpy(p[j][i],"●\0");    //若人在此下棋，则记录 ●\0
			if(board[j][i]==COM) 
			strcpy(p[j][i],"◎\0");    //若电脑在此下棋，则记录 ◎\0
		}  
	printf("\n 下子请输入坐标x y(如 13 6) (Enter键输入结束)  悔棋请输入66 66  退出游戏请输入77 77\n\n");
	 
	printf("         0");
		for(k=1;k<x-1;k++)
		{                //写下横坐标 
		printf("  %2d",k);
		}
		printf("  %2d  \n",x-1);                
	
		printf("       ┌───┬");   //第一行的头长这样，因为特殊，先特殊处理绘制下来
		 
	for(k=1;k<x-1;k++){                //接着绘制中间的线 
		printf("───┬");
	} 
	printf("───┐─ ─>x\n");       //第一行的尾长这样，因为特殊，特殊处理绘制下来
	
	for(i = 0; i<x-1 ; i++){           //绘制棋子 
		printf("     %2d│",i);        //先写下纵坐标 
		for(j = 0;j<x-1 ; j++){
			printf("%3s│",p[i][j]);   //绘制棋子 
		}
		printf("%3s│ %d\n",p[i][j],i);//绘制最后一个棋子，并再写一次纵坐标，方便查看棋盘 
		
		printf("       ├───");     //棋子下面的线 头长这样，因为特殊，特殊处理绘制下来
			for(j = 1;j<x-1 ; j++){
			printf("┼───");        //接着绘制中间的线 
		}
		printf("┼───┤\n");        //棋子下面的线 尾长这样，因为特殊，特殊处理绘制下来
	}
	

	//绘制最后的线 
	printf("     %2d│",i);
	for(j=0 ; j< x-1 ; j++){
		printf("%3s│",p[i][j]);
	}
		printf("%3s│ %d\n",p[i][j],i);
		
	printf("       └───┴");
	for(k=1;k<x-1;k++){
		printf("───┴");
	}
	printf("───┘\n"); 
	printf("         0");
    for(k=1;k<x-1;k++){
		printf("  %2d",k);
	}
	printf("  %2d  \n",x-1);       
} 

void AI(int *p,int *q,int x)           /* 电脑下子 *p *q返回下子坐标 ,传入期盼大小*/ 
{  
	int i,j,k,max=0,I,J;        /* I J为下点坐标 */  
	for(j=0;j<x;j++)   
		for(i=0;i<x;i++)    
		if(board[j][i]==SPA)
		{		      /* 历遍棋盘，遇到空点则计算价值，取最大价值点下子。 */     
			k=value(i,j,x);     
			if(k>=max) 
			{ 
				I=i; J=j; max=k; 
			}    
		}  
	*p=I; *q=J; 
}  

int value(int p,int q,int x) /* 计算空点p q的价值 以k返回 */  
{  
	int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp;    
	int  a[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0};         
	/* 数组a中储存己方和对方共32种棋型的值  己方0对方1    活0冲1空活2空冲3    子数0-3（0表示1个子，3表示4个子） */ 
	while(n!=5)
	{   
		k1=qixing(n,p,q,x); 
		n+=4;   /* k1,k2为2个反方向的棋型编号 */   
		k2=qixing(n,p,q,x); n-=3;   
		if(k1>k2) 
		{ 
			temp=k1; k1=k2; k2=temp; 
		}  /* 使编号小的为k1,大的为k2 */
		K1=k1; K2=k2;       /* K1 K2储存k1 k2的编号 */   
		Z1=k1%10; Z2=k2%10; 
		k1/=10; k2/=10; 
		Y1=k1%10; Y2=k2%10; 
		k1/=10; k2/=10; 
		X1=k1%10; 
		X2=k2%10; /* X Y Z分别表示 己方0对方1    活0冲1空活2空冲3    子数0-3（0表示1个子，3表示4个子） */   
		if(K1==-1) 
		{ 
			if(K2<0) 
			{ 
				k+=0; 
				continue; 
			}	 
			else k+=a[X2][Y2][Z2]+5; continue;  
		};    /* 空棋型and其他 */   
		if(K1==-2) 
		{ 
			if(K2<0) 
			{ 
				k+=0; 
				continue; 
			} 
			else 
			k+=a[X2][Y2][Z2]/2; continue; 
		};       /* 边界冲棋型and其他 */    
		if(K1==-3) 
		{ 
			if(K2<0) 
			{ 
				k+=0; continue; 
			} 
			else 
			k+=a[X2][Y2][Z2]/3; continue; 
		};    /* 边界空冲棋型and其他 */    
		if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{    /* 己活己活 己活己冲 对活对活 对活对冲 的棋型赋值*/    
			if(Z1+Z2>=2) 
			{ 
				k+=a[X2][Y2][3]; continue; 
			}    
			else 
			{ 
				k+=a[X2][Y2][Z1+Z2+1]; continue; 
			}   
		}   
		if(((K1>9&&K1<14)&&(K2>9&&K2<14))||((K1>109&&K1<114)&&(K2>109&&K2<114)))
		{    /* 己冲己冲 对冲对冲 的棋型赋值*/    
			if(Z1+Z2>=2) 
			{ 
				k+=10000; continue; 
			}    
			else 
			{ 
				k+=0; continue; 
			}   
		}   
		if(((K1>-1&&K1<4)&&((K2>99&&K2<104)||(K2>109&&K2<114)))||((K1>9&&K1<14)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{    /* 己活对活 己活对冲 己冲对活 己冲对冲 的棋型赋值*/    
			if(Z1==3||Z2==3) 
			{ 
				k+=10000; continue; 
			}    
			else 
			{ 
				k+=a[X2][Y2][Z2]+a[X1][Y1][Z1]/4; continue; 
			}		    
		}   
		else  
		{ 
			k+=a[X1][Y1][Z1]+a[X2][Y2][Z2]; continue;  
		}    /* 其他棋型的赋值 */  
	}  
	return k; 
} 

int 
qixing(int n,int p,int q,int x)/* 返回空点p q在n方向上的棋型号 n为1-8方向 从右顺时针开始数 */  
{  
	int k,m=0;  
	/* 棋型号注解:  己活000-003 己冲010-013 对活100-103 对冲110-113 己空活020-023 
	   己空冲030-033 对空活120-123 对空冲130-133 空-1 边界冲-2 边界空冲-3*/  
	yiwei(n,&p,&q);  
	if(p<0||p>x-1||q<0||q>x-1) 
	k=-2;         /* 边界冲棋型 */
	switch(board[q][p])
	{   
		case COM:
		{     
			m++; yiwei(n,&p,&q);      
			if(p<0||p>x-1||q<0||q>x-1) 
			{ 
				k=m+9; return k; 
			}      
			while(board[q][p]==COM) 
			{ 
				m++; 
				yiwei(n,&p,&q); 
				if(p<0||p>x-1||q<0||q>x-1) 
				{ 
					k=m+9; return k; 
				} 
			}      
			if(board[q][p]==SPA) 
			k=m-1;                         /* 己方活棋型 */       
			else 
			k=m+9;  /* 己方冲棋型 */      
		} break;   
		case MAN:
		{      
			m++; 
			yiwei(n,&p,&q);      
			if(p<0||p>x-1||q<0||q>x-1) 
			{ 
				k=m+109; return k; 
			}      
			while(board[q][p]==MAN) 
			{ 
				m++; yiwei(n,&p,&q); 
				if(p<0||p>x-1||q<0||q>x-1) 
				{ 
					k=m+109; return k; 
				} 
			}      
			if(board[q][p]==SPA) 
			k=m+99;                         /* 对方活棋型 */      
			else 
			k=m+109;                                        /* 对方冲棋型 */      
		} break;   
		case SPA:
		{      
			yiwei(n,&p,&q);      
			if(p<0||p>x-1||q<0||q>x-1) 
			{ 
				k=-3; return k; 
			}         /* 边界空冲棋型 */      
			switch(board[q][p])
			{      
				case COM:
				{         
					m++; yiwei(n,&p,&q);         
					if(p<0||p>x-1||q<0||q>x-1) 
					{ 
						k=m+29; return k; 
					}        
					while(board[q][p]==COM) 
					{ 
						m++; yiwei(n,&p,&q); 
						if(p<0||p>x-1||q<0||q>x-1) 
						{ 
							k=m+29; return k; 
						} 
					}         
					if(board[q][p]==SPA) 
					k=m+19;                  /* 己方空活棋型 */         
					else 
					k=m+29;                  /* 己方空冲棋型 */        
				 } break;      
				case MAN:
				{         
					m++; 
					yiwei(n,&p,&q);         
					if(p<0||p>x-1||q<0||q>x-1) 
					{ k=m+129; return k; }        
					 while(board[q][p]==MAN)
					{ 
						m++; yiwei(n,&p,&q);
						if(p<0||p>14||q<0||q>14) 
						{ k=m+129; return k; } 
					}             
 					if(board[q][p]==SPA)
					k=m+119;                  /* 对方空活棋型 */      
					else 
					k=m+129; /* 对方空冲棋型 */          
				} break;      
				case SPA:
				k=-1; break;                  /* 空棋型 */     
 			}    
 		} break; 
 	} 
 	return k;
}  

void 
yiwei(int n,int *i,int *j)        /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数 */
{  
	switch(n)
	{  
		case 1: *i+=1; break;         //右方 
		case 2: *i+=1; *j+=1; break;  //右下方 
		case 3: *j+=1; break;         //下方 
		case 4: *i-=1; *j+=1; break;  //左下方 
		case 5: *i-=1; break;         //左方 
		case 6: *i-=1; *j-=1; break;  //左上方 
		case 7: *j-=1; break;         //上方 
		case 8: *i+=1; *j-=1; break;  //右上方 
	} 
}

int win(int p,int q,int x)      /* 判断胜利 p q为判断点坐标，x为棋盘长度，胜利返回1，否则返回0 */ 
{  
	int k,n=1,m,P,Q;      /* k储存判断点p q的状态COM或MAN。P Q储存判断点坐标。
	n为判断方向。m为个数。 */  
	P=p; Q=q;  k=board[q][p];  
	while(n!=5)     //当n不为正反方向 
	{   
		m=0;    
		while(k==board[q][p])
		{    
			m++;    
			if(m==5) 
			return 1;     
			yiwei(n,&p,&q); //（p,q)往n方向移一位 
			if(p<0||p>x-1||q<0||q>x-1) break;   
		}   
		n+=4; m-=1; p=P; q=Q;   /* 转向判断 */   
		while(k==board[q][p])
		{    
			m++;    
			if(m==5) 
			return 1;     
			yiwei(n,&p,&q); 
			if(p<0||p>x-1||q<0||q>x-1) break;   
		}   
		n-=3; p=P; q=Q;         /* 不成功则判断下一组方向 */  
	}  
	return 0; 
}
