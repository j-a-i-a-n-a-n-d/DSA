import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {
    public static void main(String args[] ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int maxChars = Integer.parseInt(br.readLine());
        String inputString=br.readLine();
        String[] arr = inputString.split(" ");
        StringBuilder sBuffer = new StringBuilder();
        String temp="";
        String tempearlier="";
        for(String eachWord : arr)
        {
            tempearlier=temp;
            temp = temp + eachWord+" ";
            if (temp.length()>=maxChars)
            {
                if(tempearlier.length()<maxChars)
                {
                    sBuffer.append(tempearlier+"\n");
                    temp=eachWord+" ";
                    tempearlier="";
                }
            }
        }
        sBuffer.append(temp);
        System.out.println(sBuffer.toString().trim());
    }
}