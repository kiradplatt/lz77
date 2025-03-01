#include <iostream>
#include <lz77.hpp>

using namespace std;

int main(){

    int x;
    vector<pair<int,int>> lz77_pairs;

    while(cin >> x){
     
        if(x==0){
            // pair (0,c)
            char c=0;
            cin.get(c);//skip space
            cin.get(c);//read character

            lz77_pairs.push_back({x,int(c)});
        }else{
            //pair (x,y)
            int y=0;
            cin >> y;
            lz77_pairs.push_back({x,y});
        }

    }

    string s = decompress(lz77_pairs);
    cout << s;
        
}
