package it.unibo.apice.oop.p16reflection.annotations;

import java.util.*;

public class UseSuppress{
    @SuppressWarnings({ "unchecked", "unused" })
	public static void main(String[] s){
    	Object o = new ArrayList<Integer>(Arrays.asList(1,2,3,4));
		List<Integer> list = (List<Integer>)o;
    }
}

