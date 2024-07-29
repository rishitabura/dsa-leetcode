interface  GrandParent{

    int value = 10;

    void printFun();
    
}
class Parent {

    public int id;
    Parent(int id)
    {

        this.id = id;
        System.out.println("Parent " + id);

    }
    
    public void printFun()
    {
        System.out.println("Parent " + id);
    }
}

class Child extends Parent implements GrandParent{

    public int id;

    public Child(int x,int id)
    {
        // System.out.println("Hi child");
        super(x);
        this.id = id;
        System.out.println("Child "+id);
        System.out.println("parent id : " + super.id);

    }

    
    // public void printFun()
    // {
    //     System.out.println("Child "+id);
    // }

}
public class trial{

    // void printFun()
    // {
    //     System.out.println("Hello harsh");
    // }

    public static void main(String args[])
    {
        // trial obj = new trial();
        // obj.printFun();

        GrandParent obj = new Child(4,3);
        // obj.id = 1;
        // obj.printFun();

    }
}

// class Parent{

//     public Parent()
//     {
//         System.out.println("non param of parent");
//     }

//     public Parent(int x)
//     {
//         System.out.println("param of parent = " + x);
//     }
// }

// class Child extends Parent{ 
    
//     public Child()
//     {
//         System.out.println("non param of child ");
//     }

//     public Child(int y)
//     {
//         System.out.println("param of child = " + y);
//     }

//     public Child(int a, int b)
//     {
//         super(a);
//         System.out.println("param of child = " + b);
//     }
// }

// public class trial {

//     public static void main(String[] args) {
        
//         // Parent p = new Parent();
//         // Child c = new Child();
//         Child c = new Child(4,7);

//         System.out.println(c.getClass());

//     }
    
// }

