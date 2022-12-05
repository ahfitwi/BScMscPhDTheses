//@uthor: Alem Haddush Fitwi, M.Sc in Computer Engineering, May 2010 G.C
//--------------------------------Headers/packages------------------------------
import java.io.*;
import java.security.*;
import javax.crypto.*;
import javax.swing.JOptionPane;

public class AESE{
   //------------------------Main Method begins here----------------------------
   public static void main(String[] args)
    {
    	      
    	//-------------------Key Generation-------------------------------------
    	String outFile="D:\\Thesis\\text\\key.txt";
        try{
      	
    		KeyGenerator keygen = KeyGenerator.getInstance("AES");
        	SecureRandom random = new SecureRandom();
        	keygen.init(random);
        	SecretKey key = keygen.generateKey();
        	System.out.println("key="+key);
        	ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(outFile));
             out.writeObject(key);
             out.close();
        	      	
      	}
      	catch (IOException e)
       	{
          	e.printStackTrace();
       	}
       catch (GeneralSecurityException e)
       	{
          	e.printStackTrace();
       	}       
       	
       	//-------------------AES Enciphering------------------------------------       	
       	
        String inFileK1="D:\\Thesis\\text\\key.txt";
        String inFile1="D:\\Thesis\\text\\ptxt10.txt";
        String outFile1="D:\\Thesis\\text\\cipher3.txt";
        
        
       try{
       	     int mode1= Cipher.ENCRYPT_MODE;  
       	     ObjectInputStream keyIn = new ObjectInputStream(new FileInputStream(inFileK1));
             Key key = (Key) keyIn.readObject();
             keyIn.close();                      

             InputStream in1 = new FileInputStream(inFile1);
             OutputStream out1 = new FileOutputStream(outFile1);
             Cipher cipher1 = Cipher.getInstance("AES");
             cipher1.init(mode1, key);
             crypt(in1, out1, cipher1);
             in1.close();
             out1.close();
         
       }
       catch (IOException e)
       	{
          	e.printStackTrace();
       	}
       catch (GeneralSecurityException e)
       	{
          	e.printStackTrace();
       	}
       catch (ClassNotFoundException e)
       	{
          	e.printStackTrace();
       	}
      	
       //--------------------AES Deciphering------------------------------------
       String inFileK2="D:\\Thesis\\text\\key.txt";
       String inFile2="D:\\Thesis\\text\\cipher3.txt";
       String outFile2="D:\\Thesis\\text\\decrypt3.txt";
       double jj=0.32;
       
       try{
       	     int mode2 = Cipher.DECRYPT_MODE;
       	     ObjectInputStream keyIn = new ObjectInputStream(new FileInputStream(inFileK2));
             Key key = (Key) keyIn.readObject();
             keyIn.close();            

             InputStream in2 = new FileInputStream(inFile2);
             OutputStream out2 = new FileOutputStream(outFile2);
             Cipher cipher2 = Cipher.getInstance("AES");
             cipher2.init(mode2, key);
             crypt(in2, out2, cipher2);
             in2.close();
             out2.close();
         
       }
       catch (IOException e)
       	{
          	e.printStackTrace();
       	}
       catch (GeneralSecurityException e)
       	{
          	e.printStackTrace();
       	}
       catch (ClassNotFoundException e)
       	{
          	e.printStackTrace();
       	}
         	
    }
    //------------------End of Main Method--------------------------------------
    
    //-------------Member Method Begins here------------------------------------
    public static void crypt(InputStream in, OutputStream out, Cipher cipher)
          throws IOException, GeneralSecurityException
    {
       int blockSize = cipher.getBlockSize();
       int outputSize = cipher.getOutputSize(blockSize);
       byte[] inBytes = new byte[blockSize];
       byte[] outBytes = new byte[outputSize];

       int inLength = 0;
       boolean more = true;
       while (more)
       {
          inLength = in.read(inBytes);
          if (inLength == blockSize)
          {
             int outLength = cipher.update(inBytes, 0, blockSize, outBytes);
             out.write(outBytes, 0, outLength);
          }
          else more = false;
       }
       if (inLength > 0) outBytes = cipher.doFinal(inBytes, 0, inLength);
       else outBytes = cipher.doFinal();
       out.write(outBytes);
    }
    //-------------Member Method Ends here--------------------------------------
 }
//End of Class AEStest