
//----------@uthor: Alem Haddush Fitwi. GSR/0996/01--------------
//-----------------------Headers/packages------------------------

package my.Cryptosystem;
import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.UIManager;

//-----------------------class Jframe------------------------------

public class RSAFinal extends javax.swing.JFrame {
    
    
    public RSAFinal() {
        initComponents();
    }
    
    
    private void initComponents() {

        panelKey = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        textKeyLength = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        modulus = new javax.swing.JTextArea();
        jScrollPane2 = new javax.swing.JScrollPane();
        pubKey = new javax.swing.JTextArea();
        jScrollPane3 = new javax.swing.JScrollPane();
        priKey = new javax.swing.JTextArea();
        generateKey = new javax.swing.JButton();
        encryptPanel = new javax.swing.JPanel();
        plainTextScrollPane = new javax.swing.JScrollPane();
        plainText = new javax.swing.JTextArea();
        jLabel6 = new javax.swing.JLabel();
        jScrollPane4 = new javax.swing.JScrollPane();
        encryptedText = new javax.swing.JTextArea();
        jLabel7 = new javax.swing.JLabel();
        encrypt = new javax.swing.JButton();
        textFieldFile = new javax.swing.JTextField();
        browse = new javax.swing.JButton();
        decryptPanel = new javax.swing.JPanel();
        jLabel8 = new javax.swing.JLabel();
        jScrollPane5 = new javax.swing.JScrollPane();
        decipheredText = new javax.swing.JTextArea();
        decrypt = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("RSA Algorithm Implementation. By Alem H, AAU, ECE.");
        setResizable(false);

        panelKey.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createTitledBorder(null, "Key Generation", javax.swing.border.TitledBorder.LEFT, javax.swing.border.TitledBorder.DEFAULT_POSITION)));

        jLabel1.setText("key Length:");

        jLabel2.setText("number of Bits");

        jLabel3.setText("Modulus (N) :");

        jLabel4.setText("Public Key (e) :");

        jLabel5.setText("Private Key (d) :");

        textKeyLength.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        textKeyLength.setText("32");

        modulus.setColumns(20);
        modulus.setEditable(false);
        modulus.setLineWrap(true);
        modulus.setRows(10);
        jScrollPane1.setViewportView(modulus);

        pubKey.setColumns(20);
        pubKey.setEditable(false);
        pubKey.setLineWrap(true);
        pubKey.setRows(10);
        jScrollPane2.setViewportView(pubKey);

        priKey.setColumns(20);
        priKey.setEditable(false);
        priKey.setLineWrap(true);
        priKey.setRows(10);
        jScrollPane3.setViewportView(priKey);

        generateKey.setText("Generate Keys");
        generateKey.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generateKeyActionPerformed(evt);
            }
        });
     //-------------------------------------------------------------------------
        javax.swing.GroupLayout panelKeyLayout = new javax.swing.GroupLayout(panelKey);
        panelKey.setLayout(panelKeyLayout);
        panelKeyLayout.setHorizontalGroup(
            panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelKeyLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2, 0, 0, Short.MAX_VALUE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, 115, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panelKeyLayout.createSequentialGroup()
                        .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 104, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(panelKeyLayout.createSequentialGroup()
                                .addComponent(jLabel1)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(textKeyLength, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabel2))
                            .addComponent(generateKey)))
                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        panelKeyLayout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {jScrollPane1, jScrollPane2, jScrollPane3});

        panelKeyLayout.setVerticalGroup(
            panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelKeyLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panelKeyLayout.createSequentialGroup()
                        .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel3)
                            .addComponent(jLabel4)
                            .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(panelKeyLayout.createSequentialGroup()
                                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(jScrollPane2, javax.swing.GroupLayout.Alignment.LEADING, 0, 0, Short.MAX_VALUE)
                                    .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, 62, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panelKeyLayout.createSequentialGroup()
                                .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addGroup(panelKeyLayout.createSequentialGroup()
                                        .addGroup(panelKeyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                            .addComponent(jLabel1)
                                            .addComponent(jLabel2)
                                            .addComponent(textKeyLength, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGap(29, 29, 29))
                                    .addComponent(jScrollPane3, 0, 0, Short.MAX_VALUE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                        .addGap(23, 23, 23))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panelKeyLayout.createSequentialGroup()
                        .addComponent(generateKey)
                        .addContainerGap())))
        );

        panelKeyLayout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {jScrollPane1, jScrollPane2, jScrollPane3});

        encryptPanel.setBorder(javax.swing.BorderFactory.createTitledBorder("Encryption"));

        plainText.setColumns(20);
        plainText.setEditable(false);
        plainText.setLineWrap(true);
        plainText.setRows(5);
        plainText.setWrapStyleWord(true);
        plainTextScrollPane.setViewportView(plainText);

        jLabel6.setText("Plain Text from Source File : ");

        encryptedText.setColumns(20);
        encryptedText.setEditable(false);
        encryptedText.setLineWrap(true);
        encryptedText.setRows(5);
        encryptedText.setWrapStyleWord(true);
        jScrollPane4.setViewportView(encryptedText);

        jLabel7.setText("Encrypted Text");

        encrypt.setText("Encrypt");
        encrypt.setName("");
        encrypt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                encryptActionPerformed(evt);
            }
        });

        textFieldFile.setEditable(false);

        browse.setText("Browse...");
        browse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                browseActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout encryptPanelLayout = new javax.swing.GroupLayout(encryptPanel);
        encryptPanel.setLayout(encryptPanelLayout);
        encryptPanelLayout.setHorizontalGroup(
            encryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(encryptPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(encryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 479, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, encryptPanelLayout.createSequentialGroup()
                        .addComponent(jLabel7)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 336, Short.MAX_VALUE)
                        .addComponent(encrypt))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, encryptPanelLayout.createSequentialGroup()
                        .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(textFieldFile, javax.swing.GroupLayout.DEFAULT_SIZE, 278, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(browse))
                    .addComponent(plainTextScrollPane, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, 479, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap())
        );
        encryptPanelLayout.setVerticalGroup(
            encryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(encryptPanelLayout.createSequentialGroup()
                .addGroup(encryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(browse)
                    .addComponent(textFieldFile, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(plainTextScrollPane, javax.swing.GroupLayout.PREFERRED_SIZE, 55, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(encryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(encrypt))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        encryptPanelLayout.linkSize(javax.swing.SwingConstants.VERTICAL, new java.awt.Component[] {jScrollPane4, plainTextScrollPane});

        decryptPanel.setBorder(javax.swing.BorderFactory.createTitledBorder("Decryption"));

        jLabel8.setText("Decrypted Text");

        decipheredText.setColumns(20);
        decipheredText.setEditable(false);
        decipheredText.setLineWrap(true);
        decipheredText.setRows(5);
        decipheredText.setWrapStyleWord(true);
        jScrollPane5.setViewportView(decipheredText);

        decrypt.setText("Decrypt");
        decrypt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                decryptActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout decryptPanelLayout = new javax.swing.GroupLayout(decryptPanel);
        decryptPanel.setLayout(decryptPanelLayout);
        decryptPanelLayout.setHorizontalGroup(
            decryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(decryptPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(decryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 473, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(decryptPanelLayout.createSequentialGroup()
                        .addComponent(jLabel8)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(decrypt)))
                .addContainerGap(16, Short.MAX_VALUE))
        );
        decryptPanelLayout.setVerticalGroup(
            decryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(decryptPanelLayout.createSequentialGroup()
                .addGroup(decryptPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(decrypt))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 55, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(panelKey, javax.swing.GroupLayout.Alignment.LEADING, 0, 515, Short.MAX_VALUE)
                    .addComponent(decryptPanel, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(encryptPanel, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(11, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panelKey, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(encryptPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(decryptPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(22, 22, 22))
        );

        pack();
    }

private void browseActionPerformed(java.awt.event.ActionEvent evt) {
     readFile();
}

private void decryptActionPerformed(java.awt.event.ActionEvent evt) {
   
   String enc = encryptedText.getText();
   decipheredText.setText("");
   //Timer begins here
    long start=System.currentTimeMillis();
    if(enc.equals(""))
    {
        JOptionPane.showMessageDialog(this,String.format("No File to decrypt!"));
	return;
    }
   int beginIndex=0;
   int endIndex= enc.indexOf(" ");
   String decipheredMessage="";
   while(endIndex != -1)
   {
       String dec = enc.substring(beginIndex, endIndex);
       BigInteger decipheredMessageAsBigInteger = decrypt(new BigInteger(dec,16));
       decipheredMessage +=  new String(decipheredMessageAsBigInteger.toByteArray());
       beginIndex =endIndex+1;
       endIndex = enc.indexOf(" ", beginIndex);
   }
   decipheredText.setText(decipheredMessage);
   //Timer ends here
   long elapsed=System.currentTimeMillis()-start;        
   JOptionPane.showMessageDialog(null, "RSA Decryption is successfully completed!\n"+"Time elapsed is: "+((double)elapsed/1000)+" seconds","RSA decryption Timer, By Alem",JOptionPane.PLAIN_MESSAGE ); 
     
}
public void readFile()
{
        fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(this);
        String inFile ="";
        String str;

        if(result == JFileChooser.APPROVE_OPTION)
        {
		try
		{
			File file = fileChooser.getSelectedFile();
			textFieldFile.setText(file.getPath());
			str=textFieldFile.getText();
			File in = new File(str);
			Scanner read = new Scanner(in);
			
			while(read.hasNext())
			{
                            inFile += new String(read.nextLine())+ "\n";   
			}
                        plainText.setText(inFile);
			read.close();
                }
		catch(FileNotFoundException e)
		{
			JOptionPane.showMessageDialog(this,String.format("File not found"));
			return;
		}
	}
}
    private void encryptActionPerformed(java.awt.event.ActionEvent evt) {
    String plain = plainText.getText();
    encryptedText.setText("");
    //Timer begins here
    long start=System.currentTimeMillis();
    if(plain.equals("")|| modulus.getText().equals(""))
    {
        JOptionPane.showMessageDialog(this,String.format("ERROR!\nTry again!"));
	return;
    }
    int textLen= plain.length();
    int j=0;
    String encryptedMessage ="";
    while(j<textLen)
    {
        int endIndex = (j+bitLen/8) > textLen ? textLen : j+bitLen/8;
        String blockString = plain.substring(j,endIndex); 
        byte[] plainByte = blockString.getBytes();
        BigInteger message = new BigInteger(plainByte);
        BigInteger encryptedMessageAsBigInteger = encrypt(message);
        encryptedMessage += encryptedMessageAsBigInteger.toString(16) + " ";
        j += blockString.length();
    }
    encryptedText.setText(encryptedMessage);
    //Timer ends here
    long elapsed=System.currentTimeMillis()-start;        
   	JOptionPane.showMessageDialog(null, "RSA encryption is successfully completed!\n"+"Time elapsed is: "+((double)elapsed/1000)+" seconds","RSA encryption Timer, By Alem",JOptionPane.PLAIN_MESSAGE ); 
       	
}

private void generateKeyActionPerformed(java.awt.event.ActionEvent evt) {
      
    clearFields();
   
    
    String s=textKeyLength.getText();
    if(!isNumber(s))
    {
        JOptionPane.showMessageDialog(this,String.format("Please Enter Numeric Value!"));
        textKeyLength.requestFocus();
        textKeyLength.selectAll();
        return;
    }
    bitLen = Integer.parseInt(textKeyLength.getText());
    if(bitLen<8)
    {
        JOptionPane.showMessageDialog(this,String.format("Please Enter Bitlength >= 8 !"));
        textKeyLength.requestFocus();
        textKeyLength.selectAll();
        return;
    }		
    // ---------------------------get two big primes----------------------------
    do
    { 
        r = new SecureRandom();  
        p = BigInteger.probablePrime(bitLen, r);
        do
        {
            q = BigInteger.probablePrime(bitLen, r);
        }while(q.compareTo(p)==0);
        // get the modulo
         N = p.multiply(q);	
        // phi is needed to compute the exponent for encryption
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        // compute the exponent necessary for encryption (private key)
         e = BigInteger.probablePrime(bitLen/2, r);	
         while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0 ) 
        {
            e.add(BigInteger.ONE);
        }
    }while(e.gcd(p.subtract(BigInteger.ONE)).compareTo(BigInteger.ONE)>0 || 
            e.gcd(q.subtract(BigInteger.ONE)).compareTo(BigInteger.ONE)>0);
    // compute public key
    d = e.modInverse(phi); 
    modulus.setText(N.toString());
    pubKey.setText(e.toString());
    priKey.setText(d.toString());
}

private BigInteger encrypt(BigInteger message) 
{
    return message.modPow(e, N);
}
private BigInteger decrypt(BigInteger encrypted)
{
    return encrypted.modPow(d, N);
}
private boolean isNumber(String s)
{
    int i = s.length();
    for(int j =0;j<i;j++)
    {
        if(Character.isDigit(s.charAt(j))== false)
            return false;
    }
    return true;
}
private void clearFields()
{
    modulus.setText("");
    pubKey.setText("");
    priKey.setText("");
}
    
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                UIManager.put("swing.boldMetal",Boolean.FALSE);
                new RSAFinal().setVisible(true);
            }
        });
    }
    
    //---------------------------Declaration---------------------------------
    private javax.swing.JButton browse;
    private javax.swing.JTextArea decipheredText;
    private javax.swing.JButton decrypt;
    private javax.swing.JPanel decryptPanel;
    private javax.swing.JButton encrypt;
    private javax.swing.JPanel encryptPanel;
    private javax.swing.JTextArea encryptedText;
    private javax.swing.JButton generateKey;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JTextArea modulus;
    private javax.swing.JPanel panelKey;
    private javax.swing.JTextArea plainText;
    private javax.swing.JScrollPane plainTextScrollPane;
    private javax.swing.JTextArea priKey;
    private javax.swing.JTextArea pubKey;
    private javax.swing.JTextField textFieldFile;
    private javax.swing.JTextField textKeyLength;
    private SecureRandom r;
    private BigInteger p;
    private BigInteger q;
    private BigInteger N;
    private BigInteger phi;
    private BigInteger e;
    private BigInteger d;
    private int bitLen = 1024; 
    private JFileChooser fileChooser;
   
}
