// kursach1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// prim kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
const int n = 3;
struct Stack
{
	int A[n];
	int count;
};
//создание стека
void Creation(Stack *p)
{
	p->count = 0;
}
//проверка стека на пустоту
int Full(Stack *p)
{
	if (p->count == 0) return 1;
	else if (p->count == n) return -1;
	else return 0;
}
//добавление элемента
void Add(Stack *p)
{
	int value;
	cout << "Введите элемент > "; cin >> value;
	p->A[p->count] = value;
	p->count++;
}
//удаление элемента
void Delete(Stack *p)
{
	p->count--;
}
//вывод верхнего элемента
int Top(Stack *p)
{
	return p->A[p->count - 1];
}
//размер стека
int Size(Stack *p)
{
	return p->count;
}
//********************************************************************************************

struct Node //описание узла списка
{
	int data; //информационное поле
	Node *next; //указатель на следующий элемент
};
struct Queue //описание очереди
{
	int size; //счетчик размера очереди
	Node *first; //указатель на начало очереди
	Node *last; //указатель на конец очереди
};
void Creation(Queue *Q) //создание очереди
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}
bool Full(Queue *Q) //проверка очереди на пустоту
{
	if (Q->first == Q->last) return true;
	else return false;
}
int Top(Queue *Q) //вывод начального элемента
{
	return Q->first->next->data;
}
void Add(Queue *Q) //добавление элемента
{
	int value;
	cout << "\nЗначение > "; cin >> value;
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value; //добавление элемента в конец
	Q->last->next = NULL; //обнуление указателя на следующий элемент
	Q->size++;
	cout << "\nЭлемент добавлен\n\n";
}
void Delete(Queue *Q) //удаление элемента
{
	Q->first = Q->first->next; //смещение указателя
	Q->size--;
	cout << "\nЭлемент удален\n\n";
}
int Size(Queue *Q) //размер очереди
{
	return Q->size;
}

//************************************************************************************************

const int N = 5; //размер дека
struct Deque
{
	int data[N]; //массив данных
	int last; //указатель на конец
};
void Creation(Deque *D) //создание дека
{
	D->last = 0;
}
bool Full(Deque *D) //проверка дека на пустоту
{
	if (D->last == 0) return true;
	else return false;
}
void AddL(Deque *D) //добавление элемента в начало
{
	if (D->last == N)
	{
		cout << "\nДек заполнен\n\n"; return;
	}
	int value;
	cout << "\nЗначение > "; cin >> value;
	for (int i = D->last; i > 0; i--)
		D->data[i] = D->data[i - 1];
	D->data[0] = value;
	D->last++;
	cout << endl << "Элемент добавлен\n\n";
}
void AddR(Deque *D) //добавление элемента в конец
{
	if (D->last == N)
	{
		cout << "\nДек заполнен\n\n"; return;
	}
	int value;
	cout << "\nЗначение > "; cin >> value;
	D->data[D->last++] = value;
	cout << endl << "Элемент добавлен\n\n";
}
void DeleteL(Deque *D) //удаление первого элемента
{
	for (int i = 0; i < D->last; i++) //смещение элементов
		D->data[i] = D->data[i + 1]; D->last--;
}
void DeleteR(Deque *D) //удаление последнего элемента
{
	D->last--;
}
int OutputL(Deque *D) //вывод первого элемента
{
	return D->data[0];
}
int OutputR(Deque *D) //вывод последнего элемента
{
	return D->data[D->last - 1];
}
int Size(Deque *D) //размер дека
{
	return D->last;
}
//*********************************************************************************************
int main()
{
	setlocale(LC_ALL, "Russian");
	Stack s;
	Creation(&s);
	char stack;
	char menu;
	Queue Q;
	Creation(&Q);
	char  queue;
	Deque D;
	Creation(&D);
	char deque;
	cout << "1. Стек" << endl;
	cout << "2. Очередь" << endl;
	cout << "3. Дек" << endl;
	cout << "Номер команды > ";
	cin >> menu;

	switch (menu) {
	case 1:

		do
		{
			cout << "1. Добавить элемент" << endl;
			cout << "2. Удалить элемент" << endl;
			cout << "3. Вывести верхний элемент" << endl;
			cout << "4. Узнать размер стека" << endl;
			cout << "0. Выйти" << endl;
			cout << "Номер команды > ";
			cin >> stack;
			switch (stack)
			{
			case '1':
				if (Full(&s) == -1) cout << endl << "Стек заполнен\n\n";
				else
				{
					Add(&s);
					cout << endl << "Элемент добавлен в стек\n\n";
				} break;
				//-----------------------------------------------
			case '2':
				if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
				else
				{
					Delete(&s);
					cout << endl << "Элемент удален из стека\n\n";
				} break;
				//-----------------------------------------------
			case '3':
				if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
				else cout << "\nВерхний элемент: " << Top(&s) << "\n\n";
				break;
				//-----------------------------------------------
			case '4':
				if (Full(&s) == 1) cout << endl << "Стек пуст\n\n";
				else cout << "\nРазмер стека: " << Size(&s) << "\n\n";
				break;
				//-----------------------------------------------
			case '0': break;
			default: cout << endl << "Команда не определена\n\n";
				break;
			}
		} while (stack != '0');

		system("pause");

		break;


	case 2:
		do
		{
			cout << "1. Добавить элемент" << endl;
			cout << "2. Удалить элемент" << endl;
			cout << "3. Вывести верхний элемент" << endl;
			cout << "4. Узнать размер очереди" << endl;
			cout << "0. Выйти\n\n";
			cout << "Номер команды > ";
			cin >> queue;
			switch (queue)
			{
			case '1': Add(&Q);
				break;
				//-----------------------------------------------
			case '2':
				if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
				else Delete(&Q);
				break;
				//-----------------------------------------------
			case '3':
				if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
				else { cout << "\nНачальный элемент: " << Top(&Q) << "\n\n"; }
				break;
				//-----------------------------------------------
			case '4':
				if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
				else cout << "\nРазмер очереди: " << Size(&Q) << "\n\n";
				break;
				//-----------------------------------------------
			case '0': break;
			default: cout << endl << "Команда не определена\n\n";
				break;
			}
		} while (queue != '0');
		system("pause");

		break;


	case 3:
		do
		{

			cout << "1. Добавить элемент в начало" << endl;
			cout << "2. Добавить элемент в конец" << endl;
			cout << "3. Удалить первый элемент" << endl;
			cout << "4. Удалить последний элемент" << endl;
			cout << "5. Вывести первый элемент" << endl;
			cout << "6. Вывести последний элемент" << endl;
			cout << "7. Узнать размер дека" << endl;
			cout << "0. Выйти\n\n";
			cout << "Номер команды > "; cin >> deque;
			switch (deque)
			{
			case '1': AddL(&D);
				break;
				//-----------------------------------------------
			case '2': AddR(&D);
				break;
				//-----------------------------------------------
			case '3':
				if (Full(&D)) cout << endl << "Дек пуст\n\n";
				else
				{
					DeleteL(&D);
					cout << endl << "Элемент удален из дека\n\n";
				} break;
				//-----------------------------------------------
			case '4':
				if (Full(&D)) cout << endl << "Дек пуст\n\n";
				else
				{
					DeleteR(&D);
					cout << endl << "Элемент удален\n\n";
				} break;
				//-----------------------------------------------
			case '5':
				if (Full(&D)) cout << endl << "Дек пуст\n\n";
				else cout << "\nПервый элемент: " << OutputL(&D) << "\n\n";
				break;
				//-----------------------------------------------
			case '6':
				if (Full(&D)) cout << endl << "Дек пуст\n\n";
				else cout << "\nПоследний элемент: " << OutputR(&D) << "\n\n";
				break;
				//-----------------------------------------------
			case '7':
				if (Full(&D)) cout << endl << "Дек пуст\n\n";
				else cout << "\nРазмер дека: " << Size(&D) << "\n\n";
				break;
				//-----------------------------------------------
			case '0': break;
			default: cout << endl << "Команда не определена\n\n";
				break;
			}
		} while (deque != '0');
		system("pause");

		break;

	}


}














