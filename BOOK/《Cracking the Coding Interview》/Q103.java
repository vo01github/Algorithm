public class Q103 {
    public static void main(String[] args) { 
        boolean isEqual = permutation("Helo,Wrd","safsf");
        if( isEqual ){
            System.out.println("no equal");
        }else{
             System.out.println("equal");
        }
        
    }
    
    public static boolean permutation(String s,String t){
        if( s.length() != t.length() ){
            return false;
        }
        
        int[] letters = new int[256];
        
        chat[] s_array = s.toCharArray();
        for( char c : s_array ){
            letters[c]++;
        }
        
    }
}