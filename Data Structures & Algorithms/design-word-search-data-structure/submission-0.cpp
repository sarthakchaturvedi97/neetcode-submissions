class Node{
    public:
    Node *child[26];
    bool isWordEnding;
    Node(){
        isWordEnding = false;
        for(auto &ch:child)
        ch = NULL;
    }
};
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *temp = root;
        for(char &ch:word)
        {
            int element = ch - 'a';
            if(!temp->child[element])
            temp->child[element] = new Node();
            temp = temp->child[element];
        }
        temp->isWordEnding = true;
        return;
    }
    bool searchHelper(string word, int index, Node *root)
    {
        if(!root)
        return false;

        if(index == word.length())
        return root->isWordEnding;

        char ch = word[index];

        if(ch == '.')
        {
            for(int c = 0;c<26; c++)
            {
                if(root->child[c] && searchHelper(word,index+1,root->child[c]))
                return true;
            }
            return false;
        }
        else
        {
            int element = ch - 'a';
            if(!root->child[element])
            return false;

            return searchHelper(word,index+1,root->child[element]);
        }
    }
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};
