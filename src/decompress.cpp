#include <lz77.hpp>
using namespace std;
string decompress(const vector<pair<int,int>> &compressed){
	string output;
	for (int i = 0; i < compressed.size(); ++i)
	{
		int offset=compressed[i].first;
		int length=compressed[i].second;
		if(offset==0){
			output+=static_cast<char>(length);
		}else{
			int start=output.size()-offset;
			if (start >= output.size()) {
                cerr << "Error: Invalid offset in compressed data" << endl;
                exit(EXIT_FAILURE);
            }
			for (int j = 0; j < length; ++j)
			{
				output+=output[start+j];
			}
		}
	}
	return output;
}