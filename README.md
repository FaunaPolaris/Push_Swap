# Push_Swap

## llist.h

Small linked list library.  
make llist_test rule to test all functions of the library.  

### functions:  
double linked list:
    - dll_new_node; 
        allocates memory for a new node of the list, initializes all elements, setting value to input value and prev/next to NULL;  
        returns the allocated memory, or NULL if allocation fails;  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_new_list;  
        create and returns the head for a list of size n.  
        n being the amount of values received.  
        If allocation of any node fails it clears the list and returns NULL;  
        the list starts at the first element sent, and ends at the last one;  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_new_rlist;  
        create and returns the head for a list of size n.  
        n being amount of values received.  
        If allocation of any node fails it clears the list and returns NULL;  
        the list starts at the last element sent, and ends at the first one;  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_clear;  
        frees the memory for every node on the list.  
        set the head of the list to NULL;  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_add_back;  
        adds a new node at the back of the list, the new node becomes the back of the list.  
        returns 0 if allocation of new node fails.  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_add_frnt;  
        adds a new node at the front of the list, the new node becomes the front of the list.  
        returns 0 if allocation of new node fails.  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_fnd_back;  
        returns a pointer to the back of the list.  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  

    - dll_putlist_fd;  
        puts all contents of the list to specified fd.  
        receives as a parameter a char that specifies how to treat the values of each node.  
        - c = char;  
        - s = string;  
        - i = int; 

        if content_type is any other char an error message will be displayed, if the list is empty, nothing will be displayed.  

    added: 0.0.0 (04/10/23);  
    last updated: 0.0.0 (04/10/23);  
