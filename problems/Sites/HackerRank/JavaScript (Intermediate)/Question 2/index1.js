function Employee(title) {
    this.title = title;

    const getTitle = () => {
        return this.title;
    }
    this.getTitle = getTitle.bind(this);

    const setTitle = (value) => {
        this.title = value;
    }
    this.setTitle = setTitle.bind(this);

}

function Engineer(title, isManager) {
    Employee.call(this, title);
    this.isManager = isManager;

    const getIsManager = () => {
        return this.isManager;
    }
    this.getIsManager = getIsManager.bind(this);

    const setIsManager = (value) => {
        this.isManager = value;
    }
    this.setIsManager = setIsManager.bind(this);
}


let eng = new Engineer("Dev", true);
console.log(eng.getTitle());
console.log(eng.getIsManager());
eng.setTitle("QA");
eng.setIsManager(false);
console.log(eng.getTitle());
console.log(eng.getIsManager());
