#include <iostream>
#include <map>
#include "Doctor.h"
#include "Patient.h"

class Hospital {
public:
    std::map<std::string, Doctor> doctors;
    std::map<std::string, Patient> patients;

    void addDoctor(IDoctor* doctor);

    void removeDoctor(std::string doctorId);

    void addPatient(IPatient* patient);

    void removePatient(std::string patientId);

    std::string toString();

    void chain(std::string doctor, std::string patient);
};

int main() {
    Doctor doctor("Cardiologist", "Dr. Smith");
    Patient patient("Heart attack", "John Doe");
    doctor.addPatient(&patient);
    std::cout << doctor.toString() << "\n";
}