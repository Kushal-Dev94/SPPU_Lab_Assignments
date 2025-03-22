class Employee {
    double basic_pay, DA, HRA, PF, staff_lub_fund, gross, net;

    Employee(double basic_pay) {
        this.basic_pay = basic_pay;
    }

    void displaySalary() {
        DA = 0.97 * basic_pay;
        HRA = 0.1 * basic_pay;
        PF = 0.12 * basic_pay;
        staff_lub_fund = 0.01 * basic_pay;
        gross = basic_pay + DA + HRA;
        net = gross - PF - staff_lub_fund;
        System.out.println("The Gross Salary is: " + gross + ".\nThe Net Salary is: " + net);
    }
}

class Salary{
    public static void main(String args[]) {
        System.out.println("Enter basic pay");
        Employee E1 = new Employee(50000);
        E1.displaySalary();
    }
}