#include<bits/stdc++.h>
using namespace std;
unordered_map<char,long long int>freq;

void calculate_freq(vector<char>input)
{
    long long int i;
    long long int n=input.size();
    for(i=0;i<n;i++)
    {
        freq[input[i]]++;
    }

}

int main()
{
    string filename("file.txt");
    vector<char> input;
    char byte = 0;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file.get(byte)) {
        input.push_back(byte);
    }
    for(long long int i=0;i<input.size();i++)
    {
        cout<<input[i]<<" ";
    }
    cout << endl;
    input_file.close();
    calculate_freq(input);
    for(auto & x: freq)
    {
        cout<<x.first<<": "<<x.second<<endl;
    }




    return EXIT_SUCCESS;



   
}