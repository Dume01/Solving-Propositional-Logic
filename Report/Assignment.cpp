#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Stack made for converting the prefix expression to infix expression

struct MyStack{
    string *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new string [cap];
        top=-1;
    }

// To push an element in the stack
    
    void push(string x){
        if(top==cap-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top]=x;
    }

// To pop an element from the stack

    string pop(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return NULL;}
        string res=arr[top];
        top--;
        return res;
    }

// To get the top elemenet from the stack
    
    string peek(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return NULL;}
        return arr[top];
    }


    int size(){
        return (top+1);
    }

// To check if the stack is empty or not
    
    bool isEmpty(){
        return top==-1;
    }
};

/*
//Following function checks if the And Intro is Done right or not it has variables of array of string, inputed value and line numbers on which the rule is implemented
*/

bool andIntro(string str[],string p,int ini,int fin)
{   
    string q=str[ini-1]+"^"+str[fin-1];
    string qcheck=p.substr(1,p.find("/")-2);
    if(q.compare(qcheck)==0)
    return true;
    return false;
}

/*
//Following function checks if the And Eli 1 is Done right or not it has variables of array of string, inputed value and line number on which the rule is implemented
*/

bool andEli1(string str[],string p,int pos)
{
    string q=str[pos-1];
    //stack to get the elements before ^
    stack<string> st;
    string wq;
    int count=0;
    for(int i=1;i<q.length();i++)
    {
        if(q[i]=='(')
        count+=1;
    }
    
    if(count>1)
    {   for(int i=1;i<q.length();i++)
        {
            if(q[i]=='(')
            {
                st.push("(");
                wq+="(";
            }
            else if(q[i]==')')
            {
                st.pop();
                wq+=")";
                if(st.empty()) break;
            }
            else
            wq+=q[i];
        
        }
        string z=p.substr(0,p.find("/"));
        if(z.compare(wq)==0)
        return true;
        return false;
    }
    else
    {
        string ab=q.substr(1,q.find("^")-1);
        string z=p.substr(0,p.find("/"));
        if(z.compare(ab)==0)
        return true;
    }
    return false;
}

/*
//Following function checks if the And Eli 2 is Done right or not it has variables of array of string, inputed value and line number on which the rule is implemented
*/

bool andEli2(string str[],string p,int pos)
{
    string q=str[pos-1];
    //stack to get the elements before ^
    stack<string> st;
    string wq;
    int count=0;
    for(int i=1;i<q.length();i++)
    {
        if(q[i]=='(')
        count+=1;
    }
    if(count>1)
    {   int cp=0;
        for(int i=1;i<q.length();i++)
        {
            if(q[i]=='(')
            {
                st.push("(");
                wq+="(";
                cp++;
            }
            else if(q[i]==')')
            {
                st.pop();
                wq+=")";
                cp++;
                if(st.empty()) break;
            }
            else
            {
             wq+=q[i];
             cp++;
            }
        
        }
        int y=q.length()-wq.length()-3;
        string x=q.substr(cp+2,y);
        string z=p.substr(0,p.find("/"));
        if(z.compare(x)==0)
        return true;
    }
    else
    {
        string ab=q.substr(q.find("^")+1,q.length()-wq.length()-4);
        string z=p.substr(0,p.find("/"));
        if(z.compare(ab)==0)
        return true;
    }
    return false;
}

/*
//Following function checks if the Or Intro 1 is Done right or not it has variables of array of string, inputed value and line number on which the rule is implemented
*/

bool orIntro1(string str[],string p,int pos)
{
    string q=str[pos-1];
    q="("+q+"v";
    bool f=true;
    for(int i=0;i<q.length();i++)
    {
        if(q[i]!=p[i])
        {
            f=false;
            break;
        }
    }
    if(f==false) return false;
    return true;
    
}

/*
//Following function checks if the And Or Intro 2 is Done right or not it has variables of array of string, inputed value and line number on which the rule is implemented
*/

bool orIntro2(string str[],string p,int pos)
{   string q=str[pos-1];
    q="v"+q+")";
    int index=p.find("/");
    int c=q.length()-1;
    for(int i=index-1;i>=index-q.length();i--)
    {   
         if(q[c]!=p[i])
        {
            return false;
        }
        c--;
    }
    return true;
}

/*
//Following function checks if the Imp Eli is Done right or not it has variables of array of string, inputed value and line numbers on which the rule is implemented
*/

bool implEli(string str[],string p,int pos1,int pos2)
{
    string q1=str[pos1-1];
    string q2=str[pos2-1];
    q1="("+q1+">";
    bool f=true;
    
    for(int i=0;i<q1.length();i++)
    {   
        if(q1[i]!=q2[i])
        {
            f=false;
            break;
        }
    }
    if(f==false)
    return false;
    string wq="";
    for(int i=q1.length();i<q2.length()-1;i++)
    {
        wq+=q2[i];
    }
    string z=p.substr(0,p.find("/"));

    if(z.compare(wq)==0)
    return true;
    return false;
}

/*
//Following function checks if the Modus Tollens is Done right or not it has variables of array of string, inputed value and line numbers on which the rule is implemented
*/

bool modusTollens(string str[],string p,int pos1,int pos2)
{
     string q1=str[pos1-1];
     string q2=str[pos2-1];
     int c2=0;
     bool flag=true;
     int counter=q1.length()-1;
     int pp=0;

     for(int i=0;i<q2.length();i++)
     {  if(q2[i]=='~')
         c2++;
     }
     if(c2==2)
     {  
         for(int i=q2.length()-1;i>=2;i--)
        {    cout<<q1[counter]<<"  "<<q2[i]<<endl;
             if(q1[counter]!=q2[i])
             {
                 flag=false;
                 break;
             }
             counter--;
        }
        if(flag==false)
        return false;
     }
     else if(c2==1)
    {       
            for(int i=2;i<q2.length()-1;i++)
            {  
                 pp++;
            }
            if(pp>1)
            q2+=")";
            
         
         for(int i=q2.length()-1;i>=2;i--)
        {    if(q1[counter]!=q2[i])
             {
                 flag=false;
                 break;
             }
             counter--;
        }
        if(flag==false) return false;
        if(pp>1) counter--;
        if(q1[counter]!='>') return false;
     }
    else if(c2==0)
    { return false;
    }
    else
    return false;
    stack<string> st;
    string wq;
    int count=0;
    for(int i=0;i<q1.length();i++)
    {
        if(q1[i]=='(')
        count+=1;
    }
    if(count>1)
    {   for(int i=1;i<q1.length();i++)
        {
            if(q1[i]=='(')
            {
                st.push("(");
                wq+="(";
            }
            else if(q1[i]==')')
            {
                st.pop();
                wq+=")";
                if(st.empty()) break;
            }
            else
            wq+=q1[i];
        
        }
        wq="~"+wq;
           
        string z=p.substr(0,p.find("/"));
        
        if(z.compare(wq)==0)
        return true;
        return false;
    }
    return true;
}

/*
// For running the code
*/
int main()
{   //For getting the number of lines
    
    cout<<"Enter the line you wish the proof to have"<<endl;
    int n=0;
    cin>>n;
    //for storing each of the lines
    
    string a[n];
    cout<<"Enter the proof"<<endl;
    bool flag=true;
    for(int i=0;i<n;i++)
    {   //for in putting the lines (one by one)
        
        string w="";
        cin>>w;
        if(w.find("P")<100)
        {
            a[i]+=w.substr(0,w.find("/"));
        }
        else if(w.find("^i")<100)
        {
            string s1;
            string s2;
            //for finding the number of lines
            
            s1+=w[w.find("^i")+3];
            int c1=stoi(s1);
            s2+=w[w.find("^i")+5];
            int c2=stoi(s2);
            flag=andIntro(a,w,c1,c2);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
        else if(w.find("^e1")<100)
        {
            string s1;
            s1+=w[w.find("^e1")+4];
            //for finding the number of lines
            
            int c1=stoi(s1);
            flag=andEli1(a,w,c1);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
        else if(w.find("^e2")<100)
        {
            string s1;
            s1+=w[w.find("^e2")+4];
            //for finding the number of lines
            int c1=stoi(s1);
            flag=andEli2(a,w,c1);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
         else if(w.find("vi1")<100)
        {
            string s1;
            s1+=w[w.find("vi1")+4];
            //for finding the number of lines
            int c1=stoi(s1);
            flag=orIntro1(a,w,c1);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
        else if(w.find("vi2")<100)
        {
            string s1;
            s1+=w[w.find("vi2")+4];
            //for finding the number of lines
            int c1=stoi(s1);
            flag=orIntro2(a,w,c1);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
         else if(w.find(">e")<100)
        {
            string s1;
            string s2;
            //for finding the number of lines
            s1+=w[w.find(">e")+3];
            int c1=stoi(s1);
            s2+=w[w.find(">e")+5];
            int c2=stoi(s2);
            flag=implEli(a,w,c2,c1);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
         else if(w.find("MT")<100)
        {
            string s1;
            string s2;
            //for finding the number of lines
            s1+=w[w.find("MT")+3];
            int c1=stoi(s1);
            s2+=w[w.find("MT")+5];
            int c2=stoi(s2);
            flag=modusTollens(a,w,c1,c2);
            if(flag==false) break;
            a[i]+=w.substr(0,w.find("/"));
        }
        else
        {   // incase the input is wrong(have no rule and isn't a premise)
            
             cout<<"Your input is invalid we'll terminate the program here."<<endl;
            flag=false;
            break;
        }
    }
    if(flag) cout <<"Valid";
    else cout << "Invalid";
    return 0;
}


