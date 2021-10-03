// BFS graphs- traversing adjacent nodes first
// TC: big Oh N+E
#include<bits/stdc++.h>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
	int vertex,edges;
	cin>>vertex>>edges;
	vector<int>adj[vertex+1];
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// Printing adjacency list->
//for (int i = 0; i <=vertex; i++) {
//  
//        cout << "Elements at index "
//             << i << ": ";
//      vector<int>::iterator it;
//
//       
//        for (it = adj[i].begin();
//             it != adj[i].end(); it++) {
//  
//           
//            cout << *it << ' ';
//        }
//        cout << endl;
//    }

vector<int>vis(vertex+1,0);
 for(int i=1;i<=vertex;i++){
 	if(!vis[i]){
 	
 		queue<int>q;
 		q.push(i);
 		vis[i]=1;
 		  while(!q.empty())
		   {
 		  	    int node=q.front();
 		  	    vis[node]=1;
 		  	    cout<<node<<" ";
 		  	    q.pop();
// 		  	    vector<int>::iterator it;
 		  	    for(auto it :adj[node]){
 		  	  	    if(!vis[it]){
 		  	  	    	q.push(it);
 		  	  	    	vis[it]=1;
					}
				}
		   }
	 }
 }

	
}
