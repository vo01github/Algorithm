public class Q103 {
    public static void main(String[] args) { 
        boolean isEqual = permutation("helowrd","wrdhloe");
        if( isEqual ){
            System.out.println("equal");
        }else{
             System.out.println("no equal");
        }
        
    }
    
    public static boolean permutation(String s,String t){
        if( s.length() != t.length() ){
            return false;
        }
        
        int[] letters = new int[256];
        
        char[] s_array = s.toCharArray();
        for( char c : s_array ){
            letters[c]++;
        }
        
        for( int i = 0; i< t.length(); i++ ){
            int c = (int)t.charAt(i);
            if( --letters[c] < 0 ){
                return false;
            }
        }
        
        return true;
    }
}