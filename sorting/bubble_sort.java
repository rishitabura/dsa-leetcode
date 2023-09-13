package sorting;
import java.util.*;
public class bubble_sort {
    static Scanner sc = new Scanner(System.in);
    static class student{
        int roll;
        String name;

         public student(int r, String s)
        {
            this.name = s;
            this.roll = r;
        }
    }
    static void accept(student list[], int n)
    {
        for (int i = 0 ; i < n; i++)
        {
            list[i] = new student(0,"");
            System.out.println("Enter roll and name of student "+ (i+1));
            list[i].roll = sc.nextInt();
            list[i].name = sc.next();

        }
    }

    static void bubble(student list[], int n)
    {
        for (int i = 0 ; i < (n-1);  i++)
        {
            for (int j = 0 ; j < (n-i-1); j++)
            {
                if (list[j].roll > list[j+1].roll)
                {
                    student temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
        }
    }

    static void print(student list[], int n)
    {
        System.out.println("Roll no\tName");

        for (int i = 0 ; i < n ; i++)
        {
            System.out.print(list[i].roll+"\t"+list[i].name+"\n");

        }
    }

    public static void main(String[] args)
    {
        System.out.println("Enter number of students : ");
        int num = sc.nextInt();
        student list[] = new student[num];
        System.out.println("Enter details of students : ");
        accept(list, num);
        bubble(list,num);
        System.out.println("Sorted order : ");
        print(list, num);


    }
}
