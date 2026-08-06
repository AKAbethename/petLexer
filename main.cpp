#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

enum class Sex {MALE, FEMALE};

std::ostream& operator<<(std::ostream& os, const Sex& s){
    if(s == Sex::FEMALE) os << "FEMALE";
    else if(s == Sex::MALE) os << "MALE";
    return os;
}

struct Human {
    std::string name;
    Sex sex;
    int age;

    Human(const std::string& name, const Sex& sex, int age) : name(name),
                                                             sex(sex),
                                                             age(age) {}
};


int main(){
   /*  std::unordered_map<std::string, int> table = {
        {"Arkady", 6758},
        {"Nona", 8246},
        {"Alik", 6993}
    };
    std::cout << table["Alik"] << " is Alik\n"; */

    auto p1 = std::make_unique<Human>("Arkady", Sex::MALE, 20);

    std::cout << p1->name << "\t" << p1->sex << "\t" << p1->age << '\n';

}
