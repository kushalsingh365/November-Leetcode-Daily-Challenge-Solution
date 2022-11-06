class Trie{
  
  public:
  bool isWordEnd;
  vector<Trie*> children;
    
     Trie(){
          isWordEnd=false;
          children.assign(26,NULL);
      }

    void insert(string &s){
        Trie* curr=this;
        
        for(auto &x:s){
            
            x-='a';
            if(!curr->children[x]){
                curr->children[x]=new Trie();
            }
            
            curr=curr->children[x];
        }
        
        curr->isWordEnd=true;
    }
    
};

class Solution {
    
    unordered_set<string> ans;
    vector<vector<bool>> visited;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        ///*** insert in the Tries
        Trie * root=new Trie();
        for(auto &x:words){
            root->insert(x);
        }
        
        int n=board.size(),m=board[0].size();
        
        vector<vector<char>> newBoard(n+2,vector<char>(m+2,'0'));
        //*** creating new board to handle corner case
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newBoard[i+1][j+1]=board[i][j];        
            }
        }
        n+=2;m+=2;
        visited.assign(n,vector<bool>(m,false));
        
        for(int i=1;i<n-1;i++){
            
            for(int j=1;j<m-1;j++){
                string res="";
                getWords(i,j,n,m,res,root,newBoard);
            }
            cout<<endl;
        }
        
        vector<string> res;
        for(auto it=ans.begin();it!=ans.end();it++){
            res.push_back(*it);
        }
        return res;
    }
    
    void getWords(int i,int j,int n,int m,string &res,Trie *root,vector<vector<char>> &board){
        //**BASE CASE
        if(i==0 or j==0 or i==n-1 or j==m-1) return;
        if(!root) return;
        if(visited[i][j]) return;
        
        char letter=board[i][j];
        if(!root->children[letter-'a']) return;
        
        root=root->children[letter-'a'];
        res+=letter;
        
        if(root->isWordEnd)  ans.insert(res);
        
        visited[i][j]=true;
        //** [i][j+1] [i][j-1]  *** Horizontal neighbours
            getWords(i,j+1,n,m,res,root,board);
            getWords(i,j-1,n,m,res,root,board);
       
        //** [i+1][j]  [i-1][j] **** vertical neighbpurs
            getWords(i-1,j,n,m,res,root,board);
            getWords(i+1,j,n,m,res,root,board);
        
        res.pop_back();
        visited[i][j]=false;
    }
};
