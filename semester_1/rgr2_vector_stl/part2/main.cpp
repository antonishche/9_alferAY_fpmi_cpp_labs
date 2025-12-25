#include "train.h"

#include <fstream>
#include <algorithm>
// #include <ctime>

void checkOpen(std::ifstream& inputFile, const std::string& fileName) {
    if (!inputFile.is_open()) {
        throw std::runtime_error("не удалось открыть файл \"" + fileName +
                                 "\"...");
    } else if (inputFile.peek() == std::fstream::traits_type::eof()) {
        throw std::runtime_error("файл \"" + fileName + "\" пустой.");
    }
}

std::string convertTrainTypeToString(const TrainType type) {
    if (type == TrainType::PASSENGER) {
        return "PASSENGER";
    } else if (type == TrainType::FREIGHT) {
        return "FREIGHT";
    } else if (type == TrainType::HIGH_SPEED) {
        return "HIGH_SPEED";
    } else if (type == TrainType::SPECIALIZED) {
        return "SPECIALIZED";
    } else if (type == TrainType::SUBWAY) {
        return "SUBWAY";
    } else {
        return "";
    }
}

void printTrain(const Train& train) {
    std::cout << train.GetTrainId() << " "
              << convertTrainTypeToString(train.GetTrainType()) << " "
              << train.GetDestination() << " ";
    // Время отправления
    std::time_t dispatchTime = train.GetDispatchTime();
    std::tm* dt = std::localtime(&dispatchTime);
    std::cout << std::setfill('0') << std::setw(2) << std::right << dt->tm_hour
              << ":" << std::setw(2) << std::right << dt->tm_min;

    std::cout << " ";

    // Время в пути
    std::time_t travelTime = train.GetTravellingTime();
    std::tm* tt = std::localtime(&travelTime);
    std::cout << std::setfill('0') << std::setw(2) << std::right << tt->tm_hour
              << ":" << std::setw(2) << std::right << tt->tm_min;

    std::cout << "\n";
}

void printTrainsIf(const std::vector<Train>& trains,
                   const std::string& description,
                   std::function<bool(const Train&)> condition) {
    std::cout << "*\n" << description << "\n";

    bool noTrains = true;

    for (const Train& train : trains) {
        if (condition(train)) {
            printTrain(train);
            noTrains = false;
        }
    }

    if (noTrains) {
        std::cout << "Отсутствуют";
    }
}

TrainType defineTrainType(const std::string& typeStr) {
    if (typeStr == "PASSENGER") {
        return TrainType::PASSENGER;
    } else if (typeStr == "FREIGHT") {
        return TrainType::FREIGHT;
    } else if (typeStr == "HIGH_SPEED") {
        return TrainType::HIGH_SPEED;
    } else if (typeStr == "SPECIALIZED") {
        return TrainType::SPECIALIZED;
    } else if (typeStr == "SUBWAY") {
        return TrainType::SUBWAY;
    } else {
        return TrainType::NO_TYPE;
    }
}

std::time_t defineTime(const std::string& timeStr) {
    size_t hours, minutes;

    size_t delimeterPos = timeStr.find(':');

    if (delimeterPos == 0 || delimeterPos == timeStr.size() - 1 ||
        delimeterPos == std::string::npos) {
        throw std::runtime_error("неверный формат времени.");
    }

    try {
        hours = std::stoul(timeStr.substr(0, delimeterPos));
        minutes = std::stoul(timeStr.substr(delimeterPos + 1));
    } catch (...) {
        throw std::runtime_error(
            "ошибка преобразования для нахождения времени.");
    }

    return SetTime(hours, minutes);
}

void fillVectorFromFile(std::vector<Train>& trains, std::ifstream& inputFile) {

    size_t id;
    std::string typeStr, destination, dispatchTimeStr, travellingTimeStr;

    while (inputFile >> id >> typeStr >> destination >> dispatchTimeStr >>
           travellingTimeStr) {
        Train newTrain;

        newTrain.SetTrainId(id);
        newTrain.SetTrainType(defineTrainType(typeStr));
        newTrain.SetDestination(destination);
        newTrain.SetDispatchTime(defineTime(dispatchTimeStr));
        newTrain.SetTravellingTime(defineTime(travellingTimeStr));

        trains.push_back(newTrain);
    }
}

void sortVectorByDispatchTime(std::vector<Train>& trains) {
    std::sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
        return a.GetDispatchTime() < b.GetDispatchTime();
    });
}

time_t getDispatchBorder(const std::string& typeOfRange) {
    std::cout << "Введите " << typeOfRange
              << " границу (в формате ЧЧ:ММ) диапазона времени:";

    std::string timeStr;
    if (!(std::cin >> timeStr)) {
        throw std::runtime_error("Неверный ввод.");
    }

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    return defineTime(timeStr);
}

void printTrainsFromDispatchRange(const std::vector<Train>& trains) {
    std::cout << "*\n";
    time_t minTime = getDispatchBorder("нижнюю");
    time_t maxTime = getDispatchBorder("верхнюю");

    if (minTime > maxTime) {
        std::swap(minTime, maxTime);
        std::cout << "(Границы поменялись местами)\n";
    }

    printTrainsIf(trains,
                  "Поезда из заданного диапазона времени:",
                  [minTime, maxTime](const Train& t) {
                      time_t dispatchTime = t.GetDispatchTime();
                      return dispatchTime >= minTime && dispatchTime <= maxTime;
                  });
}

std::string getDestination() {
    std::cout << "*\nВыберите пункт "
                 "назначения:\n1.Baranovichi\n2.Brest\n3.Gomel\n4.Grodno\n5."
                 "Mogilev\n6.Molodechno\n7.Polotsk\n8.Vitebsk\n";
    int cityNum;
    if (!(std::cin >> cityNum)) {
        throw std::runtime_error("неверно введён номер.");
    }

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    switch (cityNum) {
        case 1:
            return "Baranovichi";
        case 2:
            return "Brest";
        case 3:
            return "Gomel";
        case 4:
            return "Grodno";
        case 5:
            return "Mogilev";
        case 6:
            return "Molodechno";
        case 7:
            return "Polotsk";
        case 8:
            return "Vitebsk";
        default:
            throw std::runtime_error("неверно введён номер.");
    }
}

void printTrainsFromDestination(const std::vector<Train>& trains) {
    std::string destination = getDestination();

    printTrainsIf(trains,
                  "Поезда, направляющиеся в " + destination + ":",
                  [destination](const Train& t) {
                      return t.GetDestination() == destination;
                  });
}

TrainType getType() {
    std::cout << "*\nВыберите тип "
                 "поезда:\n1.PASSENGER\n2.FREIGHT\n3.HIGH_SPEED\n4.SUBWAY\n5."
                 "SPECIALIZED\n";

    int cityNum;
    if (!(std::cin >> cityNum)) {
        throw std::runtime_error("неверно введён номер.");
    }

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    if (cityNum == 1) {
        return TrainType::PASSENGER;
    } else if (cityNum == 2) {
        return TrainType::FREIGHT;
    } else if (cityNum == 3) {
        return TrainType::HIGH_SPEED;
    } else if (cityNum == 4) {
        return TrainType::SUBWAY;
    } else if (cityNum == 5) {
        return TrainType::SPECIALIZED;
    } else {
        throw std::runtime_error("неверно введён номер.");
    }
}

void printTrainsCurrentTypeFromDestination(const std::vector<Train>& trains) {
    TrainType type = getType();
    std::string destination = getDestination();

    printTrainsIf(trains,
                  "Поезда типа " + convertTrainTypeToString(type) +
                      ", направляющиеся в " + destination + ":",
                  [type, destination](const Train& t) {
                      return t.GetDestination() == destination &&
                             t.GetTrainType() == type;
                  });
}

int main() {

    setlocale(LC_ALL, "Russian");

    const std::string inputFileName = "TRAINS.TXT";
    std::ifstream in(inputFileName);

    try {
        checkOpen(in, inputFileName);

        std::vector<Train> trains;

        fillVectorFromFile(trains, in);
        printTrainsIf(
            trains, "Полученные поезда:", [](const Train&) { return true; });

        sortVectorByDispatchTime(trains);
        printTrainsIf(trains,
                      "Поезда после сотрировки по времени отправления:",
                      [](const Train&) { return true; });

        printTrainsFromDispatchRange(trains);

        printTrainsFromDestination(trains);

        printTrainsCurrentTypeFromDestination(trains);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
