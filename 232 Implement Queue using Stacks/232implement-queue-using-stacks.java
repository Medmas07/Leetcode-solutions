import java.util.Stack;
class MyQueue {
    public Stack<Integer> stack1;
    public Stack<Integer> stack2;
    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
        stack1.push(x);
    }
    
    public int pop() {
        int c=0;
        while (!(stack1.isEmpty())){
            c=stack1.pop();
            stack2.push(c);
        }
        while (!(stack2.isEmpty())){
            int b=stack2.pop();
            if(b!=c){
                stack1.push(b);
            }
        }
        return c;
    }
    
    public int peek() {
        int c=0;
        while (!(stack1.isEmpty())){
            c=stack1.pop();
            stack2.push(c);
        }
        while (!(stack2.isEmpty())){
            int b=stack2.pop();
           
            stack1.push(b);
        }
        return c;
    }
    
    public boolean empty() {
        return stack1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */