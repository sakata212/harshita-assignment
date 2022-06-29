#include <iostream>
#define X 5
#define Y 5
using namespace std;

bool bipGraph[X][Y];
bool bipartiteMatch(int u, bool visited[], int assign[])
{
   for (int v = 0; v < Y; v++)
    {
      if (bipGraph[u][v] && !visited[v])
       {
         visited[v] = true;
         if (assign[v] < 0 || bipartiteMatch(assign[v], visited, assign))
         {
            assign[v] = u;
            return true;
         }
      }
   }
   return false;
}

int maxMatch()
{
   int assign[Y];
   for(int i = 0; i<Y; i++)
      assign[i] = -1;
   int jobCount = 0;
   for (int u = 0; u < X; u++)
    {
      bool visited[Y];
      for(int i = 0; i<Y; i++)
         visited[i] = false;
      if (bipartiteMatch(u, visited, assign))
         jobCount++;
   }
   return jobCount;
}

int main()
 {
    cout<<"Enter the matrix"<<endl;
    int i,j;
    int graph[X][Y];
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
        cin>>graph[i][j];
        bipGraph[i][j]=graph[i][j];
        }
    }

   cout << "Maximum number of vertices that can be matched are:" << maxMatch();
   return 0;
 }
