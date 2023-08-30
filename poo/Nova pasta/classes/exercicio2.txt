package br.univali.poo.exercicio2;

public class Employee {
        String nome, sobrenome;
        double salario;

    public Employee(String nome, String sobrenome, double salario) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        if(salario>0) this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        if(salario>0) this.salario = salario;
    }
    public void aumentoSalario(int perc){
        salario = salario * (1 + perc/100.0);
    }

    public void displayLine()
    {
        System.out.println(nome + " " + sobrenome);
        System.out.printf("Salario %.2f\n", getSalario());
    }
    @Override
    public String toString() {
        return "Employee{" +
                "nome='" + nome + '\'' +
                ", sobrenome='" + sobrenome + '\'' +
                ", salario=" + salario +
                '}';
    }
}

package br.univali.poo.exercicio2;

public class EmployeeTest {

    public static void main(String[] args) {

        Employee e1 = new Employee("John", "Hook", 1000.00);
        Employee e2 = new Employee("Mary", "Bone", 1500.00);
        System.out.println(e1.toString());
        System.out.println(e2.toString());

        e1.aumentoSalario(10);
        e2.aumentoSalario(10);
        System.out.println("Novos salarios: ");
        e1.displayLine();
        e2.displayLine();
    }

}
