#include <iostream>
#include <string>

struct person
{
    std::string fName;
    std::string lName;
    int age;
};

void incrementAge(struct person &p)
{
    p.age += 1;
}

int main()
{
    person person1;
    person1.fName = "Max";
    person1.lName = "Muster";
    person1.age = 37;

    person person2;
    person2.fName = "Jane";
    person2.lName = "Doe";
    person2.age = 23;

    std::cout << person1.fName << " " << person1.age << std::endl;
    std::cout << person2.fName << " " << person2.age << std::endl;
    incrementAge(person1);
    std::cout << person1.fName << " " << person1.age << std::endl;
    std::cout << person2.fName << " " << person2.age << std::endl;

    struct person *p1 = NULL; // Create a pointer variable and initialise it to NULL
    p1 = &person1;            // Store pointer value for person1 in p1

    p1->fName = "Maximillian"; // Overwrite fName for person1
    std::cout << person1.fName << " " << person1.age << std::endl;

    return 0;
};