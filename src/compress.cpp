#include <lz77.hpp>
using namespace std;
vector<pair<int,int>> compress(const string& input){
	vector<pair<int,int>> output;
	int window_size=256; 
	int n=input.size();
	//Iterate over each character
	for (int i = 0; i < n;)
	{
		int best_offset=0, best_Length=0;
		//look for lonest match
		for (int j=max(0,i-window_size);j<i; ++j)
		{
			int k=0; //track the length
			while(i+k<n && input[j+k]==input[i+k]) {
				k++;
				if (k>6) break;
			}
			if (k>best_Length) //update if found
			{
				best_offset=i-j;
				best_Length=k;
			}
		}
		//cout << "At index " << i << " Best Offset: " << best_offset << " Best Length: " << best_Length << endl;
		if (best_Length>1) //if no repeating match
		{
			output.emplace_back(best_offset,best_Length);
			i+=best_Length;
		}else{
			unsigned char literal=static_cast<unsigned char>(input[i]);
			//cout << "No match at index " << i << ", output literal: " << input[i] << endl;
			output.emplace_back(0,literal);
			i++;
		}
	}
	//for (const auto& p : output) {
    //	cout << "(" << p.first << ", " << p.second << ") ";
	//}
	//cout << endl;
	return output;

}