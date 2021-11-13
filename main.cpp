#include<bits/stdc++.h>
using namespace std;

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
    for(int i=0;i<input.size();i++)
    {
        cout<<input[i]<<" ";
    }
    cout << endl;
    input_file.close();

    return EXIT_SUCCESS;



   
}