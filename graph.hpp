//pour une taille type  std::size_t
//friend dans les classe pour avoir accees au elements private
#pragma once //inclusion une seule fois
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include"termcolor.hpp"


using namespace std;
class Edge
{
private:
friend class Graph;
friend class Vertex;
    float value;
    int num;
    Edge( )=default;
    Edge(float val,int etatf);
public:

};
inline Edge::Edge(float val,int etatf){
    value=val;
    num=etatf;
}

struct Vertex
{
private:  
friend class Graph;
    vector<Edge> edges;
    int num;
    Vertex( ) = default;
    Vertex(int numero);
    void deep_search(vector<Vertex> &v,vector<bool> &visit);
public:
    
};
inline Vertex::Vertex(int numero){
    num=numero;
}
inline void Vertex::deep_search(vector<Vertex> &v, vector<bool> &visit){
    //vector<bool>visit_arret(edges.size(),false);
    for(Edge& e:edges){
        cout<<termcolor::bright_red <<e.value<<"\t";
        //if(not visit_arret[])
        if(not visit[e.num]){
            visit[e.num]=true;
            cout<<termcolor::bright_yellow <<e.num<<"\t";
            v[e.num].deep_search(v,visit);
        }
    }
}

class Graph
{
private: 
    vector<Vertex> vertices; 
public:
    
    ~Graph() = default;
    void add_vertex(int num){
        vertices.push_back(Vertex(num));
    }
    void add_edge(int from,int to,float val){
        vertices[from].edges.push_back(Edge(val,to));
    }
    void print(){
        cout<<termcolor::reset <<"etat courant \t valeur/etat futur"<<endl;
        for(int i=0; i<vertices.size();i++){
            for(int j=0;j<vertices[i].edges.size();j++){
                cout<<termcolor::reset<<vertices[i].num<<" -> \t"<<vertices[i].edges[j].value<<"/"<<vertices[i].edges[j].num<<endl;
            }
            
        }
    }
    void print_graph(void);
    void deep_search(void);
};

inline void Graph::deep_search(void){
    vector<bool>visit(vertices.size(),false);
    //visit.reserve(vertices.size());
    for(Vertex& v : vertices){
        if(not visit[v.num]){
            visit[v.num]=true;
            cout<<termcolor::bright_yellow <<v.num<<"\t";
            v.deep_search(vertices,visit);

        }
    }
    cout<<endl;
}

inline void Graph::print_graph(void){
    string const mon_fichier("graph_print.dot");
    ofstream myfile(mon_fichier);
    myfile<<"digraph G{"<<endl;
    for(int i=0 ; i<vertices.size();i++){
        myfile<<vertices[i].num<<" [label=\""<<vertices[i].num<<"\"]"<<endl;
    }
    for(int i=0; i<vertices.size();i++){
        for(int j=0;j<vertices[i].edges.size();j++){
            myfile<<vertices[i].num<<" -> "<<vertices[i].edges[j].num<<"[label=\""<<vertices[i].edges[j].value<<"\"]"<<endl;
        }    
    }
    myfile<<"}";
    myfile.close();
    system("dot -Tsvg graph_print.dot > graph.svg");
    system("display graph.svg");
}
