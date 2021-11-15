#include<bits/stdc++.h>
using namespace std;
unordered_map<char,long long int>f;
unordered_map<char,string>mp;
ofstream Code_file("Huffman_Codes.txt");
ofstream Encoded_file("Encoded_file.txt");
vector<char> input;
void show_codes(struct huffmanNode * root,string s);
void create_codes();
void encrypt();
void calculate_freq();
void Make_Code_File(struct huffmanNode * root,string s);
struct huffmanNode{
    char val;
    long long int freq;
    struct huffmanNode * left;
    struct huffmanNode* right;
};


struct fun1 {
 
    bool operator()(struct huffmanNode* l,struct  huffmanNode* r)
 
    {
        return (l->freq>r->freq);
    }
};



int main()
{
    
    string filename("file.txt");
    
    char byte = 0;
    long long int i;
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
    calculate_freq();
    cout<<"Frequency of characters in the file:\n";
    for(auto x: f)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    
    create_codes();
    
    encrypt();
    Code_file.close();
    Encoded_file.close();
    
    return EXIT_SUCCESS;    
}
void encrypt()
{
    long long int i;
    
    for(i=0;i<input.size();i++)
    {
       
        
        Encoded_file<<mp[input[i]];
        
    }
}
void show_codes(struct huffmanNode * root,string s)
{
    if(!root)
    {
        return;
    }
    if(root->val!='$')
    {
        cout<<root->val<<": "<<s<<"\n";
        
    }
    if(root->val=='$' && root->right==NULL && root->left==NULL)
    {
         cout<< root->val << ": " << s << "\n";
        
    }
 
    show_codes(root->left, s + "0");
    show_codes(root->right, s + "1");
}
void calculate_freq()
{
    long long int i;
    long long int n=input.size();
    for(i=0;i<n;i++)
    {
        
        f[input[i]]++;
        
    }

}
void Make_Code_File(struct huffmanNode * root,string s)
{
    if(!root)
    {
        return;
    }
    if(root->val!='$')
    {
        Code_file<<root->val<<": "<<s<<"\n";
        mp[root->val]=s;
    }
    if(root->val=='$' && root->right==NULL && root->left==NULL)
    {
         Code_file<< root->val << ": " << s << "\n";
          mp[root->val]=s;
    }
 
   Make_Code_File(root->left, s + "0");
   Make_Code_File(root->right, s + "1");
}
void create_codes()
{
    priority_queue<struct huffmanNode*, vector<struct huffmanNode*> ,fun1> heap;
  
    long long int i;
    for(auto x: f)
    {
        struct huffmanNode* temp=new huffmanNode();
        temp->val=x.first;
        temp->freq=x.second;
        temp->left=NULL;
        temp->right=NULL;
        heap.push(temp);

    }
    while(heap.size()!=1)
    {
        struct huffmanNode* l=heap.top();
        heap.pop();
        cout<<"Nodes used in combining this time:\n";
        cout<<l->val<<" : "<<l->freq<<endl;
        struct huffmanNode* r=heap.top();
        heap.pop();
        cout<<r->val<<" : "<<r->freq<<endl<<endl;
        struct huffmanNode* parent=new huffmanNode();
        parent->val='$';
        parent->freq=l->freq + r->freq;
        parent->left=l;
        parent->right=r;
        heap.push(parent);
    }
    //cout<<"Huffman Codes for characters:\n";
    //show_codes(heap.top(),"");
    Make_Code_File(heap.top(),"");
}
