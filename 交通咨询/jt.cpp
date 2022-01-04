#include <iostream>
#include <cstring>
#define time TT
#include "jt.h"
using namespace std;
char	city[MAX_VERTEX_NUM][10];
int		TTime[2];
int		time[2];
int		time1[2];
int		time2[2];
int		c[MAX_VERTEX_NUM];
int		d[MAX_VERTEX_NUM];


//��ʾ������ѡ�����
int main()  
{
	ALGraph G;
	int i;
	system("cls");
	cout << "��ѡ�������:"	<< endl;
	cout << "1=����Ա����"		<< endl
		 << "2=�û���ѯ"		<< endl
		 << "3=��ʾ��ͨϵͳ"	<< endl
		 << "4=�˳�"			<< endl;
	cout << "ѡ��?";
	cin  >> i;
	
	while(i!=4)
	{
		switch(i)
		{
			case 1: Administer(&G);	break;
			case 2: UserDemand(G);	break;
			case 3: PrintGraph(&G);	break;
		}
		system("cls");
		cout << endl 
			 << "��ѡ�������:" 
			 << endl;
		cout << "1=����Ա����"		<< endl
			 << "2=�û���ѯ"		<< endl
			 << "3=��ʾ��ͨϵͳ"	<< endl
			 << "4=�˳�"			<< endl;
		cout << "ѡ��?";
		cin  >> i;
	}
	return 0;
}



//����Ա������Ŀѡ�����
void Administer(ALGraph *G)
{
	int i;
	system("cls");
	cout << endl 
		 << "��ѡ�������Ŀ:" 
		 << endl;
	cout << "1=��ʼ����ͨϵͳ"	<< endl
		 << "2=���б༭"		<< endl
		 << "3=�ɻ�����༭"	<< endl
		 << "4=�г����α༭"	<< endl
		 << "5=������һ���˵�"	<< endl;
	cout << "ѡ��?";
	cin  >> i;
	
	while ( i!=5 )
	{
		switch(i)
		{
			case 1: initgraph(G);	break;
			case 2: cityedit(G);	break;
			case 3: flightedit(G);  break;
			case 4: trainedit(G);   break;
		}
		system("cls");
		cout 
			 << "��ѡ�������Ŀ:"
			 << endl;
		cout << "1=��ʼ����ͨϵͳ"	<< endl
			 <<	"2=���б༭"		<< endl
			 <<	"3=�ɻ�����༭"	<< endl
		     <<	"4=�г����α༭"	<< endl
			 <<	"5=������һ���˵�"	<< endl;
		cout << "ѡ��?";
		cin  >> i;		
	}
}

//����ͨϵͳ��ʽѡ�����
void initgraph(ALGraph *G)
{
	int i;
	
	cout << endl
		 << "��ѡ���ʼ����ʽ:"
		 << endl;
	cout << "1=����" << endl
		 << "2=�ĵ�" << endl;
	cout << "ѡ��?";
	cin  >> i;
	
	switch(i)
	{
		case 1:	createcityfile();
				createplanefile();
				createtrainfile();
				CreateGraph(G);
				break;
		case 2: CreateGraph(G);	
				break;
	}
}

//�������������ĵ�
void createcityfile()
{
	int i=0;
	int j;
	char flag='y';
	FILE *fp;
	
	cout << endl
		 << "������������Ƶ���Ϣ:"
		 << endl;
	
	while(flag=='y'||flag=='Y')
	{
		cout << "��������:";
		cin  >> city[i];
		i++;
		cout << "��������? (Y/N)";
		cin  >> flag;		
	}
	cout << endl;

	if ( (fp=fopen("city.txt","wb"))==NULL )
	{
		printf( "\n�޷����ļ�!\n" );
		return;
	}
	for( j=0; j<i; j++ )
		fprintf( fp,"%10s",city[j] );//��ʼ������Ϣ
	fclose( fp );
}

//�����ɻ������ĵ�
void createplanefile()
{
	int code,bt[2],at[2];
	float money;
	int i;
	int count;
	char vt[10],vh[10],flag;
	FILE *fp;
	flag = 'y';//��flag��һֱȷ���Ƿ�Ҫ�������룬��ʵҲ�����ñ�ķ���
	count=0;
	
	while ( flag=='Y' || flag=='y' )
	{
		cout << "������ɻ��������Ϣ:" << endl;
		cout << "�ɻ�������:";
		cin  >> code;
		
		cout << "��ʼ����:";
		cin  >> vt;
		cout << "Ŀ�ĳ���:";
		cin  >> vh;
		cout << "�������:";
		cin  >> money;
		
		printf( "���ʱ��:" );
		scanf( "%d:%d", &bt[0], &bt[1] );		
		while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
		{
			printf( "\nʱ��������������������!\n" );				 
			scanf( "%d:%d", &bt[0], &bt[1] );		
		}
		
		printf( "����ʱ��:" );
		scanf( "%d:%d", &at[0], &at[1] );		
		while ( at[0]<0 || at[0]>=24 || at[1]<0 || at[1]>=60 )
		{
			printf( "\nʱ��������������������!\n" );
			scanf( "%d:%d", &at[0], &at[1] );		
		}

		a[count].co=code;
		strcpy(a[count].vt,vt);
		strcpy(a[count].vh,vh);
		a[count].bt[0]=bt[0];
		a[count].bt[1]=bt[1];
		a[count].at[0]=at[0];
		a[count].at[1]=at[1];
		a[count].mo=money;
		count++;
		cout << "��������? (Y/N)";
		cin  >> flag;		
		cout << endl;
	}

	if ((fp=fopen("plane.txt","wb"))==NULL)
		printf( "\n�޷����ļ�!\n" );			 
	fprintf( fp, "%d", count );
	for ( i=0; i<count; i++ )
		if ( fwrite(&a[i],sizeof(struct arc),1,fp)!=1 )
			printf( "\n�ļ�д�����!\n" );
	fclose(fp);
}


//�����г������ĵ�
void createtrainfile()
{
	int code,bt[2],at[2];
	float money;
	int i;
	int count;
	char vt[10],vh[10],flag;
	FILE *fp;
	flag='y';
	count=0;
	while(flag=='y'||flag=='Y')
	{
		cout << endl << "�������г����ε���Ϣ:" << endl;
		cout << "�г����α��:";
		cin  >> code;
		
		cout << "��ʼ����:";
		cin  >> vt;
		cout << "Ŀ�ĳ���:";
		cin  >> vh;
		cout << "���η���:";
		cin  >> money;
		
		printf( "����ʱ��:" );
		scanf( "%d:%d", &bt[0], &bt[1] );		
		while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
		{
			printf( "\nʱ��������������������!\n" );				 
			scanf( "%d:%d", &bt[0], &bt[1] );		
		}
		
		printf( "����ʱ��:" );
		scanf( "%d:%d", &at[0], &at[1] );				
		while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
		{
			printf( "\nʱ��������������������\n" );
			scanf( "%d:%d", &at[0], &at[1] );					
		}

		a[count].co=code;
		strcpy(a[count].vt,vt);
		strcpy(a[count].vh,vh);
		a[count].bt[0]=bt[0];
		a[count].bt[1]=bt[1];
		a[count].at[0]=at[0];	
		a[count].at[1]=at[1];
		a[count].mo=money;
		count++;
		cout << "��������?(Y/N)";
		cin  >> flag;
		cout << endl;
	}
	if ((fp=fopen("train.txt","wb"))==NULL)
		printf( "\n�޷����ļ�!\n" );			 
	fprintf( fp,"%d",count);
	for(i=0;i<count;i++)
		if ( fwrite(&a[i],sizeof(struct arc),1,fp)!=1 )
			printf( "\n�ļ�д�����!\n" );				 
	fclose(fp);
}


//�������ڽ�ͨϵͳ�ж�λ����
int LocateVertex(ALGraph *G,char *v)
{
	int j,k;
	j = -1;
	for(k = 0; k < G -> vexnum ; k ++ )
		if (strcmp (G -> vertices[k].cityname, v ) == 0 )//�ڽӱ����ʽ
		{
			j = k;
			break;
		}		
	return(j);
}


//��city��plan��train�����ĵ��������н�ͨϵͳ
void CreateGraph(ALGraph *G)
{
	int i,j,k;
	int arc_num;
	int count1,count2;
	int m,t;
	ArcNode *p,*q;
	FILE *fp;
	
	i=0;
	if((fp=fopen("city.txt","rb"))==NULL)
	{
		printf( "\n�޷����ļ�!\n" );		
		return;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%10s",city[i]);
		i++;
	}
	fclose(fp);
	j = 0;
	while(j < i)
	{
		strcpy(G -> vertices[j].cityname,city[j]);
		G -> vertices[j].planefirstarc = NULL;
		G -> vertices[j].trainfirstarc = NULL;
		j ++;
	}
	G -> vexnum = i;
	if ( (fp=fopen("plane.txt","rb")) == NULL ) printf( "\n�޷����ļ�!\n" );				 
	k = 0;
	fscanf(fp,"%d",&count1);
	while(k < count1)//�������
	{
		if ( fread(&a[k],sizeof(struct arc),1,fp)!=1 ) printf( "\n�ļ��������!\n" );				 
		k ++;
	}
	fclose(fp);
	k = 0;
	arc_num=0;
	while(k < count1)
	{
		i = LocateVertex(G,a[k].vt);
		j = LocateVertex(G,a[k].vh);
		q = G -> vertices[i].planefirstarc;
		m = 0;
		while (q != NULL)//������浽���Ա��
		{
			if (q -> adjvex == j)
			{
				t = q -> info.last + 1;
				q -> info.stata[t].number = a[k].co;
				q -> info.stata[t].expenditure = a[k].mo;
				q->info.stata[t].begintime[0]=a[k].bt[0];
				q->info.stata[t].begintime[1]=a[k].bt[1];
				q->info.stata[t].arrivetime[0]=a[k].at[0];
				q->info.stata[t].arrivetime[1]=a[k].at[1];
				q->info.last=t;
				m=1;
				break;
			}
			q = q -> nextarc;
		}
		if (m == 0)
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p -> adjvex=j;
			p -> info.stata[0].number=a[k].co;
			p -> info.stata[0].expenditure=a[k].mo;
			p -> info.stata[0].begintime[0]=a[k].bt[0];
			p -> info.stata[0].begintime[1]=a[k].bt[1];
			p -> info.stata[0].arrivetime[0]=a[k].at[0];
			p -> info.stata[0].arrivetime[1]=a[k].at[1];
			p -> info.last=0;
			p -> nextarc=G->vertices[i].planefirstarc;
			G -> vertices[i].planefirstarc=p;
			arc_num ++;
		}
		k++;
	}
	G -> planearcnum = arc_num;
	if((fp=fopen("train.txt","rb"))==NULL)
	{
		printf( "\n�޷����ļ�!\n" );
		return;
	}
	k=0;
	fscanf(fp,"%d",&count2);
	while(k<count2)
	{
		if ( fread(&a[k],sizeof(struct arc),1,fp)!=1 )	printf( "\n�ļ��������!\n" );				 
		k++;
	}
	fclose(fp);
	k=0;
	arc_num=0;
	while(k<count2)
	{
		i=LocateVertex(G,a[k].vt);
		j=LocateVertex(G,a[k].vh);
		q=G->vertices[i].trainfirstarc;
		m=0;
		while(q!=NULL)
		{
			if(q->adjvex==j)
			{
				t=q->info.last+1;
				q->info.stata[t].number=a[k].co;
				q->info.stata[t].expenditure=a[k].mo;
				q->info.stata[t].begintime[0]=a[k].bt[0];
				q->info.stata[t].begintime[1]=a[k].bt[1];
				q->info.stata[t].arrivetime[0]=a[k].at[0];
				q->info.stata[t].arrivetime[1]=a[k].at[1];
				q->info.last=t;
				m=1;
				break;
			}
			q=q->nextarc;
		}
		if(m==0)
		{
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex=j;
			p->info.stata[0].number=a[k].co;
			p->info.stata[0].expenditure=a[k].mo;
			p->info.stata[0].begintime[0]=a[k].bt[0];
			p->info.stata[0].begintime[1]=a[k].bt[1];
			p->info.stata[0].arrivetime[0]=a[k].at[0];
			p->info.stata[0].arrivetime[1]=a[k].at[1];
			p->info.last=0;
			p->nextarc=G->vertices[i].trainfirstarc;
			G->vertices[i].trainfirstarc=p;
			arc_num++;
		}
		k++;
	}
	G->trainarcnum=arc_num;
}

//������н�ͨϵͳ����Ӧ���ĵ�
void save(ALGraph *G)
{
	int i,j,k,t;
	ArcNode *q;
	FILE *fp;
	
	j = 0;
	while ( j<G->vexnum )
	{
		strcpy(city[j],G->vertices[j].cityname);
		j++;
	}
	i = 0;
	if ( (fp=fopen("city.txt","wb"))==NULL ) printf( "�����޷����ļ�!" );			 

	while ( i<G->vexnum )
	{
		fprintf(fp,"%10s",city[i]);
		i++;
	}
	fclose( fp );
	k = 0;
	for( i=0; i<G->vexnum; i++ )
	{
		q = G->vertices[i].planefirstarc;
		while( q!=NULL )
		{
			for(t=0;t<=q->info.last;t++)
			{
				strcpy(a[k].vt,G->vertices[i].cityname);
				strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
				a[k].co=q->info.stata[t].number;
				a[k].mo=q->info.stata[t].expenditure;
				a[k].bt[0]=q->info.stata[t].begintime[0];
				a[k].bt[1]=q->info.stata[t].begintime[1];
				a[k].at[0]=q->info.stata[t].arrivetime[0];
				a[k].at[1]=q->info.stata[t].arrivetime[1];
				k++;
			}
			q = q->nextarc;
		}
	}
	if ( (fp=fopen("plane.txt","wb"))==NULL )	
	{
		printf( "\n�޷����ļ�!\n" );
		return;
	}
	i = 0;
	fprintf(fp,"%d",k);
	while ( i<k )
	{
		if ( fwrite(&a[i],sizeof(struct arc),1,fp)!=1 ) printf( "\n�ļ�д�����!\n" );				 
		i++;
	}
	fclose(fp);
	k = 0;
	for ( i=0; i<G->vexnum; i++ )
	{
		q = G->vertices[i].trainfirstarc;
		while ( q!=NULL )
		{
			for( t=0; t<=q->info.last; t++ )
			{
				strcpy(a[k].vt,G->vertices[i].cityname);
				strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
				a[k].co=q->info.stata[t].number;
				a[k].mo=q->info.stata[t].expenditure;
				a[k].bt[0]=q->info.stata[t].begintime[0];
				a[k].bt[1]=q->info.stata[t].begintime[1];
				a[k].at[0]=q->info.stata[t].arrivetime[0];
				a[k].at[1]=q->info.stata[t].arrivetime[1];
				k++;				
			}
			q = q->nextarc;
		}
	}
	if((fp=fopen("train.txt","wb"))==NULL)
	{
		printf( "\n�޷����ļ�!\n" );
		return;
	}
	i = 0;
	fprintf( fp,"%d",k );
	while ( i<k )
	{
		if ( fwrite(&a[i],sizeof(struct arc),1,fp)!=1 ) printf( "\n�ļ�д�����!\n" );				 
		i++;
	}
	fclose(fp); 
}

//��ʾ���б༭��Ŀѡ�����
void cityedit(ALGraph *G)
{
	int i;
	cout << endl
		 << "��ѡ����б༭��Ŀ:"
		 << endl;
	cout << "1=���ӳ���" << endl
		 << "2=ɾ������" << endl;
	cout << "ѡ��?";
	
	cin  >> i;
	if ( i==1 ) EnterVertex(G);
	if ( i==2 ) DeleteVertex(G);
}

//���ӳ���
void EnterVertex(ALGraph *G)
{
	char v[10],c;
	int i;
	cout << endl
		 << "�������������е�����:";
	cin  >> v;
	i=LocateVertex(G,v);
	if ( i>=0 && i<G->vexnum )
	{
		printf( "\n���󣡴˳����Ѵ���!\n" );			 
		return;
	}
	else
	{
		cout << endl
			 << "ȷ��?(Y/N)";
		
		cin  >> c;
		if ( c=='Y'||c=='y' )
		{
			i=G->vexnum;
			strcpy(G->vertices[i].cityname,v);
			G->vertices[i].planefirstarc=NULL;
			G->vertices[i].trainfirstarc=NULL;
			G->vexnum=i+1;
			save(G);
		}
		else return;
	}
}

//ɾ������
void DeleteVertex(ALGraph *G)
{
	int i,j,k,n;
	char v[10],c;
	ArcNode *p,*q,*m;
	cout << endl
		 << "������ɾ���ĳ���:"
		 << endl;
	cin >> v;
	cout << endl
		 << "ȷ��?(Y/N)";

	cin  >> c;
	if ( c=='Y'||c=='y' )
	{
		n=0;
		while(n<G->vexnum&&strcmp(G->vertices[n].cityname,v)!=0)
			n++;
		if ( n==G->vexnum ) printf( "\n�����޷��ҵ��˳���!\n" );			
		else
		{
			i = LocateVertex(G,v);
			p = G->vertices[i].planefirstarc;
			while ( p!=NULL )
			{
				q = p;
				p = p->nextarc;
				free(q);
			}
			p = G->vertices[i].trainfirstarc;
			while(p!=NULL)
			{
				q = p;
				p = p->nextarc;
				free(q);
			}
			for ( j=i;j<G->vexnum-1;j++ )
			{
				strcpy(G->vertices[j].cityname,G->vertices[j+1].cityname);
				G->vertices[j].planefirstarc=G->vertices[j+1].planefirstarc;
				G->vertices[j].trainfirstarc=G->vertices[j+1].trainfirstarc;
			}
			G->vertices[j].planefirstarc=NULL;
			G->vertices[j].trainfirstarc=NULL;
			for ( k=0;k<G->vexnum-1;k++ )
			{
				p=G->vertices[k].planefirstarc;
				while ( p!=NULL )
				{
					if ( p->adjvex>i )
					{
						p->adjvex=p->adjvex-1;
						q = p;
						p = p->nextarc;
					}
					else if ( p->adjvex==i )
					{
						if ( p==G->vertices[k].planefirstarc )
						{
							m = p;
							G->vertices[k].planefirstarc=p->nextarc;
							p = p->nextarc;
							free(m);
						}
						else
						{
							q->nextarc=p->nextarc;
							m = p;
							p = p->nextarc;
							free(q);
						}
					}
					else
					{
						q = p;
						p = p->nextarc;
					}
				}
			}
			for ( k=0; k<G->vexnum-1; k++ )
			{
				p = G->vertices[k].trainfirstarc;
				while ( p!=NULL )
				{
					if(p->adjvex>i)
					{
						p->adjvex = p->adjvex-1;
						q = p;
						p = p->nextarc;
					}
					else if ( p->adjvex==i )
					{
						if ( p==G->vertices[k].trainfirstarc )
						{
							m = p;
							G->vertices[k].trainfirstarc=p->nextarc;
							p=p->nextarc;
							free(m);
						}
						else
						{
							q->nextarc=p->nextarc;
							m=p;
							p=p->nextarc;
							free(q);
						}
					}
					else
					{
						q=p;
						p=p->nextarc;
					}
				}
			}
		}
		G->vexnum--;
		save(G);
	}
	else return;
}

//�ɻ�����༭��Ŀѡ�����
void flightedit(ALGraph *G)
{
	int i;
	cout << endl 
		 << "��ѡ��ɻ�����༭��Ŀ:"
		 << endl;
	cout << "1=��������" << endl
		 << "2=ɾ������" << endl;
	cout << "ѡ��?";
	cin  >> i;
	
	if ( i==1 ) EnterplaneArc(G);
	if ( i==2 ) DeleteplaneArc(G);
}

//�г����α༭��Ŀѡ�����
void trainedit(ALGraph *G)
{
	int i;
	cout << endl
		 << "��ѡ���г����α༭��Ŀ:"
		 << endl;
	cout << "1=��������" << endl
		 << "2=ɾ������" << endl;
	cout << "ѡ��?";
	cin  >> i;
	
	if ( i==1 ) EntertrainArc(G);
	if ( i==2 ) DeletetrainArc(G);
}

//���ӷɻ�����
void EnterplaneArc(ALGraph *G)
{
	int i,j,bt[2],at[2];
	int code;
	float money;
	int m,t;
	char vt[10],vh[10],c;
	ArcNode *p,*q;
	cout << endl
		 << "�����������ɻ��������Ϣ:"
		 << endl;
	cout << "�ɻ�������:";
	cin  >> code;
	cout << "��ʼ����:";
	cin  >> vt;
	cout << "Ŀ�ĳ���:";
	cin  >> vh;
	cout << "�������:";
	cin  >> money;
	
	printf( "���ʱ��:" );;
	scanf( "%d:%d", &bt[0], &bt[1] );
	while ( bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60 )
	{
		printf ( "\nʱ��������������������\n" );			 
		scanf( "%d:%d", &bt[0], &bt[1] );		
	}

	printf( "\n����ʱ��:" );
	scanf( "%d:%d", &at[0], &at[1] );		
	while ( at[0]<0||at[0]>=24||at[1]<0||at[1]>=60 )
	{
		printf( "\nʱ��������������������\n" );
		scanf( "%d:%d", &at[0], &at[1] );				
	}

	cout << endl
		 << "ȷ��?(Y/N)";
	cin  >> c;
	if ( c=='Y'||c=='y' )
	{
		i = LocateVertex(G,vt);
		j = LocateVertex(G,vh);
		if ( i==-1 )
		{
			printf( "\n�����޷��ҵ���ʼ����1\n" );				 
			return;
		}
		if ( j==-1 )
		{
			printf( "\n�����޷��ҵ��������!\n" );
			return;
		}
		q = G->vertices[i].planefirstarc;
		m = 0;
		while ( q!=NULL )
		{
			if ( q->adjvex==j )
			{
				t = q->info.last+1;
				q->info.stata[t].number = code;
				q->info.stata[t].expenditure = money;
				q->info.stata[t].begintime[0] = bt[0];
				q->info.stata[t].begintime[1] = bt[1];
				q->info.stata[t].arrivetime[0] = at[0];
				q->info.stata[t].arrivetime[1] = at[1];
				q->info.last = t;
				m = 1;
				break;
			}
			q = q->nextarc;
		}
		if ( m==0 )
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info.stata[0].number = code;
			p->info.stata[0].expenditure = money;
			p->info.stata[0].begintime[0] = bt[0];
			p->info.stata[0].begintime[1] = bt[1];
			p->info.stata[0].arrivetime[0] = at[0];
			p->info.stata[0].arrivetime[1] = at[1];
			p->info.last = 0;
			p->nextarc = G->vertices[i].planefirstarc;
			G->vertices[i].planefirstarc = p;
			G->planearcnum++;
		}
		save(G);
	}
	else return;
}

//�����г�����
void EntertrainArc(ALGraph *G)
{
	int i,j,bt[2],at[2];
	int code;
	float money;
	int m,t;
	char vt[10],vh[10],c;
	ArcNode *p,*q;
	cout << endl
		 << "�����������г����ε���Ϣ:"
		 << endl;
	cout << "�г����α��:";
	cin  >> code;
	cout << "��ʼ����:";
	cin  >> vt;
	cout << "Ŀ�ĳ���:";
	cin  >> vh;
	cout << "���η���:";
	cin  >> money;
	
	printf( "\n����ʱ��:" );
	scanf( "%d:%d", &bt[0], &bt[1] );
	while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
	{
		printf( "\nʱ��������������������\n" );
		scanf( "%d:%d", &bt[0], &bt[1] );	
	}

	printf ( "����ʱ��:" );
	scanf( "%d:%d", &at[0], &at[1] );	
	while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
	{
		printf( "\nʱ��������������������\n" );
		scanf( "%d:%d", &at[0], &at[1] );		
	}
	
	cout << endl
		 <<"ȷ��?(Y/N)";
	cin  >> c;
	if ( c=='Y' || c=='y' )
	{
		i = LocateVertex(G,vt);
		j = LocateVertex(G,vh);
		if ( i==-1 )
		{ 
			printf( "\n�����޷��ҵ���ʼ����!\n" );				 
			return;
		}
		if ( j==-1 )
		{
			printf( "\n�����޷��ҵ��������!\n" );				 
			return;
		}
		q = G->vertices[i].trainfirstarc;
		m = 0;
		while ( q!=NULL )
		{
			if ( q->adjvex==j )
			{
				t = q->info.last+1;
				q->info.stata[t].number = code;
				q->info.stata[t].expenditure = money;
				q->info.stata[t].begintime[0] = bt[0];
				q->info.stata[t].begintime[1] = bt[1];
				q->info.stata[t].arrivetime[0] = at[0];
				q->info.stata[t].arrivetime[1] = at[1];
				q->info.last=t;
				m=1;
				break;
			}
			q = q->nextarc;
		}
		if ( m==0 )
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info.stata[0].number = code;
			p->info.stata[0].expenditure = money;
			p->info.stata[0].begintime[0] = bt[0];
			p->info.stata[0].begintime[1] = bt[1];
			p->info.stata[0].arrivetime[0] = at[0];
			p->info.stata[0].arrivetime[1] = at[1];
			p->info.last = 0;
			p->nextarc = G->vertices[i].trainfirstarc;
			G->vertices[i].trainfirstarc = p;
			G->trainarcnum++;
		}
		save(G);
	}
	else return;
}

//ɾ���ɻ�����
void DeleteplaneArc(ALGraph *G)
{
	int i,j;
	int code;
	char vt[10],vh[10],c;
	int n;
	int k;
	ArcNode *p,*q;
	
	cout << endl
		 << "������ɾ���ɻ��������Ϣ:"
		 << endl;
	cout << "�ɻ�����ı��:";
	cin  >> code;
	cout << "��ʼ����:";
	cin  >> vt;
	cout << "Ŀ�ĳ���:";
	cin  >> vh;
	cout << "ȷ��?(Y/N)";
	cin  >> c;
	if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt);
		j=LocateVertex(G,vh);
		if ( i==-1 )
		{
			printf( "\n�����޷��ҵ���ʼ����!\n" );				 
			return;
		}
		if ( j==-1 )
		{
			printf( "\n�����޷��ҵ�Ŀ�ĳ���!\n" );				 
			return;
		}
		p=G->vertices[i].planefirstarc;
		q=p;
		while(p!=NULL)
		{
			if(p->adjvex==j)
			{
				n=-1;
				for ( k=0;k<=p->info.last;k++ )
				{
					if(p->info.stata[k].number==code)
					{
						n = k;
						break;
					}
				}
				if ( n!=-1 )
				{
					if ( p->info.last==0 )
					{ 
						if ( q==p )
							G->vertices[i].planefirstarc=p->nextarc;
						else
							q->nextarc=p->nextarc;
						free(p);
					}
					else
					{
						for(k=n;k<p->info.last;k++)
						{
							p->info.stata[k].number=p->info.stata[k+1].number;
							p->info.stata[k].expenditure=p->info.stata[k+1].expenditure;
							p->info.stata[k].begintime[0]=p->info.stata[k+1].begintime[0];
							p->info.stata[k].begintime[1]=p->info.stata[k+1].begintime[1];
							p->info.stata[k].arrivetime[0]=p->info.stata[k+1].arrivetime[0];
							p->info.stata[k].arrivetime[1]=p->info.stata[k+1].arrivetime[1];
						}
						p->info.last=p->info.last-1;
					}
				}
				else printf( "\n�ڴ�������֮���޷��ҵ�No.%d�ɻ�����!\n", code );
				save(G);
				return;
			}
			q = p;
			p = p->nextarc;
		}
		if ( p==NULL) printf( "\n�ڴ�������֮���޷ɻ��������!\n" );						   
	}
	else return;
}

//ɾ���г�����
void DeletetrainArc(ALGraph *G)
{
	int i,j;
	int code;
	char vt[10],vh[10],c;
	int n;
	int k;
	ArcNode *p,*q;
	cout << endl 
		 << "������ɾ���г����ε���Ϣ:"
		 << endl;
	cout << "�г����εı��:";
	cin >> code;
	cout << "��ʼ����:";
	cin  >> vt;
	cout << "Ŀ�ĳ���:";
	cin  >> vh;
	cout << "ȷ��?(Y/N)";
	
	cin >> c;
	if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt);
		j=LocateVertex(G,vh);
		if ( i==-1 )
		{ 
			printf( "\n�����޷��ҵ���ʼ����!\n" );				 
			return;
		}
		if ( j==-1 )
		{
			printf( "\n�����޷��ҵ�Ŀ�ĳ���!\n" );				 
			return;
		}
		p = G->vertices[i].trainfirstarc;
		q = p;
		while ( p!=NULL )
		{
			if ( p->adjvex==j )
			{
				n = -1;
				for ( k=0;k<=p->info.last;k++ )
				{
					if ( p->info.stata[k].number==code )
					{
						n = k;
						break;
					}
				}
				if ( n!=-1 )
				{
					if ( p->info.last==0 )
					{
						if ( q==p )
							G->vertices[i].trainfirstarc=p->nextarc;
						else
							q->nextarc=p->nextarc;
						free(p);
					}
					else
					{
						for(k=n;k<p->info.last;k++)
						{
							p->info.stata[k].number=p->info.stata[k+1].number;
							p->info.stata[k].expenditure=p->info.stata[k+1].expenditure;
							p->info.stata[k].begintime[0]=p->info.stata[k+1].begintime[0];
							p->info.stata[k].begintime[1]=p->info.stata[k+1].begintime[1];
							p->info.stata[k].arrivetime[0]=p->info.stata[k+1].arrivetime[0];
							p->info.stata[k].arrivetime[1]=p->info.stata[k+1].arrivetime[1];
						}
						p->info.last=p->info.last-1;
					}
				}
				else printf( "\n�ڴ�������֮���޷��ҵ� No.%d �г�����!\n",code );
				save(G);
				return;
			}
			q = p;
			p = p->nextarc;
		}
		if ( p==NULL ) printf( "\n�ڴ�������֮�����г����δ���!\n" );							
	}	
	else return;
}

//�û���ѯ��Ŀѡ�����
void UserDemand(ALGraph G)
{
	int i;
	cout << endl 
		 << "��ѡ����ѯ��Ŀ:"
		 << endl;
	cout << "1=�������з���"		<< endl
		 << "2=��������ʱ��"		<< endl
		 << "3=����������ת����"	<< endl
		 << "4=������һ���˵�"		<< endl;
	cout << "ѡ��?";
	cin  >> i;
	
	while(i!=4)
	{
		switch(i)
		{
			case 1: DemandDispose(1,G);	break;
			case 2: DemandDispose(2,G);	break;
			case 3: DemandDispose(3,G);	break;
		}
		
		cout << "��ѡ����ѯ��Ŀ:"		<< endl;
		cout << "1=�������з���"		<< endl
			 << "2=��������ʱ��"		<< endl
			 << "3=����������ת����"	<< endl
			 << "4=������һ���˵�"		<< endl;
		cout << "ѡ��?";
		cin  >> i;		
	}
}

//�û���ѯѡ����Ϣ�������
void DemandDispose(int n,ALGraph G)
{
	char q;
	ArcNode *plane,*train;
	infolist planearcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM],trainarcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int i,j,k,final[MAX_VERTEX_NUM],T[MAX_VERTEX_NUM][2];
	float M[MAX_VERTEX_NUM];
	
	for ( i=0; i<G.vexnum; i++ )
		for ( j=0; j<G.vexnum; j++ )
			for ( k=0; k<MAX_ROUTE_NUM; k++ )
			{
				planearcs[i][j].stata[k].expenditure = INFINITY;
				planearcs[i][j].stata[k].begintime[0] = 0;
				planearcs[i][j].stata[k].begintime[1] = 0;
				planearcs[i][j].stata[k].arrivetime[0] = INFINITY;
				planearcs[i][j].stata[k].arrivetime[1] = INFINITY;
				planearcs[i][j].last = -1;
				trainarcs[i][j].stata[k].expenditure = INFINITY;
				trainarcs[i][j].stata[k].begintime[0] = 0;
				trainarcs[i][j].stata[k].begintime[1] = 0;
				trainarcs[i][j].stata[k].arrivetime[0] = INFINITY;
				trainarcs[i][j].stata[k].arrivetime[1] = INFINITY;
				trainarcs[i][j].last=-1;
			}
	for ( i=0; i<G.vexnum; i++ )
	{
		plane = G.vertices[i].planefirstarc;
		train = G.vertices[i].trainfirstarc;
		while ( plane!=NULL )
		{
			planearcs[i][plane->adjvex] = plane->info;
			plane = plane->nextarc;
		}
		while ( train!=NULL )
		{
			trainarcs[i][train->adjvex] = train->info;
			train = train->nextarc;
		}
	}
	
ll:	cout << endl << "��ѡ��������ʼ����:" << endl;
	for ( k=0;k<G.vexnum; k++ ) printf("%d=%s\n",k,G.vertices[k].cityname);
	cout << "ѡ��?";
	cin  >> i;
	cout << endl  << "��ѡ�����е������:" << endl;
	for ( k=0; k<G.vexnum; k++ ) printf("%d=%s\n",k,G.vertices[k].cityname);
	cout << "ѡ��?";
	cin  >> j;
	cout << endl
		 << "��ѡ��ͨ����:"
		 << endl;
	cout << "1=�г�" << endl 
		 << "2=�ɻ�" << endl;
	cout << "ѡ��?";
	cin  >> k;
	cout << "ȷ��? (Y/N)";
	
	cin  >> q;
	if ( q=='Y' || q=='y' )
	{
		if( k==1&&n==1 )
			ExpenditureDispose(1,trainarcs,G,i,j,M,final);
		else if ( k==1&&n==2 )
			TimeDispose(1,trainarcs,G,i,j,T,final);
		else if ( k==1&&n==3 )
			TransferDispose(1,trainarcs,G,i,j);
		else if( k==2&&n==1 )
			ExpenditureDispose(2,planearcs,G,i,j,M,final);
		else if ( k==2&&n==2 )
			TimeDispose(2,planearcs,G,i,j,T,final);
		else if ( k==2&&n==3 )
			TransferDispose(2,planearcs,G,i,j);
	}
	else if ( q=='N'||q=='n' ) goto ll;		
	else 
	{
		printf( "\nѡ�����\n\n" );
		return;
	}
}

//��ʼ������
void InitQueue(LinkQueue *Q)
{
	Q->front = (QNode *)malloc(sizeof(QNode));
	Q->rear = Q->front;
	Q->front->next = NULL;
}

//��Ӳ���
void EnterQueue(LinkQueue *Q,int x)
{
	QNode *newnode;
	newnode = (QNode *)malloc(sizeof(QNode));
	newnode->adjvex = x;
	newnode->next = NULL;
	Q->rear->next = newnode;
	Q->rear = newnode;
}

//���Ӳ���
void DeleteQueue( LinkQueue *Q, int *x )
{
	QNode *p;
	p = Q->front->next;
	Q->front->next = p->next;
	if ( Q->rear==p ) Q->rear = Q->front;
	*x = p->adjvex;
	free( p );
}

//�����пղ���
int IsEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear) return(1); else return(0);
}

//����������ת��������
void TransferDispose( int k, infolist (*arcs)[MAX_VERTEX_NUM], ALGraph G, int v0, int v1 )
{
	int visited[MAX_VERTEX_NUM],v,w,n=1;
	LinkQueue Q;
	ArcNode *t;
	Node *p,*q,*r,*s;
	p = (Node *)malloc(G.vexnum * sizeof(Node));
	for ( v=0; v<G.vexnum; v++ )
	{
		visited[v] = 0;
		p[v].next = NULL;
	}
	InitQueue(&Q);
	visited[v0] = 1;
	q = (Node *)malloc(sizeof(Node));
	q->adjvex = v0;
	q->next = NULL;
	p[v0].next = q;
	EnterQueue(&Q,v0);
	while ( !IsEmpty(&Q) )
	{
		DeleteQueue(&Q,&v);
		if ( k==1 )
			t = G.vertices[v].trainfirstarc;
		else
			t = G.vertices[v].planefirstarc;
		while ( t!=NULL )
		{
			w = t->adjvex;
			if ( !visited[w] )
			{
				visited[w] = 1;
				q = &p[w];
				s = p[v].next;
				while ( s!=NULL )
				{
					r = (Node *)malloc(sizeof(Node));
					r->adjvex = s->adjvex;
					q->next = r;
					q = r;
					s = s->next;
				}
				r = (Node *)malloc(sizeof(Node));
				r->adjvex = w;
				r->next = NULL;
				q->next = r;
				if ( w==v1 )
				{
					q = p[w].next;
					r = q->next;
					
					printf( "\n����·����:\n" );
					while ( r!=NULL )
					{
						if ( k==1 )
							cout << "����No."
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number
								 << "�г�������"
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0]
								 << ":"
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1]
								 <<	"��"
								 <<	G.vertices[q->adjvex].cityname
								 << "��"
								 <<	G.vertices[r->adjvex].cityname
								 <<	endl;								 
						else
							cout << "����No."
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number
								 << "�ɻ�������"
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0]
								 << ":"
								 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1]
								 << "��" 
								 << G.vertices[q->adjvex].cityname
								 << "��"
								 << G.vertices[r->adjvex].cityname
								 << endl;								 
						q = r;
						r = r->next;
						n ++;
					}
					
					printf( "������ת������ %s ��\n", n-2 );						 
					for ( v = 0; v < G.vexnum; v ++ )
					{
						q = p[v].next;
						while ( q!=NULL )
						{
							s = q;
							q = q->next;
							free(s);
						}
						p[v].next = NULL;
					}
					free(p);
					return;	
				}
				EnterQueue(&Q,w);
			}
			t = t->nextarc;
		}
	}
	for ( v=0; v<G.vexnum; v++ )
	{
		q=p[v].next;
		while(q!=NULL)
		{
			s = q;
			q = q->next;
			free(s);
		}
		p[v].next = NULL;
	}
	free(p);
	if ( k==1 )
		printf( "\n�������г�����: �� %s �� %s!\n", G.vertices[v0].cityname, G.vertices[v1].cityname );		
	else
		printf( "\n�����ڷɻ�����: �� %s �� %s!\n", G.vertices[v0].cityname, G.vertices[v1].cityname );				
}


//��ֱ�����֮���������з��ú���Ӧ·��	
void MinExpenditure( infolist arcs, float *expenditure, int *route )
{
	int i;
	*expenditure = arcs.stata[0].expenditure;
	if ( *expenditure<INFINITY ) *route = 0; else *route = -1;
	for ( i=1;i<=arcs.last;i++ )
		if( arcs.stata[i].expenditure<*expenditure )
		{
			*expenditure=arcs.stata[i].expenditure;
			*route=i;
		}
}


//�������з��ô���	
void ExpenditureDispose( int k, infolist (*arcs)[MAX_VERTEX_NUM], ALGraph G, int v0, int v1, float *M, int *final )
{
	int v=-1,w,i,route;
	float m,expenditure;
	Node *p,*q,*r,*s;
	p=(Node *)malloc(G.vexnum*sizeof(Node));
	for ( v=0; v<G.vexnum; v++ )
	{
		*(final+v) = False;
		MinExpenditure( *(*(arcs+v0)+v), M+v, &route );
		p[v].next = NULL;
		if ( *(M+v)<INFINITY )
		{
			q = (Node *)malloc(sizeof(Node));
			s = (Node *)malloc(sizeof(Node));
			q->adjvex = v0;
			s->adjvex = v;
			s->route = route;
			p[v].next = q;
			q->next = s;
			s->next = NULL;
		}
	}
	*(M+v0) = 0;
	*(final+v0) = True;
	for ( i=1; i<G.vexnum; i++ )
	{
		m = INFINITY;
		v = -1;
		for ( w=0; w<G.vexnum; w++ )
			if ( *(final+w)==False )
				if ( *(M+w)<m )
				{
					v = w;
					m = *(M+w);
				}
		if ( v==v1 )
		{
			q = p[v].next;
			r = q->next;
			printf( "\n����·����:\n" ); 				 
			while ( r!=NULL )
			{
				if ( k==1 )					
					cout << "����No."
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number
						 << "�г�������"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0]
						 << ":"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1]
						 << "��"
						 << G.vertices[q->adjvex].cityname 
						 << "��"
						 << G.vertices[r->adjvex].cityname
						 << endl;
				else					
					cout << "����No."
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number
						 << "�ɻ�������"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0]
						 << ":"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1]
						 << "��"
						 << G.vertices[q->adjvex].cityname
						 << "��"
						 << G.vertices[r->adjvex].cityname
						 << endl;
				q = r;
				r=r->next;
			}
			
			printf( "�������з�����%dԪ!\n\n", m );
			for(v=0;v<G.vexnum;v++)
			{
				q=p[v].next;
				while(q!=NULL)
				{
					s=q;
					q=q->next;
					free(s);
				}
				p[v].next=NULL;
			}
			free(p);
			return;
		}
		else if(v!=-1)
		{
			*(final+v)=True;
			for(w=0;w<G.vexnum;w++)
				if(*(final+w)==False&&(*(*(arcs+v)+w)).last>-1)
				{
					MinExpenditure(*(*(arcs+v)+w),&expenditure,&route);
					if(*(M+w)>m+expenditure)
					{
						*(M+w)=m+expenditure;
						q=p[w].next;
						while(q!=NULL)
						{
							s=q;
							q=q->next;
							free(s);
						}
						q=&p[w];
						s=p[v].next;
						while(s!=NULL)
						{
							r=(Node *)malloc(sizeof(Node));
							r->adjvex=s->adjvex;
							r->route=s->route;
							q->next=r;
							q=r;
							s=s->next;
						}
						r=(Node *)malloc(sizeof(Node));
						r->adjvex=w;
						r->route=route;
						r->next=NULL;
						q->next=r;
					}
				}
		}
	}
	for(v=0;v<G.vexnum;v++)
	{
		q=p[v].next;
		while(q!=NULL)
		{
			s=q;
			q=q->next;
			free(s);
		}
		p[v].next=NULL;
	}
	free(p);
	if ( k==1 )
		printf( "\n�������г�����: �� %s �� %s!\n", G.vertices[v0].cityname, G.vertices[v1].cityname );
	else
		printf( "\n�����ڷɻ�����: �� %s �� %s!\n", G.vertices[v0].cityname, G.vertices[v1].cityname );		
}


//��ֱ�����֮����������ʱ�����Ӧ·��,ֻ�����ʱ�䴦���Ǹ������е��ù�
void MinTime(infolist arcs,int *time,int *route)
{
	int i,t[2];
	time[0]=arcs.stata[0].arrivetime[0]-arcs.stata[0].begintime[0];
	time[1]=arcs.stata[0].arrivetime[1]-arcs.stata[0].begintime[1];
	if ( time[0]<0 ) time[0]=time[0]+24;//����Ԥ����
	if(time[1]<0) { time[0]--; time[1]=time[1]+60; }//ʱ��Ԥ����
	*route=0;
	for ( i=1; i<=arcs.last; i++ )//�����Ա�����ö�ٰ���
	{
		t[0] = arcs.stata[i].arrivetime[0]-arcs.stata[i].begintime[0];  
		t[1] = arcs.stata[i].arrivetime[1]-arcs.stata[i].begintime[1];	 
		if ( t[0]<0 ) t[0]=t[0]+24;
		if ( t[1]<0 ) { t[0]--; t[1]=t[1]+60; }
		if ( t[0]<time[0]||(t[0]==time[0]&&t[1]<time[1]))
		{
			time[0]=t[0]; time[1]=t[1]; *route=i;
		}
	}
}

//ʱ��������
void TimeTreeDispose( Node *head, infolist (*arcs)[MAX_VERTEX_NUM] )
{
	int n,i,j;
	Node *p;
	LinkQueue Q;
	TimeTree root;
	root = (TimeNode *)malloc(sizeof(TimeNode));
	InitQueue(&Q);
	TTime[0] = INFINITY;
	TTime[1] = INFINITY;
	p = head->next;
	while ( p!=NULL )
	{
		EnterQueue( &Q, p->adjvex );
		p = p->next;
	}
	DeleteQueue(&Q,&i);
	root->adjvex = i;
	DeleteQueue(&Q,&j);
	CreateTimeTree(root,i,j,&Q,arcs); 
	for ( n=0; n<=(*(*(arcs+i)+j)).last; n++ )
	{
		time1[0] = 0;
		time1[1] = 0;
		time2[0] = root->child[n]->begintime[0];
		time2[1] = root->child[n]->begintime[1];
		time[0] = INFINITY;
		time[1] = INFINITY;
		VisitTimeTree(root->child[n]);
		if ( time[0]<TTime[0]||(time[0]==TTime[0]&&time[1]<TTime[1]) )
		{
			TTime[0] = time[0];
			TTime[1] = time[1];
			p = head->next;
			while( p!=NULL )
			{
				p->route = d[p->adjvex];
				p = p->next;
			}
		}
	}
	DestoryTimeTree( root );
}

//����ʱ��������������ȫ����Ψһ�õ����ĵط�
void CreateTimeTree( TimeTree p, int i, int j, LinkQueue *Q, infolist (*arcs)[MAX_VERTEX_NUM] )
{
	int n,x,y;
	TimeTree q;
	q = (TimeNode *)malloc(sizeof(TimeNode));
	q->adjvex = j;
	q->begintime[0] = (*(*(arcs+i)+j)).stata[0].begintime[0];
	q->begintime[1] = (*(*(arcs+i)+j)).stata[0].begintime[1];
	q->arrivetime[0] = (*(*(arcs+i)+j)).stata[0].arrivetime[0];
	q->arrivetime[1] = (*(*(arcs+i)+j)).stata[0].arrivetime[1];
	q->route = 0;
	p->child[0] = q;
	for ( n=1; n<=(*(*(arcs+i)+j)).last; n++ )
	{
		q = (TimeNode *)malloc(sizeof(TimeNode));
		q->adjvex = j;
		q->begintime[0] = (*(*(arcs+i)+j)).stata[n].begintime[0];
		q->begintime[1] = (*(*(arcs+i)+j)).stata[n].begintime[1];
		q->arrivetime[0] = (*(*(arcs+i)+j)).stata[n].arrivetime[0];
		q->arrivetime[1] = (*(*(arcs+i)+j)).stata[n].arrivetime[1];
		q->route = n;
		p->child[n] = q;
	}
	while ( n < MAX_ROUTE_NUM )
	{
		p->child[n] = NULL;
		n ++;
	}
	x = j;
	if ( !IsEmpty(Q) )
	{
		DeleteQueue(Q,&y);
		CreateTimeTree(p->child[0],x,y,Q,arcs);
		for ( n=1;n<=(*(*(arcs+i)+j)).last;n++ )
			CopyTimeTree( p->child[n], p->child[0] );
	}
	else
	{
		for ( n=0; n<MAX_ROUTE_NUM; n++ ) 
			p->child[0]->child[n]=NULL;
		for ( n=1; n<=(*(*(arcs+i)+j)).last; n++ )
			CopyTimeTree( p->child[n], p->child[0] );
	}
}

//����ʱ����
void CopyTimeTree( TimeTree p, TimeTree q )
{
	TimeTree r;
	int n=0;
	while ( q->child[n]!=NULL )
	{
		r = (TimeNode *)malloc(sizeof(TimeNode));
		r->adjvex=q->child[n]->adjvex;
		r->begintime[0] = q->child[n]->begintime[0];
		r->begintime[1] = q->child[n]->begintime[1];
		r->arrivetime[0] = q->child[n]->arrivetime[0];
		r->arrivetime[1] = q->child[n]->arrivetime[1];
		r->route = q->child[n]->route;
		p->child[n] = r;
		CopyTimeTree( p->child[n], q->child[n] );
		n++;
	}
	while ( n<MAX_ROUTE_NUM ) 
	{
		p->child[n]=NULL;
		n++;
	}
}

//����ʱ��������
void VisitTimeTree( TimeTree p )
{
	int n,x[2],y[2];
	
	x[0] = time1[0]; x[1] = time1[1]; y[0] = time2[0]; y[1] = time2[1];

	if ( p->begintime[0]>time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]>=time2[1]) )
	{
		time1[0] = time1[0]+p->begintime[0]-time2[0];
		time1[1] = time1[1]+p->begintime[1]-time2[1];
		if(time1[1]<0)
		{
			time1[1] = time1[1]+60;
			time1[0]--;
		}
		if ( time1[1]>=60 )
		{
			time1[1] = time1[1]-60;
			time1[0]++;
		}
	}
	else if ( p->begintime[0]<time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]<time2[1]) )
	{
		time1[0] = time1[0]+p->begintime[0]-time2[0]+24;
		time1[1] = time1[1]+p->begintime[1]-time2[1];
		if ( time1[1]<0 )
		{
			time1[1] = time1[1]+60;
			time1[0]--;
		}
		if ( time1[1]>=60 )
		{
			time1[1] = time1[1]-60;
			time1[0]++;
		}
	}
	if ( p->arrivetime[0]>p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]>=p->begintime[1]) )
	{
		time1[0] = time1[0]+p->arrivetime[0]-p->begintime[0];
		time1[1] = time1[1]+p->arrivetime[1]-p->begintime[1];
		if ( time1[1]<0 )
		{
			time1[1] = time1[1]+60;
			time1[0]--;
		}
		if ( time1[1]>=60 )
		{
			time1[1] = time1[1]-60;
			time1[0]++;
		}
	}
	else if ( p->arrivetime[0]<p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]<p->begintime[1]) )
	{
		time1[0] = time1[0]+p->arrivetime[0]-p->begintime[0]+24;
		time1[1] = time1[1]+p->arrivetime[1]-p->begintime[1];
		if( time1[1]<0 )
		{
			time1[1] = time1[1]+60;
			time1[0]--;
		}
		if ( time1[1]>=60 )
		{
			time1[1] = time1[1]-60;
			time1[0]++;
		}
	}
	time2[0] = p->arrivetime[0];
	time2[1] = p->arrivetime[1];
	c[p->adjvex] = p->route;
	if( p->child[0]==NULL )
	{
		if( time1[0]<time[0]||(time1[0]==time[0]&&time1[1]<time[1]) )
		{
			time[0] = time1[0];
			time[1] = time1[1];
			for ( n=0;n<MAX_VERTEX_NUM;n++ ) 
				d[n] = c[n];
		}
	}
	else
	{
		n = 0;
		while ( p->child[n]!=NULL )
		{
			VisitTimeTree( p->child[n] );
			n++;
		}
	}
	
	time1[0] = x[0];  time1[1] = x[1];  time2[0] = y[0];  time2[1] = y[1];
}

//����ʱ����
void DestoryTimeTree( TimeTree p )
{
	if ( p!=NULL )
	{
		DestoryTimeTree( p->child[0] );
		DestoryTimeTree( p->child[1] );
		DestoryTimeTree( p->child[2] );
		DestoryTimeTree( p->child[3] );
		DestoryTimeTree( p->child[4] );
		p->child[0] = NULL; 
		p->child[1] = NULL;
		p->child[2] = NULL;
		p->child[3] = NULL;
		p->child[4] = NULL;
		free( p );
	}
}

//��������ʱ�䴦��
void TimeDispose( int k, infolist (*arcs)[MAX_VERTEX_NUM], ALGraph G, int v0, int v1, int (*T)[2], int *final )
{
	int v,w,i,route,m[2];
	Node *p,*q,*r,*s,*t;
	p = (Node *)malloc (G.vexnum*sizeof(Node));
	for ( v=0; v<G.vexnum; v++ )
	{
		*(final+v) = False;
		MinTime( *(*(arcs+v0)+v),*(T+v), &route );//���������road��ָ����̵Ľڵ�ĵط�
		p[v].next=NULL;
		if ( *(*(T+v)+0)<INFINITY&&*(*(T+v)+1)<INFINITY )
		{
			q = (Node *)malloc(sizeof(Node));
			s = (Node *)malloc(sizeof(Node));
			q->adjvex = v0;
			s->adjvex = v;
			s->route = route;
			p[v].next = q;
			q->next = s;
			s->next = NULL;
		}
	}
	*(*(T+v0)+0) = 0;
	*(*(T+v0)+1) = 0;
	*(final+v0) = True;
	for ( i=1; i<G.vexnum; i++ )
	{
		m[0] = INFINITY;
		m[1] = INFINITY;
		v = -1;
		for ( w=0; w<G.vexnum; w++ )
			if ( *(final+w)==False )
				if ( *(*(T+w)+0)<m[0] || (*(*(T+w)+0)==m[0]&&*(*(T+w)+1)<m[1]) )
				{ 
					v = w;
					m[0] = *(*(T+w)+0);
					m[1] = *(*(T+w)+1);
				}
		if ( v==v1 )
		{
			q = p[v].next;
			r = q->next;
			cout << endl 
				 << "����·����:"
				 << endl;
			while ( r!=NULL )
			{
				if ( k==1 )
					cout << "����No."
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number
						 << "�г�������"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0]
						 << ":"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1]
						 << "��"
						 << G.vertices[q->adjvex].cityname
						 << "��"
						 << G.vertices[r->adjvex].cityname
						 << endl;
				else					
					cout << "����No."
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number
						 << "�ɻ�������"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0]
						 << ":"
						 << (*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1]
						 << "��"
						 << G.vertices[q->adjvex].cityname
						 << "��"
						 << G.vertices[r->adjvex].cityname
						 << endl;
				q = r;
				r = r->next;
			}
			cout << "��������ʱ����"
				 << m[0] 
				 << ":" 
				 << m[1] 
				 << endl << endl;
			for ( v=0; v<G.vexnum; v++ )
			{
				q = p[v].next;
				while ( q!=NULL )
				{ 
					s = q;
					q = q->next;
					free(s);
				}
				p[v].next = NULL;
			}
			free(p);
			return;
		}
		else if ( v!=-1 )
		{
			*(final+v)=True;
			for ( w=0;w<G.vexnum;w++)
				if ( *(final+w)==False && (*(*(arcs+v)+w)).last>-1 )
				{
					t = p[w].next;
					q = &p[w];
					s = p[v].next;
					while ( s!=NULL )
					{
						r = (Node *)malloc(sizeof(Node));
						r->adjvex = s->adjvex;
						r->route = s->route;
						q->next = r;
						q = r;
						s = s->next;
					}
					r = (Node *)malloc(sizeof(Node));
					r->adjvex = w;
					r->route = route;
					r->next = NULL;
					q->next = r;
					TimeTreeDispose(&p[w],arcs);
					if ( *(*(T+w)+0)>TTime[0]||(*(*(T+w)+0)==TTime[0]&&*(*(T+w)+1)>TTime[1]) )
					{
						*(*(T+w)+0) = TTime[0];
						*(*(T+w)+1) = TTime[1];
						while ( t!=NULL )
						{
							q = t;
							t = t->next;
							free(q);
						}
					}
					else 
					{
						q = p[w].next;
						while ( q!=NULL )
						{
							r = q;
							q=q->next;
							free(r);
						}
						p[w].next = t;
					}
				}
		}
	}
	for ( v=0; v<G.vexnum; v++ )
	{
		q = p[v].next;
		while ( q!=NULL )
		{
			s = q;
			q = q->next;
			free(s);
		}
		p[v].next = NULL;
	}
	free(p);

	if ( k==1 )
		printf( "\n�������г�����: ��%s��%s\n", G.vertices[v0].cityname, G.vertices[v1].cityname );		
	else
		printf( "\n�����ڷɻ�����: ��%s��%s\n", G.vertices[v0].cityname, G.vertices[v1].cityname );				
}

//��ʾ���н�ͨϵͳ
void PrintGraph(ALGraph *G)
{
	int i,j,k;
	ArcNode *q;

	cout << endl
		 << "��ѡ����ʾ��Ŀ:"
		 << endl;
	cout << "0=��ʾ����"		<< endl
		 << "1=��ʾ�ɻ�����"	<< endl
		 << "2=��ʾ�г�����"	<< endl
		 << "3=������һ���˵�"	<< endl;
	cout <<"ѡ��?";
	cin  >> i;
	
	while(i!=3)
	{
		switch(i)
		{
			case 0: cout << endl << "����:" << endl;
					for (j=0;j<G->vexnum;j++)
						cout << G->vertices[j].cityname << "  ";
					cout << endl;
					break;
			case 1: cout << endl << "�ɻ�����:" << endl;
					for (j=0;j<G->vexnum;j++)
					{
						q=G->vertices[j].planefirstarc;
						while(q!=NULL)	
						{
							cout << G->vertices[j].cityname
								 << "---->"
								 << G->vertices[q->adjvex].cityname
								 << endl;
							for (k=0;k <= q -> info.last; k ++ )
								cout << "    number: "
									 << q->info.stata[k].number
									 << "  expenditure: "
									 << q->info.stata[k].expenditure
									 << "  begintime: "
									 << q->info.stata[k].begintime[0]
									 << ":"
									 << q->info.stata[k].begintime[1]
									 << "  arrivetime: "
									 << q->info.stata[k].arrivetime[0]
									 << ":"
									 << q->info.stata[k].arrivetime[1]
									 << endl;
							q=q->nextarc;
						}
					}
					break;
			case 2: cout << endl << "�г�����:" << endl;
					for ( j=0; j<G->vexnum; j++ )
					{
						q=G->vertices[j].trainfirstarc;
						while(q!=NULL)
						{
							cout << G->vertices[j].cityname
								 << "---->"
								 << G->vertices[q->adjvex].cityname
								 << endl;
							for (k=0;k<=q->info.last;k++)
								cout << "    number:"
									 << q->info.stata[k].number
									 << "  expenditure:"
									 << q->info.stata[k].expenditure
									 << "  begintime:"
									 << q->info.stata[k].begintime[0]
									 << ":"
									 << q->info.stata[k].begintime[1]
									 << "  arrivetime:"
									 << q->info.stata[k].arrivetime[0]
									 << ":"
									 << q->info.stata[k].arrivetime[0]
									 << endl;
							q=q->nextarc;
						}
					}
					break;
		}
		cout << endl 
			 << "��ѡ����ʾ��Ŀ:" 
			 << endl;
		cout << "0=��ʾ����"		<< endl
			 << "1=��ʾ�ɻ�����"	<< endl
			 << "2=��ʾ�г�����"	<< endl
			 << "3=������һ���˵�"  << endl;
		cout << "ѡ��?";
		cin  >> i;		
	}
}
