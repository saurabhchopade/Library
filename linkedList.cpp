#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

//================Bubble sort=================================
 void my_swap (Node *node_1, Node *node_2)
{
	int temp = node_1->data;
	node_1->data = node_2 -> data;
	node_2 -> data = temp;
}

 void bubble_sort(Node *head)
{
	int swapped;

	Node *lPtr; // left pointer will always point to the start of the list
	Node *rPrt = NULL; // right pointer will always point to the end of the list
	do
	{	
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt)
		{
			if (lPtr->data > lPtr->next->data) 
			{
				my_swap(lPtr, lPtr->next); 
                swapped = 1; 
			}
			lPtr = lPtr->next;
		}
		//as the largest element is at the end of the list, assign that to rPtr as there is no need to
		//check already sorted list
		rPrt = lPtr;

	}while(swapped);
}
//====================================================

void deleteNode(Node * head){
    Node *temp =head;
    int data;
    cout << "\n Enter Node to Delete" << endl;
    cin>>data;

    while (temp!= NULL)
    {
        Node *dummy;

        if(temp->data == data){
            dummy->next = temp->next;
            Node *a = temp;
            // delete(a);
            // delete(dummy);
            cout << "\n Note Deleted Successfully" << endl;
            return;
        }
        dummy =temp;
        temp = temp->next;
    }
    cout << "\n Node Not found" << endl;
}

void addNewNode(Node * head){
    Node *temp = head;

    cout << "Enter AFter which Node = " << endl;
    int data;
    cin>>data;
    int num;
    cout << "ENter Number to insert" << endl;
    cin>>num;

    Node *newNode = new Node(num);
    if (head->next == NULL)
    {
        head->next = newNode;
        return; 
    }
    
    while (temp->next !=NULL)
    {
        if(temp->data == data){
            
            newNode ->next = temp->next;
            temp->next = newNode;

            //Optional
            // Node *dummy = temp->next;
            // temp ->next = newNode;
            // newNode->next = dummy;
            return;
        }
        temp = temp->next;
    }
    cout << "No Such Number Present" << endl;
}

void printer(Node *header){
    Node *temp = header;
    while (temp!=NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}



Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL; 
    Node *tail = NULL; 
    while(data!=-1){
        Node *newNode =  new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        
    cin>>data;
    }

return head;
}


int   reverseRec(Node *head){
    if(head == NULL){
        return 0;
    }
    int add = reverseRec(head->next)+1;
    if (add == 2)
    {
        cout << head->data << endl;
    }
    return add;
}   


Node* reverseItr(Node *head){
    Node *temp = head;
    Node *prev = NULL;
    Node *curr = head;
    
    
    while(temp->next!=NULL){
        curr =  temp->next;         
    }

    return temp;
}


Node* duplicate(Node * head){
         Node *temp = head;
   
        if(head == NULL){
            return head;
        }
        int flag =0;
        
        Node *dummy;
        while(temp->next!=NULL){
          
            dummy = temp->next;
            
            if(temp->data == dummy->data) {
                flag++;
                temp->next = dummy->next;
            }
            
            if(temp->data != dummy->data) {
                    if(flag >0){
                        temp->data = dummy->data;  
                        flag--;
                    }else{
                        
                        temp = temp->next;         
                    }
            }
        }
        
        return head;

}

void recrAdd(Node *head,int num){
    
    if(head->next==NULL){
        if(head->data == num){
            Node *a = new Node(10);
            head->next = a;
            return;     
        }
        return;
    }

    if(head->data == num){
        Node *dum = head->next;
        Node *a =new Node(10);
        head->next =a;
        a->next = dum;
        // return;
    }
    head = head->next;
    recrAdd(head,num);   
}

//Middle is working if Last node Not Working To delete
void recrDel(Node *head,int num){
    
    if(head->next ==NULL){
        return;
    }
    if(head->data == num){
        Node *dummy = head->next;
        head->data = dummy->data;
        head->next = dummy->next;
        delete(dummy);
    }

    head = head->next;
    recrDel(head,num);
}

Node* reverseLinkedList(Node* head){

        if(head == NULL || head->next == NULL){
            return head;
        }

        Node *prev = head;
        Node *curr = head->next;
        head->next = NULL;
        Node *currNext;
        
        while (curr->next!=NULL)
        {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }

        if(curr->next == NULL){
            curr->next = prev;
        }
        return curr;
}

Node* replace(Node *head, int k){

    Node *temp = head;
    Node *temp1;
    temp1 = head->next;
    
    if(temp1->next == NULL){
        int val2 = head->data;
        head->data =temp1->data;
        temp1->data = val2;
        return head;
    }
        Node *first; 
        int count =0;
        int count1 = 0;
        while(temp->next !=NULL){
            count++;

            if(count == (count1)) {
                int v =temp->data;
                temp->data = first->data;
                first->data = v;
                break;
            }
            if(count == k){
                first = temp;
                temp1 = temp;
                // count1++;
                while(temp1->next!=NULL){
                    count1++;
                    temp1 = temp1->next;
                    if (temp1->next== NULL)
                    {
                            count1++;
                    }
                }

                if(k==1){
                    int v =temp1->data;
                    temp1->data = first->data;
                    first->data = v;
                    break;
                //  }
                }
            }  
            temp = temp->next;
         
        }  
    return head;
}


//find Middle Of Linked List
void middle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    int a;
   if (head!=NULL) 
    { 
        while (fast != NULL && fast->next != NULL) 
        {
            if(fast->next->next == NULL){
                 cout << slow->data << endl;
                    return;
            } 
            a = slow->data;
            slow = slow->next; 
            fast = fast->next->next; 
        }

        //this for to get first mid
        // if (fast->next == NULL)
        // {
        //     cout << a << endl;
        //     return;
        // }
        
        cout << slow->data << endl;
    } 
}


int main() {

Node *head;
// Return -1 to exit
head =takeInput();

// head = replace(head,1);
head = reverseLinkedList(head);
// duplicate(head);
middle(head);
// recrDel(head,3);
// printer(head);
// reverseRec(head);
// addNewNode(head);
// deleteNode(head);
// printer(head);

}
