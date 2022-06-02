#include "list.h"

int main(void)
{
	List l = CreateList();
	while (1) {
		system("cls");
		printf("1.AddToStart\n\
2.RemoveByValue\n\
3.TotalValues\n\
4.InsertAfterValue\n\
5.GetIndex\n\
6.PrintAllValues\n\
7.DeleteAllValues\n\
8.Append\n\
9.Reverse\n\
10.Sort\n\
11.Josephus Problem\n");

		int choice;
		scanf("%d", &choice);
		int v;
		switch (choice) {
		case 1:
			printf("Please input the value:");
			scanf("%d", &v);
			AddToStart(&l, v);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 2:
			printf("Please input the value:");
			scanf("%d", &v);
			RemoveByValue(&l, v);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 3:
			printf("The total value is %d\n", TotalValues(&l));
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 4:
			printf("Please input the value:");
			scanf("%d", &v);
			InsertAfterValue(&l, v);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 5:
			printf("Please input the value:");
			scanf("%d", &v);
			printf("The index is %d\n", GetIndex(&l, v));
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 6:
			PrintAllValues(&l);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;

		case 7:
			DeleteAllValues(&l);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 8:
			printf("Please input the value:");
			scanf("%d", &v);
			ListAppend(&l, v);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 9:
			Reverse(&l);
			PrintAllValues(&l);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 10:
			Sort(&l);
			PrintAllValues(&l);
			printf("Press Enter to continue...");
			getchar();
			getchar();
			break;
		case 11:
			printf("输入圆桌上的人数n:");
			int n;
			scanf("%d", &n);
			Node* head = initLink(n);
			printf("从第k人开始报数(k>1且k<%d)：", n);
			int k;
			scanf("%d", &k);
			printf("数到m的人出列：");
			int m;
			scanf("%d", &m);
			findAndKillK(head, k, m);
			getchar();
			getchar();
			printf("Press Enter to continue...");
			break;
		}
	}
	return 0;
}