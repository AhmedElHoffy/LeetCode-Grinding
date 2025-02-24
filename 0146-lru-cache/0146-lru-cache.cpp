class LRUCache {
private:
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    int Max_Capacity;
    unordered_map<int, Node*> HashMap;
    Node* LRU;  // Least Recently Used (head)
    Node* MRU;  // Most Recently Used (tail)

    void Add_New_Node(Node* newNode) {
        if (!LRU) {
            LRU = MRU = newNode;
        } else {
            MRU->next = newNode;
            newNode->prev = MRU;
            MRU = newNode;
        }
    }

    void Delete_Node(Node* DelNode) {
        if (!DelNode) return;

        if (DelNode == LRU && DelNode == MRU) {  // Only one node
            LRU = MRU = nullptr;
        } else if (DelNode == LRU) {  // Remove LRU
            LRU = LRU->next;
            LRU->prev = nullptr;
        } else if (DelNode == MRU) {  // Remove MRU
            MRU = MRU->prev;
            MRU->next = nullptr;
        } else {  // Middle node
            DelNode->prev->next = DelNode->next;
            if (DelNode->next) {
                DelNode->next->prev = DelNode->prev;
            }
        }

        HashMap.erase(DelNode->key);
        delete DelNode;
    }

    void Move_to_MRU(Node* Curr_Node) {
        if (Curr_Node == MRU) return;  // Already MRU, no need to move

        // Remove from current position
        if (Curr_Node == LRU) {
            LRU = LRU->next;
            if (LRU) LRU->prev = nullptr;
        } else {
            Curr_Node->prev->next = Curr_Node->next;
            if (Curr_Node->next) {
                Curr_Node->next->prev = Curr_Node->prev;
            }
        }

        // Attach at MRU position
        Curr_Node->next = nullptr;
        Curr_Node->prev = MRU;
        if (MRU) MRU->next = Curr_Node;
        MRU = Curr_Node;
    }

public:
    LRUCache(int capacity) {
        Max_Capacity = capacity;
        LRU = MRU = nullptr;
    }

    int get(int key) {
        if (HashMap.find(key) != HashMap.end()) {
            Move_to_MRU(HashMap[key]);
            return HashMap[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (HashMap.find(key) != HashMap.end()) {
            // Update value and move to MRU
            HashMap[key]->val = value;
            Move_to_MRU(HashMap[key]);
        } else {
            Node* newNode = new Node(key, value);
            HashMap[key] = newNode;
            Add_New_Node(newNode);

            if (HashMap.size() > Max_Capacity) {
                Delete_Node(LRU);  // Remove LRU when capacity is exceeded
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