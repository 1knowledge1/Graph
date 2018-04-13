#include "queue_t.cpp"
int main()
{
	queue_t<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.print(std::cout);
	std::cout << que.pop();
	std::cout << que.pop();
	queue_t<int> que1 = que;
	que1.print(std::cout);
    return 0;
}
