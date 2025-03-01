#include <iostream>
#include <sstream>
#include <lz77.hpp>

using namespace std;

/*
 *  Compress the string provided in standard input
 *  Format of the compressed file: if the LZ77 pairs are (x,y), (z,k), ....
 *  we write to file x y z k ... (integers are separated with a space)
 */
int main(){

    //read the whole input stream into a string
    ostringstream oss;
    oss << cin.rdbuf();
    string s = oss.str(); 

    auto lz77_pairs = compress(s);

    for(auto x : lz77_pairs){
     
        cout << x.first << " ";

        if(x.first == 0) 
            cout << char(x.second);
        else 
            cout << x.second;

        cout << " ";

    }
        
}


