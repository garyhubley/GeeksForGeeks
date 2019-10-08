#include <bits/stdc++.h>
using namespace std;

/* Included for the sake of using an input file as opposed to cmd line entry */
#include <fstream>


/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/* Function to implement push operation in priority_queue
* pq : priority_queue
* x : element to be pushed
*/
void push_pq(priority_queue<int, vector<int>, greater<int> > &pq, int x){
    pq.push(x);   
}

/* Function to implement pop operation in priority_queue
* pq : priority_queue
*/
void pp_pq(priority_queue<int, vector<int>, greater<int> > &pq){

    if(!pq.empty())
        pq.pop();
    else
        return;
                
}

/* Function to implement top operation in priority_queue
* pq : priority_queue
*/
int pq_top(priority_queue<int, vector<int>, greater<int> > &pq){

    if(!pq.empty())
        return pq.top();
    else
        return -1;
}

// Initial Template for C++
// CPP code to implement functions of priority_queue
//Position this line where user code will be pasted.
// Driver code
int main(int argc, char** argv) {

    ifstream input(argv[1]);

    int testcase;
    input >> testcase;
    // Declaring priority queue
    priority_queue<int, vector<int>, greater<int> > pq; 
         
    while(testcase--){
        // Queries input
        int queries;
        input >> queries;

        while(queries--){
            
            string s;
            input >> s;

            // If query is to push
            if(s == "p"){
                int x;
                input >> x;
                push_pq(pq, x);
                cout << pq.size() << endl;
            }

            // If query is to pop
            if(s == "pp"){
                pp_pq(pq);

                cout << pq.size() << endl;
            }

            // If query is to return top
            if(s == "t"){
                cout << pq_top(pq) << endl;
            }
        }

        // resetting priority queue
        pq = priority_queue <int, vector<int>, greater<int> >();
    }

    return 0;
   
}



