#include <iostream>
#include <fstream>
#include <exception>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <string>
#include <cmath>

class Employee
{
protected:
    std::string m_name;
    int m_age;

    std::string m_position;
    int m_rank;

public:
    Employee(std::string name, int age, std::string position, int rank)
            : m_name(std::move(name)), m_age(age), m_position(std::move(position)), m_rank(rank)
    {}

    // Copy constructor
    Employee(const Employee& employee) {
        m_name = employee.m_name;
        m_age = employee.m_age;
        m_position = employee.m_position;
        m_rank = employee.m_rank;
    }

    // Default Constructor
    Employee() {}

    friend std::ostream& operator<<(std::ostream& out, const Employee& e);
    virtual int CalculatePay() const { return 200 + m_rank * 50; }
};

std::ostream& operator<<(std::ostream& out, const Employee& e)
{
    out << e.m_name << " (" << e.m_position << " , " << e.m_age << ") ==> "
              << e.CalculatePay() << "만원";
    return out;
}

class Manager : public Employee
{
private:
    int m_year_of_service;

public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
        : m_year_of_service(year_of_service), Employee(std::move(name), age, std::move(position), rank)
    {}

    Manager(const Manager& manager)
        : m_year_of_service(manager.m_year_of_service),
          Employee(manager.m_name, manager.m_age, manager.m_position, manager.m_rank)
    {}

    // Default constructor
    Manager() : Employee() {}
    int CalculatePay() const override { return 200 + m_rank * 50 + 5 * m_year_of_service; }

    friend std::ostream& operator<<(std::ostream& out, const Manager& m);
};

std::ostream& operator<<(std::ostream& out, const Manager& m)
{
    out << m.m_name << " (" << m.m_position << " , " << m.m_age << ") ==> "
        << m.CalculatePay() << "만원";
    return out;
}

class EmployeeList
{
    int m_alloc_employee;
    int m_current_employee;
    int m_current_manager;
    Employee** m_employee_list;
    Manager** m_manager_list;

public:
    EmployeeList(const int alloc_in)
        : m_alloc_employee(alloc_in)
    {
        m_employee_list = new Employee*[m_alloc_employee];
        m_manager_list = new Manager*[m_alloc_employee];
        m_current_employee = 0;
        m_current_manager = 0;
    }

    void AddEmployee(Employee* employee)
    {
        m_employee_list[m_current_employee] = employee;
        m_current_employee++;
    }
    void AddManager(Manager* manager)
    {
        m_manager_list[m_current_manager] = manager;
        m_current_manager++;
    }
    int CurrentEmployeeNum() const { return m_current_employee; }
    int currentManagerNum() const { return m_current_manager; }
    void PrintEmployeeInfo() const
    {
        int total_pay = 0;

        for(int i = 0; i < m_current_employee; ++i)
        {
            std::cout << *(m_employee_list[i]) << std::endl;
            total_pay += m_employee_list[i]->CalculatePay();
        }

        for(int i = 0; i < m_current_manager; ++i)
        {
            std::cout << *(m_manager_list[i]) << std::endl;
            total_pay += m_manager_list[i]->CalculatePay();
        }

        std::cout << "Total Pay: " << total_pay << std::endl;
    }
    ~EmployeeList()
    {
        for(int i = 0; i < m_current_employee; ++i)
            delete m_employee_list[i];

        for(int i = 0; i < m_current_manager; ++i)
            delete m_manager_list[i];

        delete[] m_employee_list;
        delete[] m_manager_list;
    }
};

int main()
{

}