class MovingAverage {
public:
    queue<int>Q;
    double Curr_Sum=0;
    int Max_Size;
    MovingAverage(int Size) {
     Max_Size = Size;    
    }
    
    double next(int Val) {
        if(Q.empty()){
            Q.push(Val);
            
        }else{
            if(Q.size() < Max_Size){
                Q.push(Val);
                
            }else{
                Curr_Sum-=Q.front();
                Q.pop();
                Q.push(Val);
                
            }
        }
        Curr_Sum+=Val;
        return Curr_Sum/Q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */



 



/*

    // Optimized Approach 

    private:
    int Capacity;
    queue<int> Window_Q;
    double RunningSum;

public:
    MovingAverage(int size) {
        Capacity = size;
        RunningSum = 0.0;
    }

    double next(int val) {
        if (Window_Q.size() == Capacity) {
            // Subtract the oldest value from the running sum
            RunningSum -= Window_Q.front();
            Window_Q.pop();
        }

        // Add the new value to the running sum
        RunningSum += val;
        Window_Q.push(val);

        // Calculate the average
        return RunningSum / Window_Q.size();
    }

*/


//My Approach

/*
private:
    int Capacity;

    struct Node_Q{
        int item;
        Node_Q* next;
    };
    Node_Q *front,*back;

    void RemoveItem(){
        Node_Q* temp = front;
        front = front->next;
        delete temp;
    }

    void AddItem(int value){
        Node_Q *newNode = new Node_Q(value);
        if(!front){
            front = back = newNode;
            front->next=back->next = nullptr;
        }else{
            back->next=newNode;
            newNode->next = nullptr;
            back = newNode;
        }
    }
    double Average(){
        Node_Q* Curr= front;
        double Sum=0;
        while(Curr){
            Sum+= Curr->item;
            Curr = Curr->next;
        }
        return Sum/CountNodes();
    }
    int CountNodes(){
        int count=0;
        Node_Q* Curr= front;
        while(Curr){
           count++;
            Curr = Curr->next;
        }
        return count;
    }
    
public:
    // Constructor
    MovingAverage(int size) {
        Capacity = size;
        front = back = nullptr;
    }
    
    double next(int val) {
            AddItem(val);

            if(CountNodes() <= Capacity){
                return Average();
            }else{
                RemoveItem();
                return Average();
            }
    }
    */