#include<bits/stdc++.h>
using namespace std;
unordered_map<char,long long int>f;

void show_codes(struct huffmanNode * root,string s);
void create_codes(unordered_map<char,long long int>f);
void calculate_freq(vector<char>input);

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
    vector<char> input;
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
    calculate_freq(input);
    cout<<"Frequency of characters in the file:\n";
    for(auto x: f)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    
    create_codes(f);



    return EXIT_SUCCESS;    
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
        cout << root->val << ": " << s << "\n";
    }
 
    show_codes(root->left, s + "0");
    show_codes(root->right, s + "1");
}
void calculate_freq(vector<char>input)
{
    long long int i;
    long long int n=input.size();
    for(i=0;i<n;i++)
    {
        
        f[input[i]]++;
        
    }

}
void create_codes(unordered_map<char,long long int>f)
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
    cout<<"Huffman Codes for characters:\n";
    show_codes(heap.top(),"");
}
