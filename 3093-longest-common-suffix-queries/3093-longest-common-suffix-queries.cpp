class Solution {
public:
    struct Trie{
        unordered_map<char,Trie*> arr;
        int idx;
        Trie(){
            idx=-1;
        }
        ~Trie(){
            for(auto &p : arr){
                if(p.second != NULL) delete p.second;
            }
        }
    };
    void update(Trie* root,vector<string>& wordsContainer,int i){
        if(root->idx==-1) root->idx=i;
        else{
            if(wordsContainer[root->idx].size()>wordsContainer[i].size())       root->idx=i;
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans(wordsQuery.size());
        Trie * root = new Trie();
        for(int i=0;i<wordsContainer.size();i++){
            Trie* node = root;
            update(node,wordsContainer,i);
            for(int j=wordsContainer[i].size()-1;j>=0;j--){
                int a = wordsContainer[i][j];
                if(node->arr.find(a)==node->arr.end())
                    node->arr[a] = new Trie();
                node = node->arr[a];
                update(node,wordsContainer,i);
            }
        }
        for(int i=0;i<wordsQuery.size();i++){
            Trie * node = root;
            for(int j = wordsQuery[i].size()-1;j>=0;j--){
                int a = wordsQuery[i][j];
                if(node->arr.find(a)==node->arr.end()) break;
                node = node->arr[a];
            }
            ans[i] = node->idx;
        }
        delete root;
        return ans;
    }
};