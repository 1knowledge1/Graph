#include <iostream>
#include <sstream>
#include <fstream>
class Graph
{
private:
	struct vertex
	{
		vertex **next;
		int val;
		unsigned int num_edges;
		int for_dfs;
		vertex()
		{
			next = nullptr;
			val = 0;
			num_edges = 0;
			for_dfs = 0;
		}
		~vertex()
		{
			//std::cout << val << " destr begine\n";
			if (next)
			{
				//for (unsigned int i = 0; i < num_edges; i++)
				//{
				//	std::cout << i << " - edge\n";
				//	delete next[i];
				//}
				delete[] next;
			}
			//std::cout<< " destr end\n";
		}


		//void dfs_v(vertex * v)
		//{
		//	if (dfs == 1)  // Если мы здесь уже были, то тут больше делать нечего
		//	{
		//		std::cout << val << " exit, cause dfs=1\n";
		//		return;
		//	}
		//	dfs = 1; // Помечаем, что мы здесь были
		//	if (next != nullptr)
		//	{
		//		for (int i = 0; i < num_edges; ++i)
		//		{
		//			std::cout << val << " call DFS for V[" << i << "]\n";
		//			dfs_v(next[i]);
		//		}
		//	}
		//	else
		//	{
		//		return;
		//	}
		//}
	};
private:
	int num_vertices;
	vertex *V;




	
public:
	Graph()
	{
		V = nullptr;
		num_vertices = 0;
	}
	~Graph()
	{
		if (V) delete[] V;
	}
	bool read(std::istream &stream)
	{
		bool success = true;
		if (stream >> num_vertices)
		{
			int ** elements = new int *[num_vertices];
			for (unsigned int i = 0; success && i < num_vertices; ++i) {
				elements[i] = new int[num_vertices];
				for (unsigned int j = 0; j < num_vertices; ++j) {
					if (!(stream >> elements[i][j])) {
						success = false;
						break;
					}
					if (elements[i][j] != 1 && elements[i][j] != 0) {
						success = false;
						break;
					}
				}
			}
			if (success)
			{
				V = new vertex[num_vertices];
				for (unsigned int i = 0; i < num_vertices; i++)
				{
					V[i].val = i + 1;
					for (unsigned int j = 0; j < num_vertices; j++)
					{
						V[i].num_edges += elements[i][j];
					}
					if (V[i].num_edges != 0)
					{
						V[i].next = new vertex*[V[i].num_edges];
						int counter = 0;
						for (unsigned int j = 0; j < num_vertices; j++)
						{
							if (elements[i][j] == 1)
							{
								V[i].next[counter] = &V[j];
								counter++;
							}
						}
					}
				}
				for (unsigned int i = 0; i < num_vertices; ++i)
				{
					delete[] elements[i];
				}
				delete[] elements;
			}
			else
			{
				success = false;
			}
		}
		else
		{
			success = false;
		}
		return success;
	}

};
int main() {
	std::ifstream fin;
	fin.open("E:\\projects\\ConsoleApplication2\\gr.txt");

	Graph gr;
	gr.read(fin);
	gr.printdfs(std::cout);
	//for (int i = 0; i< 4; i++)
	//	std::cout << gr.V[i].val << " - " << gr.V[i].num_edges << '\n';

	return 0;
}
