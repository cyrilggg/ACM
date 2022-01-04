
#ifndef JT_H
#define JT_H

#define False			0
#define True			1
#define INFINITY		10000

#define MAX_VERTEX_NUM	30
#define NULL			0
#define MAX_ARC_SIZE	200
#define MAX_ROUTE_NUM	10

//交通工具信息
typedef struct
{
	int number;
	float expenditure;
	int begintime[2];
	int arrivetime[2];
} Vehide;

//线性表里面嵌套着交通工具结构体
typedef struct
{
	Vehide stata[MAX_ROUTE_NUM];
	int last;
} infolist;

//图节点
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	infolist info;
} ArcNode;

//邻接表
typedef struct VNode {
	char cityname[10];//存了城市
	ArcNode  *planefirstarc, *trainfirstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

//用邻接表表示的图，其中adjlist是数组
typedef struct {
	AdjList vertices;
	int  vexnum, planearcnum, trainarcnum;
} ALGraph;

//存路线的图的点
typedef struct Node
{
	int adjvex;
	int route;
	struct Node *next;
} Node;

//队列节点
typedef struct QNode
{
	int adjvex;
	struct QNode *next;
} QNode;

//队列
typedef struct
{
	QNode *front;
	QNode *rear;
} LinkQueue;

//时间树，有边有路线
typedef struct TimeNode
{
	int  adjvex;
	int  route;
	int  begintime[2];
	int  arrivetime[2];
	struct TimeNode *child[MAX_ROUTE_NUM];
} TimeNode, *TimeTree;

///用来存储时间地点的数组
struct arc
{
	int   co;//列车编号
	char  vt[10];//起始城市
	char  vh[10];//终止城市
	
	int   bt[2];//发车时间
	int   at[2];//到达时间
	float mo;//费用
} a[MAX_ARC_SIZE];

void InitQueue(LinkQueue *Q);
void EnterQueue(LinkQueue *Q,int x);
void DeleteQueue(LinkQueue *Q,int *x);
int  IsEmpty(LinkQueue *Q);

void createcityfile();
void createplanefile();
void createtrainfile();

void CreateTimeTree(TimeTree p,int i,int j,LinkQueue *Q,infolist (*arcs)[MAX_VERTEX_NUM]);
void CopyTimeTree(TimeTree p,TimeTree q);
void VisitTimeTree(TimeTree p);
void DestoryTimeTree(TimeTree p);

void MinExpenditure(infolist arcs,float *expenditure,int *route);
void MinTime(infolist arcs,int *time,int *route);
void TimeTreeDispose(Node *head, infolist (*arcs)[MAX_VERTEX_NUM]);

void Administer(ALGraph *G);
void initgraph(ALGraph *G);
int  LocateVertex(ALGraph *G,char *v);
void CreateGraph(ALGraph *G);
void save(ALGraph *G);
void cityedit(ALGraph *G);
void EnterVertex(ALGraph *G);
void DeleteVertex(ALGraph *G);
void flightedit(ALGraph *G);
void trainedit(ALGraph *G);
void EnterplaneArc(ALGraph *G);
void EntertrainArc(ALGraph *G);
void DeleteplaneArc(ALGraph *G);
void DeletetrainArc(ALGraph *G);
void UserDemand(ALGraph G);
void DemandDispose(int n,ALGraph G);
void TransferDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1);
void ExpenditureDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,float *M,int *final);
void TimeDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,int (*T)[2],int *final);
void PrintGraph(ALGraph *G);

#endif