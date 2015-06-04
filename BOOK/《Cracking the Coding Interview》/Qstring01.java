public class Qstring01 {
    public static void main(String[] args) { 
        boolean isUnique = isUniqueChar2("Helo,Wrd");
        if( isUnique ){
            System.out.println("no equal");
        }else{
             System.out.println("equal");
        }
        
    }
    
    public static boolean isUniqueChar2(String str){
        if(str.length()>256)return false;
        
        boolean[] char_set = new boolean[256];
        for(int i = 0;i<str.length();i++){
            int val = str.charAt(i);
            if(char_set[val]){
                return false;
            }
            char_set[val] = true;
        }
        return true;    
    }
}