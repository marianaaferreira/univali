import mysql.connector
from pymongo import MongoClient

cnxmysql = mysql.connector.connect(user='root', password='root',
                              host='localhost',
                              database='employees')

cnxmongo = MongoClient('mongodb://localhost:27017/')
db = cnxmongo.m2
collection = db.employees

cursor = cnxmysql.cursor(dictionary=True)
query = ("select * from employees")
cursor.execute(query)
employees = cursor.fetchall()

for employee in employees:
    emp_no = employee['emp_no']

    existing_employee = collection.find_one({'emp_no': emp_no})
    if not existing_employee:

        query = ("select * from salaries where emp_no=%s")
        cursor.execute(query, (emp_no,))
        salaries = cursor.fetchall()

        query = ("select * from titles where emp_no=%s")
        cursor.execute(query, (emp_no,))
        titles = cursor.fetchall()

        query = ("select * from dept_emp where emp_no=%s")
        cursor.execute(query, (emp_no,))
        dept_emp = cursor.fetchall()

        query = ("select * from dept_manager where emp_no=%s")
        cursor.execute(query, (emp_no,))
        dept_manager = cursor.fetchall()

        query = ("select d.* from departments d "
                 "join dept_emp de on d.dept_no = de.dept_no "
                 "where de.emp_no = %s")
        cursor.execute(query, (emp_no,))
        departments_emp = cursor.fetchall()

        query = ("select d.* from departments d "
                 "join dept_manager dm on d.dept_no = dm.dept_no "
                 "where dm.emp_no = %s")
        cursor.execute(query, (emp_no,))
        departments_manager = cursor.fetchall()

        salaries_list = []
        for salary in salaries:
            salaries_list.append({
                'salary': salary['salary'],
                'from_date': salary['from_date'].isoformat(),
                'to_date': salary['to_date'].isoformat()
            })

        titles_list = []
        for title in titles:
            titles_list.append({
                'title': title['title'],
                'from_date': title['from_date'].isoformat(),
                'to_date': title['to_date'].isoformat()
            })

        departments_emp_list = []
        for de in departments_emp:
            departments_emp_list.append({
                'dept_no': de['dept_no'],
                'dept_name': de['dept_name']
            })

        dept_emp_list = []
        for demp in dept_emp:
            dept_emp_list.append({
                'departments': departments_emp_list,
                'emp_no': demp['emp_no'],
                'from_date': title['from_date'].isoformat(),
                'to_date': title['to_date'].isoformat()
            })

        departments_manager_list = []
        for dm in departments_manager:
            departments_manager_list.append({
                'dept_no': dm['dept_no'],
                'dept_name': dm['dept_name']
            })

        dept_manager_list = []
        for dmanager in dept_manager:
            dept_manager_list.append({
                'departments': departments_manager_list,
                'emp_no': dmanager['emp_no'],
                'from_date': title['from_date'].isoformat(),
                'to_date': title['to_date'].isoformat()
            })

        doc_employee = {
            'emp_no': emp_no,
            'birth_date': employee['birth_date'].isoformat(),
            'first_name': employee['first_name'],
            'last_name': employee['last_name'],
            'gender': employee['gender'],
            'hire_date': employee['hire_date'].isoformat(),
            'salaries': salaries_list,
            'titles': titles_list,
            'dept_emp': dept_emp_list,
            'dept_manager': dept_manager_list
        }
        collection.insert_one(doc_employee)

cnxmysql.close()
cnxmongo.close()