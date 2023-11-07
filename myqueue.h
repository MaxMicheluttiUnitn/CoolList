#ifndef __MY_QUEUE_H__
#define __MY_QUEUE_H__
#endif
using namespace std;
#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <utility>

class UnreachableException{
    string msg;
    
    public:
    UnreachableException(string msg){
        this->msg=msg;
    }
};

class ItemNotFoundException{
    string msg;
    
    public:
    ItemNotFoundException(string msg){
        this->msg=msg;
    }
};

class IndexOutOfBoundsException{
    string msg;
    
    public:
    IndexOutOfBoundsException(string msg){
        this->msg=msg;
    }
};

class NullPointerDerefException{
    string msg;
    
    public:
    NullPointerDerefException(string msg){
        this->msg=msg;
    }
};

class EmptyListRemovalexception{
    string msg;
    
    public:
    EmptyListRemovalexception(string msg){
        this->msg=msg;
    }
};

template <typename T> class CoolList;
template <typename T> class CoolNode;
template <typename T> ostream & operator<<(ostream& os,CoolList<T> const & list);
template <typename T> ostream & operator<<(ostream& os,CoolNode<T> const & node);
template <typename T> ostream & operator<<(ostream& os, CoolList<CoolList<T>*> const & list);

template <typename T> class CoolIter{
    private:CoolNode<T>* current;

    public:
    CoolIter(){
        current == nullptr;
    }

    CoolIter(CoolNode<T>* begin){
        current = begin;
    }

    ~CoolIter(){}

    CoolIter<T>& operator++(){
        if(current == nullptr){
            throw NullPointerDerefException("CoolIter++");
        }
        current = current->getNext();
        return *this;
    }

    CoolIter<T>& operator++(int){
        if(current == nullptr){
            throw NullPointerDerefException("++CoolIter");
        }
        current = current->getNext();
        return *this;
    }

    friend bool operator==(CoolIter<T>const& a,CoolIter<T>const& b){
        return a.current==b.current;
    }

    friend bool operator!=(CoolIter<T>const& a,CoolIter<T>const& b){
        return a.current!=b.current;
    }

    T& operator*(){
        return this->current->getContentReference();
    }
};

template <typename T> class CoolIterConst{
    private:CoolNode<T>* current;

    public:
    CoolIterConst(){
        current == nullptr;
    }

    CoolIterConst(CoolNode<T>* begin){
        current = begin;
    }

    ~CoolIterConst(){}

    CoolIterConst<T>& operator++(){
        if(current == nullptr){
            throw NullPointerDerefException("CoolIterConst++");
        }
        current = current->getNext();
        return *this;
    }

    CoolIterConst<T>& operator++(int){
        if(current == nullptr){
            throw NullPointerDerefException("++CoolIterConst");
        }
        current = current->getNext();
        return *this;
    }

    friend bool operator==(CoolIterConst<T>const& a,CoolIterConst<T>const& b){
        return a.current==b.current;
    }

    friend bool operator!=(CoolIterConst<T>const& a,CoolIterConst<T>const& b){
        return a.current!=b.current;
    }

    T operator*(){
        return this->current->getContent();
    }
};

template <typename T> class CoolIterReverse{
    private:CoolNode<T>* current;

    public:
    CoolIterReverse(){
        current == nullptr;
    }

    CoolIterReverse(CoolNode<T>* begin){
        current = begin;
    }

    ~CoolIterReverse(){}

    CoolIterReverse<T>& operator++(){
        if(current == nullptr){
            throw NullPointerDerefException("CoolIterReverse++");
        }
        current = current->getPrevious();
        return *this;
    }

    CoolIterReverse<T>& operator++(int){
        if(current == nullptr){
            throw NullPointerDerefException("++CoolIterReverse");
        }
        current = current->getPrevious();
        return *this;
    }

    friend bool operator==(CoolIterReverse<T>const& a,CoolIterReverse<T>const& b){
        return a.current==b.current;
    }

    friend bool operator!=(CoolIterReverse<T>const& a,CoolIterReverse<T>const& b){
        return a.current!=b.current;
    }

    T& operator*(){
        return this->current->getContentReference();
    }
};

template <typename T> class CoolIterConstReverse{
    private:CoolNode<T>* current;

    public:
    CoolIterConstReverse(){
        current == nullptr;
    }

    CoolIterConstReverse(CoolNode<T>* begin){
        current = begin;
    }

    ~CoolIterConstReverse(){}

    CoolIterConstReverse<T>& operator++(){
        if(current == nullptr){
            throw NullPointerDerefException("CoolIterConstReverse++");
        }
        current = current->getPrevious();
        return *this;
    }

    CoolIterConstReverse<T>& operator++(int){
        if(current == nullptr){
            throw NullPointerDerefException("++CoolIterConstReverse");
        }
        current = current->getPrevious();
        return *this;
    }

    friend bool operator==(CoolIterConstReverse<T>const& a,CoolIterConstReverse<T>const& b){
        return a.current==b.current;
    }

    friend bool operator!=(CoolIterConstReverse<T>const& a,CoolIterConstReverse<T>const& b){
        return a.current!=b.current;
    }

    T operator*(){
        return this->current->getContent();
    }
};

template <typename T> class CoolNode{
    private: T content;
    private: CoolNode<T>* next;
    private: CoolNode<T>* previous;

    public:
    CoolNode(T content){
        this->content = content;
        this->next = nullptr;
        this->previous = nullptr;
    }

    CoolNode(T content,CoolNode<T>* previous,CoolNode<T>* next){
        this->content = content;
        this->next = next;
        this->previous = previous;
    }

    CoolNode(const CoolNode<T>& node){
        this->content = node.content;
        this->next = node.next;
        this->previous = node.previous;
    }

    ~CoolNode(){}

    T getContent()const{
        return this->content;
    }

    T& getContentReference(){
        return (this->content);
    }

    void setNext(CoolNode<T>* next){
        this->next = next;
    }

    void setPrevious(CoolNode<T>* previous){
        this->previous = previous;
    }

    void swapPointers(){
        CoolNode<T>* temp=this->next;
        this->next = this->previous;
        this->previous = temp;
    }

    CoolNode<T>* getNext()const{
        return this->next;
    }

    CoolNode<T>* getPrevious()const{
        return this->previous;
    }

    friend ostream& operator<< <>(ostream& os, CoolNode<T> const & node);

    friend bool operator==(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()==n2.getContent();
    }

    friend bool operator!=(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()!=n2.getContent();
    }

    friend bool operator>(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()>n2.getContent();
    }

    friend bool operator>=(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()>=n2.getContent();
    }

    friend bool operator<(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()<n2.getContent();
    }

    friend bool operator<=(CoolNode<T> const & n1,CoolNode<T> const & n2){
        return n1.getContent()<=n2.getContent();
    }
};

template <typename T> class CoolList{
    private: CoolNode<T>* head;
    private: CoolNode<T>* tail;
    private: int length;

    private:
    /**
     * Dequeues a node
    */
    CoolNode<T>* dequeueNode(){
        if (this->isEmpty()){
            throw EmptyListRemovalexception("dequeue Node");
        }
        CoolNode<T>* temp = this->head;
        this->head = temp->getNext();
        temp->setNext(nullptr);
        temp->setPrevious(nullptr);
        if(this->head == nullptr){
            this->tail = nullptr;
            this->length = 0;
            return temp;
        }
        this->head->setPrevious(nullptr);
        this->length -= 1;
        return temp;
    }

    /**
     * Enqueues a node
    */
    void enqueueNode(CoolNode<T>* item){
        CoolNode<T> * node = item;
        this->length += 1;
        if(this->head == nullptr){
            this->head = node;
            this->tail = node;
        }else{
            this->tail->setNext(node);
            node->setPrevious(this->tail);
            this->tail = node;
        }
    }

    /**
     * Returns a node at the given index.
    */
    CoolNode<T>* getNode(int index)const{
        if((index<0)||(index>=this->getLength()))
            throw IndexOutOfBoundsException("get Node");
        CoolNode<T>* temp = this->head;
        for(int i = 0; temp != nullptr; i++){
            if(i==index){
                return temp;
            }
            temp = temp->getNext();
        }
        throw UnreachableException("get Node");
    }

    /**
     * Swaps two nodes in the list
    */
    void swapNodes(int id1,int id2){
        if(id1==id2){
            return;
        }
        CoolNode<T>* n1=getNode(id1);
        CoolNode<T>* n2=getNode(id2);
        CoolNode<T>* prev1 = n1->getPrevious();
        CoolNode<T>* next1 = n1->getNext();
        CoolNode<T>* prev2 = n2->getPrevious();
        CoolNode<T>* next2 = n2->getNext();
        if(prev1!=nullptr){
            prev1->setNext(n2);
        }
        if(next1!=nullptr){
            next1->setPrevious(n2);
        }
        if(prev2!=nullptr){
            prev2->setNext(n1);
        }
        if(next2!=nullptr){
            next2->setPrevious(n1);
        }
        if(next2==n1){
            n1->setNext(n2);
        }else{
            n1->setNext(next2);
        }
        if(prev2==n1){
            n1->setPrevious(n2);
        }else{
            n1->setPrevious(prev2);
        }
        if(next1!=n2){
            n2->setNext(next1);
        }else{
            n2->setNext(n1);
        }
        if(n2==prev1){
            n2->setPrevious(n1);
        }else{
            n2->setPrevious(prev1); 
        }
        if(this->head==n1){
            this->head=n2;
        }else if(this->head==n2){
            this->head=n1;
        }
        if(this->tail==n1){
            this->tail=n2;
        }else if(this->tail==n2){
            this->tail=n1;
        }
    }

    public:
    CoolList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    CoolList(const CoolList& list){
        this->head = nullptr;
        this->tail = nullptr;
        CoolNode<T>* prev = nullptr;
        this->length = list.getLength();
        for(int i=0;i<this->length;i++){
            T item = list.get(i);
            CoolNode<T>* new_node = new CoolNode(item);
            if(prev == nullptr){
                this->head = new_node;
            }else{
                prev->setNext(new_node);
                new_node->setPrevious(prev);
            }
            prev = new_node;
        }
        this->tail = prev;
    }

    ~CoolList(){
        this->tail = nullptr;
        while(this->head != nullptr){
            CoolNode<T>* temp = this->head;
            this->head = this->head->getNext();
            delete temp;
        }
    }

    CoolList<T>& operator=(const CoolList& list){
        this.head = list.head;
        this.tail = list.tail;
        this.length = list.length;
        return *this;
    }

    CoolList<T>& operator=(CoolList&& list){
        this.head = list.head;
        this.tail = list.tail;
        this.length = list.length;
        list.head = nullptr;
        list.tail = nullptr;
        return *this;
    }

    /**
     * Sort the list
    */
    void sort(){
        multimap<T,CoolNode<T>*> m = multimap<T,CoolNode<T>*>();
        while(!this->isEmpty()){
            CoolNode<T> * temp = this->dequeueNode();
            m.insert(pair<T,CoolNode<T>*>(temp->getContent(),temp));
        }
        for(auto it = m.begin();it != m.end(); it++){
            this->enqueueNode(it->second);
        }
    }

    /**
     * returns a list that is the same as the initial one, but sorted, without modifying the original list
    */
    CoolList<T> getSorted(){
        CoolList<T> res = CoolList(*this);
        res.sort();
        return res;
    }

    /**
     * returns a pointer to a list that is the same as the initial one, but sorted, without modifying the original list
    */
    CoolList<T>* getSortedHeap(){
        auto res = new CoolList(*this);
        res->sort();
        return res;
    }

    /**
     * Reverse the list
    */
    void reverse(){
        CoolNode<T>* temp=this->head;
        while(temp!=nullptr){
            temp->swapPointers();
            temp = temp->getPrevious();
        }
        temp = this->head;
        this->head = this->tail;
        this->tail = temp;
    }

    /**
     * Returns a list that is the same as the initial one, but reversed, without modifying the original list
    */
    CoolList<T> getReversed(){
        auto res = CoolList(*this);
        res.reverse();
        return res;
    }

    /**
     * Returns a pointer to a list that is the same as the initial one, but reversed, without modifying the original list
    */
    CoolList<T>* getReversedHeap(){
        auto res = new CoolList(*this);
        res->reverse();
        return res;
    }

    /**
     * Shuffle the list randomly
    */
    void shuffle(){
        this->shuffle((unsigned)time(NULL));
    }

    /**
     * Shuffle the list randomly given the seed
    */
    void shuffle(unsigned int seed){
        srand(seed);
        int len = this->getLength();
        for(int index=0;index<len-1;index++){
            int n;
            int size = len - index;
            while( ( n = rand() ) > RAND_MAX - (RAND_MAX-size+1)%size ){}
            n=n%size + index;
            cout.flush();
            this->swapNodes(index,n);
        }
    }

    /**
     * Returns a list that is the same as the initial one, but shuffled, without modifying the original list
    */
    CoolList<T> getShuffled(){
        auto res = CoolList(*this);
        res.shuffle();
        return res;
    }

    /**
     * Returns a list that is the same as the initial one, but shuffled given the seed, without modifying the original list
    */
    CoolList<T> getShuffled(unsigned int seed){
        auto res = CoolList(*this);
        res.shuffle(seed);
        return res;
    }

    /**
     * Returns a pointer to a list that is the same as the initial one, but shuffled, without modifying the original list
    */
    CoolList<T>* getShuffledHeap(){
        auto res = new CoolList(*this);
        res->shuffle();
        return res;
    }

    /**
     * Returns a pointer to a list that is the same as the initial one, but shuffled given the seed, without modifying the original list
    */
    CoolList<T>* getShuffledHeap(unsigned int seed){
        auto res = new CoolList(*this);
        res->shuffle(seed);
        return res;
    }

    /**
     * Returns an item at the given index
    */
    T get(int index)const{
        if((index<0)||(index>=this->getLength()))
            throw IndexOutOfBoundsException("get");
        CoolNode<T>* temp = this->head;
        for(int i = 0; temp != nullptr; i++){
            if(i==index){
                return temp->getContent();
            }
            temp = temp->getNext();
        }
        throw UnreachableException("get");
    }

    /**
     * Returns a reference to the item at the given index
    */
    T& getReference(int index){
        if((index<0)||(index>=this->getLength()))
            throw IndexOutOfBoundsException("get reference");
        CoolNode<T>* temp = this->head;
        for(int i = 0; temp != nullptr; i++){
            if(i==index){
                return temp->getContentReference();
            }
            temp = temp->getNext();
        }
        throw UnreachableException("get reference");
    }

    /**
     * Add an element to the end of the list
    */
    bool enqueue(T item){
        CoolNode<T> * node = new CoolNode<T>(item);
        if(this->head == nullptr){
            this->head = node;
            this->tail = node;
            node->setPrevious(nullptr);
            node->setNext(nullptr);
        }else{
            this->tail->setNext(node);
            node->setPrevious(this->tail);
            node->setNext(nullptr);
            this->tail = node;
        }
        this->length += 1;
        return true;
    }

    /**
     * Add an element to the end of the list
    */
    bool push(T item){
        return enqueue(item);
    }

    /**
     * Add an element to the beginning of the list
    */
    bool add_first(T item){
        CoolNode<T> * node = new CoolNode<T>(item);
        if(this->head == nullptr){
            this->head = node;
            this->tail = node;
        }else{
            this->head->setPrevious(node);
            node->setNext(this->head);
            this->head = node;
        }
        this -> length += 1;
        return true;
    }

    /**
     * Add an element at the specified index of the list
    */
    bool add(T item,int index){
        if((index<0)||(index>this->getLength()))
            return false;
        CoolNode<T> * new_node = new CoolNode<T>(item);
        if(index == this->getLength()){
            new_node->setPrevious(this->tail);
            this->tail->setNext(new_node);
            this->tail = new_node;
            this->length+=1;
            return true;
        }else if(index == 0){
            new_node->setNext(this->head);
            this->head->setPrevious(new_node);
            this->head = new_node;
            this->length+=1;
            return true;
        }else{
            CoolNode<T>* next = this->getNode(index);
            CoolNode<T>* prev = next->getPrevious();
            next->setPrevious(new_node);
            prev->setNext(new_node);
            new_node->setNext(next);
            new_node->setPrevious(prev);
            this->length+=1;
            return true;
        }   
    }

    /**
     * Check if the list is empty
    */
    bool isEmpty()const{
        return this->length == 0;
    }

    /**
     * Returns the length of the list
    */
    int getLength()const{
        return (this->length);
    }

    /**
     * Remove an element from the start of the list and return the element. Returns nullptr if the list is empty
    */
    T dequeue(){
        if (this->isEmpty()){
            throw EmptyListRemovalexception("dequeue");
        }
        CoolNode<T>* temp = this->head;
        T item = temp->getContent();
        this->head = temp->getNext();
        if(this->head == nullptr){
            this->tail = nullptr;
            this->length = 0;
            delete temp;
            return item;
        }
        this->head->setPrevious(nullptr);
        this->length -= 1;
        delete temp;
        return item;
    }

    /**
     * Remove an element from the end of the list and return the element. Returns nullptr if the list is empty
    */
    T pop(){
        if (this->isEmpty()){
            throw EmptyListRemovalexception("pop");
        }
        CoolNode<T>* temp = this->tail;
        T item = temp->getContent();
        this->tail = temp->getPrevious();
        if(this->tail == nullptr){
            this->head = nullptr;
            this->length = 0;
            delete temp;
            return item;
        }
        this->tail->setNext(nullptr);
        this->length -= 1;
        delete temp;
        return item;
    }

    /**
     * Removes an element at the given index
    */
    T remove_at(int index){
        if((index<0)||(index>=this->getLength()))
            throw IndexOutOfBoundsException("remove at");
        CoolNode<T>* temp = this->getNode(index);
        CoolNode<T>* prev = temp->getPrevious();
        CoolNode<T>* next = temp->getNext();
        if(temp == this->head){
            this->head = next;
        }
        if(temp == this->tail){
            this->tail = prev;
        }
        if(prev!=nullptr){
            prev->setNext(next);
        }
        if(next!=nullptr){
            next->setPrevious(prev);
        }
        T res = temp->getContent();
        this->length-=1;
        delete temp;
        return res;
    }

    /**
     * Removes the first item in the list which equals the item parameter
    */
    T remove(T item){
        if(!this->contains(item))
            throw ItemNotFoundException("remove");
        int index = this->index_of(item);
        return this->remove_at(index);
    }

    /**
     * Removes all occureences of the item in the list which equals the item parameter
    */
    T remove_all(T item){
        if(!this->contains(item))
            throw ItemNotFoundException("remove all");
        int index;
        T res;
        while((index = this->index_of(item)) != -1){
            res = this->remove_at(index);
        }
        return res;
    }

    /**
     * Concatenate the list at the end of the original one
    */
    void concat(CoolList<T> const& list){
        (*this)+=list;
    }

    /**
     * Returns an iterator to the beginning of the list
    */
    CoolIter<T> begin(){
        return CoolIter<T>(this->head);
    }

    /**
     * Returns an iterator to the end of the list
    */
    CoolIter<T> end(){
        return CoolIter<T>(nullptr);
    }

    /**
     * Returns a constant iterator to the beginning of the list
    */
    CoolIterConst<T> cbegin()const{
        return CoolIterConst<T>(this->head);
    }

    /**
     * Returns a costant iterator to the end of the list
    */
    CoolIterConst<T> cend()const{
        return CoolIterConst<T>(nullptr);
    }

    /**
     * Returns an iterator to the end of the list
    */
    CoolIterReverse<T> rbegin(){
        return CoolIterReverse<T>(this->tail);
    }

    /**
     * Returns an iterator to the beginning of the list
    */
    CoolIterReverse<T> rend(){
        return CoolIterReverse<T>(nullptr);
    }

    /**
     * Returns a constant iterator to the end of the list
    */
    CoolIterConstReverse<T> crbegin()const{
        return CoolIterConstReverse<T>(this->tail);
    }

    /**
     * Returns a costant iterator to the beginning of the list
    */
    CoolIterConstReverse<T> crend()const{
        return CoolIterConstReverse<T>(nullptr);
    }

    /**
     * Splits the list into 2 coolists at the given index
    */
    CoolList<CoolList<T>*> split_at_index(int index){
        if(index<0 || index>this->getLength()){
            throw IndexOutOfBoundsException("split at index");
        }
        CoolList<CoolList<T>*> lists = CoolList<CoolList<T>*>();
        CoolList<T>* new_list = new CoolList<T>();
        if(index==this->getLength()){
            lists.enqueue(this);
            lists.enqueue(move(new_list));
            return lists;
        }
        CoolNode<T>* split_item =this->getNode(index);
        this->length = index;
        CoolNode<T>* prev= split_item->getPrevious();
        if(prev==nullptr){
            this->head=nullptr;
            this->tail=nullptr;
        }else{
            prev->setNext(nullptr);
            this->tail=prev;
        }
        while(split_item!=nullptr){
            CoolNode<T>* next=split_item->getNext();
            new_list->enqueueNode(split_item);
            split_item = next;
        }
        lists.enqueue(this);
        lists.enqueue(move(new_list));
        return lists;
    }


    /**
     * Splits the list into multiple lists when the given item is found, removing the instances of the item.
    */
    CoolList<CoolList<T>*> split(T item){
        CoolList<T>* current_list = this;
        CoolList<CoolList<T>*> res = CoolList<CoolList<T>*>();
        res.enqueue(this);
        while(current_list->contains(item)){
            int index=current_list->index_of(item);
            CoolList<CoolList<T>*> lists = current_list->split_at_index(index);
            lists[1]->dequeue();
            current_list = lists[1];
            res.enqueue(lists[1]);
        }
        return res;
    }

    /**
     * Splits the list into multiple lists when the given item is found, removing the instances of the item, without modifying the original list
    */
    CoolList<CoolList<T>*> split_const(T item)const{
        CoolList<T>* new_list=new CoolList<T>(*this);
        return new_list->split(item);
    }

    /**
     * Splits the list into 2 coolists at the given index
    */
    CoolList<CoolList<T>*> split_at_index_const(int index)const{
        CoolList<T>* new_list=new CoolList<T>(*this);
        return new_list->split_at_index(index);
    }

    /**
     * Returns true if the list contains the specified item
    */
    bool contains(T item)const{
        for(CoolIterConst iter=this->cbegin();iter!=this->cend();iter++){
            if((*iter)==item){
                return true;
            }
        }
        return false;
    }

    /**
     * Returns the index of the first appearence of the item in the list. Returns -1 if the item is not in the list.
    */
    int index_of(T item){
        int index=0;
        for(CoolIterConst iter=this->cbegin();iter!=this->cend();iter++){
            if((*iter)==item){
                return index;
            }
            index++;
        }
        return -1;
    }

    /**
     * Returns the number of instances of the item in the list
    */
    int count_instances_of(T item)const{
        int count = 0;
        for(auto it=this->cbegin();it!=this->cend();it++){
            if((*it)==item){
                count++;
            }
        }
        return count;
    }

    /**
     * Merges a list into this list without modifying the parameter of the merge
    */
    void merge(CoolList<T>const& list){
        (*this)+=list;
    }

    /**
     * Applyes the specified function to all the elements of the list
    */
    void apply(T (*func)(T)){
        for(auto it=this->begin();it!=this->end();it++){
            (*it)=func(*it);
        }
    }

    /**
     * Applies an incrementative function to the list 
    */
    T accumulate(T (*func)(const T,const T), T init_value)const{
        for(CoolIterConst iter=this->cbegin(); iter != this->cend(); iter++){
            init_value = func(init_value,*iter);
        } 
        return init_value;
    }

    /**
     * Applyes the specified function to all the elements of the list without editing the original list
    */
    CoolList<T> map(T (*func)(T)){
        CoolList<T> res(*this);
        res.apply(func);
        return res;
    }

    /**
     * Applyes the specified function to all the elements of the list and removes all elements that make it true
    */
    void filter(bool (*func)(T)){
        CoolList<int> indexes= CoolList();
        int index=0;
        for(auto it=this->begin();it!=this->end();it++){
            if(func(*it)){
                indexes.push(index);
            }
            index++;
        }
        for(auto it=indexes.rbegin();it!=indexes.rend();it++){
            this->remove_at(*it);
        }
    }

    CoolList<T>& operator+=(const CoolList<T>& arg_list){
        for(auto iter=arg_list.cbegin();iter!=arg_list.cend();iter++){
            this->enqueue(*iter);
        }
        return *this;
    }
 
    friend CoolList<T> operator+(const CoolList<T>& a,const CoolList<T>& b){
        CoolList<T> res = CoolList<T>();
        res += a;
        res += b;
        return res;
    }

    friend ostream& operator<< <>(ostream& os, CoolList<T> const & list);

    friend ostream& operator<< <>(ostream& os, CoolList<CoolList<T>*> const & list);

    T& operator[](int index){
        return this->getReference(index);
    }

    friend bool operator==(const CoolList<T>& a,const CoolList<T>& b){
        if(a.getLength()!=b.getLength()){
            return false;
        }
        auto a_iter = a.cbegin();
        auto b_iter = b.cbegin();
        while(a_iter != a.cend() && b_iter != b.cend()){
            if((*a_iter) != (*b_iter)){
                return false;
            }
            a_iter++;
            b_iter++;
        }
        return true;
    }

    friend bool operator==(const CoolList<T*>& a,const CoolList<T*>& b){
        if(a.getLength()!=b.getLength()){
            return false;
        }
        auto a_iter = a.cbegin();
        auto b_iter = b.cbegin();
        while(a_iter != a.cend() && b_iter != b.cend()){
            if((**a_iter) != (**b_iter)){
                return false;
            }
            a_iter++;
            b_iter++;
        }
        return true;
    }

    friend bool operator!=(const CoolList<T>& a,const CoolList<T>& b){
        return ! (a == b);
    }
};

template <typename T> ostream & operator<<(ostream& os,CoolList<T>const & list){
    //os<<list.length<<" [";
    os<<"[";
    for(auto iter=list.cbegin();iter!=list.cend();iter++){
        if(iter!=list.cbegin()){
            os<<",";
        }
        os<<(*iter);
    }
    os<<"]";
    return os;
}

template <typename T> ostream & operator<<(ostream& os,CoolList<CoolList<T>*>const & list){
    //os<<list.length<<" [";
    os<<"[";
    for(auto iter=list.cbegin();iter!=list.cend();iter++){
        if(iter!=list.cbegin()){
            os<<",";
        }
        os<<(**iter);
    }
    os<<"]";
    return os;
}

template <typename T> ostream & operator<<(ostream& os,CoolNode<T>const & node){
    os<<"Node: "<<node.content<<endl;
    os<<"Next: "<<(node.next==nullptr?nullptr:node.next->getContent())<<endl;
    os<<"Prev: "<<(node.previous==nullptr?nullptr:node.previous->getContent())<<endl;
    return os;
}
