#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h>

struct telebook{
	char num[4];
	char name[10];
	char phonenum[15];
	char email[20];
	struct telebook *next; //下一结点指针
};
typedef struct telebook TeleBook;


 
int Display_Main_Menu();                                      //显示主菜单
TeleBook *Create();                                            //数据输入
void Display(TeleBook *);                      //输出数据
TeleBook *Insert(TeleBook *, TeleBook *);          //插入一条结点记录
TeleBook *Insert_a_record(TeleBook *);

TeleBook *Delete(TeleBook *,char *);  //删除一条结点记录
TeleBook *Delete_a_record(TeleBook *);

void  Sort_by_num(TeleBook *);                  //排序
TeleBook *Query(TeleBook *,char *);                          //查询数据
void Query_a_record(TeleBook *);

TeleBook *AddfromText(TeleBook *,char *);   //从文件中整批输入数据
void WritetoText(TeleBook *, char *);     //将记录写到文件
TeleBook *Reverse(TeleBook *);                      //将表反序存放
TeleBook *DeleteSame(TeleBook *);                     //删除雷同数据
void Quit(TeleBook *);  
int n;



 /*TeleBook *Create() 
{ 
	TeleBook *p1, *p2, *head;
	int a;
	printf("Creating a list...\n");
	p1=p2=(TeleBook *) malloc(sizeof(TeleBook));
	head = NULL;		
	printf("\n编号  姓名   电话号码  电子邮件\n");
	scanf("%s %s %s %s",p1->num,p1->name,p1->phonenum,p1->email);
	printf("Please input a number(if(0) stop): ");
	scanf("%d",&a);
    while( a!=0 )    
    {   
	if(head==NULL)     
		head= p1;  
	else                         
		p2->next=p1;
	p2=p1;   
	p1=(TeleBook *) malloc(sizeof(TeleBook)); 
	printf("\n编号  姓名   电话号码  电子邮件\n");
	scanf("%s %s %s %s",p1->num,p1->name,p1->phonenum,p1->email); 
	printf("Please input a number(if(0) stop): ");//判断是否输入
    scanf("%d",&a);
    }
	p2->next=NULL;
                                   
    return(head);           
 }*/
 
 TeleBook *Create()  /*创建有序链表*/ 
 { 
    TeleBook *p,*head=NULL;  /*定义结构体指针*/ 
	char b='y';      /* 定义一个字符数组*/ 
    printf("Create an inceaing list----\n"); 
    while (b!='n'&&b!='N')         /*如果不是No执行循环*/   
	{ 
        p=( TeleBook*)malloc(sizeof( TeleBook));  /*申请存储空间*/     
        printf("\n编号  姓名   电话号码  电子邮件\n");
	    scanf("%s%s%s%s",p->num,p->name,p->phonenum,p->email);    /*输入*/ 
        head=Insert(head,p); 
        printf("Please input a number(if(n) stop): ");//判断是否输入  
		getchar();     
		scanf("%c",&b);    
	} 
    return(head);                   
 }  
 /*TeleBook *Create()
{
	TeleBook *head;
	TeleBook *p1,*p2;
	char *s="0";
	n=0;
	p1=p2=( TeleBook *)malloc(sizeof(TeleBook));
	printf("\n编号  姓名   电话号码  电子邮件\n");
	scanf("%s %s %s %s",p1->num,p1->name,p1->phonenum,p1->email);
	head=NULL;
	while(strcmp(p1->num,s))
	{

		n=n+1;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=( TeleBook *)malloc(sizeof(TeleBook));
		printf("\n编号  姓名   电话号码  电子邮件\n");
		scanf("%s %s %s %s",p1->num,p1->name,p1->phonenum,p1->email);
	}
	p2->next=NULL;
	return(head);
}*/
   



TeleBook *Delete_a_record(TeleBook *head)
{
	char a,b[20]; 
    printf("Please input the num:"); 
    scanf("%s",b);        /*输入待删结点编号*/  
    printf("Are you sure ?(Y/N): "); /*确认是否删除，Y表示确定 */ 
	getchar();               /*读取空格*/   
	a=getchar();   
	if (a=='Y') { 
        head = Delete(head, b);   /*调用Delete函数*/  

		return head;
	}    
	
	else       
		exit(1);
} 

TeleBook *Delete(TeleBook *head,char *num) /*删除一个结点*/
{
	TeleBook *p1,*p2; 
    if (head==NULL)         /*如果链表为空链表*/     { 
        printf("The list is NULL.\n");   
		return(NULL);    
	}    
	p1=head; 
    while (strcmp(p1->num,num)!=0&&p1->next!=NULL) /*循环查找待删结点*/  
	{ 
        p2=p1; 
		p1=p1->next; /*p1向后挪动一个结点，p2指向的结点在p1指向的结点之前*/   
	} 
    if (strcmp(p1->num,num)==0)  /*找到待删结点，由p1指向*/    
	{ 
        if (p1==head)               /*找到的结点是首结点*/           
			head=p1->next;      
		else 
            p2->next=p1->next;   /*找到的结点不是首结点*/       
		printf("The first node %s is deleted.\n",p1->num);      
		free(p1);     } 
    else                  /*未找到待删结点*/     
		printf("Node %s is not finded.\n",num);

	return(head);      /*返回链表头指针*/
} 
/*
TeleBook *DeleteSame(TeleBook *head)
{
	TeleBook *p,*p1,*p2; 
    for (p=head;p!=NULL;p=p->next)   //循环查找并删除相同的记录  
	{ 
        for (p2=p,p1=p->next;p1!=NULL;)    
		{ 
           if (strcmp(p1->num,p->num)==0) 
            p2->next=p1->next;        //删除相同姓名结点    
			p1=p1->next;       
			p2=p2->next;      
		}   
	} 
    printf("The node of same name has been deleted\n");//相同结点被删除
	return(head);                 //返回链表头指针 
}*/
TeleBook *DeleteSame(TeleBook *head)
{
    TeleBook *p,*q,*r;
    p = head; // 适用于有头节点的单链表；对于不带头节点的单链表，此处改为 p＝head 即可。
    while(p != NULL)    // p用于遍历链表
    {
        q = p;
        while(q->next != NULL) // q遍历p后面的结点，并与p数值比较
        {
            if(strcmp(q->next->num, p->num)==0)
            {
                r = q->next; // r保存需要删掉的结点
                q->next = r->next;   // 需要删掉的结点的前后结点相接
                free(r);
            }
            else
                q = q->next;
        }

        p = p->next;
    }

    return head;
}


void WritetoText(TeleBook *head, char *filename)
{
	 FILE *fp2; 
	 TeleBook *p,*p1;   
	 int num=0;   
	 p1=head;   
	 while(p1!=NULL)   
	 {
		 p1=p1->next;
		 num++;
	 }   
	 if ((fp2=fopen("records.txt","w"))==NULL) /*打开输出文件*/   
	 { 
        printf("Can't open the file!\n")  ;     /*无法打开*/  
		exit(1);    
	 }  
	 p=head; 
	 fprintf(fp2,"%d\n",num);  
    while (p!=NULL)    
	{ 
        fprintf(fp2,"%-20s%-20s%-20s%-20s\n",p->num,p->name,p->phonenum,p->email); /*将数据写入文件*/ 
		p=p->next;  
	} 
    fclose(fp2);                 /*关闭文件*/
} 


TeleBook *Insert_a_record(TeleBook *head)
{
	TeleBook *p; 
	char a[20],b[20],c[20],d[20];    
    printf("Please input a record:\n"); 
	printf("编号  姓名   电话号码  电子邮件\n");
    scanf("%s%s%s%s",a,b,c,d);             /*输入待插结点数据*/    
    p=(TeleBook *)malloc(sizeof(TeleBook));  /*申请存储空间*/  
	strcpy(p->num,a); 
	strcpy(p->name,b);
	strcpy(p->phonenum ,c);
	strcpy(p->email,d);
    head=Insert(head,p);       /*调用Insert函数*/  
	printf("Succeed insert a record!\n"); 
    return(head);             /*返回链表首地址*/
} 

TeleBook *AddfromText(TeleBook *head,char *filename)
{
	FILE *fp1;  
	TeleBook *p;  
	int i ,n; 
    printf("please enter an filename: "); 
	scanf("%s",filename);           /*输入文件名*/ 
    if ((fp1=fopen(filename,"r"))==NULL) /*打开输入数据文件*/    
	{ 
        printf("Can't open the file!");   
		exit(1);   
	} 
	fscanf(fp1,"%d",&n);/*记录个数*/
	
	for(i=0;i<n;i++)/*循环读入数据*/   
	{ 
        p=(TeleBook*)malloc(sizeof(TeleBook));     
		fscanf(fp1,"%s%s%s%s",p->num,p->name,p->phonenum,p->email);   
		head=Insert(head,p);
	} 
	
	printf("It's OK!\n"); 
	
    fclose(fp1);            /*关闭文件*/   
	return(head);           /*返回链表头指针*/
} 
/*void Display(TeleBook *head)
{
	TeleBook *p;
	int n=0;
	p=head;                         //令p为头结点
	printf("Output list:\n"); 
	printf("编号  姓名  电话号码    电子邮件\n");
    if (p!=NULL)                  //p非空执行
	{ 
		n++; 
        printf("%-6s%-6s%-15s%-15s\n",p->num,p->name,p->phonenum,p->email);//输出结点 
		p=p->next;                      //指向下一个结点 
		if (n%10==0 && n>=10)      
		{ 
            system("cls");          
			system("pause"); 
        }                       //每输出10个暂停一次
	}
} */
void Display(TeleBook *head)/*显示所有结点记录*/
{
	TeleBook *p;
	printf("\n now,these are records :\n");
	printf("\n编号  姓名  电话号码      电子邮件\n");
	p=head;
    if(head!=NULL);
	do
	{
		n=0;
		n++;
		printf("%-6s%-6s%-15s%-15s\n",p->num,p->name,p->phonenum,p->email);
		p=p->next;/*指向下一个结点*/ 
		if (n%10==0 && n>=10)      
		{ 
            system("cls");          
			system("pause"); 
        }                       //每输出10个暂停一次

	}while(p!=NULL);
}

TeleBook *Query(TeleBook *head,char *num)
{
	  TeleBook *p; 
	  p=head;                   /*考虑*/
	  while (p!=NULL)    
	  { 
        if (strcmp(p->num,num)==0)   
			return(p);          /*若找到着返回该结点指针*/ 
		p=p->next;             /*考虑*/
	  } 
    return NULL;                  /*若找不到着返回空指针*/
} 


void Query_a_record(TeleBook *head) //查询一个结点并显示
{
	char num[20]; 
    scanf("%s",num);             /*输入待查找的编号*/  
	head=Query(head,num);        /*函数调用*/  
	if (head!=NULL)     { 
        printf("Success!\n"); 
		printf("\n编号  姓名   电话号码  电子邮件\n");
        printf("%-6s%-6s%-15s%-15s\n",head->num,head->name,head->phonenum,head->email);/*输出结点记录*/ 
	} 
	else 
        printf("There is no %s!\n",num);  /*查找不到*/ 
} 

TeleBook *Insert(TeleBook *head,TeleBook *p0) /*结点有序插入*/

{ 
    TeleBook *p1,*p2;                    /*定义结构体指针*/    
	if (head==NULL)                  /*如果原链表为空链表*/    
	{ 
        head=p0;      
		p0->next=NULL; 
        return(head);                     /*返回链表头指针*/  
	} 
    p2=p1=head; 
    while (strcmp(p0->num,p1->num)>0&&p1->next!=NULL)/*寻找待差位置*/   
	{ 
        p2=p1; 
        p1=p1->next;/*指向后一个结点，p2指向的结点在p1指向的结点之前*/   
	} 
    if (strcmp(p0->num,p1->num)<=0) /*插在1之前*/ 

	{ 
        p0->next=p1; 
        if (head==p1)
			head=p0;          /*插在链表首部*/        
		else 
			p2->next=p0;               /*插在链表中间*/  
	}

    else                 /*插在链表尾结点之后*/
     {
		p1->next=p0; 
		p0->next=NULL;
 }

    return(head);            /*返回链表头指针*/

}             
void Quit(TeleBook *head)
{
	TeleBook *p; 
    while (head!=NULL)        //循环释放个结点空间
	{ 
        p=head; 
        head=head->next;     
		free(p);   
	}
} 

TeleBook *Reverse (TeleBook *head)

{
	TeleBook *p,*p1; 
    if (head==NULL)            //链表为空
	{ 
        printf("It's a NULL\n");    
		exit(1);   
	} 
    for (p1=head;p1->next!=NULL;)   //循环逆序   
	{ 
        p=p1->next; 
		p1->next=p->next; 
		p->next=head;
		head=p;   
	} 
        printf("The node has been reversed\n");   
		return(head); 
} 
/*
void  Sort_by_num(TeleBook *head)
{
TeleBook *p,*s,*pt; 
	p = head;
	s = p->next;
	while(p->next != NULL)
	{
		while(s->next != NULL)
		{
			if(strcmp(p->next->num , s->next->num)<0)
			{
				pt = p->next;
				p->next = s->next;
				s->next = p->next->next;
				p->next->next = pt;
			}
			else s = s->next;
		}
		p = p->next;
		s = p->next;
	}
}*/
/*void  Sort_by_num(TeleBook *head) 
{  
 TeleBook *sorted,*unsorted,*min,*upmin;
 TeleBook *temp;
 unsorted=head;
 sorted=NULL;  
       while (unsorted->next)   
		 {   
             min = unsorted;   
               temp = unsorted->next;            //在未排序部分找出最小元素的指针min  
		         while (temp)       
				 {   
                   if (strcmp(min->num,temp->num)>0)                  
				    min = temp;              
			        temp = temp->next;  
				 }
				 if(unsorted==min)
					 sorted=unsorted;
				 else
				 {
					 upmin=unsorted;//找出找出指向min的链元素
					 while(upmin->next!=min)
						 upmin=upmin->next;
					 upmin->next=min->next;
					 if(sorted==NULL)
					 {
						 min->next=head;
						 head=sorted=min;
					 }
					 else
					 {
						 sorted->next = min;
						 min->next = unsorted;
						 sorted=min;
					 }
				 }
				 unsorted=sorted->next;
		 }
	   }*/
void Sort_by_num(TeleBook *head)                                            /*5. 升序排列 */
{
TeleBook *p1,*p2,*p0,*p3,*p;/*表头指针，表尾指针，更小的节点的前节点，最小节点，当前节点*/ 
p1 = NULL;
while (head!= NULL)/*在链表中找最小的节点。*/ 
{
for (p=head,p3=head; p->next!=NULL; p=p->next)/*循环遍历链表中的节点，找出此时最小的节点。*/   
{
if (strcmp(p->next->num,p3->num)<0) /*找到一个比当前p3小的节点。*/ 
{
p0 = p;
p3 = p->next;
} 
}
if (p1 == NULL)  
{
p1 = p3; /*第一次找到键值最小的节点*/ 
p2 = p3;/*尾指针让它指向最后的一个节点。*/ 
}
else
{
p2->next = p3;/*把刚找到的最小节点放到最后*/ 
p2 = p3;/*尾指针也指向它。*/ 
}   
if (p3 == head) /*如果找到的最小节点就是第一个节点*/
head = (head)->next;
else
p0->next = p3->next; /*让p3离开了原链表。*/ 
}
if (p1 != NULL)
p2->next = NULL;
head = p1;
printf("排序成功\n");
}



void main()
{
	TeleBook *head=NULL;
	char filename[20];
	while(1)
	{
		switch(Display_Main_Menu())
		{
		case 1:
			system("cls"); 
			printf("Input Record\n");
			head=Create();
			system("pause");
			break;
		case 2:
			system("cls"); 
			printf("Display All Records\n");
			Display(head);
			system("pause");
			break;
		case 3:
			system("cls"); 
			printf("Insert a Record\n");
		    head=Insert_a_record(head);
			system("pause");
			break;
	    case 4:
			system("cls"); 
			printf("Delete a Record\n");
			head=Delete_a_record(head);
			system("pause");
			break;
	    case 5:
			system("cls"); 
			printf("Sort\n");
		    Sort_by_num(head); 
			system("pause");
			break;
		case 6:
			system("cls"); 
			printf("Query\n");
			Query_a_record(head);
			system("pause");
			break;
		case 7:
			system("cls"); 
			printf("Add Records from a Text File\n");        
            head=AddfromText(head,filename);
			system("pause");
			break;
		case 8:
			system("cls"); 
			printf("Write to a Text File\n");
			WritetoText(head,"records.txt");
			system("pause");
			break;
		case 9:
			system("cls"); 
			printf("Reverse List\n");
		    head=Reverse(head);
			system("pause");
			break;
		case 10:
			system("cls"); 
			printf("Delete the Same Records\n");
			head=DeleteSame(head);
			system("pause");
			break;
		case 0:
			system("cls"); 
			Quit(head);
			system("pause");
			exit(0);
		}
	}
}

	 int Display_Main_Menu()
		{
			int c;

			do{
				system("cls"); /*清屏*/
				printf("                The telephone Management System                \n");
				printf("***************************************************************\n");
				printf("*                        Menu                                 *\n");
                printf("***************************************************************\n");               
				printf("*                    1.Input Record                           *\n");
				printf("*                    2.Display All Records                    *\n");
				printf("*                    3.Insert a Record                        *\n");
				printf("*                    4.Delete a Record                        *\n");
				printf("*                    5.Sort                                   *\n");
				printf("*                    6.Query                                  *\n");
				printf("*                    7.Add Records from a Text File           *\n");
				printf("*                    8.Write to a Text File                   *\n");
				printf("*                    9.Reverse List                           *\n");
				printf("*                    10.Delete the Same Records               *\n");
				printf("*                    0.Quit                                   *\n");
			    printf("***************************************************************\n"); 
				printf("Please enter your choice(0-10):");

				scanf("%d",&c);
			} while (c<0 || c>10);

			return (c);
		}
