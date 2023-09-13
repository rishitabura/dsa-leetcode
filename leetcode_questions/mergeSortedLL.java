package leetcode_questions;

public class mergeSortedLL {

    static node head;
    class node{
        int data;
        node next;

        node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }

    public node mergeSorted(node l1, node l2)
    {
        node ptr1 = l1;
        node ptr2 = l2;

        node temp = new node(-1);
        node ptr3 = temp;

        while (ptr1!= null && ptr2!= null)
        {
            if (ptr1.data > ptr2.data)
            {
                ptr3.data = ptr2.data;
                ptr3 = ptr3.next;
                ptr2 = ptr2.next;
            }
            else
            {
                ptr3.data = ptr1.data;;
                ptr3 = ptr3.next;
                ptr1 = ptr1.next;
            }
            ptr3 = ptr3.next;

        }
        while (ptr1!=null)
        {
            ptr3.next =ptr1;
            ptr1 = ptr1.next;
            ptr3 = ptr3.next;
        }
        while (ptr2!=null)
        {
            ptr3.next =ptr2;
            ptr2 = ptr2.next;
            ptr3 = ptr3.next;
        }

        return temp.next;

    }
    public void  insertLast(int data)
    {
        node newNode = new node(data);
        if (head == null)
        {
            head = newNode;
            return;
        }
        mergeSortedLL.node current = head;
        while (current.next!= null)
        {
            current = current.next;
        }
        current.next = newNode;
    }

    public  void printList()
    {
        node current = head;
        while (current != null)
        {
            System.out.print(current.data+ "->" );
            current = current.next;
        }
        System.out.println("Null");
    }

    public static void main(String[] args) {
        node l1 = null;
        node l2 = null;

        l1.data = 1;
        l1.next.data = 2;
        l1.next.next.data = 3;
        l2.data = 4;
        l2.next.data = 1;
        l2.next.next.data = 2;

        System.out.println("Merged List :");
//        node newList = mergeSorted(l1,l2);


        
    }
}
