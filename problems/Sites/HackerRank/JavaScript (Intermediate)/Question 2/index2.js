function Employee(title) {
    this.title = title;
}

Employee.prototype.getTitle = function() {
    return this.title;
}

Employee.prototype.setTitle = function(value) {
    this.title = value;
}

function Engineer(title, isManager) {
    Employee.call(this, title);
    this.isManager = isManager;
}

Engineer.prototype = Object.create(Employee.prototype);
Engineer.prototype.constructor = Engineer;

Engineer.prototype.getIsManager = function() {
    return this.isManager;
}

Engineer.prototype.setIsManager = function(value) {
    this.isManager = value;
}

let emp = new Employee("Manager");
let eng = new Engineer("Dev", false);