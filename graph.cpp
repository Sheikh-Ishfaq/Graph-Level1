#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template <typename T>

class Graph{
  public:
    // adjacancy list for storing edges...
    unordered_map<T,list<pair<T,int>>>adjList;

    //Member function to add an edge...
    void addEdge(T u, T v,int wt, bool direction){
        //for non directed edges
        if(direction){
            adjList[u].push_back({v,wt});
        }
        //for directed edges
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back(make_pair(u,wt));
        }
        //print(u);
    }
    
    void print(T src){
        cout<<src<<"->{";
        for(auto i:adjList[src]){
            pair<T,int>p = i;
            cout<<"{"<<p.first<<","<<p.second<<"}";
        }
        cout<<"}"<<endl;
    }

    //BFS Traversal...
    void bfs(T src, unordered_map<T,bool>&vis){
        
        queue<T>q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T front = q.front();
            cout<<front<<" ";
            q.pop();
            
            //Exploring each child or neighbour of a src node...
            for(auto p : adjList[front]){

                if(vis[p.first] == false){
                    q.push(p.first);
                    vis[p.first ] = true;
                }
            }
        }
         
    }

    void dfs(T src,unordered_map<char,bool>&vis){
       
        
        cout<<src<<" ";
        vis[src] = true;
        for(auto it : adjList[src]){
            T node = it.first;
            if(vis[node] == false)
            dfs(node,vis);
            
        }
    }

};

 int main()
{
    Graph<char> g;
    g.addEdge('a','d',10,0);
    g.addEdge('a','b',20,0);
    g.addEdge('b','c',30,0);
    g.addEdge('c','d',40,0);
    g.addEdge('e','f',40,0);
     
    
    cout<<"dfs traversal"<<endl;
     unordered_map<char,bool>vis;

     // Tracking disconnected components of a graph
     for(char node = 'a'; node <= 'f'; node++){
        if(!vis[node])
        g.dfs(node,vis);
     }
     
    return 0;
}