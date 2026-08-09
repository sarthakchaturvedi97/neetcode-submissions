class LRUCache {
public:
    class Node{
        public:
        int key, value;
        Node *next, *prev;
        Node(int k, int val)
        {
            key = k;
            value = val;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache()
    {
        Node *curr = head;
        while(curr)
        {
            Node *nxt = curr->next;
            delete(curr);
            curr = nxt;
        }
    }

    void add(Node* root)
    {
        Node* nxt = head->next;
        head->next = root;
        root->prev = head;
        root->next = nxt;
        nxt->prev = root;
        return;
    }

    void remove(Node* root)
    {
        Node *nxt = root->next;
        Node *pr = root->prev;
        pr->next = nxt;
        nxt->prev = pr;
        return;   
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node *existing = mp[key];
            remove(existing);
            add(existing);
            return existing->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *deleteNode = mp[key];
            remove(mp[key]);
            mp.erase(key);
            delete(deleteNode);
        }

        if(mp.size() == cap)
        {
            Node *deleteNode = tail->prev;
            mp.erase(deleteNode->key);
            remove(deleteNode);
            delete(deleteNode);
        }
        
        Node *newNode = new Node(key,value);
        add(newNode);
        mp[key] = newNode;
        return;
    }
};
