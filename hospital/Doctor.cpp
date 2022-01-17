#include "Doctor.h"

Doctor::Doctor(std::string className, std::string sender) : className(className), sender(sender) {}

void Doctor::addPatient(IPatient* patient) {
    patients[patient->getId()] = patient;
    std::cout << patient->getId() << " is added to " << className << ".\n";
}

void Doctor::removePatient(std::string patientId) {
    patients.erase(patientId);
}

std::string Doctor::getClass() {
    return className;
}

std::string Doctor::getId() {
    return sender;
}

std::vector<IPatient*> Doctor::getPatients() {
    std::vector<IPatient*> patients;
    for (auto x : this->patients) {
        patients.push_back(x.second);
    }
    return patients;
}

std::string Doctor::toString() {
    std::stringstream ss;
    ss << "Doctor " << sender << " is a " << className << ".\nPatients:\n";
    for (auto x : patients) {
        ss << x.second->getId() << "\n";
    }
    return ss.str();
}
