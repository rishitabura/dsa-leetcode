package linkedlist;

import java.util.Scanner;


public class linkedlistOpt {
    static Scanner sc = new Scanner(System.in);
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

    public  void creation(int n)
    {

        int num;
        System.out.print("Enter the 1st node :");
        num = sc.nextInt();
        head = new node(num);
        head.data = num;
        head.next = null;

        node temp = head;

        for (int i = 2 ; i<=n; i++)
        {
            node newNode = null;
            System.out.print("Enter the "+ i + " node : ");
            num = sc.nextInt();
            newNode = new node(num);
            newNode.data = num;
            newNode.next = null;

            temp.next = newNode;
            temp = temp.next;

        }
    }

    public void insertFirst(int data)
    {
        node newNode = new node(data);
        if (head == null)
        {
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }

    public void  insertLast(int data)
    {
        node newNode = new node(data);
        if (head == null)
        {
            head = newNode;
            return;
        }
        node current = head;
        while (current.next!= null)
        {
            current = current.next;
        }
        current.next = newNode;
    }

    public node reverse()
    {
        node current, prev , next;
        current = head;
        prev = null;
        while (current!= null)
        {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return prev;

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

        linkedlistOpt ll = new linkedlistOpt();
        System.out.println("Enter the number of nodes : ");
        int n = sc.nextInt();
        ll.creation(n);
        ll.printList();
        ll.insertFirst(5);
        ll.insertLast(10);
        ll.printList();

        head = ll.reverse();
        System.out.println("Reverse : ");
        ll.printList();



    }
}
