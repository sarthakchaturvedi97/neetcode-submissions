class Node{
    public:
    Node* child[26];
    bool isWordEnding;
    Node()
    {
        isWordEnding = false;
        for(auto &ch: child)
        ch = NULL;
    }
};
class PrefixTree {
public:
    Node *root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char &ch: word)
        {
            int element = ch - 'a';
            if(!temp->child[element])
            temp->child[element] = new Node();
            temp = temp->child[element];
        }
        temp->isWordEnding = true;
        return;
    }
    
    bool search(string word, bool isPrefix = false) {
        Node* temp = root;
        for(char &ch: word)
        {
            int element = ch - 'a';
            if(!temp->child[element])
            return false;
            temp = temp->child[element];
        }

        if(!isPrefix)
        return temp->isWordEnding;

        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};
