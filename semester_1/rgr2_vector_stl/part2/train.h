#pragma once

#include <string>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;

enum class TrainType {
    PASSENGER,
    FREIGHT,
    HIGH_SPEED,
    SUBWAY,
    SPECIALIZED,
    NO_TYPE
};

class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    // your code goes here

    Train(TrainId id = 0,
          TrainType type = TrainType::NO_TYPE,
          const std::string& destination = "",
          std::time_t dispatchTime = 0,
          std::time_t travellingTime = 0);

    TrainId GetTrainId() const;
    TrainType GetTrainType() const;
    const std::string GetDestination() const;
    std::time_t GetDispatchTime() const;
    std::time_t GetTravellingTime() const;

    void SetTrainId(TrainId id);
    void SetTrainType(TrainType type);
    void SetDestination(const std::string& destination);
    void SetDispatchTime(const std::time_t& dispatchTime);
    void SetTravellingTime(const std::time_t& travellingTime);
};
