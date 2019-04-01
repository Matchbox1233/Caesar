import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
class exor
{
    public static void main(String[] args)
    {
        FileInputStream fin=null;
        FileOutputStream fout=null;
        try
        {
            fin=new FileInputStream("tiszta.txt");
            int c;
            ArrayList<Integer> in_v = new ArrayList<Integer>();
            ArrayList<Integer> out_v = new ArrayList<Integer>();
            Scanner in = new Scanner(System.in);
            System.out.println("Enter key:");
            String key = in.nextLine();
            if(key.length() !=9)
            {
                System.out.println("Bad key");
                return;
            }
            while((c=fin.read())!=-1)
            {
                in_v.add(c);
            }
            for(int i=0;i<in_v.size();i++)
            {
                out_v.add(in_v.get(i)^key.charAt(i%9));
            }
            fout = new FileOutputStream("titkos.txt");
            for(int i=0;i<out_v.size();i++)
            {
                System.out.printf("%c",out_v.get(i));
            }
            
        }
        catch(Exception ex)
        {

        }
        finally
        {
            try
            {
                if(fin!=null) fin.close();
                if(fout!=null) fout.close();
            }catch(Exception ex)
            {

            }
        }
    }
}