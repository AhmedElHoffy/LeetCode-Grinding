class LRUCache {
private:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;
    };

    int Size;
    unordered_map<int,Node*>HashMap;
    Node *LRU,*MRU;

    void AddNodeToTail(Node* newNode){
        if(!MRU){//List is Empty
            LRU = MRU = newNode;
        }else{
            MRU->next = newNode;
            newNode->prev = MRU;
            MRU = newNode;
        }
    }

    void RemoveNode(Node* DelNode){
        
        if(DelNode->prev){
            DelNode->prev->next = DelNode->next;
        }else{
            // Node is the Head (LRU)
            LRU = DelNode->next;
        }

        if(DelNode->next){
            DelNode->next->prev = DelNode->prev;
        }else{
            // Node is the Tail (MRU);
            MRU = DelNode->prev;
        }
        DelNode->prev = DelNode->next = nullptr;

    }

    // Move to MRU  (Tail)

    void MoveNode_To_Tail(Node* Curr_Node){
        RemoveNode(Curr_Node);
        AddNodeToTail(Curr_Node);
    }

public:
    //Constructor
    LRUCache(int capacity) {
        Size = capacity;
        LRU = MRU = nullptr;
    }
    
    int get(int key) {
        if(HashMap.find(key)==HashMap.end()){
            return -1;
        }
        // Key found, therefore :  needs to be moved to 
        //MRU Position(tail where new nodes are inserted) and return its value
        Node* temp = HashMap[key];
        MoveNode_To_Tail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        // if Key exists in the cashe
        if(HashMap.find(key)!=HashMap.end()){
            Node* temp = HashMap[key];
            temp->val = value;
            MoveNode_To_Tail(temp);
        }else{
            // Create new node for key-val Pair
            Node* newNode = new Node(key,value);
            HashMap[key] = newNode;
            AddNodeToTail(newNode);

            // Check if the Cahce Exceeds its Capacity, evict the LRU Node
            if(HashMap.size() > Size ){
                Node* Del_LRU_Node = LRU;
                RemoveNode(Del_LRU_Node);
                HashMap.erase(Del_LRU_Node->key);
                delete Del_LRU_Node;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




 /*

class LRUCache {
private:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;
    };

    int Size;
    unordered_map<int,Node*>HashMap;
    Node *LRU,*MRU;

    void AddNodeToTail(Node* newNode){
        if(!MRU){//List is Empty
            LRU = MRU = newNode;
        }else{
            MRU->next = newNode;
            newNode->prev = MRU;
            MRU = newNode;
        }
    }

    void RemoveNode(Node* DelNode){
        
        if(DelNode->prev){
            DelNode->prev->next = DelNode->next;
        }else{
            // Node is the Head (LRU)
            LRU = DelNode->next;
        }

        if(DelNode->next){
            DelNode->next->prev = DelNode->prev;
        }else{
            // Node is the Tail (MRU);
            MRU = DelNode->prev;
        }
        DelNode->prev = DelNode->next = nullptr;

    }

    // Move to MRU  (Tail)

    void MoveNode_To_Tail(Node* Curr_Node){
        RemoveNode(Curr_Node);
        AddNodeToTail(Curr_Node);
    }

public:
    //Constructor
    LRUCache(int capacity) {
        Size = capacity;
        LRU = MRU = nullptr;
    }
    
    int get(int key) {
        if(HashMap.find(key)==HashMap.end()){
            return -1;
        }
        // Key found, therefore :  needs to be moved to 
        //MRU Position(tail where new nodes are inserted) and return its value
        Node* temp = HashMap[key];
        MoveNode_To_Tail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        // if Key exists in the cashe
        if(HashMap.find(key)!=HashMap.end()){
            Node* temp = HashMap[key];
            temp->val = value;
            MoveNode_To_Tail(temp);
        }else{
            // Create new node for key-val Pair
            Node* newNode = new Node(key,value);
            HashMap[key] = newNode;
            AddNodeToTail(newNode);

            // Check if the Cahce Exceeds its Capacity, evict the LRU Node
            if(HashMap.size() > Size ){
                Node* Del_LRU_Node = LRU;
                RemoveNode(Del_LRU_Node);
                HashMap.erase(Del_LRU_Node->key);
                delete Del_LRU_Node;
            }
        }
        
    }
};
 */