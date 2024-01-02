#include "graphrepresentations.h"

namespace mygraphs{
    void EdgeListGraph::addVertex(Vertex vertex){
        vertices_.push_back(vertex);
    }
}

    class EdgeListGraph{
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