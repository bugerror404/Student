#include<stdio.h>
#include<string.h>			//strcmp strcpy函数头文件 //strcmp函数是比较两个字符串的大小 //strcpy函数用于实现两个字符串的拷贝 
#include<stdlib.h>			//文件头文件
#define N 50               //如果出现N，就用50来替换
void show();
void luru(struct student stu[],int length);//录入   //声明函数函数参数有两个，第一个参数为结构体数组，
void oupt(struct student stu[],int length);//显示   //struct student stu是一个结构体，student则是结构体数组指针第二个参数为int型数据 
void change(struct student stu[],int length);//修改
void fond(struct student stu[],int length);//查找
void delet(struct student stu[],int length);//删除 

//全局定义
struct student				//存入学生成绩
	{
		int xh;				//学号
		char xm[20];		//姓名
		char xb[10];		//性别		
		int nl;				//年龄
		char bz[30];		//备注
	};
 //主函数
int main()
{	
	int a;
	struct student students[N];		//定义结构体数组
	show();							//界面显示函数
	do								//循环语句
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1:				//录入
				system( "cls ");//清屏函数 
				luru(students,N);
				show();
				break;
			case 2:				//显示
				system( "cls ");
				oupt(students,N);
				show();
				break;		
			case 3:
				delet(students,N);
				show();
				break;
			case 4:				//修改
				system( "cls ");
				change(students,N);
				show();
				break;
			case 5:				//查询
				system( "cls ");
				fond(students,N);
				show();
				break; 
			case 6:				//退出
				system( "cls ");
				printf("谢谢使用！\n");
				getchar();
				getchar();
				break;
			default :
				system( "cls ");				
				printf("\n输入指令不正确(任意键继续)\n");				
				getchar();//用户输入的字符存放在键盘缓冲区，直到用户按回车键 
				getchar();
				system( "cls ");
				show();
		}
		
	}while(a!=6);
}
//菜单 
void show()
{
	printf("\t\t ╭═════════■□■□═══╮\n");  
	printf("\t\t│         学生信息管理系统         │\n");  
	printf("\t\t╰═══■□■□══════════╯\n");  
	printf("\t\t请选择系统功能项：\n");//转义字符 \t横向跳到下一制表位置
	printf("\t\t1.学生基本信息录入：\n");
	printf("\t\t2.学生基本信息显示：\n");
	printf("\t\t3.学生基本信息删除：\n");
	printf("\t\t4.学生基本信息修改(先输入密码)：\n");
	printf("\t\t5.学生基本信息查询：\n");
	printf("\t\t6.退出系统：\n");
	printf("\t\t请选择：");
}
//录入
void luru(struct student stu[],int length)
{
	int i,h=0;// i是循环用的，h是一共记录信息的条数 
	FILE *fp;					//定义文件
	char a;//a是用来存键盘上输入的y n，从而判断是否继续执行的 
	for(i=0;a!='n'&&a!='N';i++)
	{			
		printf("输入同学的学号，姓名，性别，年龄，备注\n");
		printf("请输入学生学号\n");
		scanf("%d",&stu[i].xh);
		printf("请输入学生姓名\n");
		scanf("%s",stu[i].xm);
		printf("请输入学生性别\n");
		scanf("%s",stu[i].xb);
		printf("请输入学生年龄\n");
		scanf("%d",&stu[i].nl);
		printf("请输入学生备注\n");
		scanf("%s",stu[i].bz);
		system( "cls ");
		printf("是否继续输入？y.是     n.否\n");
		scanf("\n%c",&a);
		h=h+1;
		system( "cls ");
	}
	printf("是否保存本次录入？y.是      n.否\n");
	scanf("\n%c",&a);
	system( "cls ");				//清屏函数	
	switch(a)						//选择是否保存
	{
		case 'y':
			fp=fopen("allxx.txt","a");//以追加形式打开文件		
			if(fp==NULL)			//若无法打开则退出系统
			{
				printf("错误!");
				exit(0);           //退出 
			}

			for(i=0;i<h;i++)		//循环语句写入文件			
			fwrite(&stu[i],sizeof(struct student),1,fp);//记录信息,参数&stu[i]对fwrite来说是要输出数据的地址.
			printf("  保存成功!\n");                    //参数sizeof(struct student)要写入内容的单字节数;																				
			getchar();                                  //参数1要进行写入sizeof(struct student)字节的数据项的个数是1
			getchar();	                                //参数fp:目标文件指针。    
			system( "cls ");
			fclose(fp);//关闭文件
			break;
		case 'n':
			printf("本次数据不保存!\n");
			getchar();
			getchar();			       
			system( "cls ");
		}
}


//显示
void oupt(struct student stu[],int length)
{
	int i,h=0;
	FILE *fp;						//定义文件
	fp=fopen("allxx.txt","r");		//以只读形式打开文件
	if(fp==NULL)					//如果无法打开文件则退出系统
	{
		printf("错误!");
		exit(0);
	}
	while(!feof(fp))				//将文件内容循环输入到struct student stu[N]中直到输入到文件最后（导出文件）
	{
		fread(&stu[h],sizeof(struct student),1,fp);//从文件内容中读取数据 
		h++;
	}
	fclose(fp);						//关闭文件							
	printf("编号\t学号\t姓名\t性别\t年龄\t备注\n");
	for(i=0;i<h-1;i++)
	{
		printf("%d %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
	}
	getchar();
	getchar();
	system( "cls ");
}
//修改
void change(struct student stu[],int length)
{
	FILE *fp;						
	char a[20]={"000000"};//修改的密码 
	char b[20];
	int c,i,z,h=0;//c学号 h信息条数 z定义的变量 
	fp=fopen("allxx.txt","r");	    //以只读形式打开文件
	if(fp==NULL)					//如果无法打开文件则退出系统
	{
		printf("错误!");
		exit(0);
	}
	while(!feof(fp))				//导出文件
	{
		fread(&stu[h],sizeof(struct student),1,fp);
		h++;
	}

	fclose(fp);						//关闭文件
	printf("请输入密码\n");
	scanf("%s",&b);
	system( "cls ");
	if(strcmp(a,b)==0)				//验证密码是否正确
	{
		printf("请输入需要修改信息同学的学号\n");
		scanf("%d",&c);
		for(i=0;i<h;i++)
			if(c==stu[i].xh)
				break;
		if(i==h)
		{
			system( "cls ");
			printf("学号输入错误!\n");
			getchar();
			getchar();
		}
		else
		{			
			printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("输入需要修改的信息\n");
			printf("1.修改学生学号\n");
			printf("2.修改学生姓名\n");
			printf("3.修改学生性别\n");
			printf("4.修改学生年龄\n");
			printf("5.修改学生备注\n");
			printf("6.返回\n");
			printf("请选择：");
			scanf("%d",&z);
			system( "cls ");
			switch(z)
			{
				case 1:
					printf("请输入学生学号\n");
					scanf("%d",&stu[i].xh);
					break;
				case 2:
					printf("请输入学生姓名\n");
					scanf("%s",stu[i].xm);
					break;
				case 3:
					printf("请输入学生性别\n");
					scanf("%s",stu[i].xb);
					break;
				case 4:
					printf("请输入学生年龄\n");
					scanf("%d",&stu[i].nl);
					break;
				case 5:
					printf("请输入学生备注\n");
					scanf("%s",stu[i].bz);
					break;
			}
			fp=fopen("allxx.txt","w");			//以只写形式打开文件
			if(fp==NULL)					
			{
				printf("错误!");
				exit(0);
			}
			for(i=0;i<h;i++)					//循环写入
				fwrite(&stu[i],sizeof(struct student),1,fp);
			fclose(fp);							//关闭文件
			system( "cls ");
			printf("修改完成！");			
			getchar();
			getchar();
		}
		
	}
	else
	{
		printf("密码输入错误！请核实后操作\n");
		getchar();
		getchar();
	}
	system( "cls ");
}
//查询
void fond(struct student stu[],int length)
{
	int a,c,i,f,h=0;//a定义变量 c学号 d姓名 e性别 f年龄 
	char d[10];
	char e[10];
	FILE *fp;
	fp=fopen("allxx.txt","r");		//以只读形式打开文件
	if(fp==NULL)					
	{
		printf("错误!");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&stu[h],sizeof(struct student),1,fp);
		h++;
	}
	fclose(fp);
	printf("1.按学号查找\n");
	printf("2.按姓名查找\n");
	printf("3.按性别查找\n");
	printf("4.按年龄查找\n");
	printf("5.返回\n");
	scanf("%d",&a);
	system( "cls ");
	switch(a)
	{
	case 1:					//按学号查找
		printf("请输入需要查询的学号\n");
		scanf("%d",&c);
		system( "cls ");
		for(i=0;i<h;i++)
			if(c==stu[i].xh)
				break;
		if(i==h)
			printf("学号输入错误!\n");
		else
			{
				printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
				printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			}
		getchar();
		getchar();
		break;
	case 2:						//按姓名查找
		printf("请输入需要查询的姓名\n");
		scanf("%s",d);
		system( "cls ");
		for(i=0;i<h;i++)
			if(strcmp(d,stu[i].xm)==0)
				break;
		if(h==i)
			printf("姓名输入错误!\n");
		else
		{
			printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
		}
			getchar();
			getchar();
		break;
	case 3:							//按性别查找
		printf("请输入需要查询的性别\n");
		scanf("%s",e);
		system( "cls ");
		printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
		for(i=0;i<h;i++)
			if(strcmp(e,stu[i].xb)==0)			
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			getchar();
			getchar();
		break;
	case 4:							//按年龄查找
	printf("请输入需要查询的年龄\n");
		scanf("%d",&f);
		system( "cls ");
		printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
		for(i=0;i<h;i++)
			if(f==stu[i].nl)				
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
				//printf("学号，姓名，性别，年龄，备注分别为\n%5d %6s %3s %3d %s\n",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
				getchar();
				getchar();
			break;
	case 5:
		getchar();//
		break;
	}
	system( "cls ");
}
//删除
void delet(struct student stu[],int length)
{

	int i,h=0,c,z;//学号 z定义的变量 
	FILE *fp;
	fp=fopen("allxx.txt","r");
	while(!feof(fp))
	{
		fread(&stu[h],sizeof(struct student),1,fp);
		h++;
	}
	h=h-1;
	fclose(fp);
	system( "cls ");
	printf("请输入需要删除信息同学的学号\n");
	scanf("%d",&c);
	for(i=0;i<h;i++)
		if(c==stu[i].xh)
			break;
		if(i==h)
			printf("输入学号不存在\n");
		else
		{
			//printf("学号，姓名，性别，年龄，备注分别为\n%5d %6s %3s %3d %s\n",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("该同学的\n编号\t学号\t姓名\t性别\t年龄\t备注\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("按1确定删除该学生信息,其他任意数字键放弃");//
			scanf("%d",&z);
			system( "cls ");		
			if(z==1)
			{					
				for(;i+1<h;i++)	
				stu[i]=stu[i+1];			
				fp=fopen("allxx.txt","w");
				for(i=0;i<h-1;i++)
					fwrite(&stu[i],sizeof(struct student),1,fp);
				fclose(fp);
				printf("已删除\n");
			}
			else
				printf("删除操作已取消\n");
			}
	getchar();
	getchar();
	system( "cls ");
}
