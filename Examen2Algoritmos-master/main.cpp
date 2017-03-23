#include "Test.h"
#include <iostream>
using namespace std;

//Counts the number of posibles paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int** res;
void initializer_res(int size){
    res = new int* [size];
    for(int i = 0 ; i<size; i++){
        res[i]= new int[size];
        for(int j = 1 ; j<size; j++){
            res[i][j]=-1;
        }
    }
}

int solve(int** DAG, int size, int origin, int destination){
    if (size <= 0)
    return 0;
    if (origin == destination)
    return 1;
    if (size == 1 && DAG[origin][destination])
    return 1;

    int count = 0;

    for (int i = 0; i < size; i++)
        if (DAG[origin][i] != -1){
            if(res[origin][i] == -1){
                int temp = solve(DAG, size, i, destination);
                res[origin][i] = temp;
                count += temp;
            } else{
                count += res[origin][i];
            }
        }
    return count;
}

int countPaths(int** DAG, int size, int origin, int destination)
{
   initializer_res(size);
   /*for(int i = 0 ; i<size; i++){
        for(int j = 1 ; j<size; j++){
            cout<<i<<", "<<j<<res[i][j]<<endl;
        }
    }*/
    int x = solve(DAG,size,origin,destination);
    //cout<<"RESPUESTA: "<<x<<endl;
   return x;
}

//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
bool checkRes(vector<int> answer, bool dis[], int nav, int size){
    for(int i =0; i < size; i++){
        if(dis[i]){
            if(answer[i]==nav){
                return false;
            }
        }
    }
    return true;
}
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    answer.push_back(0);
    for(int i=1; i < size; i++)
        answer.push_back(-1);

    bool dis[size];
    for (int cr = 0; cr < size; cr++)
        dis[cr] = false;

    for(int i = 0; i < size; i++){
        for(int j= 0; j < size; j++){
            if(graph[i][j] != -1 || graph[j][i] != -1){
                dis[j] = true;
            }
        }
        int nav;
        for (nav = 0; nav < size; nav++){
            if (dis[nav] == false && checkRes(answer, dis, nav, size)){
                break;
            }
        }
        answer[i] = nav;
        for(int j =0; j < size; j++){
            if(graph[i][j] != -1 || graph[j][i] != -1){
                dis[j] = false;
            }
        }

    }
    for(int i =0; i < size; i++)
    cout<<"vertice en la posicion: "<<i<<" color: "<<answer[i]<<endl;
    return answer;
}

int main ()
{
    test();
    return 0;
}
