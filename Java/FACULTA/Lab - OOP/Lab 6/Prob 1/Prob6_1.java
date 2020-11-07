interface Item {
    String getContent();
}

class File implements Item{
    private String information;

    public File(String information){
        this.information = information;
    }

    public String getContent(){
        return this.information;
    }

    public boolean equals(Object o){
        return (o instanceof File) && ((File)o).name.equals(this.name);
    }
}

class Folder implements Item{
    private Item[] entries;
    private int size = 0;

    public void addItem(Item newItem){
        File[] temp = new File[size+1];
        if ( size != 0 ){
            System.arraycopy(entries, 0, temp, 0, size);
        }
        temp[size] = newItem;
        this.entries = temp;
        size++;
    }

    public String getContent(){
        String printString = "";

        for (int i = 0 ; i < size ; i++){
            printString += this.entries[i].getContent() + "\n";
        }
        
        return printString;
    }
}

public class Prob1 {
    public static void main(String[] args){
        File f1 = new File("bani.txt", "Abi si Dani");
        File f2 = new File("Romeo Fantastik.mov", "Carolina Jambala");
        File f3 = new File("hatz.txt", "Gionule");

        Folder fol = new Folder();
        fol.addFile(f1);
        fol.addFile(f2);
        fol.addFile(f3);
        fol.addFile(f2);

        System.out.print(fol.getContent());
    }
}
