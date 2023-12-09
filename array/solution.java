package array;

import java.util.*;
import java.lang.*;

class solution
{
    public static int minOperations(String[] logs) {
        Stack<String>stack=new Stack<String>();
        for(String log:logs){
            if(log.equals("../")){
                if(stack.size()>0)stack.pop();
            }
            else if(log.equals("./"));
            else{
                stack.push(log);
            }
        }
        return stack.size();
    }

    public static void main(String args[])
    {
        String[]logs={"d1/","d2/","../","d21/","./"};

        System.out.println(minOperations(logs));
    }
}