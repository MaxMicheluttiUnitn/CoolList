# CoolList

Wanting to experience lists the way cool people experience them? Tired of using boring lists for your projects? Frustrated by the std implementation of list for some unknown reason?  Well, today is your lucky day!!! This implementation of a list in C++ is the coolest list implementation you can find out there, and it's all open source and easily available. Just copy the **"myqueue.h"** file in whatever project you want to use it and include it with **#include "myqueue.h"**. Your programming experience will instantly turn into something awesome and you will finally become a certified cool developer. What are you waiting for!? Start using CoolLists right now!!!

## CoolList interface

OK... you included the library... but now how do you use it?<br>
Don't worry, my cool friend, here is all you need to know: whatever you need to do with your CoolLists, in this section you can find how you can do it.

### Constructors

Let's create our CoolList!<br>

You can create a CoolList with its constructor

```
    CoolList<int> cool_list = CoolList<int>();
```

You can copy a CoolList with the copy constructor. The newly created CoolList performes a deep copy of the CoolList. However items stored in the CoolList are not deep copied, so if you use the CoolList to store pointers you will get a new CoolList with pointers to **the same memory adresses**.

```
    CoolList<int> other_list = CoolList<int>(cool_list);
```

You can also use the 'new' operator to allocate the CoolList in the heap

```
    CoolList<int> * cool_list = new CoolList<int>();
```

### Destructor

Ok, You don't need this istance of the CoolList anymore... what happens when it is destroyed?<br>

Every time you destruct a CoolList, all its node will also be destroyed, but eventual pointers stored in the CoolList will not be destroyed.

```
    delete cool_list;
```

### Adding items

Having a coolLists is alreasy cool by itself, but do you know what would make it even better? Adding items into it!<br>

There are multiple ways to add items to the CoolList:

- **enqueue(T item)**: add the item to the end of the CoolList, using it as a queue

```
    int x = 10;
    cool_list.enqueue(x);
```

- **enqueue_all(T... items)**: add all the itesm to the end of the CoolList, using it as a queue

```
    cool_list.enqueue(1,2,3,4);
```

- **push(T item)**: add the item to the end of the CoolList, using it as a stack

```
    int x = 10;
    cool_list.push(x);
```

- **push_all(T... items)**: add the item to the end of the CoolList, using it as a stack

```
    cool_list.push_all(1,2,3,4);
```

- **add_first(T item)**: add the item to the beginning of the CoolList

```
    int x = 10;
    cool_list.add_first(x);
```

- **add(T item,int index)**: add the item to the CoolList at the specified index. The rest of the CoolList is shifted by one position.

```
    string hello = "hello";
    cool_list.add(hello,3);
```

### Removing Items

This item is uncool, let's remove it from the CoolList!<br>

You can remove items from the front of the CoolList by calling the **dequeue()** function, which returns the removed item. If the CoolList is empty, an **EmptyListRemovalException** is thrown. You can use the structure as a queue in this way.


```
    string removed = cool_list.dequeue();
```

You can remove items from the end of the CoolList by calling the **pop()** function, which returns the removed item. If the CoolList is empty, an **EmptyListRemovalException** is thrown. You can use the structure as a stack in this way.

```
    string removed = cool_list.pop();
```

If you want to remove an item at a specific index you can call **remove_at(int index)**. This function will remove the removed item. If the index is out of bounds an **IndexOutOfBoundsException** is thrown.

```
    string removed = cool_list.remove_at(3);
```

If you want to remove a specific item from the CoolList you can call **remove(T item)**. This function will remove the first instance that matches the parameter item from the CoolList. If the CoolList does not contain any instances of the item, an **ItemNotFoundException** is thrown.

```
    string removed = cool_list.remove("hello");
```

If you want to delete once multiple items from the CoolList you can call the **remove_all(T... items)** function. This will return a CoolList containing the removed items. If the CoolList does not contain any instances of an item, an **ItemNotFoundException** is thrown.

```
    CoolList<string> removed = cool_list.remove("hello","how","are","you");
```

To delete all instances of a specific item, call **remove_every(T item)**. The function will return an istance of the removed item. If the CoolList does not contain any instances of the item, an **ItemNotFoundException** is thrown.

```
    string removed = cool_list.remove_every("hello");
```

To delete all instances of a multiple items, call **remove_all_every(T... items)**. The function will return a CoolList with an single istance of the removed items (you will not get copies). If the CoolList does not contain any instances of any item, an **ItemNotFoundException** is thrown.

```
    CoolList<string> removed = cool_list.remove_all_every("hello","how","are","you");
```

### Getting items

Wondering how to find your items inside the CoolList? Here's how:<br>

To get a copy of the item contained at a specific index, call **get(int index)**. If the index is out of bounds an **IndexOutOfBoundsException** is thrown. This is a copy of the item, editing this copy will have no effect on the item in the CoolList.

```
    double number = cool_list.get(5);

    // this will not affect the double in the CoolList
    number++;
```
To get a reference to the item contained at a specific index, call **getReference(int index)**. If the index is out of bounds an **IndexOutOfBoundsException** is thrown. This is a reference to the item, edits on the returned value will be also applied on the item inside the CoolList.

```
    double& number = cool_list.getReference(5);

    // this will change the value of the double in the CoolList
    number++;
```

You can also get a reference to an item in the CoolList through the **[]** operator.

```
   double& number = cool_list[5];

    // this will change the value of the double in the CoolList
    number++; 
```

### Checking Basic Properties

Ok, now some basic, but very useful stuff<br>

You can get the current length of the CoolList with the **getLength()** function

```
    int list_length = cool_list.getLength();
```

You can check if the CoolList is empty with the **isEmpty()** function

```
    if ( cool_list.isEmpty() ){
        std::cout << "The cool cool list is empty";
    }
```

You can check if the CoolList contains a given item with the **contains(T item)** function

```
    if ( cool_list.contains(100) ){
        std::cout << "The cool list contains at least an instance of 100";
    }
```

You can get the first index of a given item with the **index_of(T item)** function

```
    int index_of_100 = cool_list.index_of(100);
```

You can count how many instances of a given item there are in the CoolList with the **count_instances_of(T item)** function

```
    int instances_of_100 = cool_list.count_instances_of(100);
    std::cout << "100 appears " << instances_of_100 << " times in the cool list";
```

### Ordering of the items

The arrangement of the items in the CoolList doesn't please you? Well, you can change it very easily!<br>

The CoolList can be sorted, reversed and shuffled. There are 2 ways to sort the CoolList: you can either sort the original CoolList with **sort()** or get another CoolList which has the same items as the original but sorted without modifying the original using **getSorted()**

```
    // cool_list will be chaned
    cool_list.sort();

    // old_list will not change
    CoolList<char> other_list = old_list.getSorted();
```

There are 2 ways to reverse the CoolList: you can either reverse the original CoolList with **reverse()** or get another CoolList which has the same items as the original but reversed in order without modifying the original using **getReversed()**

```
    // cool_list will be chaned
    cool_list.reverse();

    // old_list will not change
    CoolList<char> other_list = old_list.getReversed();
```

There are 4 ways to shuffle the CoolList: you can either shuffle the original CoolList with **shuffle()** and **shuffle(unsigned int seed)** or get another CoolList which has the same items as the original but shuffled without modifying the original using **getShuffled()** or **getShuffled(unsigned int seed)**

```
    // cool_list will be chaned
    cool_list.shuffle();
    cool_list_with_seed.shuffle(1000);

    // old_list will not change
    CoolList<char> other_list = old_list.getShuffled();
    CoolList<char> other_list_with_seed = old_list_with_seed.getShuffled(1234);
```

### Merging

Putting things together is always fun!<br>

You can concatenate CoolLists with the **concat(CoolList<T>&const list)** and **merge(CoolList<T>&const list)** functions. This functions will produce a concatenated CoolList by modifying the CoolList on which they are called. The parameter of the function is not modified. The CoolList are concatenated always at the end

```
    // second_list will not change
    first_list.concat(second_list);

    // third_list will not change
    first_list.merge(third_list);
```

You can also concatenate CoolLists by summing them

```
   // second_list and third_list will not change
    first_list = second_list + third_list;

    // fourth_list will not change, first_list will change
    first_list += fourth_list;
```

### Splitting

You know what is cooler than a CoolList? A CoolList of CoolLists, obviously! Find out how you can get one by splitting your CoolLists!<br>

You can split your CoolList into 2 using the **split_at_index(int index)** function. This will return a CoolList of CoolLists of your chosen type (so cool!!!). The first element of this CoolList will be a copy of the shortened verion of the original CoolList, while the second element will be a newly genertated CoolList which contains the tail of the original CoolList. The original CoolList will be shortened. If the index parameter is out of bounds, an **IndexOutOfBoundsException** will be thrown.

```
    // cool_list = [1,2,3,4,5,6]
    CoolList<CoolList<T>*> list_of_lists = cool_list.split_at_index(3);
    
    // cool_list = [1,2,3]
    // list_of_lists = [[1,2,3],[4,5,6]]
```

If you don't want to split the original CoolList you can use the **split_at_index_const(int index)** function 

```
    // cool_list = [1,2,3,4,5,6]
    CoolList<CoolList<T>*> list_of_lists = cool_list.split_at_index_const(3);
    
    // cool_list = [1,2,3,4,5,6]
    // list_of_lists = [[1,2,3],[4,5,6]]
```

Another way to split CoolLists is by specifying an item that is used as separator with the **split(T item)** function. This function splits the original CoolList into multiple CoolLists wherever it finds the separator item, removing it from the generated CoolLists. The original CoolList will be shrunk to the size of the first element of the returned CoolList of CoolLists

```
    // cool_list = ['a','b','a','a','c','d']
    CoolList<CoolList<T>*> list_of_lists = cool_list.split('a');
    
    // cool_list = []
    // list_of_lists = [[],['b'],[],['c','d']]
```

Also in this case, you can avoid modifying the original CoolList with the **split_const(T item)** function

```
    // cool_list = ['a','b','a','a','c','d']
    CoolList<CoolList<T>*> list_of_lists = cool_list.split_const('a');
    
    // cool_list = ['a','b','a','a','c','d']
    // list_of_lists = [[],['b'],[],['c','d']]
```

### Iterators

Iterating through a list can be tedious, luckily CoolList's iterators do all the heavy job for you!<br>

There are currently 4 types of Iterators for CoolLists:

- **CoolIter** allows you to iterate over the CoolList in order and to edit values into the CoolList

```
    CoolIter cool_iter = cool_list.begin();
    for( ; cool_list.end() != cool_iter ; cool_iter++){
        // This will increment each item of the CoolList
        (*cool_iter)++;
    }
```

- **CoolIterConst** allows you to iterate over the CoolList in order in read only

```
    CoolIterConst cool_iter = cool_list.cbegin();
    for( ; cool_list.cend() != cool_iter ; cool_iter++){
        // This will not change the values in the CoolList
        int x = (*cool_iter) + 1;
    }
```

- **CoolIterReverse** allows you to iterate over the CoolList in reverse order and to edit values into the CoolList

```
    CoolIterReverse cool_iter = cool_list.rbegin();
    for( ; cool_list.rend() != cool_iter ; cool_iter++){
        // This will increment each item of the CoolList starting from the last
        (*cool_iter)++;
    }
```

- **CoolIterConstReverse** allows you to iterate over the CoolList in reverse order in read only

```
    CoolIterConstReverse cool_iter = cool_list.crbegin();
    for( ; cool_list.crend() != cool_iter ; cool_iter++){
        // This will not change the values in the CoolList
        int x = (*cool_iter) + 1;
    }
```

### Applying Functions to the CoolList

With CoolLists mapping and filtering are as easy as they can be!<br>

You can transform uniformly all the items in your CoolList by applying a function to all its items. To perform this transformation you can call the **apply()** function on a CoolList and pass as the parameter of this function the function that you want to apply, as in the example below

```
    int sum_five(int i){
        return i + 5;
    }

    int main(){
        [...]
        // cool_list is [1,2,3]

        cool_list.apply(sum_five);

        // now cool_list is [6,7,8]
    }
```

If you want to apply the function on your CoolList without changing it, you can instead use the **map()** function, which will retiurn a newly generated CoolList which is the result of applying the function to the original CoolList

```
    int sum_five(int i){
        return i + 5;
    }

    int main(){
        [...]
        // cool_list is [1,2,3]

        CoolList<int> mapped = cool_list.map(sum_five);

        // now cool_list is [1,2,3]
        // and mapped is [6,7,8]
    }
```

Another useful function that you can apply to a CoolList is a filter. A filter is a boolean function that decides which items can stay in the CoolList and which items are not cool enough. You can filter your CoolList with the **filter()** function, as in the example

```
    bool is_uncool(int i){
        // odd numbers are uncool
        return (i % 2 == 1);
    }

    int main(){
        [...]
        // cool_list is [1,2,3,4,5]

        cool_list.filter(is_uncool);

        // now cool_list is [2,4]
    }
```

One more cool thing that you can do with CoolLists is accumulate their content. You can use accumulators to apply a function that puts together all items in the list to produce a single result. The example below will help you understand better

```
    int multiply(int i, const int j){
        return i * j;
    }

    int main(){
        [...]
        // cool_list is [1,2,3,4,5]

        int factorial = cool_list.accumulate(multiply,1);

        // factorial is 1 * [ 1 * 2 * 3 * 4 * 5 ]
    }
```

### Matching CoolLists

When are two CoolLists equal? When all their elements are the same and in the same order.<br>

You can check equality between two CoolLists with the **==** (or **!=**) operator

```
    if ( first_list == second_list ){
        std::cout << "The cool lists are equal"; 
    }
```

### Printing CoolLists

Sometimes some output is all you need!<br>

You can print CoolLists on any output stream by using the **<<** operator. The generated stream will start and end in square brackets, and items will be separated by commas

```
    std::cout << "My cool list: " << std::endl << my_cool_list;
```

## Conclusion

Now that you know how to use CoolLists you are officially a certified cool developer and nobody can say otherwise. Star this cool repository if you liked it and be ready to other cool structures in the future!