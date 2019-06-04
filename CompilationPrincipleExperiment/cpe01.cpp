
#include <iostream>
using namespace std;
int t = 0;
char A[20];
struct LeftItem;
struct RightNode
{
	char right;
	RightNode* nextsibling;
	RightNode* nextrule;
	RightNode(char abc)
	{
		right = abc;  nextsibling = NULL;  nextrule = NULL;
	}
};

struct LeftItem
{
	char left;
	RightNode* therule;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(RightNode*& pNode, char* temp)
{

	pNode = new RightNode(*temp);
	RightNode* qNode = pNode;
	temp++;
	while (*temp != '\0')
	{
		qNode->nextsibling = new RightNode(*temp);
		qNode = qNode->nextsibling;
		temp++;
	}
}

void Bianli1(LeftItem Array[], int length, RightNode* pNode)
{
	RightNode* qNode = pNode->nextrule;
	while (pNode != NULL)
	{
		int i = 0;//////
		for (i = 0; i < length; i++)
		{
			if (pNode->right == Array[i].left) break;
		}
		if (i == length)
		{
			for (i = 0; i < t; i++)
			{
				if (pNode->right == A[i]) break;
			}
			if (i == t)
			{
				if (i != 0)   cout << ", ";
				cout << pNode->right;
				A[t] = pNode->right;
				t++;
			}
		}
		pNode = pNode->nextsibling;
	}
	if (qNode != NULL) Bianli1(Array, length, qNode);
}

void Bianli2(RightNode * pNode)
{
	RightNode* qNode = pNode->nextrule;
	while (pNode != NULL)
	{
		cout << pNode->right;
		pNode = pNode->nextsibling;
	}
	if (qNode != NULL)
	{
		cout << "|";
		Bianli2(qNode);
	}
}

void SelectMenu(LeftItem Array[], int length)
{
	int sel2;
	do
	{
		cout << "��ѡ����Ҫ��ѯ����Ŀ." << endl;
		cout << "--��ѯȫ������밴------> 1" << endl;
		cout << "--��ѯָ�������밴------> 2" << endl;
		cin >> sel2;
	} while (sel2 != 1 && sel2 != 2);
	if (sel2 == 1)
	{
		for (int i = 0; i < length; i++)
		{
			cout << Array[i].left << "::=";
			Bianli2(Array[i].therule);
			cout << endl;
		}

	}
	else
	{
		char temp;
		int k,i;
		cout << endl;
		cout << "������Ҫ��ѯ������:";
		cin >> temp;
		for (i = 0; i < length; i++)
		{
			if (temp == Array[i].left)
			{
				k = i;
				break;
			}
		}
		if (i == length)
			cout << "���ķ�������û�ж�Ӧ�Ĺ���!" << endl;
		else
		{
			cout << Array[k].left << "::=";
			Bianli2(Array[k].therule);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	char temp[20];
	int size = 0;
	int k, sel, m, n, j;
	cout << "�������ķ��������Ŀ��";
	cin >> n;//�ķ���Ŀ
	LeftItem* Array = new LeftItem[n];
	for (int i = 0; i < n; i++)//���뼰�洢�ķ�����
	{
		cout << "�������ķ�����:";
		cin >> temp;
		if (*temp == NULL)//�ж������Ƿ�Ϊ��
			break;
		for (j = 0; j < size; j++)
		{
			if (Array[j].left == *temp)
			{
				k = j;
				break;
			}
		}
		if (j == size)
		{
			Array[size].left = *temp;
			Insert(Array[size].therule, temp + 4);
			size++;
		}
		else
		{
			RightNode* t = Array[k].therule;
			while (t->nextrule != NULL)
				t = t->nextrule;
			Insert(t->nextrule, temp + 4);
		}
	}
	cout << "�ķ�����洢���!" << endl << endl << endl;
	cout << "��ӭ�����ѯϵͳ!" << endl << endl;
aaa:
	cout << endl;
	do
	{
		cout << "��ѡ����Ҫ��ѯ����Ŀ." << endl;
		cout << "--��ѯʶ����밴--------> 1" << endl;
		cout << "--��ѯ���ս���밴------> 2" << endl;
		cout << "--��ѯ�ս���밴--------> 3" << endl;
		cout << "--��ѯ��������밴------> 4" << endl;
		cout << "--���Chomsky�ķ��밴---> 5" << endl;
		cout << "--�˳�ϵͳ�밴----------> 6" << endl;
		cin >> sel;
	} while (sel != 1 && sel != 2 && sel != 3 && sel != 4 && sel != 5 && sel != 6);
	switch (sel)
	{
	case 1:
		cout << endl;
		cout << "���ķ�������ʶ���Ϊ��";
		cout << Array[0].left << endl;
		break;
	case 2:
		cout << endl;
		cout << "���ķ������з��ս��Ϊ��";
		for (m = 0; m < size; m++)
		{
			cout << Array[m].left;
			if (m != size - 1) cout << " ,";
		}
		cout << endl;
		break;
	case 3:
		t = 0;
		cout << endl;
		cout << "���ķ��������ս��Ϊ��";
		for (m = 0; m < size; m++)
			Bianli1(Array, size, Array[m].therule);
		cout << endl;
		break;
	case 4:
		cout << endl;
		SelectMenu(Array, size);
		cout << endl;
		break;
	case 5:
		t = 0;
		cout << "Chomsky�ķ���ʽ���£�" << endl;
		cout << "G" << "=";
		cout << "(Vn,Vt,P," << Array[0].left << ")" << endl;
		cout << "Vn={ ";
		for (m = 0; m < size; m++)
		{
			cout << Array[m].left;
			if (m != size - 1) cout << " ,";
		}
		cout << " }" << endl;
		cout << "Vt={ ";
		for (m = 0; m < size; m++)
			Bianli1(Array, size, Array[m].therule);
		cout << "}" << endl;
		cout << "����P:" << endl;
		for (m = 0; m < size; m++)
		{
			cout << Array[m].left << "::=";
			Bianli2(Array[m].therule);
			cout << endl;
		}
		break;
	case 6:
		break;
	}
	if (sel != 6)  goto aaa;
	return 0;
}