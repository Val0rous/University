package a03b.e2;

import javax.swing.*;
import java.util.*;
import java.util.List;
import java.awt.*;
import java.awt.event.ActionListener;

public class GUI extends JFrame {
    
    private static final long serialVersionUID = -6218820567019985015L;
    private final List<JButton> cells = new ArrayList<>();
    private int counter = 0;
    private int x = 3;
    private int y = 3;
    private int size;
    
    public GUI(int size) {
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(50*size, 50*size);
        this.size = size;
        
        JPanel panel = new JPanel(new GridLayout(size,size));
        this.getContentPane().add(panel);
        
        ActionListener al = e -> {
        	switch(this.counter) {
        	//start
        	case 0:
        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
            	this.counter++;
        		break;
        	//north
        	case 1:
        	case 7:
        	case 8:
        	case 9:
        	case 21:
        	case 22:
        	case 23:
        	case 24:
        	case 25:
        	case 43:
        	case 44:
        	case 45:
        	case 46:
        	case 47:
        	case 48:
        		this.y--;
        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
            	this.counter++;
        		break;
        	//east
        	case 2:
        	case 10:
        	case 11:
        	case 12:
        	case 26:
        	case 27:
        	case 28:
        	case 29:
        	case 30:
        		this.x++;
        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
            	this.counter++;
        		break;
        	//south
        	case 3:
        	case 4:
        	case 13:
        	case 14:
        	case 15:
        	case 16:
        	case 31:
        	case 32:
        	case 33:
        	case 34:
        	case 35:
        	case 36:
        		this.y++;
        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
            	this.counter++;
            	break;
           	//west
        	case 5:
        	case 6:
        	case 17:
        	case 18:
        	case 19:
        	case 20:
        	case 37:
        	case 38:
        	case 39:
        	case 40:
        	case 41:
        	case 42:
        		this.x--;
        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
            	this.counter++;
        	
        		
        	}
        	
//        	if(this.counter == 0) {
//        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
//            	this.counter++;
//        	} else if(this.counter == 1) {
//        		this.y--;
//        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
//            	this.counter++;
//        	} else if(this.counter == 2) {
//        		this.x++;
//        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
//            	this.counter++;
//        	} else if(this.counter == 3 || this.counter == 4) {
//        		this.y++;
//        		this.cells.get(this.x + this.y*this.size).setText(String.valueOf(this.counter));
//            	this.counter++;
//        	}
        	
        	
        };
                
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
            	var pos = new Pair<>(j,i);
                final JButton jb = new JButton(" ");
                this.cells.add(jb);
                jb.addActionListener(al);
                panel.add(jb);
            }
        }
        this.setVisible(true);
    }
    
}
