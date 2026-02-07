#include "src/Rating/rating.h"

// #include <algorithm>

int main() {
    std::cout << "Hello, world!" << std::endl;

    setlocale(LC_ALL, "");

    try {
        std::string inputFileName = "INPUT.TXT";

        // 1-3
        Rating students;
        students.readDataFromFile(inputFileName);

        students.printIf("Студенты:", [](const StudentData &) {
            return true;
        });

        students.printInOrder();

        students.printByDiaposons();

        students.printBySubject();

        students.printStudentsPerSubject();

        students.printAveragePerSubject();

        students.printIf("Студенты с максимальной суммой баллов:", [](const StudentData &student) {
            for (const Mark &markData : student.marks_) {
                if (markData.mark_ != 10.00) {
                    return false;
                }
            }

            return true;
        });

        students.printIf("Студенты с неудовлетворительными оценками:", [](const StudentData &student) {
            for (const Mark &markData : student.marks_) {
                if (markData.mark_ < 4.00) {
                    return true;
                }
            }

            return false;
        });

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
