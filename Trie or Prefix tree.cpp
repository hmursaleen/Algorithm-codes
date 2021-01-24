#include <bits/stdc++.h>
using namespace std;

///Shafayet's implementation
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void insert(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{

    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        if (search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root); //ট্রাইটা ধ্বংস করে দিলাম
    return 0;
}


/// Another Implementation with delete_word function
#include <bits/stdc++.h>

using namespace std;

struct node
{
    bool endd;
    int cnt;
    node* next_chart[27];
    node()
    {
        endd=false;
        cnt=0;
        for(int i=0;i<27;i++)
        {
            next_chart[i]=NULL;
        }
    }
} *root;

void build(string st)
{
    node *cur=root;
    int sz=st.size(),ind;
    for(int i=0;i<sz;i++)
    {
        ind=st[i]-'a';
        cur->cnt++;
        if(cur->next_chart[ind]==NULL)
            cur->next_chart[ind]=new node();
        cur=cur->next_chart[ind];
    }
    cur->endd=true;
}

bool find_st(string st)
{
    node *cur=root;
    int sz=st.size(),ind;
    for(int i=0;i<sz;i++)
    {
        ind=st[i]-'a';
        if(cur->next_chart[ind]!=NULL)
            cur=cur->next_chart[ind];
        else
            return false;
    }
    return cur->endd;
}

bool delete_word(string st,node* cur=root,int ind=0)
{
    if(ind==st.size())
    {
        if(cur->endd==false)
            return false;
        cur->endd=false;
        return true;
    }
    int v=st[ind]-'a';
    if(cur->next_chart[v]!=NULL)
    {
        if(delete_word(st,cur->next_chart[v],ind+1))
        {
            if(cur->cnt==1)
                delete(cur);
            return true;
        }
    }
    return false;
}

void delete_trie(node *cur)
{
    for(int i=0;i<27;i++)
    {
        if(cur->next_chart[i]!=NULL)
            delete_trie(cur->next_chart[i]);
    }
    delete(cur);
}

int main()
{
    int n,t,q;
    string st;
    root=new node();

    cout<<"Enter the number of query:"<<endl;
    cin>>q;
    cout<<"Submit each query: 'query_type' 'word' (query type: 0 for add,1 for search,2 for delete):"<<endl;
    while(q--)
    {
        cin>>t>>st;
        if(t==0)
            build(st);
        else if(t==1)
        {
            if(find_st(st))
                cout<<"Found..."<<endl;
            else
                cout<<"Not Found !!!"<<endl;
        }
        else if(t==2)
        {
            if(!delete_word(st))
                cout<<"Not Found !!!"<<endl;
            else
                cout<<"Deleted Successfully !!!"<<endl;
        }
    }

    delete_trie(root);
    return 0;
}
