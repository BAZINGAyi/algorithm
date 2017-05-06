import java.util.ArrayList;
import java.util.Stack;

/**
 *  在时间复杂度为 O(1) 的情况下求出栈中的最小值
 *  使用辅助栈记录最小值
 */
public class MinInStack {

    static Stack stack = new Stack();

    static Stack assistStack = new Stack();

    public static int min(){
        if(assistStack.top != -1)
            return assistStack.top();
        return -1;
    }


    public static int pop(){
        if (stack.top != -1){
            assistStack.pop();
            return stack.pop();
        }
        return -1;
    }

    public static void push(int x){

        if(stack.top() == -1){
            stack.push(x);
            assistStack.push(x);
        } else {
            if(assistStack.top() > x)
                assistStack.push(x);
            else
                assistStack.push(assistStack.top());
            stack.push(x);
        }
    }

    public static int top(){
        return stack.top();
    }

    public  static void main(String [] args){

        push(1);

        push(-12);

        push(4);

        push(0);

        pop();

        pop();

        pop();

        top();

        System.out.println(min());

    }


   static class Stack{

        private int MAXSIZE = 100;

        private int  top = -1;

        int a[] = new int[MAXSIZE];

        void push(int x){

            if(top <= MAXSIZE-1)
                a[++top] = x;
        }

        int top(){

            if (top == -1)
                return -1;

            return a[top];
        }

        int pop(){
            if(top >= 0)
                return a[top--];
            else
                return -1;
        }
    }
}
