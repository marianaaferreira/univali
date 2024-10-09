package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import com.datastax.oss.driver.api.core.CqlSession;
import com.datastax.oss.driver.api.core.cql.BoundStatement;
import com.datastax.oss.driver.api.core.cql.PreparedStatement;
import com.datastax.oss.driver.api.core.cql.SimpleStatement;

import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

public class MySQLToCassandra {

    private static final Logger logger = Logger.getLogger(MySQLToCassandra.class.getName());

        static {
            ConsoleHandler handler = new ConsoleHandler();
            handler.setLevel(Level.ALL);
            logger.addHandler(handler);
            logger.setLevel(Level.ALL);
            logger.setUseParentHandlers(false);
        }

    public void migrarDados() {
        Connection cnxmysql = null;
        CqlSession cnxcassandra = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/employees";
            String user = "root";
            String password = "root";
            cnxmysql = DriverManager.getConnection(url, user, password);

            cnxcassandra = CqlSession.builder().build();

            String keyspace = "cassandra_db";
            cnxcassandra.execute(String.format("USE %s;", keyspace));

            String query1 =  "SELECT mgr.first_name AS first_name_manager, mgr.last_name AS last_name_manager, mgr.emp_no as emp_no_manager, emp.emp_no, emp.birth_date, emp.first_name, emp.last_name, emp.gender, emp.hire_date \n" +
                    "FROM employees AS mgr\n" +
                    "JOIN dept_manager AS dm ON mgr.emp_no = dm.emp_no\n" +
                    "JOIN dept_emp AS de ON dm.dept_no = de.dept_no\n" +
                    "JOIN employees AS emp ON de.emp_no = emp.emp_no;";

            String query2 = "SELECT d.dept_name, de.from_date, de.to_date, emp.emp_no, emp.birth_date, emp.first_name, emp.last_name, emp.gender, emp.hire_date\n" +
                    "FROM employees AS emp\n" +
                    "JOIN dept_emp AS de ON emp.emp_no = de.emp_no\n" +
                    "JOIN departments AS d ON de.dept_no = d.dept_no;";
            String query3 = "SELECT d.dept_name, emp.emp_no, emp.birth_date, emp.first_name, emp.last_name, emp.gender, emp.hire_date, avg(s.salary) as avg_salary\n" +
                    "FROM employees AS emp\n" +
                    "JOIN dept_emp AS de ON emp.emp_no = de.emp_no\n" +
                    "JOIN departments AS d ON de.dept_no = d.dept_no\n" +
                    "JOIN salaries AS s ON s.emp_no = emp.emp_no\n" +
                    "group by emp_no, emp.birth_date, emp.first_name, emp.last_name, emp.gender, emp.hire_date, d.dept_name;";


            executeAndInsert1(cnxmysql, cnxcassandra, query1);
            executeAndInsert2(cnxmysql, cnxcassandra, query2);
            executeAndInsert3(cnxmysql, cnxcassandra, query3);

            System.out.println("Dados migrados para o Cassandra");

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                if (cnxmysql != null) {
                    cnxmysql.close();
                }
                if (cnxcassandra != null) {
                    cnxcassandra.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    private void executeAndInsert1(Connection cnxmysql, CqlSession cnxcassandra, String mysqlQuery) throws SQLException {
        Statement stmt = cnxmysql.createStatement();
        ResultSet rs = stmt.executeQuery(mysqlQuery);

        int count = 0;
        while (rs.next()) {
            try {
                String insertQuery = String.format(
                    "INSERT INTO employees_by_manager (first_name_manager, last_name_manager, emp_no_manager, emp_no, birth_date, first_name, last_name, gender, hire_date) " +
                    "VALUES ('%s', '%s', %d, %d, '%s', '%s', '%s', '%s', '%s')",
                    rs.getString("first_name_manager"),
                    rs.getString("last_name_manager"),
                    rs.getInt("emp_no"),
                    rs.getString("birth_date"),
                    rs.getString("first_name"),
                    rs.getString("last_name"),
                    rs.getString("gender"),
                    rs.getString("hire_date")
                );

                cnxcassandra.execute(SimpleStatement.newInstance(insertQuery));
                count++;
            } catch (Exception e) {
                logger.severe("Erro ao inserir registro na tabela employees_by_manager: " + e.getMessage());
            }
        }

        logger.info("Total de registros migrados para employees_by_manager: " + count);
        rs.close();
        stmt.close();
    }


    private void executeAndInsert2(Connection cnxmysql, CqlSession cnxcassandra, String mysqlQuery) throws SQLException {
        Statement stmt = cnxmysql.createStatement();
        ResultSet rs = stmt.executeQuery(mysqlQuery);

        int count = 0;
        while (rs.next()) {
            try {
                String insertQuery = String.format(
                    "INSERT INTO employees_by_dept (dept_name, from_date, to_date, emp_no, birth_date, first_name, last_name, gender, hire_date) " +
                    "VALUES ('%s', '%s', '%s', %d, '%s', '%s', '%s', '%s', '%s')",
                    rs.getString("dept_name"),
                    rs.getDate("from_date").toLocalDate(),
                    rs.getDate("to_date").toLocalDate(),
                    rs.getInt("emp_no"),
                    rs.getDate("birth_date").toLocalDate(),
                    rs.getString("first_name"),
                    rs.getString("last_name"),
                    rs.getString("gender"),
                    rs.getDate("hire_date").toLocalDate()
                );

                cnxcassandra.execute(SimpleStatement.newInstance(insertQuery));
                count++;
            } catch (Exception e) {
                logger.severe("Erro ao inserir registro na tabela employees_by_dept: " + e.getMessage());
            }
        }

        logger.info("Total de registros migrados para employees_by_dept: " + count);
        rs.close();
        stmt.close();
    }

    private void executeAndInsert3(Connection cnxmysql, CqlSession cnxcassandra, String mysqlQuery) throws SQLException {
        Statement stmt = cnxmysql.createStatement();
        ResultSet rs = stmt.executeQuery(mysqlQuery);

        int count = 0;
        while (rs.next()) {
            try {
                String insertQuery = String.format(
                    "INSERT INTO avg_salary_employees_by_dept (dept_name, emp_no, birth_date, first_name, last_name, gender, hire_date, avg_salary) " +
                    "VALUES ('%s', %d, '%s', '%s', '%s', '%s', '%s', %d)",
                    rs.getString("dept_name"),
                    rs.getInt("emp_no"),
                    rs.getDate("birth_date").toLocalDate(),
                    rs.getString("first_name"),
                    rs.getString("last_name"),
                    rs.getString("gender"),
                    rs.getDate("hire_date").toLocalDate(),
                    rs.getInt("avg_salary")
                );

                cnxcassandra.execute(SimpleStatement.newInstance(insertQuery));
                count++;
            } catch (Exception e) {
                logger.severe("Erro ao inserir registro na tabela avg_salary_employees_by_dept: " + e.getMessage());
            }
        }

        logger.info("Total de registros migrados para avg_salary_employees_by_dept: " + count);
        rs.close();
        stmt.close();
    }
}
