void Changeinformation(int idpass,int r_n);
# define SPA 0 
# define MAN 1 
# define COM 2    /* ��λ����Ϊ0 ������µ�λ����Ϊ1 �������µ�λ����Ϊ2 */ 
//const int x = 15;
# define MAXBOARD 65
int board[MAXBOARD][MAXBOARD];    /* 15*15������ */ 
void startgame(int N,int x,int r_n);
void draw(int x);   /* ������ */ 
void AI(int *p,int *q,int x);     /* �������� p q������������ */ 
int value(int p,int q,int x);     /* ����յ�p q�ļ�ֵ */ 
int win(int p,int q,int x);  /* �ж�ʤ�� p qΪ�жϵ����� */ 
int qixing(int n,int p,int q,int x);    /* ���ؿյ�p q��n�����ϵ����� nΪ1-8���� ����˳ʱ�뿪ʼ�� */ 
void yiwei(int n,int *i,int *j);   /* ��n�����϶����� i j ��λ nΪ1-8���� ����˳ʱ�뿪ʼ��  */

int a,b,c,d;  /* a bΪ����������� ��c dΪ������������ xΪʣ���λ��*/ 

void startgame(int N,int x,int r_n)   //��¼�ɹ���,�������̳��� 
{
		int W,Z;         //���������������
		int X,Y;         //��������������� 
	int i,j,a1,b1,c1,d1,choice,max = x*x;        /* a1 b1��������������� c1 d1��������������� */  
	char ch;  
	printf("\n\n\n\n");
	printf("\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
	printf("\t\t\t   *  �û���%10s            ף��������       *\n",user[N].name);
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *      1.�˻���ս                 2.���˶�ս      *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   *                                                 *\n");
    printf("\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("��ѡ�� ");
	scanf("%d",&choice);           /* ѡ��ģʽ:�˻������� */  
	while(choice!=1&&choice!=2) 
	{
		printf("�Ƿ����룬���������룺"); 
		scanf("%d",&choice);
	}  
	if(choice==1)
	{    /* �˻�ģʽ */   
		system("cls");    
		printf("\n\t\t\t�𾴵�%s,��ӭ�����˻�ģʽ��",user[N].name); 
		for(j=0;j<x;j++)    
			for(i=0;i<x;i++)     
			board[j][i]=SPA;  /* ������ȫΪ�� */ 
		draw(x);
		printf("\n\t\t\t�����밴1�������밴2��");   
		int z;     //���º���ѡ��
		scanf("%d",&z); 
	while(z!=1&&z!=2)  
	{
		printf("����������������룺"); 
		scanf("%d",&z);
	}   
	if(z == 1)                   //���� 
	{
		printf("������:");
		
		scanf("%d%d",&X,&Y);
	 while((X<0||X>x-1)||(Y<0||Y>x-1)){
		    printf("����Ƿ�!���������룺"); 
			scanf("%d%d",&X,&Y); 
		}
	 a1=X;b1=Y;max--;
	 board[b1][a1] = MAN;        //���� 
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
			}  /* �������¾�����7 7 */  
		else
			{ 
				AI(&W,&Z,x);           //���������㷨 
				board[Z][W]=COM; max--; 
				system("cls"); 
				
				draw(x);//���µ�������Ĳ��� 
			} /* �������� */ 
			
				 printf("�������%d %d\n",X,Y); 
		c1=W; d1=Z;                 /* ��������������� */    
			if(win(W,Z,x))/* ����Ӯ */ 
			{                   
				printf("Ҫ������������y��n��"); 
				getchar(); 
				scanf("%c",&ch);     
				while(ch!='y'&&ch!='n') 
				{ 
					printf("����������������룺"); 
					scanf("%c",&ch); 
				}     
				if(ch=='n') 
				{ 
				    
					printf("����Ӯ! �´μ���Ŭ����\n"); 
					return; 
				}     
				else 
				{
					max+=2;
					board[Z][W]=SPA; 
					board[b1][a1]=SPA; 
					system("cls");
					
					 draw(x); 
				} /* ���� */    
			}    
			printf("��������%d %d\n�����룺",W,Z); 
			scanf("%d%d",&X,&Y);   /* ������� */    
			if(Y==66&&X==66) /* ���� */ 
			{
			 	max+=2; 
				board[Z][W]=SPA; 
				board[b1][a1]=SPA; 
				system("cls");
				
				draw(x); 
				printf("�����룺"); 
				scanf("%d%d",&X,&Y); 
			}    
			if(Y==77&&X==77)
			{
				printf("ȷ���˳���Ϸ��������y��n��"); 
				getchar(); 
				scanf("%c",&ch);     
				while(ch!='y'&&ch!='n') 
				{ 
					printf("����������������룺"); 
					scanf("%c",&ch); 
				}     
				if(ch=='n') 
				{ 
				    
					printf("��Ϸ����\n"); 
					printf("��������%d %d\n�����룺",W,Z); 
					scanf("%d%d",&X,&Y);   /* ������� */
				}  
				else 
				{
					Changeinformation(N,r_n); 
				}     
			}
			while((X<0||Y>x-1)||(Y<0||Y>x-1)||board[Y][X]!=SPA) 
			{ 
				printf("���������λ��������!���������룺"); 
				scanf("%d%d",&X,&Y); 
			}    
			a1=X; b1=Y; max--; 
			board[Y][X]=MAN; 
			system("cls"); 
			
			draw(x);    
			if(win(X,Y,x))
			{ 
				printf("�������������!!!\n"); 
				user[N].wins++;
				printf("ʤ��Ϊ��%d",user[N].wins);
				return ;
			}    /* ���Ӯ */   
		}  
		printf("�;�\n"); 
	}
		if(choice==2)    /*���˶�ս*/ 
	{   
		system("cls");    
		printf("��ӭʹ�����������˶�ս����������������(��13 6)������������15 15�� \n\n\n");    
		for(j=0;j<x;j++)    
			for(i=0;i<x;i++)     
			board[j][i]=SPA; /* ������ȫΪ�� */   
		draw(x);   
		while(x!=0)
		{    
			printf("1P�����룺"); 
			scanf("%d%d",&a,&b);    
			if(a==66&&b==66) /*����*/ 
			{ 
				x+=2; 
				board[d][c]=SPA; 
				board[b1][a1]=SPA; 
				system("cls"); 
				draw(x); 
				printf("1P�����룺"); 
				scanf("%d%d",&a,&b); 
			}     
			while((a<0||a>x-1)||(b<0||b>x-1)||board[b][a]!=SPA) 
			{ 
				printf("���������λ��������!���������룺"); 
				scanf("%d%d",&a,&b); 
			}    
			a1=a; b1=b; max--; 
			board[b][a]=MAN; 
			system("cls"); 
			draw(x);   
			printf("1P����%d %d��\n",a,b);    
			if(win(a,b,x))
			{
				printf("�����!!!\n"); 
				return; 
			}    /* ���1Ӯ */    
			printf("2P�����룺");
			scanf("%d%d",&c,&d);    
			if(c==66&&d==66) 
			{ 
				x+=2; 
				board[b][a]=SPA; 
				board[d1][c1]=SPA; 
				system("cls"); 
				draw(x); 
				printf("2P�����룺"); 
				scanf("%d%d",&c,&d); 
			}    
 			while((c<0||c>x-1)||(d<0||d>x-1)||board[d][c]!=SPA) 
			{ 
				printf("���������λ��������!���������룺"); 
				scanf("%d%d",&c,&d); 
			}    
			c1=c; d1=d; max--; 
			board[d][c]=COM; 
			system("cls");
			draw(x);    
			printf("2P����%d %d��\n",c,d);    
			if(win(c,d,x))
			{ 
				printf("�����!!!\n"); 
				return; 
			}    /* ���2Ӯ */   
		}  
		 printf("�;�\n");  
	} 
	
} /* �������Ҫ���ƺ��� */ 

void draw(int x)
{
	int i,j,k,q;
	int a, b, c;
	char*** p = new char** [x];        //��̬�����ڴ湹����ά���飬���ڴ洢��λ��ͼ��(��ƽ���ϵĶ�ά���ص��RGBͨ��) 
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
			strcpy(p[j][i],"  \0");    //��Ϊ�գ����¼�� 
			if(board[j][i]==MAN) 
			strcpy(p[j][i],"��\0");    //�����ڴ����壬���¼ ��\0
			if(board[j][i]==COM) 
			strcpy(p[j][i],"��\0");    //�������ڴ����壬���¼ ��\0
		}  
	printf("\n ��������������x y(�� 13 6) (Enter���������)  ����������66 66  �˳���Ϸ������77 77\n\n");
	 
	printf("         0");
		for(k=1;k<x-1;k++)
		{                //д�º����� 
		printf("  %2d",k);
		}
		printf("  %2d  \n",x-1);                
	
		printf("       ����������");   //��һ�е�ͷ����������Ϊ���⣬�����⴦���������
		 
	for(k=1;k<x-1;k++){                //���Ż����м���� 
		printf("��������");
	} 
	printf("���������� ��>x\n");       //��һ�е�β����������Ϊ���⣬���⴦���������
	
	for(i = 0; i<x-1 ; i++){           //�������� 
		printf("     %2d��",i);        //��д�������� 
		for(j = 0;j<x-1 ; j++){
			printf("%3s��",p[i][j]);   //�������� 
		}
		printf("%3s�� %d\n",p[i][j],i);//�������һ�����ӣ�����дһ�������꣬����鿴���� 
		
		printf("       ��������");     //����������� ͷ����������Ϊ���⣬���⴦���������
			for(j = 1;j<x-1 ; j++){
			printf("�੤����");        //���Ż����м���� 
		}
		printf("�੤������\n");        //����������� β����������Ϊ���⣬���⴦���������
	}
	

	//���������� 
	printf("     %2d��",i);
	for(j=0 ; j< x-1 ; j++){
		printf("%3s��",p[i][j]);
	}
		printf("%3s�� %d\n",p[i][j],i);
		
	printf("       ����������");
	for(k=1;k<x-1;k++){
		printf("��������");
	}
	printf("��������\n"); 
	printf("         0");
    for(k=1;k<x-1;k++){
		printf("  %2d",k);
	}
	printf("  %2d  \n",x-1);       
} 

void AI(int *p,int *q,int x)           /* �������� *p *q������������ ,�������δ�С*/ 
{  
	int i,j,k,max=0,I,J;        /* I JΪ�µ����� */  
	for(j=0;j<x;j++)   
		for(i=0;i<x;i++)    
		if(board[j][i]==SPA)
		{		      /* �������̣������յ�������ֵ��ȡ����ֵ�����ӡ� */     
			k=value(i,j,x);     
			if(k>=max) 
			{ 
				I=i; J=j; max=k; 
			}    
		}  
	*p=I; *q=J; 
}  

int value(int p,int q,int x) /* ����յ�p q�ļ�ֵ ��k���� */  
{  
	int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp;    
	int  a[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0};         
	/* ����a�д��漺���ͶԷ���32�����͵�ֵ  ����0�Է�1    ��0��1�ջ�2�ճ�3    ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */ 
	while(n!=5)
	{   
		k1=qixing(n,p,q,x); 
		n+=4;   /* k1,k2Ϊ2������������ͱ�� */   
		k2=qixing(n,p,q,x); n-=3;   
		if(k1>k2) 
		{ 
			temp=k1; k1=k2; k2=temp; 
		}  /* ʹ���С��Ϊk1,���Ϊk2 */
		K1=k1; K2=k2;       /* K1 K2����k1 k2�ı�� */   
		Z1=k1%10; Z2=k2%10; 
		k1/=10; k2/=10; 
		Y1=k1%10; Y2=k2%10; 
		k1/=10; k2/=10; 
		X1=k1%10; 
		X2=k2%10; /* X Y Z�ֱ��ʾ ����0�Է�1    ��0��1�ջ�2�ճ�3    ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */   
		if(K1==-1) 
		{ 
			if(K2<0) 
			{ 
				k+=0; 
				continue; 
			}	 
			else k+=a[X2][Y2][Z2]+5; continue;  
		};    /* ������and���� */   
		if(K1==-2) 
		{ 
			if(K2<0) 
			{ 
				k+=0; 
				continue; 
			} 
			else 
			k+=a[X2][Y2][Z2]/2; continue; 
		};       /* �߽������and���� */    
		if(K1==-3) 
		{ 
			if(K2<0) 
			{ 
				k+=0; continue; 
			} 
			else 
			k+=a[X2][Y2][Z2]/3; continue; 
		};    /* �߽�ճ�����and���� */    
		if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{    /* ����� ����� �Ի�Ի� �Ի�Գ� �����͸�ֵ*/    
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
		{    /* ���强�� �Գ�Գ� �����͸�ֵ*/    
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
		{    /* ����Ի� ����Գ� ����Ի� ����Գ� �����͸�ֵ*/    
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
		}    /* �������͵ĸ�ֵ */  
	}  
	return k; 
} 

int 
qixing(int n,int p,int q,int x)/* ���ؿյ�p q��n�����ϵ����ͺ� nΪ1-8���� ����˳ʱ�뿪ʼ�� */  
{  
	int k,m=0;  
	/* ���ͺ�ע��:  ����000-003 ����010-013 �Ի�100-103 �Գ�110-113 ���ջ�020-023 
	   ���ճ�030-033 �Կջ�120-123 �Կճ�130-133 ��-1 �߽��-2 �߽�ճ�-3*/  
	yiwei(n,&p,&q);  
	if(p<0||p>x-1||q<0||q>x-1) 
	k=-2;         /* �߽������ */
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
			k=m-1;                         /* ���������� */       
			else 
			k=m+9;  /* ���������� */      
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
			k=m+99;                         /* �Է������� */      
			else 
			k=m+109;                                        /* �Է������� */      
		} break;   
		case SPA:
		{      
			yiwei(n,&p,&q);      
			if(p<0||p>x-1||q<0||q>x-1) 
			{ 
				k=-3; return k; 
			}         /* �߽�ճ����� */      
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
					k=m+19;                  /* �����ջ����� */         
					else 
					k=m+29;                  /* �����ճ����� */        
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
					k=m+119;                  /* �Է��ջ����� */      
					else 
					k=m+129; /* �Է��ճ����� */          
				} break;      
				case SPA:
				k=-1; break;                  /* ������ */     
 			}    
 		} break; 
 	} 
 	return k;
}  

void 
yiwei(int n,int *i,int *j)        /* ��n�����϶����� i j ��λ nΪ1-8���� ����˳ʱ�뿪ʼ�� */
{  
	switch(n)
	{  
		case 1: *i+=1; break;         //�ҷ� 
		case 2: *i+=1; *j+=1; break;  //���·� 
		case 3: *j+=1; break;         //�·� 
		case 4: *i-=1; *j+=1; break;  //���·� 
		case 5: *i-=1; break;         //�� 
		case 6: *i-=1; *j-=1; break;  //���Ϸ� 
		case 7: *j-=1; break;         //�Ϸ� 
		case 8: *i+=1; *j-=1; break;  //���Ϸ� 
	} 
}

int win(int p,int q,int x)      /* �ж�ʤ�� p qΪ�жϵ����꣬xΪ���̳��ȣ�ʤ������1�����򷵻�0 */ 
{  
	int k,n=1,m,P,Q;      /* k�����жϵ�p q��״̬COM��MAN��P Q�����жϵ����ꡣ
	nΪ�жϷ���mΪ������ */  
	P=p; Q=q;  k=board[q][p];  
	while(n!=5)     //��n��Ϊ�������� 
	{   
		m=0;    
		while(k==board[q][p])
		{    
			m++;    
			if(m==5) 
			return 1;     
			yiwei(n,&p,&q); //��p,q)��n������һλ 
			if(p<0||p>x-1||q<0||q>x-1) break;   
		}   
		n+=4; m-=1; p=P; q=Q;   /* ת���ж� */   
		while(k==board[q][p])
		{    
			m++;    
			if(m==5) 
			return 1;     
			yiwei(n,&p,&q); 
			if(p<0||p>x-1||q<0||q>x-1) break;   
		}   
		n-=3; p=P; q=Q;         /* ���ɹ����ж���һ�鷽�� */  
	}  
	return 0; 
}
