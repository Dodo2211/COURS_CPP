#include<iostream>
#include<vector>

using namespace std;
struct Edge
{
private:
public:
    float value;
    int num;
    Edge( )=default;
    Edge(float val,int etatf);

};
inline Edge::Edge(float val,int etatf){
    value=val;
    num=etatf;
}

struct Vertex
{
private:  
public:
    vector<Edge> edges;
    int num;
    Vertex( ) = default;
    Vertex(int numero);
};
inline Vertex::Vertex(int numero){
    num=numero;
}

struct Graph
{
private:  
public:
    vector<Vertex> vertices;
    ~Graph() = default;
    void add_vertex(int num){
        vertices.push_back(Vertex(num));
    }
    void add_edge(int from,int to,float val){
        vertices[from].edges.push_back(Edge(val,to));
    }
    void print(){
        cout<<"etat courant \t valeur/etat futur"<<endl;
        for(int i=0; i<vertices.size();i++){
            for(int j=0;j<vertices[i].edges.size();j++){
                cout<<vertices[i].num<<" -> \t"<<vertices[i].edges[j].value<<"/"<<vertices[i].edges[j].num<<endl;
            }
            
        }
    }
};



