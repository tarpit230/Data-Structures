#include<iostream>
#include<queue>

using namespace std;

int main(){
        queue<string> animals;

        animals.push("cat");
        animals.push("dog");

        cout<<"Queue:";

        while(!animals.empty()){
            cout<<animals.front()<<" ";
        }

        animals.pop();

    return 0;
}