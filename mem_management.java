public class MemoryManagement {
    public static void main(String[] args) {
        
        Integer[] data = new Integer[5]; // Allocating Memory to the array
        
        for (int i = 0; i < data.length; i++) {
            data[i] = i * 10;  
        }

        data = null; // Dereferencing, eligible for GC

        System.gc(); // Manually call Garbage Collection

        System.out.println("Memory allocated and freed using Garbage collection");
    }
}