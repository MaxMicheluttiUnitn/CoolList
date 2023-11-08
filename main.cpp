#include "myqueue.h"
using namespace std;
#include <vector>
#include <iostream>

int sum_1(int x){return x+1;}
bool is_3(int x){return x==3;}
int sum(const int x,const int y){return x+y;}

// An example of the use of CoolList's cool functionalities
int main(){
    CoolList<int> my_list = CoolList<int>();
    my_list.enqueue(1);
    my_list.enqueue(2);
    my_list.enqueue(3);

    cout<<(my_list)<<endl;

    CoolList<int> other_list=CoolList<int>(my_list);

    auto item = my_list.pop();
    cout<<item<<endl;

    cout<<"List: "<<(my_list)<<endl;
    cout<<"Other: "<<(other_list)<<endl;

    my_list.concat(other_list);

    cout<<"List: "<<my_list<<endl;
    cout<<"Other: "<<other_list<<endl;

    cout<<my_list[2]<<endl;

    my_list[2]=10;
    cout<<"List: "<<my_list<<endl;

    my_list.sort();
    cout<<"List: "<<my_list<<endl;

    my_list.reverse();
    cout<<"List: "<<my_list<<endl;

    auto iter = my_list.begin();
    for(;iter!=my_list.end();iter++){
        (*iter)++;
    }
    cout<<"List: "<<my_list<<endl;

    auto citer = my_list.cbegin();
    for(;citer!=my_list.cend();citer++){
        cout<<(*citer)+2<<endl;
    }
    cout<<"List: "<<my_list<<endl;

    auto criter = my_list.crbegin();
    for(;criter!=my_list.crend();criter++){
        cout<<(*criter)+2<<endl;
    }
    cout<<"List: "<<my_list<<endl;

    my_list.shuffle();
    cout<<"List: "<<my_list<<endl;

    auto split=my_list.split_at_index_const(5);
    cout<<"Split: "<<split<<endl;
    cout<<"Split[0]: "<<split[0]<<endl;
    cout<<"Split[1]: "<<split[1]<<endl;
    cout<<"List: "<<my_list<<endl;

    CoolList<int> new_list = CoolList<int>();
    new_list.enqueue(2);
    new_list.enqueue(1);
    new_list.enqueue(2);
    new_list.enqueue(3);
    new_list.enqueue(4);
    new_list.enqueue(3);
    new_list.enqueue(2);
    new_list.enqueue(1);
    new_list.enqueue(1);
    new_list.enqueue(2);
    new_list.enqueue(2);
    new_list.enqueue(2);
    new_list.enqueue(1);
    new_list.enqueue(3);
    new_list.enqueue(4);
    new_list.enqueue(5);
    new_list.enqueue(6);
    new_list.enqueue(2);
    cout<<"New List: "<<new_list<<endl;
    cout<<"Instances of 2: "<<new_list.count_instances_of(2)<<endl;
    auto lists = new_list.split_const(2);
    cout<<"Lists: "<<lists<<endl;
    cout<<"New List: "<<new_list<<endl;
    new_list.map(sum_1);
    cout<<"New List: "<<new_list<<endl;
    new_list.filter(is_3);
    cout<<"New List: "<<new_list<<endl;
    int acc = new_list.accumulate(sum,0);
    cout<<"Sum is: "<<acc<<endl;

    auto res = new_list.split_at_index(5);
    cout<<"New List: "<<new_list<<endl;
    cout<<"Res:"<<res<<endl;
    res[0][0] = 20;
    cout<<"New List: "<<new_list<<endl;
    cout<<"Res:"<<res<<endl;

    res.dequeue();
    for(CoolIter iter=res.begin();iter!=res.end();iter++){
        new_list.merge(*iter);
    }
    cout<<"New List: "<<new_list<<endl;

    auto res_split = new_list.split(2);
    cout<<"Res Split :"<<res_split<<endl;

    CoolList<int> new_cool_list = CoolList<int>();
    new_cool_list.push_all(1,0,2,5,3,7,9,9,-1,6);

    cout<<"New cool list: "<<new_cool_list<<endl;

    new_cool_list.remove_all_every(0,9,5);
    cout<<"New cool list: "<<new_cool_list<<endl;

    CoolList<int> wow = {1,3,7,11,2,0,-1};
    cout<<"Wow: "<<wow<<endl;
}

