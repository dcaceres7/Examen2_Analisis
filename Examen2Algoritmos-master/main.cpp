#include "Test.h"
#include <iostream>
using namespace std;

//Counts the number of posibles paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int countPaths(int** DAG, int size, int origin, int destination)
{
   if (size == 0 &&  origin== destination)
    return 1;
   if (size == 1 && DAG[origin][destination])
    return 1;
   if (size <= 0)
    return 0;

   int count = 0;
   for (int i = 0; i < 4; i++)
    if (DAG[origin][destination] != -1)
        count += countPaths(DAG, i, destination, size-1 );
   return count;
}

//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    return answer;
}

int main ()
{
    test();
    return 0;
}
