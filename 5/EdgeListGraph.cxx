#include "EdgeListGraph.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  myVertices = v; //adding verticies
  myEdges = e;  //adding edges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
{
  return myVertices;  //returns a vector of verticies
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;   //returns a vector of edges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{
  EdgeCollection newEdgeCollection; //new edge collection instance
  for(int i=0; i<myEdges.size(); i++){
      if(myEdges[i].contains(v)){ //is the edge incident to the vertix?
        newEdgeCollection.push_back(myEdges[i]);  //add to new edge collection
      }
  }
  return newEdgeCollection; //return the new vector of edges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  EdgeCollection e = incidentEdges(v);  //get all of the edges incident to v
  EdgeCollection E = incidentEdges(w);   //get all of the edges incident to w
  for(int i=0; i<e.size();i++){   //loop through e
    for(int j=0; j<E.size();j++){ //loop through E
      if(e[i]==E[j]){  //if any of the verticies are the same
        return true;  //verticies are adjacent
      }
    }
  }
  return false; //not adjacent
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  myVertices.push_back(v);  //inserts vertex
  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeVertex(const Vertex& v)
{
  EdgeCollection E = incidentEdges(v);
  for(int i=0; i<E.size();i++){
    removeEdge(E[i]); //remove all edges adjacent to v
  }
  for(int i=0; i< myVertices.size();i++){
    if(myVertices[i]==v){
      myVertices.erase(myVertices.begin()+i); //erase v
      return true;  //return true
    }
  }
  return false;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertEdge(const Edge& e)
{
  bool in = false;
  VertexCollection v = e.endVertices();
  for(int i=0; i<myVertices.size();i++){
    for(int j=0; j<v.size();j++){
      if(v[j]==myVertices[i]){  //if the vertix exists
        in = true;
        break;
      }
    }
  }
  if(in){
    myEdges.push_back(e); //add to vertex
    return true;
  }
  else{
    return false;
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e)
{
  for(int i=0; i< myEdges.size(); i++){ //check to see if edge exists
    if(myEdges[i]==e){
      myEdges.erase(myEdges.begin()+i); //remove edge
      return true;
    }
  }
  return false;
}
