#include<stdio.h>
#include<string.h>			//strcmp strcpy����ͷ�ļ� //strcmp�����ǱȽ������ַ����Ĵ�С //strcpy��������ʵ�������ַ����Ŀ��� 
#include<stdlib.h>			//�ļ�ͷ�ļ�
#define N 50               //�������N������50���滻
void show();
void luru(struct student stu[],int length);//¼��   //��������������������������һ������Ϊ�ṹ�����飬
void oupt(struct student stu[],int length);//��ʾ   //struct student stu��һ���ṹ�壬student���ǽṹ������ָ��ڶ�������Ϊint������ 
void change(struct student stu[],int length);//�޸�
void fond(struct student stu[],int length);//����
void delet(struct student stu[],int length);//ɾ�� 

//ȫ�ֶ���
struct student				//����ѧ���ɼ�
	{
		int xh;				//ѧ��
		char xm[20];		//����
		char xb[10];		//�Ա�		
		int nl;				//����
		char bz[30];		//��ע
	};
 //������
int main()
{	
	int a;
	struct student students[N];		//����ṹ������
	show();							//������ʾ����
	do								//ѭ�����
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1:				//¼��
				system( "cls ");//�������� 
				luru(students,N);
				show();
				break;
			case 2:				//��ʾ
				system( "cls ");
				oupt(students,N);
				show();
				break;		
			case 3:
				delet(students,N);
				show();
				break;
			case 4:				//�޸�
				system( "cls ");
				change(students,N);
				show();
				break;
			case 5:				//��ѯ
				system( "cls ");
				fond(students,N);
				show();
				break; 
			case 6:				//�˳�
				system( "cls ");
				printf("ллʹ�ã�\n");
				getchar();
				getchar();
				break;
			default :
				system( "cls ");				
				printf("\n����ָ���ȷ(���������)\n");				
				getchar();//�û�������ַ�����ڼ��̻�������ֱ���û����س��� 
				getchar();
				system( "cls ");
				show();
		}
		
	}while(a!=6);
}
//�˵� 
void show()
{
	printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
	printf("\t\t��         ѧ����Ϣ����ϵͳ         ��\n");  
	printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
	printf("\t\t��ѡ��ϵͳ�����\n");//ת���ַ� \t����������һ�Ʊ�λ��
	printf("\t\t1.ѧ��������Ϣ¼�룺\n");
	printf("\t\t2.ѧ��������Ϣ��ʾ��\n");
	printf("\t\t3.ѧ��������Ϣɾ����\n");
	printf("\t\t4.ѧ��������Ϣ�޸�(����������)��\n");
	printf("\t\t5.ѧ��������Ϣ��ѯ��\n");
	printf("\t\t6.�˳�ϵͳ��\n");
	printf("\t\t��ѡ��");
}
//¼��
void luru(struct student stu[],int length)
{
	int i,h=0;// i��ѭ���õģ�h��һ����¼��Ϣ������ 
	FILE *fp;					//�����ļ�
	char a;//a������������������y n���Ӷ��ж��Ƿ����ִ�е� 
	for(i=0;a!='n'&&a!='N';i++)
	{			
		printf("����ͬѧ��ѧ�ţ��������Ա����䣬��ע\n");
		printf("������ѧ��ѧ��\n");
		scanf("%d",&stu[i].xh);
		printf("������ѧ������\n");
		scanf("%s",stu[i].xm);
		printf("������ѧ���Ա�\n");
		scanf("%s",stu[i].xb);
		printf("������ѧ������\n");
		scanf("%d",&stu[i].nl);
		printf("������ѧ����ע\n");
		scanf("%s",stu[i].bz);
		system( "cls ");
		printf("�Ƿ�������룿y.��     n.��\n");
		scanf("\n%c",&a);
		h=h+1;
		system( "cls ");
	}
	printf("�Ƿ񱣴汾��¼�룿y.��      n.��\n");
	scanf("\n%c",&a);
	system( "cls ");				//��������	
	switch(a)						//ѡ���Ƿ񱣴�
	{
		case 'y':
			fp=fopen("allxx.txt","a");//��׷����ʽ���ļ�		
			if(fp==NULL)			//���޷������˳�ϵͳ
			{
				printf("����!");
				exit(0);           //�˳� 
			}

			for(i=0;i<h;i++)		//ѭ�����д���ļ�			
			fwrite(&stu[i],sizeof(struct student),1,fp);//��¼��Ϣ,����&stu[i]��fwrite��˵��Ҫ������ݵĵ�ַ.
			printf("  ����ɹ�!\n");                    //����sizeof(struct student)Ҫд�����ݵĵ��ֽ���;																				
			getchar();                                  //����1Ҫ����д��sizeof(struct student)�ֽڵ�������ĸ�����1
			getchar();	                                //����fp:Ŀ���ļ�ָ�롣    
			system( "cls ");
			fclose(fp);//�ر��ļ�
			break;
		case 'n':
			printf("�������ݲ�����!\n");
			getchar();
			getchar();			       
			system( "cls ");
		}
}


//��ʾ
void oupt(struct student stu[],int length)
{
	int i,h=0;
	FILE *fp;						//�����ļ�
	fp=fopen("allxx.txt","r");		//��ֻ����ʽ���ļ�
	if(fp==NULL)					//����޷����ļ����˳�ϵͳ
	{
		printf("����!");
		exit(0);
	}
	while(!feof(fp))				//���ļ�����ѭ�����뵽struct student stu[N]��ֱ�����뵽�ļ���󣨵����ļ���
	{
		fread(&stu[h],sizeof(struct student),1,fp);//���ļ������ж�ȡ���� 
		h++;
	}
	fclose(fp);						//�ر��ļ�							
	printf("���\tѧ��\t����\t�Ա�\t����\t��ע\n");
	for(i=0;i<h-1;i++)
	{
		printf("%d %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
	}
	getchar();
	getchar();
	system( "cls ");
}
//�޸�
void change(struct student stu[],int length)
{
	FILE *fp;						
	char a[20]={"000000"};//�޸ĵ����� 
	char b[20];
	int c,i,z,h=0;//cѧ�� h��Ϣ���� z����ı��� 
	fp=fopen("allxx.txt","r");	    //��ֻ����ʽ���ļ�
	if(fp==NULL)					//����޷����ļ����˳�ϵͳ
	{
		printf("����!");
		exit(0);
	}
	while(!feof(fp))				//�����ļ�
	{
		fread(&stu[h],sizeof(struct student),1,fp);
		h++;
	}

	fclose(fp);						//�ر��ļ�
	printf("����������\n");
	scanf("%s",&b);
	system( "cls ");
	if(strcmp(a,b)==0)				//��֤�����Ƿ���ȷ
	{
		printf("��������Ҫ�޸���Ϣͬѧ��ѧ��\n");
		scanf("%d",&c);
		for(i=0;i<h;i++)
			if(c==stu[i].xh)
				break;
		if(i==h)
		{
			system( "cls ");
			printf("ѧ���������!\n");
			getchar();
			getchar();
		}
		else
		{			
			printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("������Ҫ�޸ĵ���Ϣ\n");
			printf("1.�޸�ѧ��ѧ��\n");
			printf("2.�޸�ѧ������\n");
			printf("3.�޸�ѧ���Ա�\n");
			printf("4.�޸�ѧ������\n");
			printf("5.�޸�ѧ����ע\n");
			printf("6.����\n");
			printf("��ѡ��");
			scanf("%d",&z);
			system( "cls ");
			switch(z)
			{
				case 1:
					printf("������ѧ��ѧ��\n");
					scanf("%d",&stu[i].xh);
					break;
				case 2:
					printf("������ѧ������\n");
					scanf("%s",stu[i].xm);
					break;
				case 3:
					printf("������ѧ���Ա�\n");
					scanf("%s",stu[i].xb);
					break;
				case 4:
					printf("������ѧ������\n");
					scanf("%d",&stu[i].nl);
					break;
				case 5:
					printf("������ѧ����ע\n");
					scanf("%s",stu[i].bz);
					break;
			}
			fp=fopen("allxx.txt","w");			//��ֻд��ʽ���ļ�
			if(fp==NULL)					
			{
				printf("����!");
				exit(0);
			}
			for(i=0;i<h;i++)					//ѭ��д��
				fwrite(&stu[i],sizeof(struct student),1,fp);
			fclose(fp);							//�ر��ļ�
			system( "cls ");
			printf("�޸���ɣ�");			
			getchar();
			getchar();
		}
		
	}
	else
	{
		printf("��������������ʵ�����\n");
		getchar();
		getchar();
	}
	system( "cls ");
}
//��ѯ
void fond(struct student stu[],int length)
{
	int a,c,i,f,h=0;//a������� cѧ�� d���� e�Ա� f���� 
	char d[10];
	char e[10];
	FILE *fp;
	fp=fopen("allxx.txt","r");		//��ֻ����ʽ���ļ�
	if(fp==NULL)					
	{
		printf("����!");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&stu[h],sizeof(struct student),1,fp);
		h++;
	}
	fclose(fp);
	printf("1.��ѧ�Ų���\n");
	printf("2.����������\n");
	printf("3.���Ա����\n");
	printf("4.���������\n");
	printf("5.����\n");
	scanf("%d",&a);
	system( "cls ");
	switch(a)
	{
	case 1:					//��ѧ�Ų���
		printf("��������Ҫ��ѯ��ѧ��\n");
		scanf("%d",&c);
		system( "cls ");
		for(i=0;i<h;i++)
			if(c==stu[i].xh)
				break;
		if(i==h)
			printf("ѧ���������!\n");
		else
			{
				printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
				printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			}
		getchar();
		getchar();
		break;
	case 2:						//����������
		printf("��������Ҫ��ѯ������\n");
		scanf("%s",d);
		system( "cls ");
		for(i=0;i<h;i++)
			if(strcmp(d,stu[i].xm)==0)
				break;
		if(h==i)
			printf("�����������!\n");
		else
		{
			printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
		}
			getchar();
			getchar();
		break;
	case 3:							//���Ա����
		printf("��������Ҫ��ѯ���Ա�\n");
		scanf("%s",e);
		system( "cls ");
		printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
		for(i=0;i<h;i++)
			if(strcmp(e,stu[i].xb)==0)			
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			getchar();
			getchar();
		break;
	case 4:							//���������
	printf("��������Ҫ��ѯ������\n");
		scanf("%d",&f);
		system( "cls ");
		printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
		for(i=0;i<h;i++)
			if(f==stu[i].nl)				
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
				//printf("ѧ�ţ��������Ա����䣬��ע�ֱ�Ϊ\n%5d %6s %3s %3d %s\n",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
				getchar();
				getchar();
			break;
	case 5:
		getchar();//
		break;
	}
	system( "cls ");
}
//ɾ��
void delet(struct student stu[],int length)
{

	int i,h=0,c,z;//ѧ�� z����ı��� 
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
	printf("��������Ҫɾ����Ϣͬѧ��ѧ��\n");
	scanf("%d",&c);
	for(i=0;i<h;i++)
		if(c==stu[i].xh)
			break;
		if(i==h)
			printf("����ѧ�Ų�����\n");
		else
		{
			//printf("ѧ�ţ��������Ա����䣬��ע�ֱ�Ϊ\n%5d %6s %3s %3d %s\n",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("��ͬѧ��\n���\tѧ��\t����\t�Ա�\t����\t��ע\n");
			printf("%d.    %6d%8s  %4s\t%3d \t%s\n",i+1,stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl,stu[i].bz);
			printf("��1ȷ��ɾ����ѧ����Ϣ,�����������ּ�����");//
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
				printf("��ɾ��\n");
			}
			else
				printf("ɾ��������ȡ��\n");
			}
	getchar();
	getchar();
	system( "cls ");
}
