#include<bits/stdc++.h>
using namespace std;
unordered_map<string ,char>mp; 
ofstream Decoded_file("Decoded_file.txt");
void decode(string temp1);

int main()
{
    ifstream Myfile("Huffman_Codes.txt");
    string temp;
    string temp1;
    while(getline(Myfile,temp))
    {
        temp1=temp;
        mp[temp1.substr(3,temp1.size()-3)]=temp1[0];
        cout<<temp1.substr(3,temp1.size()-3)<<": ";
        cout<<mp[temp1.substr(3,temp1.size()-3)]<<endl;
    }
    
    ifstream File("Encoded_file.txt");
    temp1="";
    while(getline(File,temp))
    {
        temp1+=temp;
    }
    cout<<"Encoded_text: "<<temp1<<endl;
    decode(temp1);
    Myfile.close();
    return 0;
}

void decode(string temp1)
{
    long long int i=0;
    long long int n=temp1.size();
    long long int j;
    string temp="";
   
    while(i<n)
    {
        temp+=temp1[i];
        unordered_map<string,char>::iterator it ;
        it=mp.find(temp);
        //cout<<"Median: "<<temp<<endl;
        if(it!=mp.end())
        {
            cout<<mp[temp];
            Decoded_file<<mp[temp];
            temp="";
            
        }
        
        i++;
    }   
    
}