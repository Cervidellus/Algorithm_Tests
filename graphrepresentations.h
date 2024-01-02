#ifndef GRAPH_REPRESENTATIONS
#define GRAPH_REPRESENTATIONS

//Several directed/weighted graph representations:
//1. Edge list.
//2. Adjacency matrix.
//3. Adjacency lists.

//Then, for the special case of volume representations
//4. Mesh represented by Faces Edges and Vertices
//5. Half-edge data structure

//For each of these, I want to implement several test algorithms to compare performance. 
//If I can I would implement the algorithms so they can work on multiple graph structures.
//1. Dijkstra's shortest path on weighted graphs. 

#include <vector>

namespace mygraphs{

    //Should I make primitives for vertices, edges, and faces?
    struct Vertex{
        double x,y,z;
    };

    struct IndexedEdge{
        int source,target;
    };

    struct IndexedTriangleFace{
        //should I enforce sorted?
        std::vector<int> vertices;

    };

    class EdgeListGraph{
        public:
        EdgeListGraph();
        ~EdgeListGraph();

        void addVertex(Vertex vertex);
        void removeVertex(Vertex vertex);
        void addEdge(IndexedEdge edge);
        void removeEdge(IndexedEdge edge);

        std::vector<int> targetVertices(int sourceVertex);
        double edgeWeight(int edgeIndex);//can either be stored or calculated when asked for.

        private:
        std::vector<Vertex> vertices_;
        std::vector<IndexedEdge> edges_;
        //Should I just calculate the distance?
        std::vector<double> edgeWeights_;
    };


}

#endif