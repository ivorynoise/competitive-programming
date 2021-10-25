package stacks;
import java.util.*;
public class valid_parenthesis_checker{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        boolean isValidParanthesis = checker(s);

        if(!isValidParanthesis)
            System.out.println("No");
        else
            System.out.println("Yes");
        
    }
    public static boolean checker(String s){
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c==')' || c==']' || c=='}'){
                if(stack.isEmpty())
                    return false;
                char temp = stack.pop();
                if(helper(c)!=temp)
                    return false;
            }
            else{
                stack.add(c);
            }
            //System.out.println(stack);
        }
        return stack.isEmpty();
    }
    public static char helper(char c){
        if(c==')')
            return '(';
        else if(c=='}')
            return '{';
        else
            return '[';
    }
}
/* 
Sample Output:

(){}[()]
Yes

(){{]]
No
*/
