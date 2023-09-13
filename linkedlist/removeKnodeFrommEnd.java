package linkedlist;

class node {
    int data;
    node next;

    node(int val) 
    {
        data = val; 
    }

    node(int val , node next) { 
        data = val; 
        this.next = next; 
    }
}

public class removeKnodeFrommEnd {

    public static node removeKEnd(node head, int n) {
        int count = 0;
        node temp1 = head;
        while (temp1 != null) {
            count = count + 1;
            temp1 = temp1.next;
        }
        System.out.println("Total : " + count);

        int k = count - n;

        if (k == 0) {
            return head.next;
        }

        node p = head;
        node q = head.next;

        for (int i = 1; i < k; i++) {
            p = p.next;
            q = q.next;
        }
        p.next = q.next;
        return head;

    }

    public static void printList(node head) {
        node current = head;
        while (current != null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.println("Null");
    }

    public static void main(String[] args) {
        node l1 = new node(1);
        l1.next = new node(2);
        l1.next.next = new node(3);
        l1.next.next.next = new node(4);
        l1.next.next.next.next = new node(5);

        printList(l1);

        node temp = removeKEnd(l1, 5);
        printList(temp);

    }
}
