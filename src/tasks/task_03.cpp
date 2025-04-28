#include <iostream>
using namespace std;

template <typename T>
class cyclicQueue
{
private:
	T *arr;
	int size;
	int front;
	int back;
	int count;

public:
	cyclicQueue(int n);
	~cyclicQueue();

	void enqueue(T x);
	T dequeue();
	T peek();
	int getSize();
	bool empty();
	void print();
	void clear();
	T operator[](int i);
};

template <typename T>
cyclicQueue<T>::cyclicQueue(int n)
{
	arr = new T[n];
	size = n;
	front = 0;
	back = 0;
	count = 0;
}

template <typename T>
cyclicQueue<T>::~cyclicQueue() { delete[] arr; }

template <typename T>
void cyclicQueue<T>::enqueue(T x)
{
	if (count == size)
		return;
	arr[back] = x;
	back = (back + 1) % size;
	count++;
}

template <typename T>
T cyclicQueue<T>::dequeue()
{
	if (count == 0)
		return T();
	T x = arr[front];
	front = (front + 1) % size;
	count--;
	return x;
}

template <typename T>
T cyclicQueue<T>::peek()
{
	if (count == 0)
		return T();
	return arr[front];
}

template <typename T>
int cyclicQueue<T>::getSize() { return count; }

template <typename T>
bool cyclicQueue<T>::empty() { return count == 0; }

template <typename T>
void cyclicQueue<T>::print()
{
	for (int i = 0; i < count; i++)
		cout << arr[(front + i) % size] << " ";
	cout << endl;
}

template <typename T>
void cyclicQueue<T>::clear()
{
	front = 0;
	back = 0;
	count = 0;
}

template <typename T>
T cyclicQueue<T>::operator[](int i) { return arr[(front + i) % size]; }

void task_03()
{
	cyclicQueue<int> q(5);
	for (int i = 0; i < 10; i++)
		q.enqueue(i);

	q.print();
	cout << "peek: " << q.peek() << endl;

	q.dequeue();
	q.dequeue();

	cout << "peek: " << q.peek() << endl;
	cout << "q[2]: " << q[2] << endl;

	for (int i = 0; i < 5; i++)
		q.dequeue();

	cout << "size: " << q.getSize() << endl;

	q.print();
	q.clear();
	q.print();

	cyclicQueue<string> q_str(3);
	q_str.enqueue("Hello");
	q_str.enqueue("World");
	q_str.enqueue("Queue");

	q_str.print();
	cout << "peek: " << q_str.peek() << endl;

	q_str.dequeue();
	q_str.dequeue();

	cout << "peek: " << q_str.peek() << endl;
	cout << "q_str[1]: " << q_str[1] << endl;
}
