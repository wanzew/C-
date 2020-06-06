#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

namespace Graph {
	//³íÃÜÍ¼ - ÁÚ½Ó¾ØÕó
	class DenseGraph {
	private:
		int node;
		int edge;
		bool directed;
		vector<vector<bool>> adjMatrix;

	public:
		DenseGraph(int node, bool directed) {
			this->node = node;
			this->directed = directed;

			this->edge = 0;
			for (int i = 0; i < node; i++) {
				adjMatrix.push_back(vector<bool>(node, false));
			}
		}

		int vertex() { return node; }
		int edges() { return edge; }

		void addEdge(int v, int w) {
			assert(v >= 0 && v < node);
			assert(w >= 0 && w < node);

			if (isConnected(v, w))
				return;

			adjMatrix[v][w] = true;
			if (!directed) {
				adjMatrix[w][v] = true;
			}

			edge++;
		}

		bool isConnected(int v, int w) {
			assert(v >= 0 && v < node);
			assert(w >= 0 && w < node);
			return adjMatrix[v][w];
		}
	};

	//Ï¡ÊèÍ¼ - ÁÚ½Ó±í
	class SparseGraph {
	private:
		int node;
		int edge;
		bool directed;

		vector<vector<int>> adjList;
	public:
		SparseGraph(int node, bool directed) {
			this->node = node;
			this->edge = 0;
			this->directed = directed;

			for (int i = 0; i < node; i++) {
				adjList.push_back(vector<int>());
			}
		}

		int V() { return node; }
		int E() { return edge; }


		void addEdge(int v, int w) {
			assert(v >= 0 && v < node);
			assert(w >= 0 && w < node);

			adjList[v].push_back(w);
			if (v != w && !directed)
				adjList[w].push_back(v);

			edge++;
		}

		bool isConnected(int v, int w) {
			assert(v >= 0 && w >= 0);
			assert(v < node&& w < node);

			for (int i = 0; i < adjList[v].size(); i++) {
				if (adjList[v][i] == w)
					return true;
			}
			return false;
		}

		class adjIterator {
		private:
			SparseGraph &m_graph;
			int vertex;
			int index;
		public:
			adjIterator(SparseGraph & graph, int v)
				: m_graph(graph)
			{
				this->vertex = v;
				this->index = 0;
			}

			int begin() {
				this->index = 0;
				if (m_graph.adjList[vertex].size())
					return m_graph.adjList[vertex][index];
			}

			int next() {
				index++;
				if (index < m_graph.adjList[vertex].size())
					return m_graph.adjList[vertex][index];
				else
					return -1;
			}

			bool end() {
				if (index >= m_graph.adjList[vertex].size())
					return true;
				else 
					return false;
			}
		};
	};


}

