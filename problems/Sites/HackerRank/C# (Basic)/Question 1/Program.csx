class Note {
    public string Name { get; set; }
    public string State { get; set; }

    public Note(string name, string state) {
        this.Name = name;
        this.State = state;
    }
}

class NotesStore {
    List<Note> notes = new List<Note>();

    bool IsValidState(string state) {
        string[] states = new string[] { "completed", "active", "others" };
        List<string> validStates = new List<string>(states);
        return validStates.Contains(state);
    }

    public void AddNote(string state, string name) {
        if ( name == "") {
            throw new System.Exception("Name cannot be empty");
        }
        if (!IsValidState(state)) {
            throw new System.Exception("Invalid state " + state);
        }

        Note note = new Note(name, state);
        notes.Add(note);
    }

    public List<string> GetNotes(string state) {
        if (!IsValidState(state)) {
            throw new System.Exception("Invalid state " + state);
        }

        List<string> notes = new List<string>();
        foreach (Note note in this.notes) {
            if (note.State == state) {
                notes.Add(note.Name);
            }
        }
        return notes;
    }
}

class Program {
    static void PrintList(List<string> list) {
        foreach (string item in list) {
            Console.WriteLine(item);
        }
    }

    public static void Main(string[] args) {
        NotesStore notesStore = new NotesStore();
        
        notesStore.AddNote("active", "Drink Tea");
        notesStore.AddNote("active", "Drink Coffee");
        notesStore.AddNote("completed", "Study");

        PrintList(notesStore.GetNotes("active"));
        PrintList(notesStore.GetNotes("completed"));
        PrintList(notesStore.GetNotes("foo"));
    }
}

Program.Main(null);