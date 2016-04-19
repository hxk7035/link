// main.cpp : 定义控制台应用程序的入口点。
//



#include<stdio.h>
#include<stdlib.h>

#define Max 10
struct List
{
	int Number;
	char Name[Max];
	struct List *Next;
};
typedef struct List Node;
typedef Node *Link;

void Free_List(Link Head)
{
	Link Pointer;
	while(Head!=NULL)
	{
		Pointer =Head;
		Head=Head->Next;
		free(Pointer);
	}
}

void Print_List(Link Head)
{
	Link Pointer;
	Pointer =Head;
	while(Pointer!=NULL)
	{
		printf("##input data##\n");
		printf("data number:%d\n",Pointer->Number);
		printf("data name:%s\n",Pointer->Name);
		Pointer=Pointer->Next;
	}
}

Link Create_List(Link Head)
{
	int datanum;
	char dataname[Max];
	Link New;
	Link Pointer;
	int i;

	Head=(Link)malloc(sizeof(Node));

	if(Head==NULL)
		printf("Memory allocate Failure!!\n");
	else
	{
		datanum=1;
		printf("please input the data name:");
		scanf_s("%s",dataname,Max);
		Head->Number=datanum;

		for(i=0;i<=Max;i++)
			Head->Name[i]=dataname[i];
		Head->Next=NULL;
		Pointer=Head;

		while(1){
			datanum++;
			New=(Link)malloc(sizeof(Node));
			printf("please input the data name:");
			scanf_s("%s",dataname,Max);
			if(dataname[0]=='0')
				break;
			New->Number=datanum;
			for(i=0;i<=Max;i++)
			{
				New->Name[i]=dataname[i];
			}
			New->Next=NULL;

			Pointer->Next=New;
			Pointer=New;
		}
	}
	return Head;
}



	void main()
	{
		Link Head=NULL;
		Head=Create_List(Head);
		
		if(Head!=NULL)
		{
			Print_List(Head);
			Free_List(Head);
		}
		getchar();
	}
