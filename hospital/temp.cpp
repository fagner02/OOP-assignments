#include <iostream>
#include <map>

class Patient;
class Doctor {
public:
    std::string className;
    std::string sender;
    std::map<std::string, Patient> patients;

    Doctor() = default;

    Doctor(std::string className, std::string sender) : className(className), sender(sender) {}

    void addPatient(Patient patient);

    void removePatient(std::string patientId);
};

class Patient {
public:
    std::string diagnostic;
    std::map<std::string, Doctor> doctors;
    std::string sender;

    Patient() = default;
    Patient(std::string diagnostic, std::string sender) : diagnostic(diagnostic), sender(sender) {}

    void addDoctor(Doctor doctor) {
        doctors[doctor.className] = doctor;
    }
};

void Doctor::addPatient(Patient patient) {
    patients[patient.sender] = patient;
}

void Doctor::removePatient(std::string patientId) {
    patients.erase(patientId);
}