import java.util.ArrayList;
public class PrintCircleMatrix {

    public static ArrayList<Integer> printMatrix(int [][] number) {

        int start = 0;

        ArrayList result = new ArrayList();

        while((number[0].length) > start * 2 && number.length > start * 2){

            PrintMatchCircle(number,start,result);

            start++;

        }

        return result;
    }

    public static void PrintMatchCircle(int [][] number, int start, ArrayList<Integer> result){

        int endx = number[0].length - start - 1;

        int endy = number.length- start - 1;


        // 第一行

        for(int i = start; i <= endx ; i++){
            result.add (number[start][i]);
        }

        // 右面列

        if(start < endy){
            for(int i = start+1; i <= endy; i++ )
                result.add(number[i][endx]);
        }

        // 下面的行

        if(start < endx && start < endy){

            for(int i = endx - 1; i >= start ; i--)
                result.add(number[endy][i]);
        }

        if(start < endx && start< endy - 1){
            for(int i = endy - 1 ; i > start; i--)
                result.add(number[i][start]);
        }

    }


    public static void main(String [] args){
        int a[][] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        ArrayList<Integer> result = printMatrix(a);
        for (Integer integer:result){
            System.out.println(integer);
        }
    }
}