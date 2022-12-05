
//@uthor: Alem Haddush Fitwi, M.Sc in Computer Engineering, May 2010 G.C
//--------------------------------Headers/packages------------------------------
import java.security.SignatureException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;
import java.applet.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.image.BufferedImage;

//----------------HMAC Class----------------------------------------------------
public class HMAC {
	//---------The main method---------------------------
	public static void main(String[] AAUECE){
		int a=69621;
		int m=(int)Math.pow(2,31)-1;		
		String key1=Integer.toString(a)+Integer.toString(m);
		System.out.println("key="+key1);
		System.out.println("Please wait for some minutes, HMAC is being computed.........");
		String path="D:\\key.jpg";;
		String path1="D:\\keyGray.jpg";;
		BufferedImage image=null;
		BufferedImage new_img=null;
		int w=0,h=0;
		int[][] ImagePixel = new int[1000][1000];
		
	   	try{ 
	 		image=ImageIO.read(new File(path));
	 	}catch (Exception e){  
   		     e.printStackTrace(); 
   		  } 
   	//-----------------	  
   	   /* JFrame frame1 = new JFrame("A shared RGB Image used as a key!"); 
		JLabel label1 = new JLabel(new ImageIcon(image)); 
		frame1.getContentPane().add(label1, BorderLayout.CENTER); 
		frame1.pack(); 
		frame1.setVisible(true);*/	
	//---------------
	    new_img = new BufferedImage( image.getWidth(),image.getHeight(),
                BufferedImage.TYPE_BYTE_GRAY); 
     	Graphics gr = new_img.getGraphics(); 
     	gr.drawImage(image, 0, 0, null);
     	gr.dispose();
    //----------------
        /*JFrame frame2 = new JFrame("A shared gray Image used as a key!"); 
		JLabel label2 = new JLabel(new ImageIcon(new_img)); 
		frame2.getContentPane().add(label2, BorderLayout.CENTER); 
		frame2.pack(); 
		frame2.setVisible(true);*/
    //------------------
        try{ 
	 	ImageIO.write(new_img, "jpg", new File(path1));
	 	}catch (Exception e){  
   		     e.printStackTrace(); 
   		  }  
    //-------------------
        int temp=0;
        byte pix[]=new byte[1];
		w=new_img.getWidth();
		h=new_img.getHeight();		
		int[][]matrix=new int[w][h];     
     	for (int row=0;row<w;++row){	
         for (int col=0;col<h;++col){          
           new_img.getRaster().getDataElements(row, col, pix);
           matrix[row][col]=pix[0];
           ImagePixel[row][col]=Math.abs(matrix[row][col]);      
                      
          }
         } 
	//----------------------
		//System.out.println("h="+h+"w="+w);
		//System.out.println("hw="+h*w);	
	 	String hexVal=" ";		
		for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			hexVal+=Integer.toHexString(ImagePixel[i][j]);
		    }			
	      }
	    //System.out.println(hexVal);	
		
	   
	    String  data1=hexVal;
	    calculateHMAC(data1,key1); 		
	}
	
	//------------Fields----------------------------------
	
	static final String HEXES ="0123456789ABCDEF";
	private static final String HMAC_SHA1_ALGORITHM ="HmacSHA1";
	
	//-----------Byte to Hex converter method-------------
	public static String getHex( byte [] raw ){
		if ( raw == null ){
			return null;
		   }
        final StringBuilder hex = new StringBuilder(raw.length*2);
        for ( final byte b : raw ){
        	hex.append(HEXES.charAt((b & 0xF0)>> 4)).append(HEXES.charAt((b & 0x0F)));
           }
         return hex.toString();
     }
   
   //----------The HMAC method------------------------------

	public static String calculateHMAC(String data, String key){	
		
		String result=null;
		
		try {
			
			byte[] keyBytes = key.getBytes();			;		
			SecretKeySpec signingKey = new SecretKeySpec(keyBytes, HMAC_SHA1_ALGORITHM);	 
			Mac mac = Mac.getInstance(HMAC_SHA1_ALGORITHM);
			mac.init(signingKey);			
			byte[] rawHmac = mac.doFinal(data.getBytes());		
			String hexBytes = getHex(rawHmac);			
			result=hexBytes;
			//System.out.println("Len=" + result.length());
			System.out.println("HMAC="+ result);

		} 
		catch (Exception e) {
			System.out.println("Failed to generate HMAC cos of" + e.getMessage());
			}
		return result;
		}
}