#include "train.h"

Train::Train(TrainId id,
             TrainType type,
             const std::string& destination,
             std::time_t dispatchTime,
             std::time_t travellingTime)
    : id_(id),
      type_(type),
      destination_(destination),
      dispatch_time_(dispatchTime),
      travelling_time_(travellingTime) {
}

TrainId Train::GetTrainId() const {
    return id_;
}

TrainType Train::GetTrainType() const {
    return type_;
}

const std::string Train::GetDestination() const {
    return destination_;
}

std::time_t Train::GetDispatchTime() const {
    return dispatch_time_;
}

std::time_t Train::GetTravellingTime() const {
    return travelling_time_;
}

void Train::SetTrainId(TrainId id) {
    id_ = id;
}

void Train::SetTrainType(TrainType type) {
    type_ = type;
}

void Train::SetDestination(const std::string& destination) {
    destination_ = destination;
}

void Train::SetDispatchTime(const std::time_t& dispatchTime) {
    dispatch_time_ = dispatchTime;
}

void Train::SetTravellingTime(const std::time_t& travellingTime) {
    travelling_time_ = travellingTime;
}