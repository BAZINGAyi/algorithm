/**
 * 问题描述，给定两个序列，一个是栈入栈序列，一个是栈的出栈序列,求第二个序列是否是第一个栈的出栈序列
 */

import java.util.ArrayList;

/**
 * 解析：如果下一个弹出的数字是栈顶数字，那么直接弹出。如果不是，则把压栈序列中的
 * 没有入栈的元素压栈，直到把需要弹出的数字压入栈顶为止。
 * 如果所有的数字都已经入栈，仍然没有找到下一个弹出的数字，则该序列不可能是弹出序列
 */
public class StackPushPopOrder {

    static Stack stack = new Stack();

   static boolean isPopOrder(int a[],int b[],int length){

        if(a.length == 0 || b.length == 0 || a.length != b.length || a.length != length)
            return false;

        int pNextPush = 0;

        int pNextPop = 0;

        // 出口是 压入栈的序列全都被访问 或者 弹出栈的序列全都被访问
        // 遍历到弹出序列的最后一个结点
        while (pNextPop < length){

            // 找到需要弹出的元素
            while(stack.emptyStack() || stack.top() != b[pNextPop]){
                if (pNextPush == length)
                        break;
                stack.push(a[pNextPush++]);
            }

            if (stack.top() != b[pNextPop])
                    break;

            stack.pop();

            pNextPop ++;
        }

        if(stack.emptyStack() && pNextPop == length)
            return true;

        return false;
    }

    public static void main(String args[]){
        int a[] = {1,2,3,4,5};
        int b[] = {4,5,3,2,1};
        System.out.println(isPopOrder(a,b,5));
   }

}

class Stack{

    private int top = -1;

    ArrayList<Integer> stack = new ArrayList<>();

    boolean emptyStack(){
        if(top == -1)
            return true;
        return false;
    }

    int pop(){
        if(emptyStack())
            return -1;
        else
            return stack.remove(top--);
    }

    void push(int x){
        top++;
        stack.add(x);
    }

    int top(){
        if(emptyStack())
            return -1;
        else
            return stack.get(top);
    }
}